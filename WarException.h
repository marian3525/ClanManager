#pragma once
#include <exception>
class WarException: std::exception
{
public:
	WarException(std::string errorMsg) :msg{ errorMsg } {};
	std::string getMessage() const { return msg; }
	~WarException();
private:
	std::string msg;
};

