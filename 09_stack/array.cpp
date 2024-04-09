
#if DINAMIC
class Array {
	int *arr_;
	int size_;
public:
	...
	void Resize(int size) {
		...
		delete[] arr_;
		arr_ = new int[size];
	}
}
#endif
#if CONST
class Array {
	const int SIZE_ = 10;
	int arr_[SIZE_];
	int realSize_;
	...
}
#endif
