#pragma once
#define BIGINT_HPP
#include <iostream>
#include <string>

using namespace std;

class Bigint
{
private:
	string number;
	int sign;
public:
	Bigint(string s);
	Bigint();
	Bigint(Bigint& other);

	bool isBigger(const Bigint& other);

	Bigint& operator=(const Bigint& num);
	Bigint operator+(const Bigint& num);
	void operator+=(const Bigint& other);

	Bigint operator*(const Bigint& other);
	void operator*=(const Bigint& other);

	bool operator==(const Bigint& other);
	bool operator!=(const Bigint& other);
	bool operator>(const Bigint& other);
	bool operator<(const Bigint& other);

	friend ostream& operator<<(ostream& out, const Bigint& num);
	friend istream& operator>>(istream& in, Bigint& num);
};

