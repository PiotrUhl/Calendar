#include <iostream>
#include "header.hpp"

short zeller(short day, short month, short year) { //zwraca dzieä tygodnia podanej daty, 0-pn, 1-wt, ... , 6-nd

	short ret = ((day += month < 3 ? year-- : year - 2, 23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7);
	ret = (ret == 0) ? 7 : ret;
	return ret - 1;
}

short monthLength(short month, short year) { //zwraca ilo˜† dni w danym miesi¥cu
	if (month == 2) {
		if (!(year % 4) && (year % 100))
			return 29;
		if (!(year % 400))
			return 29;
		return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
}

short getWeekNr(short month, short year) { //zwraca numer tygodnia w roku dla pierwszego tygodnia danego miesi¥ca (month) w danym roku (year)
	short days = 0; //suma ilo˜ci dni poprzednich miesi©cy
	short jan1 = zeller(1, 1, year); //dzieä tygodnia stycznia danego roku

	if (month == 1) { //je¾eli styczeä
		if (jan1 <= 3) //zgodnie z ISO 8601, je¾eli pierwszy tydzieä stycznia ma conajmniej cztery dni, jest pierwszym tygodniem roku
			return 1;
		else { //zgodnie z ISO 8601, je¾eli pierwszy tydzieä stycznia ma mniej cztery dni, liczy si© jako cz©˜† ostatniego tygodnia poprzedniego roku
			if (zeller(1, 12, year - 1) <= 4)
				return getWeekNr(12, year - 1) + 4;
			else
				return getWeekNr(12, year - 1) + 5;
		}
	}
	for (short i = 1; i < month; i++) { //sumowanie ilo˜ci dni poprzednich miesi©cy
		days += monthLength(i, year);
	}
	if (jan1 <= 3)
		days += jan1;
	else {
		if (jan1 == 4)
			days -= 3;
		else if (jan1 == 5)
			days -= 2;
		else
			days -= 1;
	}
	if (!zeller(1, month, year)) { //korekta dla miesi©cy zaczynaj¥cych si© od poniedziaˆku
		return ((--days / 7) + 2);
	}
	return ((--days / 7) + 1);
}