#include "..\include\Agenda.h"

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

void Agenda::avancer(const Date& d, const Heure& h, int n)
{
}

void Agenda::modifer(const Date& d, const Heure& h)
{
}

void Agenda::reporter(const Date& d, const Heure& h, int n)
{
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
}

void Agenda::enregistrer(const char* fichier)
{
}
