#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include "DateTime.h"

DateTime::DateTime(int dayIn, int monthIn, int yearIn) {
	/*int day = dayIn;
	int month = monthIn;
	int year = yearIn;*/
	innerDay = dayIn;
	innerMonth = monthIn;
	innerYear = yearIn;
}

DateTime::DateTime(const DateTime &toCopy) {
	innerDay = toCopy.innerDay;
	innerMonth = toCopy.innerMonth;
	innerYear = toCopy.innerYear;
}

std::string DateTime::getToday() {
	tm cur;
	time_t _curt;
	time(&_curt);
	cur = *localtime(&_curt);
	std::string _str = "";
	std::string _day = "";
	if (cur.tm_mday < 10) {
		_day += "0";
	}
	_str += _day + std::to_string(cur.tm_mday) + " " + month[cur.tm_mon] + " " + std::to_string(cur.tm_year + 1900) + ", " + week[cur.tm_wday - 1];
	return _str;

}

std::string DateTime::getYesterday() {
	tm cur;
	time_t _curt;
	time(&_curt);
	_curt -= 86400;
	cur = *localtime(&_curt);
	std::string _str = "";
	std::string _day = "";
	if (cur.tm_mday < 10) {
		_day += "0";
	}
	_str += _day + std::to_string(cur.tm_mday) + " " + month[cur.tm_mon] + " " + std::to_string(cur.tm_year + 1900) + ", " + week[cur.tm_wday - 1];
	return _str;

}

std::string DateTime::getTomorrow() {
	tm cur;
	time_t _curt;
	time(&_curt);
	_curt += 86400;
	cur = *localtime(&_curt);
	std::string _str = "";
	std::string _day = "";
	if (cur.tm_mday < 10) {
		_day += "0";
	}
	_str += _day + std::to_string(cur.tm_mday) + " " + month[cur.tm_mon] + " " + std::to_string(cur.tm_year + 1900) + ", " + week[cur.tm_wday - 1];
	return _str;

}

std::string DateTime::getFuture(unsigned int N) {
	tm cur;
	time_t _curt;
	time(&_curt);
	_curt += 86400 * N;
	cur = *localtime(&_curt);
	std::string _str = "";
	std::string _day = "";
	if (cur.tm_mday < 10) {
		_day += "0";
	}
	_str += _day + std::to_string(cur.tm_mday) + " " + month[cur.tm_mon] + " " + std::to_string(cur.tm_year + 1900) + ", " + week[cur.tm_wday - 1];
	return _str;

}

std::string DateTime::getPast(unsigned int N) {
	tm cur;
	time_t _curt;
	time(&_curt);
	_curt -= 86400 * N;
	cur = *localtime(&_curt);
	std::string _str = "";
	std::string _day = "";
	if (cur.tm_mday < 10) {
		_day += "0";
	}
	_str += _day + std::to_string(cur.tm_mday) + " " + month[cur.tm_mon] + " " + std::to_string(cur.tm_year + 1900) + ", " + week[cur.tm_wday];
	return _str;

}

int DateTime::getDifference(DateTime& given) {
	tm cur;
	/*time_t _curt;
	time(&_curt);
	cur = *localtime(&_curt);*/

	cur.tm_mday = innerDay;
	cur.tm_mon = innerMonth;
	cur.tm_year = innerYear - 1900;
	cur.tm_hour = 0;
	cur.tm_min = 0;
	cur.tm_sec = 0;
	cur.tm_isdst = 0;

	tm giv;
	giv.tm_mday = given.innerDay;
	giv.tm_mon = given.innerMonth;
	giv.tm_year = given.innerYear - 1900;
	giv.tm_hour = 0;
	giv.tm_min = 0;
	giv.tm_sec = 0;
	giv.tm_isdst = 0;

	//std::cout << mktime(&cur) << std::endl << mktime(&giv) << std::endl;

	//unsigned int _diff;
	return abs(mktime(&cur) - mktime(&giv)) / 86400;			// WHY 356 ???
}