#include <iostream>
using namespace std;

class CUser
{
public:
	CUser() = default;
	CUser(int a)
	{
		number = a;
	}
	int number = 5;

	static void Function() {}

	int GetID() const
	{
		return number;
	}
};

void main()
{
	CUser user(10);

	std::cout << user.number << endl;

	system("pause>null");
}