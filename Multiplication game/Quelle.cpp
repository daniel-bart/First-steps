#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;



int main() {
	time_t start_zeit, end_zeit, zeit;
	string name;
	float Anzahl = 0;
	float Multiplikator = 0;
	while (Anzahl == 0) {
		cout << "Wie viele Aufgaben darfs sein?" << endl;
		cin >> Anzahl;
		cin.clear();
		cin.ignore();
		if (cin.fail()) {
			cout << "Bitte eine Zahl eingeben!" << endl;
			Anzahl = 0;
		}

		else if (Anzahl < 0) {
			cout << "Bitte eine positive Zahl eingeben!" << endl;
			Anzahl = 0;
		}

	}
	int Anz = static_cast<int>(Anzahl);
	cout << "Ok, ich werde ihnen " << Anz << " Aufgaben stellen." << endl;
	while (Multiplikator == 0) {
		cout << "Wie hoch soll der maximale Multiplikator der Aufgaben sein?" << endl;
		cin >> Multiplikator;
		cin.clear();
		cin.ignore();
		if (cin.fail()) {
			cout << "Bitte eine Zahl eingeben!" << endl;
			Multiplikator = 0;
		}

		else if (Multiplikator < 0) {
			cout << "Bitte eine positive Zahl eingeben!" << endl;
			Multiplikator = 0;
		}
	}
	int Eingabe[50];
	int Lsg[50];
	int wrongs = 0;
	int   Multi = static_cast<int>(Multiplikator);
	cout << "Ok, " << Multi << " wird der maximale Multiplikator sein." << endl;
	cout << "Viel Erfolg!" << endl;
	time(&start_zeit);
	for (int i = 0; i < Anz; i++) {
		int random1 = rand() % Multi + 1;
		int random2 = rand() % Multi + 1;
		cout << random1 << " * " << random2 << " = ";
		cin >> Eingabe[i];
		Lsg[i] = random1 * random2;
	}
	for (int j = 0; j < Anz; j++) {
		if (Eingabe[j] != Lsg[j]) {
			wrongs++;
		}
		else {
			continue;
		}
	}
	cout << "In deinen Berechnungen befanden sich " << wrongs << " Fehler." << endl;
	time(&end_zeit);
	fstream f;
	cin.clear();
	cin.ignore();
	f.open("Highscore.txt", ios::in | ios::out);
	if (f.fail()) {
		cout << "Fehler beim Lesen der Highscore - Datei." << endl;
		return 0;
	}
	cout << "Wie ist dein Name?" << endl;
	getline(cin, name);
	f << name << " " << wrongs << " Fehler " << "Zeit: " << end_zeit - start_zeit << " Sekunden" << endl;
	cout << "Vielen Dank, " << name << "!" << endl;
	f.close();
	return 0;







}