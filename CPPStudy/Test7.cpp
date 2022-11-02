#include <iostream>
using namespace std;
using namespace Tools;

#define YearCount 12

namespace Tools
{
	template <typename T>
	static T Input(const char* question)
	{
		T storage = NULL;

		while (true)
		{
			cout << question;

			cin >> storage;

			if (!cin.fail()) break;

			cin.clear();
			cin.ignore();
			system("cls");
		}

		return storage;
	}

	template<typename Key, typename Value>
	struct KeyValuePair
	{
		Key key;
		Value value;
	};
}

class Bank
{
public:
	Bank()
	{
		accounts = new Account[0];
	}
	Bank(int length)
	{
		accounts = new Account[length];
	}
	Bank(Account values[])
	{
		int length = sizeof(values) / sizeof(Account);

		accounts = new Account[length];

		for (int count = 0; count < length; count++)
		{
			accounts[count] = values[count];
		}
	}
	~Bank()
	{
		delete[] accounts;
	}
	/*Bank(Account* values)
	{
		int length = sizeof(values) / sizeof(*values);

		accounts = new Account[length];

		for (int count = 0; count < length; count++)
		{
			accounts[count] = values[count];
		}
	}*/

	void AddAccount(Account account)
	{
		int newsize = (sizeof(accounts) + sizeof(Account)) / sizeof(Account);

		int originSize = sizeof(accounts) / sizeof(Account);

		Account* temporary = new Account[newsize];

		for (int count = 0; count < newsize; count++)
		{
			if (count < originSize)
			{
				temporary[count] = accounts[count];
			}
			else
			{
				temporary[count] = NULL;
			}
		}

		delete[] accounts;

		accounts = temporary;
	}

	Account GetAccount(int number) const
	{
		return accounts[number];
	}

private:
	Account* accounts;
	KeyValuePair<string,double>* moneies;
	Savings* savings;
	Deposit* deposits;

	// 예금 적금 여부 및 계정 별 돈 
};

class Insurance// : ICalcurater<double,double>
{
public:
	Insurance() = default;

	Insurance(string name, double rate) : name(name), rate(rate) {}

	void SetName(string value)
	{
		name = value;
	}
	void SetRate(double value)
	{
		rate = value;
	}

	string GetName() const
	{
		return name;
	}
	double GetRate() const
	{
		return rate;
	}

	double Calcurate(double value) const
	{
		return value * rate / percentage;
	}
private:
	string name;
	double rate;

	const int percentage = 100;
};

class TaxFree
{
public:
	TaxFree() = default;

	TaxFree(string name, double money) : name(name), money(money) {}

	void SetName(string value)
	{
		name = value;
	}
	void SetMoney(double value)
	{
		money = value;
	}

	string GetName() const
	{
		return name;
	}
	double GetMoney() const
	{
		return money;
	}
private:
	string name;
	double money;
};

class Tax
{
public:
	Tax() = default;

	Tax(double incomeTax) : incomeTax(incomeTax)
	{
		localIncomeTax = incomeTax * localIncomeTaxPercentage;
	}

	void SetIncomeTax(double value)
	{
		incomeTax = value;
		localIncomeTax = value * localIncomeTaxPercentage;
	}

	double GetIncomeTax() const
	{
		return incomeTax;
	}
	double GetLocalIncomeTax() const
	{
		return localIncomeTax;
	}
private:
	double incomeTax = 0;
	double localIncomeTax = 0;

	const double localIncomeTaxPercentage = 0.1;
};

class Account
{
public:
	Account() = default;

	Account(double annualSalary) : annualSalary(annualSalary)
	{
		salary = annualSalary / YearCount;
	}

	void SetName(string value)
	{
		name = value;
	}
	void SetAnnualSalary(double value)
	{
		annualSalary = value;
		salary = value / YearCount;
	}

	string GetName() const
	{
		return name;
	}
	double GetSalary() const
	{
		return salary;
	}
	double GetAnnualSalary() const
	{
		return annualSalary;
	}
private:
	string name;
	double annualSalary = 0;
	double salary = 0;
};

class Savings : public BankingAccount // 적금
{
public:
	Savings() = delete;

	Savings(string* name, int id, double money, int month, double interest, double tax)
		: BankingAccount(name, id, money, month, interest, tax) {}

	Savings(const BankingAccount& classObject)
	{
		name = new string();
		*name = classObject.GetName();
	}

	Savings& operator=(const Savings& classObject)
	{
		name = new string();
		*name = *classObject.name;

		return *this;
	}

	double Calcurate()
	{
		if (LowCheck(money, "Money")) return -1;
		if (LowCheck(month, "Month")) return -1;
		if (LowCheck(interest, "Interest")) return -1;
		if (LowCheck(tax, "Tax")) return -1;

		double totalMoney = money * month;

		double interestAddTax = (interest * (month + formulaConstant1) / formulaConstant2) * (formulaConstant3 - tax / percentage);

		double result = totalMoney * (formulaConstant4 + (interestAddTax / percentage));

		return result;
	}

private:
	const int formulaConstant1 = 1;
	const int formulaConstant2 = 24;
	const int formulaConstant3 = 1;
	const int formulaConstant4 = 1;
};

class Deposit : public BankingAccount // 정기 예금
{
public:
	Deposit() = delete;

	Deposit(string* name, int id, double money, int month, double interest, double tax)
		: BankingAccount(name, id, money, month, interest, tax) {}

	Deposit(const BankingAccount& classObject)
	{
		name = new string();
		*name = classObject.GetName();
	}

	Deposit& operator=(const Deposit& classObject)
	{
		name = new string();
		*name = *classObject.name;

		return *this;
	}

	double Calcurate()
	{
		if (LowCheck(money, "Money")) return -1;
		if (LowCheck(interest, "Interest")) return -1;
		if (LowCheck(month, "Month")) return -1;

		double result = money * pow((formulaConstant + interest / percentage / monthCount), month);

		return result;
	}

private:
	const int formulaConstant = 1;
};

int main()
{
	

	return 0;
}