//1. ���� ���� : 7, 8��
//
//2. ���� ��� : plato �� �Խ��ǿ� ���� �޴��� ����(���� ���ε�)
//
//3. 14 : 45�п� �ڵ� �����Ǹ� ���� ���� �ȵ�
//
//(5��, 6���� ��� �������� ��ȯ��)


/* 059�й�
���� 486 ���� 8.5
���� ������ ��� �����ϵ��� coding �ϼ��Ѵ�.
1. Set�� Animal ��ü�� Add(), Delete()�Ѵ�
1. ���� �ǽ��ڵ�, github, ���� �� ��� �ҽ� �ڵ� �̿� ������
2. �Ʒ� ���õ� �ڵ� ����� �ƴϸ� 0�� ó��
3. ���� �л��� ������ �ҽ��ڵ忡 ���� ǥ�� �˻�� plato � ���� ����
4. 3,4�г��� �븮 ���� ġ���� ��쿡 ���߽� Ȩ������ ���� �� ���к��ο� ¡�� ��û
   (���� �� �ڵ� ���� ����� �ϰ��� �˻�� �ǽ��л� ��ȯ�Ͽ� ��� �˻� ������)
*/
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include <vector>

using namespace std;
#define DefaultSize 20

class Point {
public:
    Point(int xp = 0, int yp = 0) : xPos(xp), yPos(yp)
    {}
    int x() { return xPos; }
    int y() { return yPos; }
    void x(int px) { xPos = px; }
    void y(int py) { yPos = py; }
    void operator += (Point p) {
        xPos += p.xPos;
        yPos += p.yPos;
    }
    void operator *= (Point p) {
        xPos *= p.xPos;
        yPos *= p.yPos;
    }

    void operator -= (Point p) {
        xPos -= p.xPos;
        yPos -= p.yPos;
    }

    bool operator != (Point p) {
        if (xPos != p.xPos && yPos != p.yPos)
            return true;
        else return false;

    }

    bool operator == (Point p) {
        if (xPos == p.xPos && yPos == p.yPos)
            return true;
        else return false;

    }

    Point& operator =(const Point& p) {
        xPos = p.xPos;
        yPos = p.yPos;
        return *this;
    }
private:
    int xPos, yPos;
};

class Animal {
public:
    Animal(Point p = Point());
    virtual void Speak() {
        std::cout << "Animal Speaking " << endl;
    }
    void JumpBy(int x, int y);
    void MoveTo(Point newPosition);

    bool operator != (Animal x) {
        if (position != x.position)
            return true;
        else return false;

    }
    bool operator == (Animal x) {
        if (position == x.position)
            return true;
        else return false;

    }
    Point& operator =(const Animal& a) {
        position = a.position;
        return position;
    }
    friend ostream& operator<< (ostream& stream, Animal& p);

protected:
    Point position;
    void MoveOutput();
};

ostream& operator<< (ostream& stream, Animal& p)
{
    p.Speak();
    return stream;
}
Animal::Animal(Point p) : position(p)
{}

void Animal::JumpBy(int x, int y) {
    position += Point(x, y);
}
void Animal::MoveTo(Point newPosition) {
    position = newPosition;
}

void Animal::MoveOutput() {
    std::cout << "Animal::\tposition.x() = " << position.x() << ", position.y() = " << position.y() << endl;
}
class Cattle : public Animal {
public:
    Cattle(Point p = Point(10, 10));
    void Speak() {
        JumpBy(9, 9);
        MoveOutput();
        std::cout << "Cattle Speaking" << endl;
    }
    void JumpBy(int x, int y) { position -= Point(x, y); }//x1 = x1 - x, y1 = y1 - y
};

Cattle::Cattle(Point p) :Animal(p)
{
}

class Cow : public Cattle {
public:
    Cow(Point p = Point(101, 101));
    void Speak() {
        JumpBy(9, 9);
        MoveOutput();
        std::cout << "Cow Speaking" << endl;
    }
    void JumpBy(int x, int y) { position *= Point(x, y); }//x1 = x1 * x, y1 = y1 * y
};
class Bull : public Cattle {
public:
    Bull(Point p = Point(106, 106));
    void Speak() {
        JumpBy(9, 9);
        MoveOutput();
        cout << "Bull Speaking" << endl;
    }
    void JumpBy(int x, int y) { position -= Point(x, y); }
};

Bull::Bull(Point p) :Cattle(p)
{
}

class Cat : public Animal {//have to use protected inheritance
public:
    Cat(Point p = Point(5, 5)) :Animal(p)
    {

    }
    Cat(char*) {}
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        std::cout << "Cat Speaking " << endl;
    }
    void JumpBy(int x, int y) { position *= Point(x, y); }
};
class Dog : public Animal {//have to use protected inheritance
public:
    Dog(Point p = Point(20, 20)) : Animal(p)
    {

    }
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        std::cout << "Dog Speaking " << endl;
    }
    void JumpBy(int x, int y) { position += Point(x, y); }
};
class Horse : public Animal {//have to use protected inheritance
public:
    Horse(Point p = Point(30, 30)) :Animal(p)
    {

    }
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        std::cout << "Horse Speaking " << endl;
    }
    void JumpBy(int x, int y) { position += Point(x, y); }
};
class Chicken : public Animal {//have to use protected inheritance
public:
    Chicken(Point p = Point(40, 40)) : Animal(p)
    {

    }
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        std::cout << "Chicken Speaking " << endl;
    }
    void JumpBy(int x, int y) { position += Point(x, y); }
};
Cow::Cow(Point p) : Cattle(p)
{}



