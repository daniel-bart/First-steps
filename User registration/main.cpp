#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Benutzer {
public:
	string name;
	int alter = 0;
	string email;
};
size_t findCaseInsensitive(string data, string toSearch, size_t pos = 0)
{
	// Convert complete given String to lower case
	transform(data.begin(), data.end(), data.begin(), ::tolower);
	// Convert complete given Sub String to lower case
	transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
	// Find sub string in given string
	return data.find(toSearch, pos);
}
void Datenabfrage() {
	char Korrektur;
	Benutzer neu;
	while (true) {
		char &Korreingabe = Korrektur;
		system("cls");
		cout << "Bitte geben Sie die nachfolgenden Daten des neuen Benutzers an.\n";
		cout << "Name:";
		cin.ignore();
		getline(cin, neu.name);
		cout << "\nAlter:";
		cin >> neu.alter;
		cout << "\nE-Mail:";
		cin.ignore();
		getline(cin, neu.email);
		system("cls");
		cout << "Folgende Daten wurden angegeben:\n";
		cout << "Name: " << neu.name << "\nAlter: " << neu.alter << "\nE-Mail: " << neu.email;
		cout << "\nSind diese Daten korrekt? (y/n)";
		cin >> Korreingabe;
		if (Korreingabe == 'y') {
			cout << "\nDaten werden gespeichert ...";
			Sleep(2000);
			break;
		}
		else if (Korreingabe == 'n') {
			cout << "\nDaten werden verworfen, Neustart der Dateneingabe ...";
			Sleep(2000);
			continue;
		}
		else {
			cout << "\nFalscheingabe, Neustart ...";
			Sleep(2000);
			continue;
		}
	}
	if (Korrektur == 'y') {
		ofstream Benutzerdaten("daten.txt", ios_base::app);
		Benutzerdaten << "\n" << neu.name << " " << neu.alter << " " << neu.email;
		Benutzerdaten.close();
		cout << "\nDaten erfolgreich gespeichert!";
	}

}
void Eintragsabfrage() {
	string suche;
	string eintraege;
	cout << "\nNach welchem Benutzer möchten Sie suchen?\n";
	cin.ignore();
	getline(cin, suche);
	cout << "Suche nach: " << suche << " gestartet!\n";
	cout << "Folgende Einträge wurden gefunden:\n";
	ifstream Benutzerdaten("daten.txt");
	while (Benutzerdaten) {
		getline(Benutzerdaten, eintraege);
		if (findCaseInsensitive(eintraege, suche) != string::npos) {
			cout << "\n" << eintraege;
			continue;
		}
		else {
			continue;
		}
	}
	Benutzerdaten.close();
	Sleep(10000);
}
int main(){
	int Wahl = 0;
		while (true) {
			int &Eingabe = Wahl;
			system("cls");
			cout << "Herzlich Willkommen zur automatisierten Registrierung!\n";
			cout << "Bitte Wählen Sie zwischen Benutzer registrieren (1) oder Benutzer suchen (2)!\n";
			cin >> Eingabe;
			if (Eingabe == 1) {
				system("cls");
				cout << "Sie haben Benutzer registrieren gewählt.\nBitte warten ...";
				Sleep(2000);
				break;
			}
			else if (Eingabe == 2) {
				system("cls");
				cout << "Sie haben Benutzer suchen gewählt.\nBitte warten ...";
				Sleep(2000);
				break;
			}
			else {
				system("cls");
				cout << "Ungültige Eingabe!\nNeustart des Programms eingeleitet ...";
				Sleep(2000);
				continue;
			}
		}
	switch (Wahl)
	{
	case 1:
		char weitere;
		while (true) {
			Datenabfrage();
			system("cls");
			cout << "Möchten sie weitere Benutzer eintragen? (y/n)\n";
			cin >> weitere;
			if (weitere == 'n') {
				cout << "Ok, bye!";
				break;
			}
			else {
				cout << "Neustart des Registrierungsprozesses.\n";
				Sleep(2000);
				continue;
			}
		}
		break;
	case 2:
		char fund;
		while (true) {
			Eintragsabfrage();
			cout << "\nFündig geworden? (y/n)\n";
			cin >> fund;
			if (fund == 'y') {
				cout << "Bye!";
				break;
			}
			else {
				cout << "Neustart der Suche!\n";
				Sleep(2000);
				continue;
			}
		}
		break;
	default:
		break;
	}
}