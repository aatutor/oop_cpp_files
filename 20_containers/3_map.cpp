// more examples: https://www.geeksforgeeks.org/lior-in-cpp-stl/

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

template <class A, class B>
void ShowMap(map<A, B> dict)
{
	cout << "\nmap ["<< dict.size() <<"] -->\t| ";
	for (const pair<A, B>& elem : dict)
		cout << elem.first <<": "<< elem.second <<"\t| ";	
	cout << "\n-----------------------------------\n";
}

int main() {
	{
		cout << "Dictionary:";
		map<char, int> dict;
		dict['a'] = 1;
		dict['b'] = 2;

		ShowMap(dict);
	}
	{
		cout << "\nInit:";
		map<char, int> dict{ {'c', 3},{'d', 5} };
		// map<char, int> dict{ pair<char, int>{'c', 3}, pair<char, int>{'d', 5} };
		ShowMap(dict);

		cout << "\nInsert:";
		dict.insert({'g', 10});
		dict.insert(pair<char, int>{'b', 20});
		ShowMap(dict);

		cout << "\nFind 'e':" << (dict.find('e'))->second << endl;
	}
	{
		cout << "\nDouble and string:";
		map<double, string> dict;
		dict[3.14] = "pi";
		dict[2.72] = "exp";

		ShowMap(dict);
	}

	return 0;
}