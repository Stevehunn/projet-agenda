#include <iostream>
#include "include/Agenda.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int rechercheDate() {
	//TODO
	return 0;
}

int rechercherMot() {
	//TODO
	return 0;
}

Date selectionDate() {
	Date rdvDate;
	cout << "Selectionner la date du rendez-vous que vous souhaitez ajouter avec le format suivant (aaaa/mm/jj)" << endl;
	cin >> rdvDate;
	return rdvDate;
}

Heure selectionHeure() {
	Heure rdvHeure;
	cout << "Selectionner l'heure du rendez-vous que vous souhaitez ajouter avec le format suivant (hh:mm)" << endl;
	cin >> rdvHeure;
	return rdvHeure;
}

int main() {
	Agenda monAgenda;
	int choix = 0;
	int choix2 = 0;
	int nombre = 0;
	int numero = 0;
	string rdvNote;
	Heure heure;
	for (;;) {
		cout << endl;
		cout << "Agenda" << endl;
		cout << "1. Ajouter un rendez-vous" << endl;
		cout << "2. Lister tous les rendez-vous" << endl;
		cout << "3. reporter/avancer un rendez-vous" << endl;
		cout << "4. modifier l'heure d'un rendez-vous" << endl;
		cout << "5. supprimer un rendez-vous" << endl;
		cout << "6. enregistrer l'agenda dans un fichier texte" << endl;
		cout << "7. charger l'agenda � partir d'un fichier texte" << endl;
		cout << "8. rechercher les rendez-vous par une date/mot cl�/num�ro " << endl;
		cout << "9. Quitter" << endl;
		cout << "Votre choix : ";
		cin >> choix;
		switch (choix) {
		case 1:
			cout << "Ajouter une note du rendez-vous" << endl;
			cin.clear(); // clear the buffer
			cin.sync();
			cin.ignore();
			std::getline(cin, rdvNote);// >> rdvNote;
			cout << endl;
			monAgenda.ajouter(selectionDate(), selectionHeure(), rdvNote);
			break;
		case 2:
			cout << monAgenda;
			break;
		case 3:
			cout << monAgenda;
			cout << "Ajouter un nombre positif pour reporter le rendez-vous et un nombre n�gatif pour avancer le rendez-vous " << endl;
			cin >> nombre;
			if (nombre == 0) {
				cout << "Nombre invalide, veuillez r��ssayer" << endl;
				break;
			}
			else if (nombre > 0) {
				cout << "le rendez-vous sera report� de " << nombre << " jours" << endl;
				monAgenda.reporter(selectionDate(), selectionHeure(), nombre);
			}
			else if (nombre < 0) {
				cout << "le rendez-vous sera avanc� de " << nombre << " jours" << endl;
				monAgenda.avancer(selectionDate(), selectionHeure(), nombre);
			}
			break;
		case 4:
			cout << "Modifier l'heure de rendez-vous" << endl;
			cout << "Heure (hh:mm) : ";
			cin >> heure;
			monAgenda.modifier(selectionDate(), selectionHeure(), heure);
			break;
		case 5:
			cout << monAgenda;
			monAgenda.supprimer(selectionDate(), selectionHeure());
			break;
		case 6:
			cout << "L'agenda va �tre enregistrer dans le fichier agenda.txt" << endl;
			monAgenda.enregistrer("agenda.txt");
			break;
		case 7:
			cout << "L'agenda va �tre charger depuis le fichier agenda.txt" << endl;
			monAgenda.ouvrir("agenda.txt");
			break;
		case 8:
			cout << "Comment voulez vous trier les rendez vous ? Par date [1] / Par mot cl� [2] / Par num�ro de rendez-vous [3]: ";
			cin >> choix2;
			switch (choix2) {
			case '1':
				rechercheDate();
				break;
			case '2':
				rechercherMot();
				break;
			case '3':
				cout << "Ajouter le num�ro de rendez-vous" << endl;
				cin >> numero;
				monAgenda.afficher(numero);
				break;
			default:
				cout << "Choix inconnu" << endl;
				break;
			}
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