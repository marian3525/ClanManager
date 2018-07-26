#pragma once
class ControllerException
{
public:
	ControllerException(std::string msg) : errorMsg{ msg } {};
	std::string getMessage() const { return errorMsg; }
	~ControllerException();
private:
	std::string errorMsg;
};

