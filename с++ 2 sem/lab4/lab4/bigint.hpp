#pragma once
#define BIGINT_HPP
#include <iostream>
#include <string>

using namespace std;

class Bigint
{
private:
	string number;
public:
	Bigint(string s);
	Bigint();
	Bigint(Bigint& other);

	Bigint& operator=(const Bigint& num);
	Bigint& operator+(const Bigint& num);
	void operator+=(const Bigint& other);

	Bigint& operator*(const Bigint& other);
	//Bigint& operator*=(const Bigint& other);
};

