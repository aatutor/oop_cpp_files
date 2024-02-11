// functional-style
int main()
{
	int* arr = new int[6]{1, 2, 2, 5, 3, 1};
	Sort(arr, 6);
	Print(arr, 6);
	cout <<"summ: "<< Sum(arr, 6) << endl;
	return 0;
}

// oop-style
int main()
{
	Arr arr{1, 2, 2, 5, 3, 1};
	arr.Sort();
	arr.Print();
	cout <<"summ: "<< arr.Sum() << endl;
	return 0;
}