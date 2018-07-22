#pragma once
using namespace std;
class ControllerException
{
public:
	ControllerException(string msg) : errorMsg{ msg } {};
	string getMessage() const { return errorMsg; }
	~ControllerException();
private:
	string errorMsg;
};

