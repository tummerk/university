#include "bigint.hpp"

Bigint::Bigint() {
	number = "";
}

Bigint::Bigint(string s)
{
	this->number = s;
}

Bigint::Bigint(Bigint& other):Bigint(other.number){}

Bigint& Bigint::operator=(const Bigint& num)
{
	if (this == &num) return *this;
	this->number = num.number;
	return *this;
}

Bigint& Bigint::operator+(const Bigint& other)
{
	Bigint sum;
	string num_max = number;
	string num_min = other.number;
	
	if (num_min.length() > num_max.length()) {
		swap(num_min, num_max);
	}

	reverse(num_min.begin(), num_min.end());
	reverse(num_max.begin(), num_max.end());

	int pred = 0;
	int nw;

	for (int i = 0; i < num_min.length();i++){
		//cout << i << "\n";
		nw = (int)num_min[i] + (int)num_max[i]+pred-96;
		//cout << nw;
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
	reverse(sum.number.begin(), sum.number.end());
	cout << sum.number;
	return sum;
}


void Bigint::operator+=(const Bigint& other)
{
	*this = *this + other;
}

Bigint& Bigint::operator*(const Bigint& other)
{
	Bigint mult;
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
		cout << zers << "\n";
		iter.number = iter.number+ zers;

		mult += iter;
		zers += "0";
	}
	cout << mult.number;
	return mult;
};
