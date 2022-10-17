#include <iostream>
#include <cstdarg>
using namespace std;

#define YearCount 12

//국민연금 : 월 소득액 4.5%
//건강보험 : 보수월액의 3.495%
//장기요양보험 : 건강보험료의 12.27%
//고용보험 : 월 소득액의 0.9%

class Insurance
{
public:
	Insurance() = delete;

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
	TaxFree() = delete;

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

class Person
{
public:
	Person() = default;

	Person(double annualSalary) : annualSalary(annualSalary)
	{
		salary = annualSalary / YearCount;
	}

	void SetAnnualSalary(double value)
	{
		annualSalary = value;
		salary = value / YearCount;
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
	double annualSalary = 0;
	double salary = 0;
};

class SalaryCalcurator
{
public:
	double Job(double salary, Insurance nationalPension, Insurance healthInsurance, 
		Insurance longTermNursingInsurance, Insurance employmentInsurance, 
		double incomeTax, double localIncomeTax, int taxFreeCount, TaxFree ...)
	{
		va_list taxFreeList;
		va_start(taxFreeList, taxFreeCount);

		for (int count = 0; count < taxFreeCount; count++)
		{
			TaxFree taxFree = va_arg(taxFreeList, TaxFree);
			salary -= taxFree.GetMoney();
		}
		//cout << fixed << salary << endl;

		double insuranceCost1 = nationalPension.Calcurate(salary);
		double insuranceCost2 = healthInsurance.Calcurate(salary);
		double insuranceCost3 = longTermNursingInsurance.Calcurate(insuranceCost2);
		double insuranceCost4 = employmentInsurance.Calcurate(salary);

		salary -= insuranceCost1 + insuranceCost2 + insuranceCost3 + insuranceCost4;
		//salary -= nationalPension + healthInsurance + longTermNursingInsurance + employmentInsurance;

		//cout << fixed << salary << endl;
		salary -= incomeTax + localIncomeTax;

		//cout << fixed << salary << endl;
		result = salary;

		return salary;
	}

	double GetBeforeJob() const
	{
		return result;
	}
private:
	double result = 0;
};

template <typename T>
static T Input(const char* question)
{
	T storage;

	while (true)
	{
		cout << question;

		cin >> storage;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}
		else
		{
			break;
		}
	}

	return storage;
}

int main()
{
	Insurance nationalPension("국민연금", 4.5);
	Insurance healthInsurance("건강보험", 3.495);
	Insurance longTermNursingInsurance("장기요양보험", 12.27);
	Insurance employmentInsurance("고용보험", 0.9);

	Tax tax;

	Person person;

	TaxFree mealPrice("식대", 100000);
	TaxFree researchAndDevelopmentCost("연구개발비", 100000);
	
	SalaryCalcurator salaryCalcurator;

	person.SetAnnualSalary(Input<double>("연봉을 입력하세요 (원) : "));

	tax.SetIncomeTax(Input<double>("소득세를 입력하세요 (원) : "));

	/*double calcurate1 = nationalPension.Calcurate(person.GetSalary());
	double calcurate2 = healthInsurance.Calcurate(person.GetSalary());
	double calcurate3 = longTermNursingInsurance.Calcurate(calcurate2);
	double calcurate4 = employmentInsurance.Calcurate(person.GetSalary());*/

	salaryCalcurator.Job(person.GetSalary(),
		nationalPension, healthInsurance, longTermNursingInsurance, employmentInsurance,
		tax.GetIncomeTax(), tax.GetLocalIncomeTax(),
		2, mealPrice, researchAndDevelopmentCost);

	cout << fixed << salaryCalcurator.GetBeforeJob() << endl;

	return 0;
}