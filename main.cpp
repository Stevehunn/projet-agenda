#include <iostream>
#include "include/Agenda.h"
using std::cin;
using std::cout;
using std::endl;

int ajouter() {
    std::string date;
    std::string heure;
    std::string note;
    cout << endl;
    cout << "Ajouter un rendez-vous" << endl;
    cout << "Date (jj/mm/aaaa) : ";
    cin >> date;
    cout << "Heure (hh:mm) : ";
    cin >> heure;
    cout << "Note : ";
    cin >> note;
    // TODO
    for (;;) {
        char choix = 0;
        cout << "Ajouter un autre rendez-vous (O/N) : ";
        cin >> choix;
        switch (choix) {
        case 'O': case 'o':
            ajouter();
            break;
        case 'N': case 'n':
            return 0;
        default:
            cout << "Choix inconnu" << endl;
            continue;
        }
    }
    return 0;
}

int lister() {
    //afficher();
    return 0;
}

void afficher() {
    cout << "Liste des rendez-vous" << endl;
// TODO
    cout << endl;
}

void reporterAvancer() {
    //afficher();
    int nombre;
    cout << "Ajouter un nombre positif pour reporter le rendez-vous et un nombre négatif pour avancer le rendez-vous " << endl;
    if (nombre = 0) {
        cout << "Nombre invalide, veuillez rééssayer" << endl;
        //reporterAvancer();
    }
    else if (nombre > 0) {
        cout << "le rendez-vous sera reporté de " << nombre << " jours" << endl;
        // reporter(,,nombre);
    }
    else if (nombre < 0) {
        cout << "le rendez-vous sera avancé de " << nombre << " jours" << endl;
        // avancer(,,nombre);
    }
}

void modifierHeure() {
    int rdv = 0;
    afficher();
    cout << "Selectionner le numéro du rendez-vous pour modifier l'heure" << endl;
    cin >> rdv;
    std::string heure;
    cout << endl;
    cout << "Modifier l'heure de rendez-vous" << endl;
    cout << "Heure (hh:mm) : ";
    cin >> heure;
    //modifier(,Heure);
    cout << "Modification de l'heure du rendez-vous effectue" << endl;

}

void supprimer() {
    int rdv = 0;
    afficher();
    cout << "Selectionner le numéro du rendez-vous que vous souhaitez supprimer" << endl;
    cin >> rdv;
    // TODO
    afficher();
}

void enregisterAgenda() {
    std::string fichier = "agenda.txt";
    cout << endl;
    cout << "L'agenda va être enregistrer dans le fichier agenda.txt" << endl;
    //mon.enregistrer(fichier);
}

void charger() {
    std::string fichier = "agenda.txt";
    cout << endl;
    cout << "L'agenda va être charger depuis le fichier agenda.txt" << endl;
    //ouvrir(fichier);

}

int rechercheDate() {
    //TODO
    return 0;
}

int rechercherMot() {
    //TODO
    return 0;
}


void rechercher() {
    char choix = 0;
    cout << "Comment voulez vous trier les rendez vous ? Par date [1] / Par mot clé [2]: ";
    cin >> choix;
    switch (choix) {
    case '1':
        rechercheDate();
        break;
    case '2':
        rechercherMot();
        break;
    default:
        cout << "Choix inconnu" << endl;
        break;
    }
}

int main(){
    Agenda monAgenda;
    int choix = 0;
    for (;;) {
        cout << endl;
        cout << "Agenda" << endl;
        cout << "1. Ajouter un rendez-vous" << endl;
        cout << "2. Lister tous les rendez-vous" << endl;
        cout << "3. reporter/avancer un rendez-vous" << endl;
        cout << "4. modifier l'heure d'un rendez-vous" << endl;
        cout << "5. supprimer un rendez-vous" << endl;
        cout << "6. enregistrer l'agenda dans un fichier texte" << endl;
        cout << "7. charger l'agenda à partir d'un fichier texte" << endl;
        cout << "8. rechercher les rendez-vous par une date/mot clé " << endl;
        cout << "9. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        switch (choix) {
        case 1:
            ajouter();
            break;
        case 2:
            lister();
            break;
        case 3:
            reporterAvancer();
            break;
        case 4:
            modifierHeure();
            break;
        case 5:
            supprimer();
            break;
        case 6:
            enregisterAgenda();
            break;
        case 7:
            charger();
            break;
        case 8:
            rechercher();
            break;
        case 9:
            return 0;
        default:
            cout << "Choix inconnu" << endl;
            continue;
        }
    }
    return 0;
}

