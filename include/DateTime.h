#ifndef DateTime_H
#define DateTime_H
#include <iostream>
//#include <string>

class DateTime {
private:
	int innerDay;
	int innerMonth;
	int innerYear;

	std::string *week = new std::string[7] {
		"sunday",
		"monday",
		"tuesday",
		"wednesday",
		"thursday",
		"friday",
		"saturday"		
	};

	std::string *month = new std::string[12] {
			"january",
			"february",
			"march",
			"april",
			"may",
			"june",
			"july",
			"august",
			"september",
			"october",
			"november",
			"december"
	};

	//std::string *stringDate;
	
public:
	DateTime(){}
	DateTime(int day, int month, int year);
	DateTime(const DateTime &toCopy);
	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(unsigned int N);
	std::string getPast(unsigned int N);
	int getDifference(DateTime&);
	
};

#endif