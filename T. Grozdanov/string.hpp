#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>
class String
{
private:
	char *str;
	int length;
	int capacity;
	void copy(const char*);
	void copy(const String&);
public:
	String();
	String(const char*);
	String(const String&);
	String& operator =(const String&);
	String& operator =(const char*);
	bool operator ==(const String&);
	bool operator !=(const String&);
	bool operator >(const String&);
	bool operator <(const String&);
	String& operator += (const String&);
	String& operator += (const char *);
	String& operator += (char);
	char& operator [] (int);

	int get_len();
	int get_capacity();
	void nullstring();

	friend std::istream& operator >> (std::istream&, String&);
	friend std::ostream& operator << (std::ostream&, const String&);

	~String();

};

#endif