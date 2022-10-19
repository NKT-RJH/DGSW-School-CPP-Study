#include <iostream>
using namespace std;

class CPerson
{
public:
	virtual void PrintData() final
	{

	}

	virtual void Print()
	{
		cout << "CUser : " << id << endl;
	}

	void TestFunc()
	{
		cout << "TestFunc()" << endl;
		Print();
	}

protected:
	int id = 1;
};

class CStudent : public CPerson
{
public:
	virtual void Print()
	{
		cout << "CStudent : " << id + 1 << endl;
	}
};

int main()
{
	CStudent a;
	a.Print();

	CPerson& b = a;
	b.Print();

	a.TestFunc();

	return 0;
}