class Bag {
public:
    virtual ~Bag();
    virtual void Add(Animal);
    virtual Animal* Delete(Animal&);
    bool IsFull();
    bool IsEmpty();
    void Full();
    void Empty();
    bool IsDuplicate(Animal& x);//check whether or not there is the same value in the Bag
    int Top();
    friend ostream& operator<< (ostream& stream, Bag* b);
    Animal* collection;
    int MaxSize;
protected:
    Bag(int MaxSize = DefaultSize);
    int top;
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);//to be implemented
    ~Set();//to be implemented
    void Add(Animal);//to be implemented
    Animal* Delete(Animal&);//to be implemented
    friend ostream& operator<< (ostream& stream, Set* s);//to be implemented
};

Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
    collection = new Animal[MaxSize];
    top = 0;
}

Bag::~Bag() {
}

bool Bag::IsFull() {
    if (top == MaxSize - 1)
        return true;
    else
        return false;
}

bool Bag::IsEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}

void Bag::Full() {
    std::cout << "Data structure is full" << endl;
}

void Bag::Empty() {
    std::cout << "Data structure is empty" << endl;
}

void Bag::Add(Animal x) {
    if (IsFull())
        Full();
    else {
        collection[top] = x;
        std::cout << "BAG " << collection[top] << "has been added" << endl;
        top++;
    }
}

bool Bag::IsDuplicate(Animal& x)
{
    for (int i = 0; i < MaxSize; i++) {
        if (collection[i] == x) {

            return true;
        }
    }
    return false;

}

Animal* Bag::Delete(Animal& x) {
    if (IsEmpty()) {
        Empty();
        return 0;
    }
    //������ �����Ͽ� ���� ���Ҹ� �����Ѵ� //Generate random numbers to delete random elements
    int temp = top / 2;
    x = collection[temp];
    for (int i = temp; i < top; i++)
    {
        collection[i] = collection[i + 1];
    }
    top--;
    return &x;
}

int Bag::Top() {
    return top;
}

ostream& operator<<(ostream& stream, Bag* b) {
    std::cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
    for (int i = 0; i < b->Top(); i++) {
        stream << b->collection[i] << endl;
    }
    return stream;
}

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(Animal x) {//to be modified for both no ordering and no duplicate
    if (IsFull())
        Full();
    else {
        if (!Bag::IsDuplicate(x))
        {
            Bag::Add(x);//�ݵ�� ���Ǿ�� �� - Must be used
            cout << "SET " << collection[top] << "has been added" << endl;
            top++;
            return;
        }
        else {
            cout << "Duplicate value." << endl;
            return;
        }
    }
}


Animal* Set::Delete(Animal& x) {//to be modified for both no ordering and no duplicate
    if (IsEmpty()) {
        Empty();
        return 0;
    }
    Bag::Delete(x);//�ݵ�� ���Ǿ�� ��
    return &x;
}

ostream& operator<<(ostream& stream, Set* s) {
    cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
    Bag* b = (Bag*)s;
    stream << b;//�ݵ�� ���Ǿ�� ��
    return stream;
}
void RunSpeaking(Animal& data, int steps)
{
    data.Speak();
}



#define MaxSet 20;
int main() {
    int select;
    Bag* ax = new Set;
    Set* pSet = dynamic_cast<Set*>(ax);//down casting
    Animal* mixedObject[20];
    Animal t;
    while (1)
    {
        cout << "\nSelect command  1. Make Animal, 2: Add Animal, 3: Delete Animal, 4. Display all, 5. Run Speak, 6. Quit = > ";
        cin >> select;
        switch (select) {
        case 1://1. Make Animal
            cout << "Add a new Animal" << endl;

            mixedObject[0] = new Cow;
            mixedObject[1] = new Cat;
            mixedObject[2] = new Dog;
            mixedObject[3] = new Horse;//implement class Horse
            mixedObject[4] = new Chicken;////implement class Chicken
            mixedObject[5] = new Cattle;
            mixedObject[6] = new Cat;
            mixedObject[7] = new Dog;
            mixedObject[8] = new Horse;//implement class Horse
            mixedObject[9] = new Chicken;////implement class Chicken
            mixedObject[10] = new Animal;
            mixedObject[11] = new Bull;
            break;

        case 2:// 2: Add Animal to Set
            for (int i = 0; i < 11; i++)
                if (!mixedObject[i])
                    break;
                else
                    ax->Add(*mixedObject[i]);
            break;
        case 3: //3 : Delete Animal from Set
            while (!ax->IsEmpty())
            {
                t = *ax->Delete(t);
                cout << " The deleted animal is ";
                RunSpeaking(t, 1);
                cout << t;
            }
            break;
        case 4://4. Display all

            cout << "4. Display:: ";
            cout << pSet << endl;
            break;
        case 5://5. Run Speak
            for (int i = 0; i < ax->MaxSize; i++)
                if (i == 10)
                    break;
                else
                    RunSpeaking(*mixedObject[i], i);
            break;


        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 0;
}