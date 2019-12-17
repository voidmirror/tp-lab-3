#include <iostream>
#include <string>
#include "DateTime.h"

int main() {
	DateTime dt1(10, 10, 2017);
	DateTime dt2(12, 10, 2017);

	std::cout << dt1.getPast(5);
	std::cout << std::endl;

	std::cout << dt1.getYesterday();
	std::cout << std::endl;

	std::cout << dt1.getToday();
	std::cout << std::endl;

	std::cout << dt1.getTomorrow();
	std::cout << std::endl;

	std::cout << dt1.getFuture(5);
	std::cout << std::endl;

	std::cout << dt1.getDifference(dt2);
}