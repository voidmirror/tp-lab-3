#include <iostream>
#include "Circle.h"
#include "task1.h"

double calcDelta() {
	double circum = 6378.1;
	double zazor = 1;			// meters

	Circle normal(circum);
	//normal.setFerence(circum);
	Circle big(circum);
	big.setFerence(big.getFerence() + zazor);

	//std::cout << big.getArea() << " " << normal.getArea() << std::endl;
	double ret = big.getRadius() - normal.getRadius();

	return trunc((big.getRadius() - normal.getRadius())*1000)/1000;


}

double calcCost() {
	Circle pool(3);
	Circle path(pool.getRadius() + 1);
	int concrete = 1000;
	int fence = 2000;
	
	return (path.getArea() - pool.getArea()) * concrete + path.getFerence() * fence;
}