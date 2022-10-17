#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace RespondError
{
	template <typename T>
	static bool IsNegativeQuantity(T value)
	{
		return value < 0;
	}

	template <typename T>
	static bool IsInRange(T value, T max, T min)
	{
		return value >= max && value <= min;
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
}

using namespace RespondError;

namespace Tools
{
	template <typename T>
	static T Input(const char* question)
	{
		T storage;

		while (true)
		{
			cout << question;

			cin >> storage;

			if (NormalizedInput()) break;
		}

		return storage;
	}

	static vector<string> split(string input, char delimiter)
	{
		vector<string> answer;
		stringstream stringStream(input);
		string temporary;

		while (getline(stringStream, temporary, delimiter))
		{
			answer.push_back(temporary);
		}

		return answer;
	}
	
	template <typename T>
	static void FreeVectorMemory(vector<T>* value)
	{
		for (int count = 0; count < value.size(); count++)
		{
			free(value[count]);
		}
	}

	static string ToStringSecond(double value)
	{
		int hour = 3600;

		string temporary = "";

		temporary += to_string((int)value / hour);
		temporary += "시 ";
		temporary += to_string((int)(value)%hour / 60);
		temporary += "분";

		return temporary;
	}

	static void PrintBusTimes(vector<string*> values)
	{
		cout << "---------------------------------------------------------------" << endl;

		for (int count = 0; count < values.size(); count++)
		{
			cout.right;
			cout << values[count][1] << "에 버스를 타려면 " << values[count][0] << "에 출발하세요" << endl;
		}

		cout << "---------------------------------------------------------------" << endl;
	}
}

using namespace Tools;

class Bus
{
public:
	Bus() = default;

	Bus(int startTime, int endTime, int dispatchInterval)
	{
		if (!IsNegativeQuantity(startTime))
		{
			this->startTime = startTime;
		}
		if (!IsNegativeQuantity(endTime))
		{
			this->endTime = endTime;
		}
		if (!IsNegativeQuantity(dispatchInterval))
		{
			this->dispatchInterval = dispatchInterval;
		}
	}

	void SetStartTime(int value)
	{
		if (IsNegativeQuantity(value)) return;

		startTime = value;
	}
	void SetStartTime(string value)
	{
		vector<string> splitValue = split(value, ':');

		if (splitValue.size() < 2) return;

		int hour = stoi(splitValue[0]);
		int minuite = stoi(splitValue[1]);

		int startTime = hour * hourToSecond + minuite * minuiteToSecond;

		if (IsNegativeQuantity(startTime)) return;

		this->startTime = startTime;
	}
	void SetEndTime(int value)
	{
		if (IsNegativeQuantity(value)) return;

		endTime = value;
	}
	void SetEndTime(string value)
	{
		vector<string> splitValue = split(value, ':');

		if (splitValue.size() < 2) return;

		int hour = stoi(splitValue[0]);
		int minuite = stoi(splitValue[1]);

		int endTime = hour * hourToSecond + minuite * minuiteToSecond;

		if (IsNegativeQuantity(endTime)) return;

		this->endTime = endTime;
	}
	void SetDispatchInterval(int value)
	{
		if (IsNegativeQuantity(value)) return;

		dispatchInterval = value * minuiteToSecond;
	}

	int GetStartTime() const
	{
		return startTime;
	}
	int GetEndTime() const 
	{
		return endTime;
	}
	int GetDispatchInterval() const
	{
		return dispatchInterval;
	}

private:
	// second
	int startTime = 21600;
	int endTime = 79200;
	int dispatchInterval = 1200;

	const int hourToSecond = 3600;
	const int minuiteToSecond = 60;
};

class Passenger
{
public:
	Passenger() = default;

	Passenger(double speed)
	{
		if (IsNegativeQuantity(speed)) return;

		this->speed = speed;
	}

	void SetSpeed(double value)
	{
		if (IsNegativeQuantity(value)) return;

		speed = value;
	}

	double GetSpeed() const
	{
		return speed;
	}

private:
	double speed = 4; // km/h
};

class Road
{
public:
	Road() = default;

	Road(double length)
	{
		if (IsNegativeQuantity(length)) return;

		this->length = length;
	}

	void SetLength(double value)
	{
		if (IsNegativeQuantity(value)) return;

		length = value;
	}

	double GetLength() const
	{
		return length;
	}

private:
	double length = 470; // meter
};

class CalculateBusTime
{
public:
	CalculateBusTime() = default;

	vector<int*> JobByVectorInt(int startTime, int endTime, int dispatchInterval, double speed, double roadlength)
	{
		vector<int*> busTimes;

		int walkTime = HourToSecond(roadlength / SpeedConvertMeterPerHour(speed));

		for (int count = startTime; count <= endTime; count += dispatchInterval)
		{
			int* temporary = new int[2];
			temporary[0] = count - walkTime;
			temporary[1] = count;
			busTimes.push_back(temporary);
		}

		return busTimes;
	}

	vector<string*> JobByVectorString(int startTime, int endTime, int dispatchInterval, double speed, double roadlength)
	{
		vector<string*> busTimes;

		int walkTime = HourToSecond(roadlength / SpeedConvertMeterPerHour(speed));

		for (int count = startTime; count <= endTime; count += dispatchInterval)
		{
			string* temporary = new string[2];
			temporary[0] = ToStringSecond(count - walkTime);
			temporary[1] = ToStringSecond(count);
			busTimes.push_back(temporary);
		}

		return busTimes;
	}

	double SpeedConvertMeterPerHour(double value) const
	{
		return value * kilometerToMeter;
	}

	double RoadLengthConvertKilometer(double value) const
	{
		return value * meterToKilometer;
	}

	int HourToSecond(double value)
	{
		return value * hour;
	}

private:
	const int kilometerToMeter = 1000;
	const int hour = 3600;
	const double meterToKilometer = 0.001;
};

int main()
{
	Bus bus = Bus();
	Passenger passenger = Passenger();
	Road road = Road();
	CalculateBusTime calculateBusTime = CalculateBusTime();

	bus.SetStartTime(Input<string>("첫차 시간을 입력하세요 (00:00 형식으로) : "));

	bus.SetEndTime(Input<string>("막차 시간을 입력하세요 (00:00 형식으로) : "));

	bus.SetDispatchInterval(Input<int>("배차 간격을 입력하세요 (분) : "));

	passenger.SetSpeed(Input<double>("걷는 속도를 입력하세요 (km/h) : "));

	road.SetLength(Input<double>("정문에서 버스정류장까지의 거리를 입력하세요 (m) : "));

	vector<string*> result = calculateBusTime.JobByVectorString(bus.GetStartTime(), bus.GetEndTime(), bus.GetDispatchInterval(), passenger.GetSpeed(), road.GetLength());

	PrintBusTimes(result);

	return 0;
}