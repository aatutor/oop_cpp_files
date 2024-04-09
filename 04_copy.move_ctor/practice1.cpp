#include <iostream>
#include <string>

struct Book {
	// size_t id_;
	std::string title_;
	std::string author_;
	size_t year_;
	Book (std::string title, std::string author, size_t year) {
		this->title_ = title;
		this->author_ = author;
		this->year_ = year;
	}
	Book() {}
	std::string ToString() {
		return title_+" ("+ author_ +", "+ std::to_string(year_) +")";
	}
};

class Library {
	Book* books_;
	size_t count_;
public:
	Library(Book books[], size_t count);
	// Library(Library& lib);
	// Library(Library&& lib);
	~Library();
	Book& GetBook(size_t index);
	// std::string ToString();
	void Print();
	Library Concat(Library& lib);
};

int main ()
{
	using namespace std;
	Book books[] = {
		{"War and Peace", "Leo Tolstoy", 1869},
		{"Anna Karenina", "Leo Tolstoy", 1877},
		{"Crime and Punishment", "Fyodor Dostoevsky", 1866},
	};
	Library lib(books, 3);
#if 0
	Library copy(lib);

	lib.GetBook(0).author_ = "Alex Pushkin";

	cout << "\tOriginal: " << endl;
	lib.Print();

	cout << "\tCopy: " << endl;
	copy.Print();

	Library newLib = lib.Concat(copy);
	cout << "\tConcat: " << endl;
	newLib.Print();
#endif

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