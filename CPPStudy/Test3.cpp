#include <iostream>
using namespace std;

class RespondError
{
public:
	template <typename T>
	static bool LowCheck(T value, const char* variableName)
	{
		if (value <= 0)
		{
			cout << "\nError : " << variableName << " Is Too Low" << endl;
			return true;
		}

		return false;
	}

	static bool NormalizedInput()
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
			return false;
		}
		return true;
	}
};

class Tools
{
public:
	template <typename T>
	static void InputQuestionResult(const char* question, T* storage)
	{
		while (true)
		{
			cout << question;

			cin >> *storage;

			if (RespondError::NormalizedInput()) break;
		}
	}

	template <typename T>
	static void InputQuestionResultRange(const char* question, T* storage, T max, T min)
	{
		while (true)
		{
			cout << question;

			cin >> *storage;

			if (RespondError::NormalizedInput())
			{
				if (storage >= min && storage <= max)
				{
					break;
				}
			}
		}
	}
};

class BankingAccount
{
public:
	BankingAccount() = default;

	BankingAccount(string* name, int id, double money, int month, double interest, double tax)
		: name(name), id(id), money(money), month(month), interest(interest), tax(tax) {}

	bool SetID(int value)
	{
		if (RespondError::LowCheck(value, "ID")) return false;

		id = value;

		return true;
	}
	bool SetName(string value)
	{

		name = new string();
		*name = value;

		return true;
	}
	bool SetMoney(double value)
	{
		if (RespondError::LowCheck(value, "Money")) return false;

		money = value;

		return true;
	}
	bool SetMonth(int value)
	{
		if (RespondError::LowCheck(value, "Month")) return false;

		month = value;

		return true;
	}
	bool SetInterest(double value)
	{
		if (RespondError::LowCheck(value, "Interest")) return false;

		interest = value;

		return true;
	}
	bool SetTax(double value)
	{
		if (RespondError::LowCheck(value, "Tax")) return false;

		tax = value;

		return true;
	}
	
	unsigned int GetID() const
	{
		if (RespondError::LowCheck(id, "id")) return -1;

		return id;
	}
	double GetMoney() const
	{
		if (RespondError::LowCheck(money, "Money")) return -1;

		return money;
	}
	int GetMonth() const
	{
		if (RespondError::LowCheck(month, "Month")) return -1;

		return month;
	}
	double GetInterest() const
	{
		if (RespondError::LowCheck(interest, "Interest")) return -1;

		return interest;
	}
	double GetTax() const
	{
		if (RespondError::LowCheck(tax, "Tax")) return -1;

		return tax;
	}
	string GetName() const
	{
		return *name;
	}

protected:
	string* name = nullptr;
	unsigned int id = -1;
	double money = 0;

	int month = 0;
	double interest = 0;
	double tax = 15.4;

	const int percentage = 100;
	const int monthCount = 12;
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
		if (RespondError::LowCheck(money, "Money")) return -1;
		if (RespondError::LowCheck(month, "Month")) return -1;
		if (RespondError::LowCheck(interest, "Interest")) return -1;
		if (RespondError::LowCheck(tax, "Tax")) return -1;

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
		if (RespondError::LowCheck(money, "Money")) return -1;
		if (RespondError::LowCheck(interest, "Interest")) return -1;
		if (RespondError::LowCheck(month, "Month")) return -1;

		double result = money * pow((formulaConstant + interest / percentage / monthCount), month);

		return result;
	}

private:
	const int formulaConstant = 1;
};

int main()
{
	BankingAccount bankingAccount = BankingAccount();

	int id;
	while (true)
	{
		cout << "아이디를 입력해주세요 : ";

		cin >> id;

		RespondError::NormalizedInput();

		if (bankingAccount.SetID(id)) break;
	}

	string name;
	while (true)
	{
		cout << "이름을 입력해주세요 : ";

		cin >> name;

		RespondError::NormalizedInput();

		if (bankingAccount.SetName(name)) break;
	}

	//---예금-------------------------------------------------------------------------------
	Deposit deposit(bankingAccount);

	deposit.SetInterest(3);

	double depositMoney;
	Tools::InputQuestionResult("[예금] 얼마나 입금하시겠습니까? : ", &depositMoney);
	deposit.SetMoney(depositMoney);

	int depositMonth;
	Tools::InputQuestionResult("[예금] 만기 개월은 얼마로 하시겠습니까? : ", &depositMonth);
	deposit.SetMonth(depositMonth);
	//--------------------------------------------------------------------------------------

	//---적금-------------------------------------------------------------------------------
	Savings savings(bankingAccount);

	savings.SetInterest(4);

	double savingsMoney;
	Tools::InputQuestionResult("[적금] 매 달 얼마나 입금하시겠습니까? : ", &savingsMoney);
	savings.SetMoney(savingsMoney);

	int savingsMonth;
	Tools::InputQuestionResult("[적금] 입금을 몇 개월 동안 하시겠습니까? : ", &savingsMonth);
	savings.SetMonth(savingsMonth);
	//--------------------------------------------------------------------------------------

	cout << bankingAccount.GetID() << " / " << bankingAccount.GetName() << endl;
	cout << "적금 : 매 월 " << savings.GetMoney() << "원 씩 " << savings.GetMonth() << "개월 입금하면 " << savings.Calcurate() << "원" << endl;
	cout << "예금 : " << deposit.GetMoney() << "원 씩 " << deposit.GetMonth() << "개월 거치하면 " << deposit.Calcurate() << "원" << endl;
}