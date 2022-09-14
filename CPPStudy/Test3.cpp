#include <iostream>
using namespace std;

const int monthCount = 12;

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

	static void NormalizedInput()
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}
	}
};

class IAccount
{
public:
	// 여기다 다 이동하고 이름은 각가 savings랑 deposit으로
	

protected:
	char* name;
	int id;
};

class Savings
{
private:
	double annualInterestRate = 3.55;
	double interestIncomeTax = 15.4;
	const int percentage = 100;
	const int formulaConstant1 = 1;
	const int formulaConstant2 = 24;
	const int formulaConstant3 = 1;
	int month = 0;

public:
	Savings() = default;

	Savings(int month)
	{
		if (RespondError::LowCheck<int>(month, "Month")) return;

		this->month = month;
	}

	Savings(double annualInterestRate)
	{
		if (RespondError::LowCheck<double>(annualInterestRate, "AnnualInterestRate")) return;

		this->annualInterestRate = annualInterestRate;
	}

	Savings(double annualInterestRate, double interestIncomeTax, int month)
	{
		if (RespondError::LowCheck<int>(month, "Month")) return;
		if (RespondError::LowCheck<double>(annualInterestRate, "AnnualInterestRate")) return;
		if (RespondError::LowCheck<double>(interestIncomeTax, "InterestIncomeTax")) return;

		this->annualInterestRate = annualInterestRate;
		this->interestIncomeTax = interestIncomeTax;
		this->month = month;
	}

	int GetMonth()
	{
		return month;
	}

	bool SetMonth(int value)
	{
		if (RespondError::LowCheck<int>(value, "Month")) return false;

		month = value;

		return true;
	}

	bool SetAnnualInterestRate(double value)
	{
		if (RespondError::LowCheck<double>(value, "AnnualInterestRate")) return false;

		annualInterestRate = value;

		return true;
	}

	bool SetInterestIncomeTax(double value)
	{
		if (RespondError::LowCheck<double>(value, "InterestIncomeTax")) return false;

		interestIncomeTax = value;

		return true;
	}

	/*double CalcurateInterestRate() const
	{
		if (RespondError::LowCheck<int>(month, "Month")) return -1;


		return result;
	}*/

	double GetInterestRate() const
	{
		if (RespondError::LowCheck<int>(month, "Month")) return -1;

		double result1 = annualInterestRate * (double)(month + formulaConstant1) / formulaConstant2;
		double result2 = result1 * (formulaConstant3 - (interestIncomeTax / percentage));

		return result2;
	}
};

class InstallmentSavingsCalcurator
{
private:
	const int constNumber = 1;
	const int percentage = 100;
	int payMonthly = 0;
	double interestRate = 0;

public:
	InstallmentSavingsCalcurator() = default;

	InstallmentSavingsCalcurator(int payMonthly)
	{
		if (RespondError::LowCheck<int>(payMonthly, "PayMonthly")) return;

		this->payMonthly = payMonthly;
		interestRate = 0;
	}

	InstallmentSavingsCalcurator(int payMonthly, double interestRate)
	{
		if (RespondError::LowCheck<int>(payMonthly, "PayMonthly")) return;
		if (RespondError::LowCheck<double>(payMonthly, "InterestRate")) return;

		this->payMonthly = payMonthly;
		this->interestRate = interestRate;
	}

	bool SetPayMonthly(int value)
	{
		if (RespondError::LowCheck<int>(value, "PayMonthly")) return false;

		payMonthly = value;

		return true;
	}

	bool SetInterestRate(double value)
	{
		if (RespondError::LowCheck<double>(value, "InterestRate"))return false;

		interestRate = value;

		return true;
	}

	double Calcuration(int month)
	{
		if (RespondError::LowCheck<int>(month, "Month")) return -1;

		int depositMoney = payMonthly * month;

		double totalMoney = depositMoney * (constNumber + (interestRate / percentage));

		return totalMoney;
	}
};

int main()
{
	/*InstallmentSavings installmentSavings = InstallmentSavings();
	InstallmentSavingsCalcurator installmentSavingsCalcurator = InstallmentSavingsCalcurator();

	while (true)
	{
		cout << "1번 : 특판적금 연(12개월) 이율 4%\n"
			<< "2번 : 일반적금 연(12개월) 이율 3%\n"
			<< "무엇을 선택하시겠습니까? (숫자 1 혹은 2 입력) : ";

		int choose;

		cin >> choose;

		RespondError::NormalizedInput();

		if (choose == 1)
		{
			installmentSavings.SetAnnualInterestRate(4);
			break;
		}
		else if (choose == 2)
		{
			installmentSavings.SetAnnualInterestRate(3);
			break;
		}

		cout << "\n다시 입력해주세요\n" << endl;
	}

	cout << endl;

	while (true)
	{
		cout << "매 달 얼마를 입금하시겠습니까? : ";

		int payMonthly;

		cin >> payMonthly;

		RespondError::NormalizedInput();

		if (installmentSavingsCalcurator.SetPayMonthly(payMonthly)) break;
	}

	cout << endl;

	while (true)
	{
		cout << "몇 개월 동안 적금하시겠습니까? : ";

		int month;

		cin >> month;

		RespondError::NormalizedInput();

		if (installmentSavings.SetMonth(month)) break;
	}

	cout << endl;

	double interestRate = installmentSavings.CalcurateInterestRate();
	double interestRateAddTax = installmentSavings.CalcurateInterestRateAddTax();

	installmentSavingsCalcurator.SetInterestRate(interestRate);

	cout << fixed << "세 전 총 금액은 " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetMonth()) << "원(소수점 버림) 입니다" << endl;

	installmentSavingsCalcurator.SetInterestRate(interestRateAddTax);

	cout << fixed << "세 후 총 금액은 " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetMonth()) << "원(소수점 버림) 입니다" << endl;

	return 0;*/
}