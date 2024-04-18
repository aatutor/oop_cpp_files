#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class DEList {
	Node* top_ = nullptr;
	Node* tail_ = nullptr;
public:
	DEList() {}
	void operator>> (std::ostream& out);
	bool IsEmpty();
	int GetSize();
	void PushFront(int value);
	void PushBack(int value);
	int Extract();
	int Search(int value);
	void Remove(int value);
	void Insert(int index, int value);
	void Clear();
	~DEList();
};

int main()
{
	DEList list;
	list.PushBack(8);
	list.PushBack(2);
	list.PushBack(5);
	cout << "Size: " << list.GetSize() << endl; // 3
	list >> cout; // 8 2 5

	list.PushFront(4);
	list.Insert(2, 10);
	list >> cout; // 4 8 10 2 5

	cout << "5 on " << list.Search(5) << endl; // 5 on 3
	list.Remove(3);
	list >> cout; // 4 8 10 5
}

#if 1
	void DEList::operator>> (std::ostream& out) {
		out << "list: ";
		Node* temp = top_;
		while (temp) {
			out << temp->value << " ";
			temp = temp->next;
		}
		out << endl;
	}
	bool DEList::IsEmpty() { 
		return top_ == nullptr; 
	}
	int DEList::GetSize() {
		int k = 0;
		Node* temp = top_;
		while (temp) {
			temp = temp->next;
			k++;
		}
		return k;
	}
	void DEList::PushFront(int value) {
		Node* temp = new Node{ value };
		if (top_ != nullptr) {
			top_->prev = temp;
			temp->next = top_;
		}
		else {
			tail_ = temp;
		}
		top_ = temp;
	}
	void DEList::PushBack(int value) {
		Node* temp = new Node{ value };
		if (tail_ != nullptr) {
			tail_->next = temp;
			temp->prev = tail_;
		}
		else {
			top_ = temp;
		}
		tail_ = temp;
	}
	int DEList::Extract() {
		if (tail_ == nullptr)
			throw "List is empty";

		int value = tail_->value;
		if (top_ == tail_) {
			delete tail_;
			top_ = tail_ = nullptr;
		}
		else {
			tail_ = tail_->prev;
			delete tail_->next;
			tail_->next = nullptr;
		}
		return value;
	}
	int DEList::Search(int value) {
		Node* temp = top_;
		int k = 0;
		while (temp) {
			if (temp->value == value)
				return k;
			temp = temp->next;
			k++;
		}
		return -1;
	}
	void DEList::Remove(int value) {
		int ind = Search(value);
		if (ind == -1) 
			return;
			
		Node* temp = top_;
		for (int i = 0; i < ind; i++)
			temp = temp->next;

		if (temp->prev) 
			(temp->prev)->next = temp->next;
		else
			top_ = temp->next;

		if (temp->next) 
			(temp->next)->prev = temp->prev;
		else
			tail_ = temp->prev;

		delete temp;
	}
	void DEList::Insert(int index, int value) {
		if ( IsEmpty() || index == 0 ) { 
			PushFront(value); 
			return;
		}

		Node* current = top_;
		for (int i = 0; i < index && current != nullptr; i++)
			current = current->next;
		if (current == nullptr) { PushBack(value); return; }

		Node* temp = new Node{ value };

		(current->prev)->next = temp;//1
		temp->next = current;  //2
			
		temp->prev = current->prev;//3
		current->prev = temp;   //4
	}
	// void DEList::Clear();
	DEList::~DEList() {
		// Clear();
	}
#endif