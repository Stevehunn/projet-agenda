#ifndef AGANDA_H
#define AGANDA_H

#include <map>
#include <string>
#include "Date.h"
#include "Heure.h"

class Aganda {
public:
    Aganda();
    virtual ~Aganda();
    void ajouter(const Date &d, const Heure &h, const std::string &note);
    void avancer(const Date &d, const Heure &h, int n);
    void modifer(const Date &d, const Heure &h);
    void reporter(const Date &d, const Heure &h, int n);
    void supprimer(const Date &d, const Heure &h);
    void ouvrir(const char *fichier); // Charger l'agenda à partir du fichier
    void enregistrer(const char *fichier); // Sauvegarder l'agenda dans un fichier
protected:
private:
    std::map<Date, std::map<Heure, std::string>> data_;
};

#endif // AGANDA_H
