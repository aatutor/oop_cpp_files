
struct Point {
	int x_;
	int y_;
	void Print('Point *this'){
		printf("(%d,%d)\n", this->x_, this->y_);
	}
};

int main() {
	Point p{'x_ =' 6, 'y_ =' 8};
	p.Print('&p');
}