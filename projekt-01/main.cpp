// Projekt nr 1
// Kalendarzator 1.01
// Autor: Piotr Uhl

#include <iostream>
#include <string>
#include <conio.h>
#include "header.hpp"

using namespace std;

int main() {

	//Wprowadzanie daty
	short year = readYear(); //rok dla kt¢rego zostanie wy˜wietlony kalendarz
	short month = readMonth(); //numer miesi¥ca dla kt¢rego zostanie wy˜wietlony kalendarz w postaci liczby 1-12

	cout << "Wy˜wietlony zostanie kalendarz dla miesi¥ca " << monthToString(month) << " roku " << year << "." << endl;

	//Ustawienia
	short startDay = readStartDay(); //pierwszy dzieä tygodnia, 0 - pn, 1 - wt, 6 - nd, domy˜lnie poniedziaˆek
	bool fill0 = readBool("Czy uzupeˆnia† liczby jednocyfrowe zerami? [[0 - nie], 1 - tak]\n"); //czy uzupeˆnia† jednocyfrowe liczby zerami
	bool weekNr = 0;
	if (startDay) {
		cout << "Numerowanie tygodni dost©pne jest tylko w przypadku tygodni zaczynaj¥cych si© od poniedziaˆku ze wzgl©du na zgodno˜† z norm¥ ISO 8601" << endl;
	}
	else
		weekNr = readBool("Czy numerowa† tygodnie? [[0 - nie], 1 - tak]\n"); //czy numerowa† tygodnie

	//Zbieranie informacji
	short weekDay = zeller(1, month, year); //dzieä tygodnia pierwszego dnia w miesi¥cu
	short daysInMonth = monthLength(month, year); //ilo˜† dni w danym miesi¥cu

	//Wy˜wietlanie
	print(month, year, fill0, weekNr, weekDay, daysInMonth);

	//Zapis do pliku
	if (readBool("Czy chcesz zapisa† wygenerowany kalendarz do pliku? [[0 - nie], 1 - tak]\n")) {
		toFile(readPath(month, year), month, year, fill0, weekNr, weekDay, daysInMonth);
	}

	cout << "Naci˜nij dowolny klawisz, aby kontunuowa†...";
	_getch();
	cout << endl;
	return 0;
}