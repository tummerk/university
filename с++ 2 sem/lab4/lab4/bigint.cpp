#include "bigint.hpp"

bool Bigint::isBigger(const Bigint& other)
{

	if (number.length() > other.number.length())
		return true;
	if (number.length() < other.number.length())
		return false;
	for (int i = number.length(); i > 0; i--) {
		if ((int)number[i] > (int)other.number[i])
			return true;
		if ((int)number[i] < (int)other.number[i])
			return false;
	}
	return false;
};


Bigint::Bigint() {
	number = "";
	sign = 1;
}

Bigint::Bigint(string s)
{
	if (s[0] == '-') {
		sign = -1;
		s.erase(0, 1);
	}
	else
	{
		sign = 1;
	}
	number = s;
}

Bigint::Bigint(Bigint& other):Bigint(other.number){}


Bigint& Bigint::operator=(const Bigint& num)
{
	if (this == &num) return *this;
	sign = num.sign;
	this->number = num.number;
	return *this;
}

Bigint Bigint::operator+(const Bigint& other)
{
	Bigint sum;
	if (this->isBigger(other)) {
		sum.sign = sign;
	}
	else {
		sum.sign = other.sign;
	}

	
	string num_max;
	string num_min;
	if (this->isBigger(other)) {
		num_max = this->number;
		num_min = other.number;
	}
	else {
		num_min = this->number;
		num_max = other.number;
	}

	reverse(num_min.begin(), num_min.end());
	reverse(num_max.begin(), num_max.end());

	int pred = 0;
	int nw;

	if (sign == other.sign){
		for (int i = 0; i < num_min.length(); i++) {
			nw = (int)num_min[i] + (int)num_max[i] + pred - 96;
			pred = nw / 10;
			sum.number += (char)(nw % 10 + 48);
		}

		for (int i = num_min.length(); i < num_max.length(); i++) {
			nw = (int)num_max[i] + pred - 48;
			pred = nw / 10;
			sum.number += (char)(nw % 10 + 48);
		}
		if (pred != 0)
			sum.number += (char)(pred + 48);
		
	}
	else {
		for (int i = 0; i < num_min.length(); i++) {
			if (num_max[i] < num_min[i] + pred) {
				sum.number += num_max[i] + 10 - num_min[i] - pred+48;
				pred = 1;
			}
			else {
				sum.number += num_max[i] - num_min[i]-pred + 48;
				pred = 0;
			}
		}
		for (int i = num_min.length(); i < num_max.length(); i++) {
			if (num_max[i] < pred) {
				sum.number += num_max[i] + 10- pred ;
				pred = 1;
			}
			else {
				sum.number += num_max[i] - pred;
				pred = 0;
			}
		}
	}
	reverse(sum.number.begin(), sum.number.end());
	cout << sum;
	return sum;
}

void Bigint::operator+=(const Bigint& other)
{
	*this = *this + other;
}

Bigint Bigint::operator*(const Bigint& other)
{
	Bigint mult("0");
	mult.sign = sign * other.sign;
	string num_max = number;
	string num_min = other.number;

	if (num_min.length() > num_max.length()) {
		swap(num_min, num_max);
	}

	reverse(num_min.begin(), num_min.end());
	reverse(num_max.begin(), num_max.end());

	Bigint iter;
	int pred = 0;
	int nw = 0;
	string zers = "";
	for (int i = 0; i < num_min.length(); i++) {

		iter.number.clear(); 
		pred = 0;

		for (int j = 0; j < num_max.length(); j++) {
			nw = (int)(num_min[i] - 48)* (int)(num_max[j] - 48)+pred;
			pred = nw / 10;
			iter.number += (char)(nw % 10 + 48);
		}
		
		reverse(iter.number.begin(),iter.number.end());	
		iter.number = iter.number+zers;
	
		mult=mult+iter;
		
		zers += "0";
	}

	return mult;	
}

void Bigint::operator*=(const Bigint& other)
{
	*this = *this * other;
}

bool Bigint::operator==(const Bigint& other)
{
	if (number.length() != other.number.length())
		return false;
	for (int i = 0; i < number.length(); i++) {
		if (number[i] != other.number[i])
			return false;
	}
	return true;
}
bool Bigint::operator!=(const Bigint& other)
{
	return !(this == &other);
}

bool Bigint::operator>(const Bigint& other)
{
	if (number.length() > other.number.length())
		return true;
	if (number.length() < other.number.length())
		return false;
	for (int i = number.length(); i > 0; i--) {
		if ((int)number[i] > (int)other.number[i])
			return true;
		if ((int)number[i] < (int)other.number[i])
			return false;
	}
	return false;
}

bool Bigint::operator<(const Bigint& other)
{
	if (this == &other)
		return false;
	return !(this > &other);
};

ostream& operator<<(ostream& out, const Bigint& num)
{
	if (num.sign == -1)
		out << '-';
	out << num.number;
	return out;
}

istream& operator>>(istream& in, Bigint& num)
{
	string input;
	in >> input;
	if (input[0] == '-') {
		num.sign = -1;
		input.erase(0, 1);
	}
	else
	{
		num.sign = 1;
	}
	num.number = input;
	return in;	
}
