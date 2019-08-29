#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <fstream>
#include "header.hpp"

using namespace std;

void print(const short &month, const short &year, const bool &fill0, const bool &weekNr, short weekDay, const short &daysInMonth) { //wypisuje na ekran kalendarz dla danego miesi¥ca

	cout << "        " << monthToString(month) << " " << year << endl; //wypisanie daty nad kalendarzem

	if (fill0) //uzupeˆnianie liczb zerami, je¾eli tak wybraˆ u¾ytkownik
		cout.fill('0');
	cout << "  ____________________________" << endl << "  |" << endl; //g¢rna kreska

	for (short i = 0, k = 1; i < 11; i++) { //p©tla dla wierszy
		if (i % 2 && k <= daysInMonth) //co drugi wiersz pusty
			cout << "  |" << endl; //lewa pionowa kreska
		else {
			for (short j = -1; j < 7 && k <= daysInMonth; j++) { //p©tla dla kolumn
				for (; weekDay >= 0; weekDay--, j++) { //przesuni©cie pocz¥tku miesi¥ca do odpowiedniego dnia tygodnia
					if (j == -1) { //lewa pionowa kreska
						if (weekNr) {
							cout.width(2);
							cout << getWeekNr(month, year) << "| ";
						}
						else
							cout << "  | ";
					}
					else {
						cout << "    "; //puste dla przesuni©cia
					}
				}
				if (j == -1) { //lewa pionowa kreska
					if (weekNr) {
						cout.width(2);
						cout << getWeekNr(month, year) + (i / 2) << "| ";
					}
					else
						cout << "  | ";
				}
				else { //wypisanie dnia
					cout.width(2);
					cout << k++ << "  ";
				}
			}
			cout << endl;
		}
	}
	cout << endl;
}

string readPath(short month, short year) { //Sczytuje od u¾ytkownika ˜cie¾k© w jakiej nale¾y zapisa† kalendarz. W przypadku pozostawienia pustego, zwracana jest ˜cie¾ka domy˜lna

	string path = "";
	cout << "Podaj nazw© pliku\n[domy˜lnie\"" << monthToString(month) << year << ".txt\"]" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, path);
	if (path == "") {
		stringstream str;
		str << monthToString(month) << year << ".txt";
		path = str.str();
	}
	return path;
}

bool toFile(string path, short month, short year, bool fill0, bool weekNr, short weekDay, short daysInMonth) {//zapisuje do pliku o nazwie "path" kalendarz dla danego miesi¥ca, zwraca false w razie bˆ©du
	ofstream file;
	file.open(path);
	if (!file.is_open()) {
		cout << "Bˆ¥d zapisu do pliku \"" << path << "\". Plik mo¾e by† u¾ywany przez innego u¾ytkownika lub program" << endl;
		return 0;
	}
	file << "        " << monthToString(month) << " " << year << endl; //wypisanie daty nad kalendarzem

	if (fill0) //uzupeˆnianie liczb zerami, je¾eli tak wybraˆ u¾ytkownik
		file.fill('0');
	file << "  ____________________________" << endl << "  |" << endl; //g¢rna kreska

	for (short i = 0, k = 1; i < 11; i++) { //p©tla dla wierszy
		if (i % 2 && k <= daysInMonth) //co drugi wiersz pusty
			file << "  |" << endl; //lewa pionowa kreska
		else {
			for (short j = -1; j < 7 && k <= daysInMonth; j++) { //p©tla dla kolumn
				for (; weekDay >= 0; weekDay--, j++) { //przesuni©cie pocz¥tku miesi¥ca do odpowiedniego dnia tygodnia
					if (j == -1) { //lewa pionowa kreska
						if (weekNr) {
							file.width(2);
							file << getWeekNr(month, year) << "| ";
						}
						else
							file << "  | ";
					}
					else {
						file << "    "; //puste dla przesuni©cia
					}
				}
				if (j == -1) { //lewa pionowa kreska
					if (weekNr) {
						file.width(2);
						file << getWeekNr(month, year) + (i / 2) << "| ";
					}
					else
						file << "  | ";
				}
				else { //wypisanie dnia
					file.width(2);
					file << k++ << "  ";
				}
			}
			file << endl;
		}
	}
	cout << "Zapisano kalendarz do pliku \"" << path << "\"." << endl;
	file.close();
	return 1;
}