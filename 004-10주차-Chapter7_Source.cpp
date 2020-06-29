#include <string>
#include <iostream>
using namespace std;

class Person {
    string name;
    string address;

public:
    Person()
    {
        //string n, a;
        cout << "Person Name : "; cin >> name;
        //name = n;
        cout << endl;
        cout << "Person Address : "; cin >> address;
        //address = a;
    }
    // Person() : name(string()) {}
   // Person(string n) :name(n) {}
    Person(string n, string a) :
        name(n), address(a) {}

    string Name() {
        return name;
    }
    string Address() {
        return address;
    }
    friend ostream& operator <<(ostream& os, Person p)
    {
        os << "	Name : " << p.name;
        os << "	Address : " << p.address;
        return os;
    }

};

class Student : public Person
    //class Student : virtual public Person 
{
    int sID; //student ID
    string schoolName; //school Name
public:
    Student() :Person() {
        cout << "Student ID :";
        cin >> sID; cout << endl;
        cout << " School Name : ";
        cin >> schoolName;
    }
    int StudentID() { return sID; }
    string SchoolName() { return schoolName; }
    friend ostream& operator <<(ostream& os, Student s)
    {
        os << "	Name : " << s.Name() << endl;
        os << "	Address : " << s.Address() << endl;
        os << "	Student Number : " << s.sID << endl;
        os << "	School Name : " << s.schoolName << endl;
        return os;
    }
};

class Employee : protected Person
    //class Employee : virtual protected Person 
{
    int eID; //employee ID
    int eSallery; //employee Sallery
    string cName; // company Name
public:
    Employee() :Person() {
        cout << " Employee Number : ";
        cin >> eID; cout << endl;
        cout << " Employee Sallery : ";
        cin >> eSallery; cout << endl;
        cout << " Company Name : ";
        cin >> cName;
    }
    int EmployeeID() {
        return eID;
    }
    int EmployeeSallery() {
        return eID;
    }

    string CompanyName() {
        return cName;
    }

    friend ostream& operator <<(ostream& os, Employee e)
    {
        os << "	Name : " << e.Name() << endl;
        os << "	Address : " << e.Address() << endl;
        os << "	Employee Number : " << e.eID << endl;
        os << "	Employee Sallery : " << e.eSallery << endl;
        os << "	Company Name : " << e.cName << endl;
        return os;
    }

};

class GradStudent : protected Student
{
    int grades; //student grades
    string major; //student major
public:
    GradStudent()
    {
        cout << " Major : ";
        cin >> major; cout << endl;
        cout << " Grades : ";
        cin >> grades;
    }
    int Grade() { return grades; }
    string Major() { return major; }
    friend ostream& operator <<(ostream& os, GradStudent gs)
    {
        os << "	Name : " << gs.Name() << endl;
        os << "	Address : " << gs.Address() << endl;
        os << "	Student Number : " << gs.StudentID() << endl;
        os << "	Grade : " << gs.grades << endl;
        os << "	Major : " << gs.major << endl;
        return os;
    }

};

class studentWorker : public GradStudent, public Employee
{
    int sIncome; //student Income
    string jobtype; //student job type
public:
    studentWorker()
    {
        cout << " Student Income :";
        cin >> sIncome; cout << endl;
        cout << " Student Job Type :";
        cin >> jobtype;
    }
    friend ostream& operator <<(ostream& os, studentWorker sw)
    {
        os << "Student Information" << endl;
        os << "	Student's Name : " << sw.Student::Name() << endl;
        os << "	Student's Address : " << sw.Student::Address() << endl;
        os << "	Student Number : " << sw.StudentID() << endl;
        os << "	School Name : " << sw.SchoolName() << endl;
        os << "	Student's Major : " << sw.Major() << endl;
        os << "	Student's Grade : " << sw.Grade() << endl;
        os << "	Student's Income : " << sw.sIncome << endl;
        os << "	Student's job type : " << sw.jobtype << endl; cout << endl;
        os << "	Employee's Name : " << sw.Employee::Name() << endl;
        os << "	Employee's Address : " << sw.Employee::Address() << endl;
        os << "	Employee Number : " << sw.EmployeeID() << endl;
        os << "	Employee's Salary : " << sw.EmployeeSallery() << endl;
        os << "	Company Name : " << sw.CompanyName() << endl;
        return os;
    }

    // with virtual
//friend ostream& operator <<(ostream& os, studentWorker sw) {
//   
//    os << "Student Information" << endl;
//    os << "	Student's Name : " << sw.Name() << endl;
//    os << "	Student's Address : " << sw.Address() << endl;
//    os << "	Student Number : " << sw.StudentID() << endl;
//    os << "	School Name : " << sw.SchoolName() << endl;
//    os << "	Student's Major : " << sw.Major() << endl;
//    os << "	Student's Grade : " << sw.Grade() << endl;
//    os << "	Student's Income : " << sw.sIncome << endl;
//    os << "	Student's job type : " << sw.jobtype << endl; cout << endl;
//    os << "	Employee Number : " << sw.EmployeeID() << endl;
//    os << "	Employee's Salary : " << sw.EmployeeSallery() << endl;
//    os << "	Company Name : " << sw.CompanyName() << endl;
//    return os;
//}

};

int main()
{
    cout << "< Type information of student S >\n";
    Student S;
    cout << "\n< Type information of employee E >\n";
    Employee E;
    cout << "\n< Type information of gradStudent GS >\n";
    GradStudent GS;
    cout << "\n< Type information of studentWorker SW >\n";
    studentWorker SW;

    cout << "\nStudent S : \n" << S;
    cout << "\nEmployee E : \n" << E;
    cout << "\nGradStudent GS : \n" << GS;
    cout << "\nStudentWorker SW : \n" << SW;

    system("pause");
    return 0;
}