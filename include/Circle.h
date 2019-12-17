#ifndef Circle_H
#define Circle_H

class Circle {
private:
	

	double radius;
	double ference;			//circumference
	double area;
	double pi = 3.14;
	

public:
	Circle(){}
	Circle(int radIn);

	void setRadius(double rad);
	void setFerence(double fer);
	void setArea(double ar);
	double getRadius();
	double getFerence();
	double getArea();
};

#endif