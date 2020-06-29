
#include <iostream>
#include <stdlib.h>

using namespace std;

class Queue 
{

private:
	string obj[20];
	static	int count;
	int individualCount=0;
public:
	Queue() { count = 0; };
	void Push(string a);
	void Pop();
	void Number();
	friend istream& operator >>(istream& is, Queue& a);
	friend ostream& operator <<(ostream& os, Queue& a);
};

void Queue::Push(string a) 
{
	if (this->individualCount < 20) 
	{
		obj[this->individualCount] = a;
		count++;
		this->individualCount++;
	}
	else
		cout << "Queue is full" << endl;
}

void Queue::Pop() 
{
	for (int i = 0; i < 19; i++)
		obj[i] = obj[i+1];
	obj[19] = "";
	count--;
	this->individualCount--;
}
void Queue::Number()
{
	cout << count << endl;
}
istream& operator>>(istream& is, Queue& a) 
{
	for (int i = 0; i < 20; i++) 
	{
		is >> a.obj[i];
		a.count++;
		a.individualCount++;
	}
	return is;
}

ostream& operator<<(ostream& os, Queue& a) 
{
	for (int i = 0; i < 20; i++) 
		os << a.obj[i] << " ";
	cout << endl;
	return os;
}

int Queue::count = 0;

int main() 
{
	Queue q1;
	Queue q2;
	int input;
	string obj;
	cout << "input 20 numbers to queue 1" << endl;
	cin >> q1;
	cout << "input 20 numbers to queue 2" << endl;
	cin >> q2;
	while (1)
	{
		cout << "1. add number to queue 1 2. add number to queue 2 3. delete number from queue 1  4. delete number from queue 2  5. display both queues" << endl;
		cin >> input;
		switch(input)
		{
		case 1:
			cout << "number of all element is ";
			q1.Number();
			cin >> obj;
			q1.Push(obj);
			cout << "number of all element is ";
			q1.Number();
			break;
		case 2:
			cout << "number of all element is ";
			q2.Number();
			cin >> obj;
			q2.Push(obj);
			cout << "number of all element is ";
			q2.Number();
			break;
		case 3:
			cout << "number of all element is ";
			q1.Number();
			q1.Pop();
			cout << "number of all element is ";
			q1.Number();
			break;
		case 4:
			cout << "number of all element is";
			q2.Number();
			q2.Pop();
			cout << "number of all element is";
			q2.Number();
			break;
		case 5:
			cout << q1;
			cout << q2;
			break;
		}
	}
	return 0;
}