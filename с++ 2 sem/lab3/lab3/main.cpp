#include <iostream>

class conus {
	private:
		double pi = 3.1415;
		double height;
		double radius;
	
	public:
		conus(double heigth, double radius) {
			this->height = heigth;
			this->radius = radius;
		}
		double volume() {
			return (1.0 / 3.0) * this->pi * std::pow(this->radius, 2) * height;
		}
		double area() {
			return pi * this->radius * (this->radius + 
			std::pow((std::pow(this->radius, 2)+ std::pow(this->height, 2)),0.5));
		}
};
void main() {
	conus cns(4, 3);
	std::cout << cns.area();
}