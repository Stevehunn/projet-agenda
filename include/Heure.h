#pragma once
#ifndef HEURE_H
#define HEURE_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Heure {
public:
	Heure() = default;
	Heure(std::string str);
	virtual ~Heure() = default;
	bool operator<(const Heure& right) const { return h_ < right.h_&& m_ < right.m_; }
	friend std::istream& operator>>(std::istream& is, Heure& heure);
	friend std::ostream& operator<<(std::ostream& os, const Heure& heure);
protected:
private:
	int h_; // Heure
	int m_; // Minute
};

#endif // HEURE_H
