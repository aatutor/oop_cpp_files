#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <time.h>
#include <string>
#include <list>

// int score = 0;

void KickByValue(int val, bool mod) 
{
	bool v = val == rand() % 3;
#if 1
	if (v == mod) {
		std::cout << "win";
		++score;
	}
	else {
		std::cout << "lose";
	}
#else
	if (v) {
		if (mod) {
			std::cout << "good block";
			++score;
		}
		else {
			std::cout << "you miss kick";
		}
	}
	else {
		if (mod) {
			std::cout << "you miss attack";
		}
		else {
			std::cout << "good kick";
			++score;
		}
	}
#endif
}
void TestByVal() 
{
	using namespace std;

	int x = -1;
	while (x != 0)
	{
#if 0
		// defend
		cin >> x;
		if (x == (rand() % 3)) {
			cout << "win";
			++score;
		}
		else {
			cout << "lose";
		}
		cout << endl;
		// atack
		cin >> x;
		if (x == (rand() % 3)) {
			cout << "lose";
		}
		else {
			cout << "win";
			++score;
		}
		cout << endl;
#else
		cin >> x;
		KickByValue(x, 1);
		cin >> x;
		KickByValue(x, 0);
#endif
	}
}

void DefendWin() {
	std::cout << "good block";
	++score;
}
void DefendLose(){
	std::cout << "you miss kick";
}
void AttackWin(){
	std::cout << "good kick";
	++score;
}
void AttackLose(){
	std::cout << "you miss attack";
}

void Kick(int val, void (*TrueRes) (), void (*FalseRes) ())
{
	if ( val == rand() % 3 ) {
		TrueRes();
	}
	else {
		FalseRes();
	}
}
void TestKick()
{
	using namespace std;

	int x = -1;
	while (x != 0)
	{
		cin >> x;
		Kick(x, DefendWin, DefendLose);
		cin >> x;
		Kick(x, AttackLose, AttackWin);
	}
}

int id1() {
	static int my_id = 0;
	return ++my_id;
}
class Iterator {
	int i_;
	int d_;
public:
	Iterator(int step = 1, int begin = 0)
		: i_(begin), d_(step) {}

	int operator() () {
		return i_ += d;
	}
}

void TestFtor() {
	using namespace std;
	list<string> names{
		"Ivan",
		"Artem",
		"Arseniy"
	};
	Iterator id, id5(5, -5);
	for (string name : names)
		cout << id5() << ". " << name << endl;
}

class Result{
	static int score_;
	std::function<bool(int)> pred_;

	virtual void Win() = 0;
	virtual void Lose() = 0;
public:
	Result(std::function<bool(int, int)> p): pred_(p) {}
	void operator() (int val) override {
		if (pred_(val, rand()%3)){
			++score_;
			Win();
		}
		else
			Lose();
	}
	static int GetScore() {
		return score_;
	}
};
int Result::score_ = 0;
class Def: public Result {
	Def(): Result(
		[](int val, int rnd) {
			return val == rnd;
		}
	) {}
	void Win() override {
		std::cout << "good block";
	}
	void Lose() override {
		std::cout << "you miss kick";
	}
} def;
class Att: public Result {
	Att(): Result(
		[](int val, int rnd) {
			return val != rnd;
		}
	) {}
	void Win() override {
		std::cout << "good kick";
	}
	void Lose() override {
		std::cout << "you miss attack";
	}
} att;

void TestKick()
{
	using namespace std;

	int x = -1;
	while (x != 0)
	{
		cin >> x;
		def(x);

		cin >> x;
		att(x);
	}
}


int main()
{
	using namespace std;
	srand(time(0));

	//TestByVal();
	TestKick();

	cout << score << endl;
}