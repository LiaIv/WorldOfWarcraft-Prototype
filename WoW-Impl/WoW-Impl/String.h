#pragma once
#include <iostream>
using namespace std;

class String {
private:
	char *str;
	int len;

	void CopyFrom(const String &other);

	void Free();

public:
	String();

	String(const char *str);

	String(const String &other);

	String &operator=(const String &other);

	~String();

	String &operator+=(const String &other);

	friend bool operator==(const String &str1, const String &str2);

	friend ostream &operator<<(ostream &os, const String &obj);

	friend istream &operator>>(istream &is, String &obj);
};

