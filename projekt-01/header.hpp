#ifndef header
#define header
#include <string>

	//Menu:
	short readYear();
	short readMonth();
	std::string monthToString(short month);
	short readStartDay();
	bool readBool(std::string text);
	//Zbieranie danych
	short zeller(short day, short month, short year);
	short monthLength(short month, short year);
	short getWeekNr(short month, short year);
	//Wypisywanie na ekran
	void print(const short &month, const short &year, const bool &fill0, const bool &weekNr, short weekDay, const short &daysInMonth);
	//Zapis do pliku
	std::string readPath(short month, short year);
	bool toFile(std::string path, short month, short year, bool fill0, bool weekNr, short weekDay, short daysInMonth);

#endif