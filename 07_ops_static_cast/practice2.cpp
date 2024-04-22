#include <iostream>
#include <string>

class Library;

struct Book {
	std::string title_;
	std::string author_;
	int year_;
	Book (std::string title, std::string author, int year) {
		this->title_ = title;
		this->author_ = author;
		this->year_ = year;
	}
	Book() {}
	operator std::string ();
	// operator Library(); ??
};

class Library {
	Book* books_;
	int count_;
public:
	Library(Book books[], int count);
	~Library();
	friend ostream& operator<< (ostream& out, const Library& lib);
	Library Concat(Library& lib);
	// Book& GetBook(int index);
	Book& operator[] (int index);
	Book  operator[] (std::string title);
	Library operator() (std::string author);
	Library operator() (int year);
};

int main ()
{
	using namespace std;
	Book b1 = {"War and Peace", "Leo Tolstoy", 1869};
	Book b2 = {"Anna Karenina", "Leo Tolstoy", 1877};
	Book b3 = {"Crime and Punishment", "Fyodor Dostoevsky", 1866};

	...

	return 0;
}

Library Library::Concat(Library& lib) {
	if (this->count_ == 0) {
		return lib;
	}
	if (lib.count_ == 0) {
		return *this;
	}
	Book* newBooks = new Book[this->count_ + lib.count_];
	for (int i = 0; i < this->count_; i++) {
		newBooks[i] = this->books_[i];
	}
	for (int i = 0; i < lib.count_; i++) {
		newBooks[i + this->count_] = lib.books_[i];
	}
	Library newLib(newBooks, this->count_ + lib.count_);
	delete[] newBooks;
	return newLib;
}
