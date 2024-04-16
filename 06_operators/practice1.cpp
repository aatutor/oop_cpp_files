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
	std::string ToString() {
		return title_+" ("+ author_ +", "+ std::to_string(year_) +")";
	}
	Library operator+ (Book& book);
	bool operator== (Book& book);
	bool operator!= (Book& book);
};

class Library {
	Book* books_;
	int count_;
public:
	Library(Book books[], int count);
	~Library();
	Book& GetBook(int index);
	friend ostream& operator<< (ostream& out, const Library& lib);
	Library Concat(Library& lib);
	Library operator= (const Library& lib);
	Library operator+= (Library& lib);
	Library operator+= (Book& book);
	Library operator-= (Book& book);
};

int main ()
{
	using namespace std;
	Book b1 = {"War and Peace", "Leo Tolstoy", 1869};
	Book b2 = {"Anna Karenina", "Leo Tolstoy", 1877};
	Book b3 = {"Crime and Punishment", "Fyodor Dostoevsky", 1866};

	Library lib1 = b1 + b2;
	cout << "b1 + b2" << endl;
	lib1.Print();

	Library lib2 = b1 + b2 + b3;
	cout << "b1 + b2 + b3" << endl;
	lib2.Print();

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