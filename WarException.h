#pragma once
#include <exception>
using namespace std;
class WarException: exception
{
public:
	WarException(string errorMsg) :msg{ errorMsg } {};
	string getMessage() const { return msg; }
	~WarException();
private:
	string msg;
};

