#ifndef __ISTRING_H__
#include "istring.h"
#endif
#include <cstring>

#ifndef __IOSTREAM__
#define __IOSTREAM__

#include <iostream>

#endif // __IOSTREAM__


// struct iString{
//   char * chars;
//   unsigned int length;
//   unsigned int capacity;
//   iString();
//   iString(const char *);
//   iString(const iString&);
//   iString &operator=(const iString&);
//   ~iString();
// };

iString::iString(): length(0), capacity(0) {
	chars = NULL;
}

iString::iString(const char *str) {
	length = strlen(str);
	capacity = 1;
	while (capacity < length) {
		capacity *= 2;
	}
	chars = new char[capacity];
	for (int i = 0; i<length; i++) {
		chars[i] = *(str+i);
	}
}

iString::iString(const iString& other) {
	length = other.length;
	capacity = other.capacity;
	chars = new char[capacity];
	for (int i = 0; i<length; i++) {
		chars[i] = other.chars[i];
	}
}

iString& iString::operator=(const iString& rhs) {
	this->length = rhs.length;
	this->capacity = 1;
	while (this->capacity < this->length) {
		this->capacity *= 2;
	}
	if (NULL != this->chars) {
		delete this->chars;
	}
	this->chars = new char[capacity];
	for (int i = 0; i<length; i++) {
		chars[i] = rhs.chars[i];
	}
	return *this;
}

iString& iString::operator=(const char* rhs) {
	this->length = strlen(rhs);
	this->capacity = 1;
	while (this->capacity < this->length) {
		this->capacity *= 2;
	}
	if (NULL != this->chars) {
		delete this->chars;
	}
	this->chars = new char[capacity];
	for (int i = 0; i<length; i++) {
		chars[i] = *(rhs+i);
	}
	return *this;
}

inline iString& operator+(const iString& self, const iString& other) {
	#ifdef DEBUG
	std::cerr << "ohgod" << std::endl;
	#endif // DEBUG
	iString * str = new iString;
	str->length = self.length + other.length;
	while (str->capacity < self.length + other.length) {
		str->capacity *= 2;
	}
	str->chars = new char[str->capacity];
	for (int i = 0; i < self.length; ++i) {
		str->chars[i] = self.chars[i];
	}
	for (int i = 0; i < other.length; ++i){
		str->chars[self.length + i] = other.chars[i];
	}
	return *str;
}

inline iString& operator+(const iString& lhs, const char *rhs){
	iString * str = new iString(rhs);
	*str = lhs+*str;
	return *str;
}

std::ostream &operator<<(std::ostream &out, const iString &c) {
	for (int i = 0; i < c.length; ++i)
	{
		out << c.chars[i];
	}
	return out;
}

std::istream &operator>>(std::istream &in, const iString &c) {
	char * str;
	in >> str;
	return in;
}

iString::~iString(){
	delete[] chars;
}



