
class Array {
	int* arr_;
	int size_;
public:
	int* getArr() {
		return arr_;
	}

	int& operator[] (int id) {
		if (id >= size_) {
			throw "out of range";
			throw std::out_of_range{"too big index"};
		}
	}

}


int main() {
	Array a(10);

	// a.size_ = 15;
	a.resize(15);


	cout << a[14];

}