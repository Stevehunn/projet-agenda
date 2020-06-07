#include "..\include\Heure.h"

Heure::Heure(std::string str) : Heure()
{
	std::vector<std::string> result;
	std::istringstream tokenStream(str);
	std::string token;
	while (std::getline(tokenStream, token, ':'))
	{
		result.push_back(token);
	}
	if (result.size() == 2) {
		h_ = std::stoi(result[0]);
		m_ = std::stoi(result[1]);
	}
}

/*Heure::~Heure()
{
	//dtor
}*/

std::istream& operator>>(std::istream& is, Heure& heure)
{
	std::string tmp;
	is >> tmp;
	std::vector<std::string> result;
	std::istringstream tokenStream(tmp);
	std::string token;
	while (std::getline(tokenStream, token, ':'))
	{
		result.push_back(token);
	}
	if (result.size() == 2) {
		heure.h_ = std::stoi(result[0]);
		heure.m_ = std::stoi(result[1]);
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Heure& heure) {
	os << heure.h_ << ":" << heure.m_;// << std::endl;
	return os;
}