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

Date Date::operator-(int n) const {
	Date result(*this);
	result.j_ = j_ - n;
	if (j_ < 0) {
		int tmp = result.j_;
		result.m_ -= 1;
		if (result.m_ == 3) {
			if (result.a_ % 4 == 0 || result.a_ % 100 == 0)
				result.j_ = 29 - tmp;
		}
		else result.j_ = 28;
		if (result.m_ % 2 == 0) {
			result.j_ = 31 - tmp;
		}
		else result.j_ = 30 - tmp;
		if (result.m_ < 0) {
			result.m_ = 12;
			result.a_ -= 1;
		}
	}
	return result;
}

Date Date::operator+(int n) const {
	Date result(*this);
	result.j_ = result.j_ + n;
	if (result.m_ == 2) {
		if (result.a_ % 4 == 0 || result.a_ % 100 == 0) {
			if (result.j_ > 29) {
				int tmp = result.j_ - 29;
				result.j_ = tmp;
				result.m_ += 1;
			}
		}
		else if (result.j_ > 28) {
			int tmp = result.j_ - 28;
			result.j_ = tmp;
			result.m_ += 1;
		}
	}
	else if (result.m_ % 2 == 0) {
		if (result.j_ > 30) {
			int tmp = result.j_ - 30;
			result.j_ = tmp;
			result.m_ += 1;
		}
	}
	else if (result.j_ > 31) {
		int tmp = result.j_ - 31;
		result.j_ = tmp;
		result.m_ += 1;
	}
	return result;
}