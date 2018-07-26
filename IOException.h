#pragma once
#include <exception>
class IOException: std::exception
{
public:
	IOException(std::string msg) : message{ msg } {};
	std::string getMessage() const { return message; }
private:
	std::string message;
};

