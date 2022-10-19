#include <iostream>
using namespace std;

class CDeviceInterface
{
public:
	CDeviceInterface()
		: deviceID(0)
	{
		cout << "CDeviceInterface" << endl;
	}

	virtual int GetDeviceID() const = 0;

protected:
	int deviceID;
};

class CDisplay : public CDeviceInterface
{
public:
	CDisplay()
	{
		cout << "CDisplay" << endl;
	}

	int GetDeviceID() const override
	{
		cout << "CDisplay GetDeviceID" << endl;
		return deviceID;
	}
};

class CAudio : public CDeviceInterface
{
public:
	CAudio()
	{
		cout << "CAudio" << endl;
	}

	int GetDeviceID() const override
	{
		cout << "CAudio GetDeviceID" << endl;
		return deviceID;
	}
};

void PrintDeviceID(CDeviceInterface* cdi)
{
	cout << "Device ID : " << cdi->GetDeviceID() << endl;
}

int main()
{
	CDisplay sp;
	PrintDeviceID(&sp);

	CAudio au;
	PrintDeviceID(&au);

	return 0;
}