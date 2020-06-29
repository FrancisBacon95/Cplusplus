#include <iostream>
using namespace std;
//////////////////////////////////
/////// Student & Employee ///////
//////////////////////////////////
class Student {
public:
    int data;
    Student(int num) : data(num) {}
    Student() {};
    ~Student() { cout << "Destructor of Student" << endl; };
};

class Employee {
public:
    int data;
    Employee(int num) : data(num) {}
    Employee() {}
    ~Employee() { cout << "Destructor of Employee" << endl; };
};
///////////////////////
//////// Stack ////////
///////////////////////
template <class T>
class Stack {
    T* data[20];
    int nElements;
public:
    Stack() : nElements(0) {}
    ~Stack() { cout << "Destructor of Stack" << endl; };
    void Push(T* elem);
    T* Pop();
    int Number();
    int Empty();
    void Display();
    int Display_nElements() { return nElements; };
};

template <class T>
void Stack<T>::Push(T* elem) {
    if (nElements == 20)
        throw StackFull();
    else {
        data[nElements] = elem;
        nElements++;
    }
}

template <class T>
T* Stack<T>::Pop() {
    if (Empty())
        throw StackEmpty();
    else {
        nElements--;
        return data[nElements];
    }
}

template <class T>
int Stack<T>::Number() {
    return nElements;
}

template <class T>
int Stack<T>::Empty() {
    return (nElements == 0);
}

template <class T>
void Stack<T>::Display() {
    for (int i = 0; i < nElements; i++) {
        cout << data[i] << endl;
    }
}
///////////////////////
//////// Error ////////
///////////////////////
class Error {
public:
    virtual void Print() = 0;
};
class StackFull : public Error {
public:
    void Print() {
        cout << "\nStack is Full\n" << endl;
    }
};
class StackEmpty : public Error {
public:
    void Print() {
        cout << "\nStack is empty\n" << endl;
    }
};
class Range : public Error {
public:
    void Print() {
        cout << "\nOut of Range\n" << endl;
    }
};
class Type :public Error {
public :
    void Print() {
        cout << "\nType Error\n" << endl;
    }
};

void main() {

    Stack<Student> StudentStack;
    Stack<Employee> EmployeeStack;
    int sno;
    int eno;
    while (1) {
        int select;
        cout << "1 : Add Student\n2 : Add Employee\n3 : Pop Student Stack\n4 : Pop Employee Stack\n5: quit\n\n";
        cin >> select;
        switch (select) {
        case 1:
            try {
                cout << "=== Enter the Student Object ===" << endl;
                cout << "Enter [[" << StudentStack.Display_nElements()+1 << "]] student object : INT type" << endl;
                cout << "(Please enter a number less than 10. Otherwise, an exception occurs.)" << endl;
                cin >> sno;
                if (sno > 10) throw Range();
                StudentStack.Push(new Student(sno));
            }
            catch (Error& er) {
                er.Print();
            }
            break;
        case 2:
            try {
                cout << "=== Enter the empl Object ===" << endl;
                cout << "Enter [[" << EmployeeStack.Display_nElements()+1 << "]] employee object : INT type" << endl;
                cout << "(Please enter a number less than 5. Otherwise, an exception occurs.)" << endl;
                cin >> eno;
                if (eno > 5) throw Range();
                EmployeeStack.Push(new Employee(eno));
            }
            catch (Error& er) {
                er.Print();
            }
            break;
        case 3:
            try {
                cout << "=== StudentStack ===" << endl;
                if (EmployeeStack.Empty()) throw StackEmpty();
                while (!EmployeeStack.Empty()) {
                    cout << ((Employee*)EmployeeStack.Pop())->data << endl;
                }
            }
            catch (Error& er) {
                er.Print();
            }
            break;
        case 4:
            try {
                cout << "=== EmployeeStack ===" << endl;
                if (EmployeeStack.Empty()) throw StackEmpty();
                while (!EmployeeStack.Empty()) {
                    cout << ((Employee*)EmployeeStack.Pop())->data << endl;
                }
            }
            catch (Error& er) {
                er.Print();
            }
            break;
        /*
        case 5:
            Student tmp_std = Student();
            Employee tmp_std = Employee();
            int tmp;
            try {
                cout << "=== Push Student Object To Employee Stack ===" << endl;
                cin >> tmp;
                tmp_std = Student(tmp);
                if()
            }
            catch () {

            }
        */
        default:
            exit(0);
            break;
        }
    }
    system("pause");
}