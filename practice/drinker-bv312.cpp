#include <iostream>
#include <initializer_list>
#include <list>
#include <random>
#include <time.h>
#include <algorithm>

/*
Игра в пьяницу

В игре в пьяницу карточная колода раздается поровну двум игрокам. Далее они вскрывают по одной верхней карте, и тот, чья карта старше, забирает себе обе, затем они кладутся под низ его колоды. Тот, кто остается без карт – проигрывает.

В колоде все карты одной масти, а самая младшая карта побеждает самую старшую карту ("шестерка берет туза"). 

Пусть в игре участвует `10` карт, имеющих значения от `0` до `9`.

Входные данные:
Программа получает на вход две строки: первая строка содержит 5 чисел, разделенных пробелами — номера карт первого игрока, вторая – аналогично 5 карт второго игрока. Карты перечислены сверху вниз, то есть каждая строка начинается с той карты, которая будет открыта первой.

Выходные данные:
Программа должна определить, кто выигрывает при данной раздаче, и вывести слово first или second, после чего вывести количество ходов, сделанных до выигрыша. Если на протяжении 106 ходов игра не заканчивается, программа должна вывести слово botva.

Примеры:

Входные данные:
1 3 5 7 9
2 4 6 8 0

Выходные данные:
second 5
*/

class Card{
    static size_t counter;
    static size_t max;
    
    size_t key_;
    char value_;
public:
    Card() = default;
    Card(char val) : value_(val), key_(counter++){
        max = key_;
    }
    char GetValue() {
        return value_;
    }
    bool operator < (Card& right) {
        return this->key_ < right.key_;
    }
};
size_t Card::counter = 0;
size_t Card::max = 0;

class Game {
    // std::list<Card> cards_;
    // size_t size_;
    std::list<Card> first_;
    std::list<Card> second_;
public:
    Game(std::list<Card> cards){
        Card* temp = new Card[cards.size()];
        CloneCards(temp, cards);
        
        srand(time(0));
        for (int i = 0; i < 50; i++) {
            std::swap(temp[rand()%cards.size()], temp[rand()%cards.size()]);
        }
        // for (int i = 0; i < cards.size(); i++) {
        //     cards_.push_back(temp[i]);
        // }
        for (int i = 0; i < cards.size(); i+=2) {
            first_.push_back(temp[i]);
            second_.push_back(temp[i+1]);
        }
    }
    void CloneCards(Card* dest, std::list<Card> src){
        size_t size = src.size();
        for (int i = 0; !src.empty(); i++) {
            dest[i] = src.front();
            src.pop_front();
        }
    }
    void Print() {
        using namespace std;
        cout << "first : ";
        for(Card c : this->first_)
            cout << c.GetValue() << " ";
        cout << endl;
        cout << "second: ";
        for(Card c : this->second_)
            cout << c.GetValue() << " ";
        cout << endl;
    }
};

int main()
{
	using namespace std;
	std::list<Card> cards;
	for (int i = 0; i < 5; i++) {
	    cards.push_back( Card('5'+i) );
	}
	cards.push_back('A');
	cards.push_back('B');
	cards.push_back('Q');
	cards.push_back('K');
	cards.push_back('T');
	
    Game drinker(cards);
    drinker.Print();

	return 0;
}