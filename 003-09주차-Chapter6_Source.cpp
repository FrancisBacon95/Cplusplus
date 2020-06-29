#include<iostream>
#include<conio.h>
using namespace std;

class Note
{
	class NoteImpl* ni;
public:
	Note();
	Note(const Note& n);
	Note(int pitch, int duration);
	~Note();

	Note& operator=(const Note& n); // Assignment Operator
	friend istream& operator>>(istream& s, Note& n);
	friend ostream& operator<<(ostream& s, Note n);
};

class NoteImpl {
	friend Note;
private:
	int pitch;// À½ÀÇ ³ô³·ÀÌ
	int duration;
	NoteImpl(int p, int d) : pitch(p), duration(d)
	{
	}
	NoteImpl() : pitch(0), duration(0)	// default contructor
	{
		cout << endl;
	}

	//void Sound()
	//{
	//	cout << "Sound(): pitch = " << pitch << ", duration = " << duration << endl;
	//}
	//void Modulate(int cycles);
	friend istream& operator>>(istream& s, Note& n);
	friend ostream& operator<<(ostream& s, Note n);
};

Note::Note()
{
	ni = new NoteImpl(0, 0);
}


Note::Note(const Note& n)
{

	ni = new NoteImpl(0, 0);
	ni->pitch = n.ni->pitch;
	ni->duration = n.ni->duration;
}

Note::Note(int pitch, int duration)
{
	ni = new NoteImpl(pitch, duration);

}

Note :: ~Note()
{
	delete ni;
}


Note& Note::operator=(const Note& n)
{
	ni = new NoteImpl(0, 0);
	ni->pitch = n.ni->pitch;
	ni->duration = n.ni->duration;
	return *this;
}

istream& operator>>(istream& s, Note& n)
{
	s >> n.ni->pitch >> n.ni->duration;
	cout << endl;
	return s;
}

ostream& operator<<(ostream& s, Note n)
{
	s << "pitch = " << n.ni->pitch << ", duration = " << n.ni->duration << endl;
	return s;
}
int main()
{
	//Note n(5,30);
	Note n;
	cout << "enter values" << endl;
	cin >> n;
	cout << "The Value of Note n " << n << endl;

	Note n1;
	cout << "enter values" << endl;
	cin >> n1;
	cout << "The Value of Note n1 " << n1 << endl;

	cout << "Assigning Value of n to n2 " << endl;
	Note n2;
	n2 = n;
	cout << "Assigned Value of n2 " << n2 << endl;

	cout << "Assigning Value of n1 to n2 " << endl;
	Note n3 = n1;
	cout << "Assigned Value of n3 " << n3 << endl;

	system("pause");
	return 0;
}