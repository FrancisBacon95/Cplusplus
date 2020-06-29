#include <iostream>
#include <string.h>
using namespace std;
//////////////////
////// Bag //////
/////////////////
template <class T>
class Bag {
protected:
	int size_bag;
	T* data;
	int top=0;
	
public:
	Bag(int s = 2) :size_bag(s) { data = new T[size_bag];};
	~Bag() {};
	bool IsEmpty();
	bool IsFull();
	virtual void Delete();
	virtual void Add(T x);
	int Top() { return top; };
	void Display();
};
template <class T>
bool Bag<T>::IsEmpty() {
	if (top == 0) {
		return true;
	}
	else return false;
}
template <class T>
bool Bag<T>::IsFull() {
	if (top < (size_bag)) {
		return false;
	}
	else return true;
}
template <class T>
void Bag<T>::Add(T x) {
	if(!IsFull()){
		data[top] = x;
		top++;
	}
	else { cout << "This Queue is Full" << endl; }
}
template <class T>
void Bag<T>::Delete() {
	if (IsEmpty()) { cout << "This Bag is Empty" << endl; return; }
	int deletePos = top / 2;
	cout << "Bag에서 삭제될 원소 : " << data[deletePos]<<endl;
	for (int idx = deletePos; idx < top; idx++) {
		data[idx] = data[idx + 1];
	}
	top--;
}
template <class T>
void Bag<T>::Display() {
	for (int i = 0; i < top; i++) {
		cout << data[i] << endl;
	}
}

//////////////////
///// Queue //////
/////////////////
template <class T>
class Queue : public Bag<T> {
public:
	Queue(int s = 2) :Bag(s) { counter++;};
	~Queue() { counter--; };
	void Delete();
	friend void show_counter(Queue<T> &);
private:
	static int counter;
};

template <class T>
void Queue<T>::Delete() {
	if (IsEmpty()) { cout << "This Queue is Empty" << endl; return; }
	cout << "Que에서 삭제될 원소 : " << data[0]<<endl;
	for (int i = 0; i < top - 1; i++) {
		data[i] = data[i + 1];
	}
	top--;
}

///////////////////////////
///// Person & Animal /////
///////////////////////////
class Person {
private:
	string* name=new string;
public:
	Person(string n="Unknown Person") { *name = n;};
	~Person() {};
	string Name() { return *name; };
};
class Animal {
private:
	string *name=new string;
public:
	Animal(string n = "Unknown Animal") { *name = n; };
	~Animal() {};
	string Name() { return *name; };
};
ostream& operator <<(ostream& s, Person p) {
	s << "This Person's Name : "<<p.Name();
	return s;
}
ostream& operator <<(ostream& s, Animal p) {
	s << "This Animal's Name : " << p.Name();
	return s;
}
////////////////////////////////////
// bound template friend func. ////
///////////////////////////////////
template <class T>
int Queue<T>::counter = 0;

void show_counter(Queue<Person>&q) {
	cout << "Person counter : " << Queue<Person>::counter << endl;
}

void show_counter(Queue<Animal>& q) {
	cout << "Animal counter : " << Queue<Animal>::counter << endl;
}

int main() {
	int* size = new int;
	Queue<Person>* queue1 = new Queue<Person>;
	string* f1 = new string;
	Person* person = new Person;

	Queue<Animal>* queue2 = new Queue<Animal>;
	string* f2 = new string;
	Animal* animal = new Animal;
	while (1) {
		int select;
		cout << "\nSelect\n1 : Create Queue\n2 : Add() to Queue\n3 : Delete() to Queue\n4 : Display Queue\n5 : quit\n\n";
		cin >> select;
		switch (select)
		{
		case 1: {
			cout << "Two queues were created." << "( Default로 2개의 Queue가 생성됩니다. )" << endl;
			cout << "The First is Queue about the [Person]." <<"( 첫 번째 Queue는 [Person]에 대한 것입니다. )"<<endl;
			cout << "The Second is Queue about the [Animal]." << endl << "( 두 번째 Queue는 [Animal]에 대한 것입니다. )" << endl<<endl;
			cout << "Enter the size of the Queue (the same applies to all Queues)." <<endl<<"( Queue의 size를 입력하세요.(모든 Queue에 동일하게 적용됩니다.). )" << endl;
			cin >> *size;
			cout << endl;
			*queue1 = Queue<Person>(*size);
			*queue2 = Queue<Animal>(*size);

			cout << "Number of Queue" << endl;
			show_counter(*queue1);
			show_counter(*queue2);
			break;
		};

		case 2: {

			cout << "The First is Queue about the [Person]." << "( 첫번째 Queue는 [Person]에 대한 것입니다. )" << endl;
			cout << "The Second is Queue about the [Animal]." << endl << "( 첫번째 Queue는 [Animal]에 대한 것입니다. )" << endl << endl;

			cout << "First : about [Person]" << endl;
			if ((*queue1).IsFull()) { cout << "All Queues are FULL!!"; break; }
			int plus = *size - (*queue1).Top();
			cout <<endl<< "Enter [[" << plus << "]] elements." << endl<<endl;
			for (int i = 0; i < plus; i++) {
				cout << i + 1 << "번째 원소의 이름 입력" << endl << "Name : ";
				cin >> *f1;
				*person = Person(*f1);
				(*queue1).Add(*person);
			}
			cout << endl;

			cout << "Second : about [Animal]" << endl;
			cout << "Enter " << plus << " elements." << endl;
			for (int i = 0; i < plus; i++) {
				cout << i + 1 << "번째 원소의 이름 입력" << endl << "Name : ";
				cin >> *f2;
				*animal = Animal(*f2);
				(*queue2).Add(*animal);
			}
			break; };
		case 3: {
			cout << "Delete one element from each Queue (First In First Out)" << endl;
			cout << "각각의 Queue에서 원소를 하나씩 삭제합니다.(선입선출)" << endl;
			(*queue1).Delete();
			(*queue2).Delete();
			break; };
		case 4: {
			cout << "First : Display [Person] Queue" << endl;
			(*queue1).Display();
			cout <<endl<< "Second : Display [Animal] Queue" << endl;
			(*queue2).Display();

			cout << "Number of Queue" << endl;
			show_counter(*queue1);
			show_counter(*queue2);
			break; };
		default:
			exit(0);
			break;
		}
	}

	system("pause");
	return 0;
}

