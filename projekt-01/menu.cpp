#include <iostream>
#include <string>
#include <limits>
#include "header.hpp"

using namespace std;

short readYear() { //Sczytuje od użytkownika rok dla którego ma być wyświetlony kalendarz, zwraca rok w postaci liczby
	short year;
	cout << "Podaj rok dla którego chcesz wyświetlić kalendarz: ";
	cin >> year;
	while (!cin.good() || year < 1582 || year == 0) {
		if (cin.good() && year == 0) {
			cout << "Przerwa na żądanie użytkownika" << endl;
			exit(1);
		}
		else if (cin.good() && year < 1582) {
			cout << "Przepraszamy, program obsługuje tylko lata od 1582 roku." << endl;
			cout << "Podaj rok, należący do kalendarza gregoriańskiego, dla którego chcesz wyświetlić kalendarz: ";
		}
		else {
			cout << "Podaj PRAWIDŁOWY rok dla którego chcesz wyświetlić kalendarz: ";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> year;
	}
	return year;
}
short readMonth() { //Sczytuje od użytkownika miesiąc dla którego ma być wyświetlony kalendarz, zwraca numer miesiąca w postaci liczby 1-12
	short month = 0;
	do {
		cout << "Dla którego miesiąca chcesz wyświetlić kalendarz?" << endl;
		cout << " [1]Styczeń" << endl;
		cout << " [2]Luty" << endl;
		cout << " [3]Marzec" << endl;
		cout << " [4]Kwiecień" << endl;
		cout << " [5]Maj" << endl;
		cout << " [6]Czerwiec" << endl;
		cout << " [7]Lipiec" << endl;
		cout << " [8]Sierpień" << endl;
		cout << " [9]Wrzesień" << endl;
		cout << "[10]Pa«dziernik" << endl;
		cout << "[11]Listopad" << endl;
		cout << "[12]Grudzień" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> month;
		if (cin.good() && month == 0) {
			cout << "Przerwa na żądanie użytkownika" << endl;
			exit(1);
		}
		if (!cin.good() || month < 1 || month > 12) {
			cout << "To nie jest prawidłowy numer miesiąca. Podaj liczbę z zakresu 1 - 12." << endl;
		}
	} while (month < 1 || month > 12);
	return month;
}
string monthToString(short month) { //Konwertuje numer miesiąca na ciąg znaków; month - numer miesiąca w postaci liczby z zakresu 1-12; zwraca łańcuch znaków zawierający nazwę miesiąca
	switch (month) {
	case 1:
		return "Styczeń";
	case 2:
		return "Luty";
	case 3:
		return "Marzec";
	case 4:
		return "Kwiecień";
	case 5:
		return "Maj";
	case 6:
		return "Czerwiec";
	case 7:
		return "Lipiec";
	case 8:
		return "Sierpień";
	case 9:
		return "Wrzesień";
	case 10:
		return "Pa«dziernik";
	case 11:
		return "Listopad";
	case 12:
		return "Grudzień";
	default:
		return "error";
	}
}

short readStartDay() {  //Sczytuje od użytkownika dzień tygodnia, zwraca numer dnia w tygodniu w postaci liczby 0 - 6, gdzie 0 to poniedziałek, 2 to wtorek, ... , 6 to niedziela. W razie błędnych danych, zwraca 0 (poniedziałek)

	short week = 1;
	cout << endl << "Od jakiego dnia należy zacząć tydzień?" << endl;
	cout << " [[1]Poniedziałek]" << endl;
	cout << " [2]Wtorek" << endl;
	cout << " [3]—roda" << endl;
	cout << " [4]Czwartek" << endl;
	cout << " [5]Piątek" << endl;
	cout << " [6]Sobota" << endl;
	cout << " [7]Niedziela" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> week;
	switch (week) {
	case 1:
		cout << "Początek tygodnia ustawiony na poniedziałek" << endl;
		return 0;
	case 2:
		cout << "Początek tygodnia ustawiony na wtorek" << endl;
		return 1;
	case 3:
		cout << "Początek tygodnia ustawiony na środę" << endl;
		return 2;
	case 4:
		cout << "Początek tygodnia ustawiony na czwartek" << endl;
		return 3;
	case 5:
		cout << "Początek tygodnia ustawiony na piątek" << endl;
		return 4;
	case 6:
		cout << "Początek tygodnia ustawiony na sobotę" << endl;
		return 5;
	case 7:
		cout << "Początek tygodnia ustawiony na niedzielę" << endl;
		return 6;
	}
	cout << "Wprowadzono błędną wartość. Początek tygodnia ustawiony domy?lnie na poniedziałek" << endl;
	return 0;
}

bool readBool(std::string text) { //Sczytuję od użytkownika wartość 0 bąd« 1. Przed żądaniem warto?ci wypisuje text; Zwraca warto?ć podaną przez użytkownika, bąd« 0 w razie błędu
	bool ret;
	cout << text;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> ret;
	if (!cin.good()) {
		cout << "Wprowadzono błędną wartość. Ustawiono domy?lnie jako na nie" << endl;
		return 0;
	}
	return ret;
}