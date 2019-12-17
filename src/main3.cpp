#include <iostream>
#include "DateTime.h"

int main() {
	DateTime dt1(10, 10, 2017);
	DateTime dt2(12, 10, 2017);

	

	std::cout << dt1.getDifference(dt2);
}