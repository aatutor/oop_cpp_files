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
	void PushFront(int val);
	void PushBack(int val);
	int Extract();
	int Search(int val, int ind=0);
	void Remove(int ind);
	void Insert(int val, int ind=0);
	// void Clear();
	// ~DEList();
};

int main()
{
	DEList list;
	list.PushBack(8);
	list.PushBack(2);
	list.PushBack(5);
	cout << "Size: " << list.GetSize() << endl; // 3
	list >> cout; // 8 2 5

	list.PushFront(5);
	list.Insert(10, 2);
	list >> cout; // 5 8 10 2 5

	int ind5 = list.Search(5);
	cout << "5 on " << ind5 << endl; // 5 on 0
	list.Remove(list.Search(5, ind5+1));
	list >> cout; // 5 8 10 2
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


void DEList::PushFront(int val) {
	Node* temp = new Node{ val };
	if (top_ != nullptr) {
		top_->prev = temp;
		temp->next = top_;
	}
	else {
		tail_ = temp;
	}
	top_ = temp;
}


void DEList::PushBack(int val) {
	Node* temp = new Node{ val };
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

	int val = tail_->value;
	if (top_ == tail_) {
		delete tail_;
		top_ = tail_ = nullptr;
	}
	else {
		tail_ = tail_->prev;
		delete tail_->next;
		tail_->next = nullptr;
	}
	return val;
}


int DEList::Search(int val, int ind/* = 0 */) {
	Node* temp = top_;			
	int k = 0;
	while (temp) {
		if (k >= ind && temp->value == val)
			return k;
		temp = temp->next;
		k++;
	}
	return -1;
}

void DEList::Remove(int ind) {
	if (ind < 0) 
		return;
		
	Node* temp = top_;
	for (int i = 0; i < ind 
			&& temp != nullptr; i++)
		temp = temp->next;

	if (temp->prev != nullptr) 
		(temp->prev)->next = temp->next;
	else
		top_ = temp->next;

	if (temp->next) 
		(temp->next)->prev = temp->prev;
	else
		tail_ = temp->prev;

	delete temp;
}


void DEList::Insert(int val, int ind/* = 0 */) {
	if ( IsEmpty() || ind == 0 ) {
		PushFront(val); 
		return;
	}

	Node* cur = top_;
	for (int i = 0; i < ind && cur != nullptr; i++)
		cur = cur->next;
	if (cur == nullptr) { PushBack(val); return; }

	Node* temp = new Node{ val };

	(cur->prev)->next = temp;//1
	temp->next = cur;  //2
		
	temp->prev = cur->prev;//3
	cur->prev = temp;   //4
}


// void DEList::Clear();
// DEList::~DEList() {
	// Clear();
// }
#endif
