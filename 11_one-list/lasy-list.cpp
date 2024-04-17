#include <iostream>

struct Node {
	int val;
	Node* next;
};

class List {
	enum { EMPTY = -1 };
#if 0
	Node* top_;
#else
	Node* top_ = nullptr;
#endif
public:
	List() {}
	void operator>> (std::ostream& out);
	bool IsEmpty();
	int GetSize();
	void PushFront(int val);
	void PushBack(int val);
	int Extract();
	int Search(int val);
	void Remove(int val);
	void Insert(int pos, int val);
	List(std::initializer_list<int> list);
	void Clear();
	~List();
};




void Demo() {
	using namespace std;
	List list;
	list.PushFront(8);
	list.PushFront(2);
	list.PushFront(5);
	cout <<"size: "<< list.GetSize() << endl; // 3
	list >> cout; // 5 2 8

	list.PushBack(4);
	list.Insert(2, 10);
	list >> cout;
	cout << "2 on "<< list.Search(2) + 1 << " position" << endl;
	list.Remove(2);
	cout << "Removed 2\n";
	list >> cout;

	List list2({5, 6, 7});
	list2 >> cout;
}



void Test(){
	List list;
#if 0
	list.PushBack(111);
	list >> std::cout;
#endif
}

int main()
{
#if 0
	Test();
#else
	Demo();
#endif
}

#if 0
void List::operator>> (std::ostream& out) {
	out << "list: ";

	Node* temp = top_;
	while (temp != nullptr) {
		out << temp->val << " ";
		temp = temp->next;
	}
	out << std::endl;
}
bool List::IsEmpty() {
	return top_ == nullptr; 
}
int List::GetSize() {
	int k = 0;
	Node* temp = top_;
	while (temp != nullptr) {
		temp = temp->next;
		k++;
	}
	return k;
}
void List::PushFront(int val) {
	Node* temp = new Node { val, nullptr };

	temp->next = top_;

	top_ = temp;
}
void List::PushBack(int val) {
	Node* temp = new Node{ val, nullptr };

	if ( IsEmpty() ){
		top_ = temp;
		return;
	}
	Node* current = top_;
	while (current->next != nullptr){
		current = current->next;
	}
	current->next = temp;
}
List::List(std::initializer_list<int> list) {
	
}

int List::Extract() {
	if ( IsEmpty() ) 
		throw "Nothing to remove";
	
	if (top_->next == nullptr) {
		int val = top_->val;

		delete top_;
		top_ = nullptr;

		return val;
	}

	Node* current = top_;
	Node* prev = 0;
	while (current->next != nullptr){
		prev = current;
		current = current->next;
	}
	int val = current->val;

	delete current;
	prev->next = nullptr;

	return val;
}
int List::Search(int val) {
	int k = 0;
	Node* temp = top_;
	while (temp != nullptr) {
		if (temp->val == val)
			return k;
		temp = temp->next;
		k++;
	}
	return EMPTY;
}
void List::Remove(int val) {
	int ind = Search(val);
	if (ind == EMPTY) 
		return;
		
	if (ind == 0) {
		Node* next = top_->next;
		delete top_;
		top_ = next;
		return;
	}

	Node* temp = top_;
	Node* prev = 0;
	for (int i = 0; i < ind; i++){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
}
void List::Insert(int pos, int val) {
	if ( IsEmpty() || pos == 0){
		PushFront(val);
		return;
	}
	Node* temp = new Node{ val, nullptr };

	Node* current = top_;
	Node* prev = 0;
	for (int i = 0; i < pos 
			&& current != nullptr; i++){
		prev = current;
		current = current->next;
	}
	prev->next = temp;
	temp->next = current;
}
#endif