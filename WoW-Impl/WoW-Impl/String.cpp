#include <iostream>
#include "String.h"
using namespace std;

bool operator==(const String & str1, const String & str2) {
	return	!strcmp(str1.str, str2.str);
}

ostream &operator<<(ostream &os, const String &obj) {
	for (int i = 0; i < obj.len; i++) {
		os << obj.str[i];
	}
	return os;
}

istream &operator>>(istream &is, String &obj) {
	obj.Free();
	obj.str = new char[30];
	is.getline(obj.str, 30);
	obj.len = strlen(obj.str);
	return is;
}

String::String() {
	str = new char[1];
	str[0] = '\0';
	len = 1;

}

String::String(const char *str) {
	len = strlen(str);
	this->str = new char[len + 1];
	strcpy(this->str, str);
}

String operator+(const String &lhs, const String &rhs) {
	String temp(lhs);
	temp += rhs;
	return temp;
}

String::String(const String &other) {
	CopyFrom(other);
}

String &String::operator=(const String &other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

String::~String() {
	Free();
}

void String::CopyFrom(const String &other) {
	str = new char[other.len + 1];
	strcpy(str, other.str);
	len = other.len;
}

void String::Free() {
	delete[] str;
}

String &String::operator+=(const String &other) {
	char *temp = new char[len + other.len + 1];
	for (int i = 0; i < len; i++)
		temp[i] = str[i];
	for (int i = 0; i < other.len; i++)
		temp[len + i] = other.str[i];
	temp[len + other.len] = '\0';
	delete[] str;
	str = temp;
	len += other.len;
	return *this;
}