// more examples: https://www.geeksforgeeks.org/vector-in-cpp-stl/

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void ShowVector(vector<int> vect) {
	cout << "\nvector ["<< vect.size() <<"] -->\t";
	for (int& elem : vect) {
		cout << elem << "\t";
	}
	cout << "\n-----------------------------------\n";
}

int main()
{
	//Создаем вектор
	vector<int> vect;
	vector<int> v5(5, 7);

	for(int i = 5; i != 0; --i)
		vect.push_back(i);	

	cout << "Size : " << vect.size();
	cout << "\nCapacity : " << vect.capacity();
	cout << "\nMax_Size : " << vect.max_size();
	ShowVector(vect);
 
	cout << "\nPush in back 0:";
	vect.push_back(0); 	//вставляем нуль
						//в конец вектора
	ShowVector(vect);

	cout << "\nResize to 3 (after to 6):";
	vect.resize(3); 	//изменяем размер	
	ShowVector(vect);

	vect.resize(6, 1); 	//изменяем размер, новые 
												//элементы заполнятся 1
	cout << "set first and last to 10:";
	vect.front() = 10;
	vect.back() = 10;
	// vect[vect.size()-1] = 10;
	ShowVector(vect);

	cout << "\nErase: [0], [3-4]";
	vector<int>::iterator it_2 = vect.begin()+2;
	vect.erase(vect.begin()); //удаляем первый элемент
	vect.erase(it_2, it_2 + 2);
	ShowVector(vect);

	cout << "\nInsert -5 x 2:";
	vect.insert(vect.begin(), 2, -5); //вставка двух значений
	ShowVector(vect);
	
	cout << "\nInsert ranges:";
	vect.insert(it_2, v5.begin(), v5.begin()+2);
	vect.insert(vect.end(), {9, 8});
	ShowVector(vect);

	return 0;
}