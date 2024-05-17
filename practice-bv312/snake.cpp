#include <iostream>
#include <string>
#include <windows.h>
#include <random>
#include <list>

// Змейка

class Cell {
	std::string val_;
	static size_t height_;
	static size_t width_;
public: 
	Cell(std::string v): val_(v) {}

	std::string ToString() {
		return val_;
	}
	size_t Height() {
		return height_;
	}
	size_t Width() {
		return width_;
	}
};
size_t Cell::height_ = 1;
size_t Cell::width_ = 1;

struct Point {
	Cell* texture_;
	size_t row, col;
};

class Apple {
	Point pos_;
	Cell texture_;
public:
	Apple() : texture_("0"), pos_{ &(this->texture_), 0, 0 } {}
	void SetPosition(size_t row, size_t col) {
		pos_.row = row;
		pos_.col = col;
	}
	Point& GetPoint() {
		return pos_;
	}
};
class Body {
	struct Node {
		Point pos_;
		Node* next_;
		Node* prev_;
	};
	Node* head_;
	Node* tail_;
	enum {LEFT, UP, RIGHT, DOWN};
	int direction_ = LEFT;
public:
	Body(Cell& text, size_t row, size_t col) {
		head_ = new Node{ {&text, row, col}, nullptr, nullptr };
		tail_ = new Node{ {&text, row, col + 1}, nullptr, head_ };
		head_->next_ = tail_;
	}
	std::list<Point> GetPoints() {
		std::list<Point> list;
		Node* temp = head_;
		while (temp != nullptr) {
			list.push_back(temp->pos_);
			temp = temp->next_;
		}
		return list;
	}
	void Move() {
		Node* temp = new Node{ head_->pos_, head_, nullptr };
		if (direction_ == LEFT) {
			temp->pos_.col -= 1;
		}
		if (direction_ == RIGHT) {
			temp->pos_.col += 1;
		}
		if (direction_ == UP) {
			temp->pos_.row -= 1;
		}
		if (direction_ == DOWN) {
			temp->pos_.row += 1;
		}
		head_->prev_ = temp;
		head_ = temp;
		// rm tail
		temp = this->tail_;
		tail_ = tail_->prev_;
		delete temp;
		tail_->next_ = nullptr;
	}
};
class Snake {
	Body body_;
	//Cell head;
	Cell textBody_;
public:
	Snake(size_t row, size_t col) 
		: textBody_("+"), body_(textBody_, row, col) {}
	std::list<Point> GetPoints() {
		return body_.GetPoints();
	}
	void Move() {
		body_.Move();
	}
};

class Console {
	std::string* canvas_;
	size_t height_;
	size_t width_;
public:
	Console(size_t h, size_t w): height_(h), width_(w) {
		this->canvas_ = new std::string[h];
		this->Clear();
	}
	void Clear() {
		for (size_t i = 0; i < this->height_; i++) {
			this->canvas_[i] = std::string(this->width_, '-');
		}
	}
	void Push(std::string s, size_t row, size_t col) {
		canvas_[row].replace(col, s.size(), s);
	}
	void Print() {
		for (size_t i = 0; i < this->height_; i++) {
			std::cout << this->canvas_[i] << "\n";
		}
	}
};
class Field {
	size_t height_;
	size_t width_;
	Apple apple_;
	Snake snake_;
	Console printer_;
	size_t fps_ = 1;
public:
	Field(size_t h, size_t w): height_(h), width_(w),
			printer_(h, w), snake_(h/2, w/2) {}

	void Push(Point& p) {
		this->printer_.Push(p.texture_->ToString(), p.row, p.col);
	}
	void MoveApple() {
		this->apple_.SetPosition(
			rand() % this->height_, 
			rand() % this->width_
		);
	}
	void MoveSnake() {
		snake_.Move();
	}
	void Play() {
		while (1) {
			this->printer_.Clear();
			this->MoveApple();
			this->MoveSnake();

			this->Print();

			Sleep(1000 * 1 / this->fps_);
			system("cls");
		}
	}
	void Print() {
		this->Push(apple_.GetPoint());

		std::list<Point> bodySnake = snake_.GetPoints();
		for (auto c : bodySnake)
			this->Push(c);

		this->printer_.Print();
	}
};

int main()
{
	Field field(20, 80);
	
	//printer.Push(apple.ToString(), 2, 5);
	//printer.Push(apple.ToString(), 3, 10);

	field.Play();

	return 0;
}