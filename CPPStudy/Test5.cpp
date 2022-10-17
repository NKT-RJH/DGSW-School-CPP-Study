#include <iostream>
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

	Insurance(string name, double rate)	: name(name), rate(rate) {}

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
	double GetRate()
	{
		return rate;
	}

	double Calcurate(double value)
	{
		return value * rate / percentage;
	}

//protected:
private:
	string name;
	double rate;

	const int percentage = 100;
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

	Person person;

	person.SetAnnualSalary(Input<double>("연봉을 입력하세요 (원) : "));

	double calcurate1 = nationalPension.Calcurate(person.GetSalary());
	double calcurate2 = healthInsurance.Calcurate(person.GetSalary());
	double calcurate3 = longTermNursingInsurance.Calcurate(calcurate2);
	double calcurate4 = employmentInsurance.Calcurate(person.GetSalary());

	double result = person.GetSalary() - (calcurate1 + calcurate2 + calcurate3 + calcurate4);

	cout << fixed << "월급 : " << result << endl;

	return 0;
}