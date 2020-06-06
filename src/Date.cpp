#include "..\include\Date.h"

Date::Date() {
}

Date::~Date() {
}

std::ostream& operator<<(std::ostream& os, const Date& dates)
{
	os << dates.a_ << "/" << dates.m_ << "/" << dates.j_ << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
	std::string tmp;
	is >> tmp;
	std::vector<std::string> result;
	std::istringstream tokenStream(tmp);
	std::string token;
	while (std::getline(tokenStream, token, '/'))
	{
		result.push_back(token);
	}
	if (result.size() == 3) {
		date.a_ = std::stoi(result[0]);
		date.m_ = std::stoi(result[1]);
		date.j_ = std::stoi(result[2]);
	}
	return is;
}