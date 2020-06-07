#pragma once

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Date {
public:
	Date() = default;
	Date(std::string str);
	virtual ~Date() = default;
	bool operator<(const Date& right) const { return a_ < right.a_&& m_ < right.m_&& j_ < right.j_; }
	friend std::istream& operator>>(std::istream& is, Date& date);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	Date operator-(int n) const;
	Date operator+(int n) const;

protected:
private:
	int a_; // Anné
	int m_; // Mois
	int j_; // Jour
};

#endif // DATE_H
