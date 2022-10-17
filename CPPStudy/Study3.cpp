#include <iostream>
using namespace std;

class CUser
{
public:
	// 묵시적 변환 생성자 호출 막기
	explicit CUser(int param)
		:id(param)
	{
		cout << "constructor" << endl;
	}

	operator int(void)
	{
		return id;
	}

	CUser(const CUser& rhs)
		:id(rhs.id)
	{
		cout << "copy constructor" << endl;
	}

	CUser(const CUser&& rhs)
		:id(rhs.id)
	{
		cout << "copy constructor" << endl;
	}

	CUser& operator=(const CUser&) = default;

	int GetID() const
	{
		return id;
	}

	void SetID(int nParam)
	{
		id = nParam;
	}

private:
	int id = 0;
};

void TestFunc(CUser user)
{
	cout << "TestFunc : " << user.GetID() << endl;
}

CUser Func(int nParam)
{
	CUser a(nParam);

	return a;
}

int main()
{
	//TestFunc(10);

	/*CUser user(10);

	cout << user << endl;
	cout << (int)user << endl;
	cout << static_cast<int>(user) << endl;*/

	CUser user2 = Func(10);

	int&& data = 3 + 4;

	return 0;
}