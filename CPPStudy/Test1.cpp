#include <iostream>
using namespace std;

const int monthCount = 12;

template <typename T> class RespondError
{
public:
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

class InstallmentSavings
{
private:
	double annualInterestRate = 3.55;
	double interestIncomeTax = 15.4;
	const int percentage = 100;
	const int formulaConstant1 = 1;
	const int formulaConstant2 = 24;
	const int formulaConstant3 = 1;
	int year = 0;

public:
	InstallmentSavings() = default;

	InstallmentSavings(int year)
	{
		if (RespondError<int>::LowCheck(year, "Year")) return;

		this->year = year;
	}

	InstallmentSavings(double annualInterestRate)
	{
		if (RespondError<double>::LowCheck(annualInterestRate, "AnnualInterestRate")) return;

		this->annualInterestRate = annualInterestRate;
	}

	InstallmentSavings(double annualInterestRate, double interestIncomeTax, int year)
	{
		if (RespondError<int>::LowCheck(year, "Year")) return;
		if (RespondError<double>::LowCheck(annualInterestRate, "AnnualInterestRate")) return;
		if (RespondError<double>::LowCheck(interestIncomeTax, "InterestIncomeTax")) return;

		this->annualInterestRate = annualInterestRate;
		this->interestIncomeTax = interestIncomeTax;
		this->year = year;
	}

	int GetYear()
	{
		return year;
	}

	bool SetYear(int value)
	{
		if (RespondError<int>::LowCheck(value, "Year")) return false;

		year = value;

		return true;
	}

	bool SetAnnualInterestRate(double value)
	{
		if (RespondError<double>::LowCheck(value, "AnnualInterestRate")) return false;

		annualInterestRate = value;

		return true;
	}

	bool SetInterestIncomeTax(double value)
	{
		if (RespondError<double>::LowCheck(value, "InterestIncomeTax")) return false;

		interestIncomeTax = value;

		return true;
	}

	double CalcurateInterestRate() const
	{
		if (RespondError<int>::LowCheck(year, "Year")) return -1;

		int month = year * monthCount;

		double result = annualInterestRate * (double)(month + formulaConstant1) / formulaConstant2;

		return result;
	}

	double CalcurateInterestRateAddTax() const
	{
		if (RespondError<int>::LowCheck(year, "Year")) return -1;

		double result = CalcurateInterestRate() * (formulaConstant3 - (interestIncomeTax / percentage));

		return result;
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
		if (RespondError<int>::LowCheck(payMonthly, "PayMonthly")) return;

		this->payMonthly = payMonthly;
		interestRate = 0;
	}

	InstallmentSavingsCalcurator(int payMonthly, double interestRate)
	{
		if (RespondError<int>::LowCheck(payMonthly, "PayMonthly")) return;
		if (RespondError<double>::LowCheck(payMonthly, "InterestRate")) return;

		this->payMonthly = payMonthly;
		this->interestRate = interestRate;
	}

	bool SetPayMonthly(int value)
	{
		if (RespondError<int>::LowCheck(value, "PayMonthly")) return false;

		payMonthly = value;

		return true;
	}

	bool SetInterestRate(double value)
	{
		if (RespondError<double>::LowCheck(value, "InterestRate"))return false;

		interestRate = value;

		return true;
	}

	double Calcuration(int year)
	{
		if (RespondError<int>::LowCheck(year, "Year")) return -1;

		int month = year * monthCount;

		int depositMoney = payMonthly * month;

		double totalMoney = depositMoney * (constNumber + (interestRate / percentage));

		return totalMoney;
	}
};

int main()
{
	InstallmentSavings installmentSavings = InstallmentSavings();
	InstallmentSavingsCalcurator installmentSavingsCalcurator = InstallmentSavingsCalcurator();

	while (true)
	{
		cout << "매 달 얼마를 입금하시겠습니까? : " << endl;

		int payMonthly;

		cin >> payMonthly;

		RespondError<int>::NormalizedInput();

		if (installmentSavingsCalcurator.SetPayMonthly(payMonthly)) break;
	}

	cout << endl;

	while (true)
	{
		cout << "몇 년 동안 적금하시겠습니까? : " << endl;

		int year;

		cin >> year;

		RespondError<int>::NormalizedInput();

		if (installmentSavings.SetYear(year)) break;
	}

	cout << endl;

	double interestRate = installmentSavings.CalcurateInterestRate();
	double interestRateAddTax = installmentSavings.CalcurateInterestRateAddTax();

	installmentSavingsCalcurator.SetInterestRate(interestRate);

	cout << fixed << "세 전 총 금액은 " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetYear()) << "원(소수점 버림) 입니다" << endl;

	installmentSavingsCalcurator.SetInterestRate(interestRateAddTax);

	cout << fixed << "세 후 총 금액은 " << (int)installmentSavingsCalcurator.Calcuration(installmentSavings.GetYear()) << "원(소수점 버림) 입니다" << endl;

	return 0;
}