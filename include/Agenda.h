#ifndef AGENDA_H
#define AGENDA_H

#include <map>
#include <string>
#include "Date.h"
#include "Heure.h"

class Agenda {
public:
    Agenda() = default;
    virtual ~Agenda() = default;
    void ajouter(const Date &d, const Heure &h, const std::string &note);
    void avancer(const Date &d, const Heure &h, int n);
    void modifer(const Date &d, const Heure &h);
    void reporter(const Date &d, const Heure &h, int n);
    void supprimer(const Date &d, const Heure &h);
    void ouvrir(const char *fichier); // Charger l'agenda � partir du fichier
    void enregistrer(const char *fichier); // Sauvegarder l'agenda dans un fichier
protected:
private:
    std::map<Date, std::map<Heure, std::string>> data_;
};

#endif // AGENDA_H