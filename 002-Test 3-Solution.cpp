#include<iostream>
using namespace std;

class Complex
{
public:
    float real;
    float imag;
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(float re, float im)
    {
        real = re;
        imag = im;
    }

    Complex(const Complex& cx);

    float Re()
    {
        return real;
    }

    float Im()
    {
        return imag;
    }
    ~Complex();
    Complex operator + (const Complex& cx);
    Complex operator * (const Complex& cx);
    Complex& operator = (const Complex& cx);

    operator float();//복소수의 크기, magnitude를 return하는 연산자 || Operator to return the size and magnitude of a complex number
    friend istream& operator >> (istream& s, Complex& cx);
    friend ostream& operator << (ostream& s, Complex cx);
};
Complex::operator float()
{
    return abs(sqrt(real * real + imag * imag));
}

Complex::~Complex() {

}

istream& operator >> (istream& s, Complex& cx)
{
    cout << "real: "; s >> cx.real;
    cout << "imag: "; s >> cx.imag;

    return s;
}

ostream& operator << (ostream& s, Complex cx)
{
    s << cx.real << " + " << cx.imag << "i";
    return s;
}

Complex& Complex::operator = (const Complex& cx)
{
    real = cx.real;
    imag = cx.imag;
    return *this;
}

Complex Complex::operator + (const Complex& cx)
{
    Complex add(0, 0);
    add.real = this->real + cx.real;
    add.imag = this->imag + cx.imag;
    return add;
}

Complex Complex::operator * (const Complex& cx)
{
    Complex mul(0, 0);
    mul.real = this->real * cx.real;
    mul.imag = this->imag * cx.imag;
    return mul;
}

Complex::Complex(const Complex& cx)
{
    real = cx.real;
    imag = cx.imag;
}


class ComplexNumberSeries
{

public:
    ComplexNumberSeries();
    ~ComplexNumberSeries();
    Complex& SumComplex();   // Complex& operator + (const Complex&); 이용하여 구현 || implementation using  Complex& operator + (const Complex&); 
    Complex& MultiplyComplex();   // Complex& operator * (const Complex&); 이용하여 구현 || Implementation using  Complex& operator * (const Complex&); 
    Complex& Delete();
    friend istream& operator >> (istream& s, ComplexNumberSeries& cxn);//reuse: friend istream& operator >> (istream& s, Complex& c);
    friend ostream& operator << (ostream& s, ComplexNumberSeries& cxn);//reuse: friend ostream& operator << (ostream& s, Complex c);
private:
    static int top;//Term의 갯수를 기록 || Record the number of terms
    Complex* Term;
};
int ComplexNumberSeries::top = 0;

ComplexNumberSeries::ComplexNumberSeries()
{
    Term = new Complex(0, 0);
}

ComplexNumberSeries::~ComplexNumberSeries()
{
    delete Term;
}
istream& operator >> (istream& s, ComplexNumberSeries& cxn)
{
    s >> *(cxn.Term + cxn.top);
    cxn.top++;
    return s;
}

ostream& operator << (ostream& s, ComplexNumberSeries& cxn)
{
    for (int i = 0; i < cxn.top; i++)
    {
        s << i + 1 << " complex digits are : " << *(cxn.Term + i) << endl;
    }
    return s;
}

Complex& ComplexNumberSeries::SumComplex()
{
    Complex csum;
    for (int i = 0; i < top; i++)
    {
        csum = csum + (*(Term + i));
    }
    return csum;
}

Complex& ComplexNumberSeries::MultiplyComplex()
{
    Complex cmul;
    cmul.real = 1;
    cmul.imag = 1;
    for (int i = 0; i < top; i++)
    {
        cmul = cmul * (*(Term + i));
    }
    return cmul;
}

Complex& ComplexNumberSeries::Delete()
{
    Complex delDATA = *(Term);
    for (int i = 1; i < top; i++)
    {
        *(Term + i - 1) = *(Term + i);
    }
    top--;
    cout << delDATA << "  deleted from ComplexNumberSeries" << endl;
    return delDATA;
}

Complex PrintComplex(Complex c)
{
    return c;
}

int main() {
    int select;
    ComplexNumberSeries* ax = new ComplexNumberSeries;
    Complex t, cx;
    float magnitude;
    while (1)
    {

        cout << "\nSelect command 1: Add Complex number, 2: Delete first Complex number, 3. Display all,4. Sum, 5. Multiply, 6.Quit = > ";
        cin >> select;
        switch (select) {
        case 1:
            cout << "Add a new Complex number" << endl;
            cin >> (*ax);//add a new Complex number
            break;

        case 2:
            cout << "Delete the first Complex" << endl;
            t = ax->Delete();

            cout << "The deleted Complex is : ";
            cout << t << endl;
            magnitude = t;
            cout << "Magnitude of complex number = " << magnitude << endl;
            break;

        case 3:
            cout << "Display all the Complexs: " << endl;
            cout << (*ax);
            break;

        case 4:
            cout << "Summarize all the Complexs: ";
            t = ax->SumComplex();//모든 complex 들의 sum || Sum of all complexes
            cout << "The sumup Complex is : ";
            cx = PrintComplex(t);
            cout << cx << endl;
            break;
        case 5:
            cout << "Multiply all the Complexs(t = a * b * c * d): ";
            t = ax->MultiplyComplex();//모든 complex 들의 multiply || Multiply of all complexes
            cout << "The Multiply Complex numbers is : ";
            cx = PrintComplex(t);
            cout << cx << endl;
            break;
        default:
            //delete ax;
            exit(0);
            break;
        }//destructor 구현 || Destructor implementation
    }
    system("pause");
    return 0;
}