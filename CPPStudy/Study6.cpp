#include <iostream>
using namespace std;

class CPerson
{
public:
	CPerson()
	{
		name = new char[32];
	}
	virtual int GetAge() = 0;
	virtual ~CPerson()
	{
		cout << "~CPerson()" << endl;
		delete[] name;
	}

private:
	char* name;
};

class CStudent : public CPerson
{
public:
	CStudent()
	{
		id = new int;
	}

	int GetAge() override
	{

	}

	virtual ~CStudent()
	{
		cout << "~CStudent()" << endl;
		delete id;
	}

private:
	int* id;
};

int main()
{
	CPerson* pPerson = new CStudent;
	delete pPerson;
}