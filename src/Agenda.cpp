#include "..\include\Agenda.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
/*Agenda::Agenda() {
}

Agenda::~Agenda() {
}*/

void Agenda::ajouter(const Date& d, const Heure& h, const std::string& note)
{
	auto result = data_.find(d);
	if (result != data_.end()) {
		result->second.insert(std::make_pair(h, note));
	}
	else {
		data_.insert(std::make_pair(d, std::map<Heure, std::string> { {h, note}}));
	}
}

void Agenda::afficher(const int numero)
{

	if (data_.size() == 0) {
		cout << "Il n'y a pas de rendez-vous enregist�" << std::endl;
	}
	else {
		int compteur = 1;
		for (auto itr = data_.begin(); itr != data_.end(); ++itr) {
			for (const std::pair<Heure, std::string>& elm : itr->second) {
				if (numero == compteur) {
					cout << "\t\t" << elm.first << "\t" << elm.second << "\t" << compteur << std::endl;
					return;
				}
				else
				{
					compteur++;
				}
				
			}
		}
	}

}


void Agenda::avancer(const Date& d, const Heure& h, int n)
{
	auto result = data_.find(d);
	if (result != data_.end()) {
		auto hour = result->second.find(h);
		if (hour != result->second.end()) {
			std::pair<Heure, std::string> tmp = *hour;
			result->second.erase(h);
			Date new_date(d - n);
			ajouter(new_date, tmp.first, tmp.second);
		}
	}
}

void Agenda::modifier(const Date& d, const Heure& old_hour, const Heure& new_hour)
{
	auto result = data_.find(d);
	if (result != data_.end()) {
		auto hour = result->second.find(old_hour);
		if (hour != result->second.end()) {
			std::string tmp = hour->second;
			result->second.erase(old_hour);
			result->second.insert(std::make_pair(new_hour, tmp));
		}
	}
}

void Agenda::reporter(const Date& d, const Heure& h, int n)
{
	auto result = data_.find(d);
	if (result != data_.end()) {
		auto hour = result->second.find(h);
		if (hour != result->second.end()) {
			std::pair<Heure, std::string> tmp = *hour;
			result->second.erase(h);
			Date new_date(d + n);
			ajouter(new_date, tmp.first, tmp.second);
		}
	}
}

void Agenda::supprimer(const Date& d, const Heure& h)
{
	auto result = data_.find(d);
	if (result != data_.end()) {
		auto hour = result->second.find(h);
		if (hour != result->second.end()) {
			result->second.erase(h);
		}
		if (result->second.size() == 0) {
			data_.erase(d);
		}
	}
}

void Agenda::ouvrir(const char* fichier)
{
	std::ifstream monFlux(fichier);  //Ouverture d'un fichier en lecture

	if (monFlux.is_open())
	{
		cout << "Le fichier est charger" << endl;

		
		
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}

void Agenda::enregistrer(const char* fichier)
{
	std::ofstream monFlux(fichier);

	if (monFlux.is_open())
	{
		for (auto itr = data_.begin(); itr != data_.end(); ++itr) {
			for (const std::pair<Heure, std::string>& elm : itr->second) {
				monFlux << itr->first << ";" << elm.first << ";\"" << elm.second << "\"" << std::endl;
			}
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Agenda& agenda)
{
	if (agenda.data_.size() == 0) {
		os << "Il n'y a pas de rendez-vous enregist�" << std::endl;
	}
	else {
		int compteur = 1;
		for (auto itr = agenda.data_.begin(); itr != agenda.data_.end(); ++itr) {
			os << '\t' << itr->first;
			for (const std::pair<Heure, std::string>& elm : itr->second) {
				os << "\t\t" << elm.first << "\t" << elm.second << "\t" << compteur << std::endl;
				compteur++;
			}
		}
		os << std::endl;
	}

	return os;
}

