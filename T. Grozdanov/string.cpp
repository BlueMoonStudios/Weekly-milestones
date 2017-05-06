#include "string.hpp"
#include <cstring>

int strlength(const char* _str)
{
	int i = 0;
	for (; _str[i] != 0; ++i);
	return i;
}

void String::copy(const char* _str)
{
	int i = 0;
	for(;_str[i] != 0 && i < capacity;++i)
		str[i] = _str[i];
	str[i] = 0;
	length = i;
}

void String::copy(const String& other)
{
	int i = 0;
	for (; other.str[i] != 0 && i < capacity; ++i)
		str[i] = other.str[i];
	str[i] = 0;
	length = i;
}

String::String() : str(new char[16]), length(0), capacity(15) { str[0] = 0; }

String::String(const char* _str)
{
	capacity = strlength(_str);
	str = new char[capacity + 1];
	copy(_str);
}

String::String(const String& other)
{
	capacity = other.capacity;
	str = new char[capacity + 1];
	copy(other);
}

String& String::operator =(const String& other)
{
	if (this != &other)
	{
		delete[] str;
		capacity = other.capacity;
		str = new char[capacity + 1];
		copy(other);
	}
	return *this;
}

String& String::operator =(const char* _str)
{
	if (std::strcmp(str, _str) != 0)
	{
		delete[] str;
		capacity = strlength(_str);
		str = new char[capacity + 1];
		copy(_str);
	}
	return *this;
}

bool String::operator ==(const String& other)
{
	return std::strcmp(str, other.str) == 0;
}

bool String::operator !=(const String& other)
{
	return !(*this == other);
}

bool String::operator <(const String& other)
{
	return std::strcmp(str, other.str) < 0;
}
bool String::operator >(const String& other)
{
	return std::strcmp(str, other.str) > 0;
}

String& String::operator +=(const char* _str)
{
	int len2 = strlength(_str);
	if (length + len2 <= capacity)
	{
		for (int i = length; i < len2 + length; i++)
			str[i] = _str[i - length];
		length += len2;
	}
	else
	{
		char* buf;
		buf = new char[length + len2 + 1];
		int i = 0;
		for (; i < length + len2; ++i)
		{
			if (i < length) buf[i] = str[i];
			else buf[i] = _str[i - length];
		}
		buf[i] = 0;
		delete[] str;
		length += len2;
		capacity = length;
		str = buf;
	}
	return *this;
}

String& String::operator +=(const String& other)
{
	if (length + other.length <= capacity)
	{
		for (int i = length; i < other.length + length; i++)
			str[i] = other.str[i - length];
		length += other.length;
	}
	else
	{
		char* buf;
		buf = new char[length + other.length + 1];
		int i = 0;
		for (; i < length + other.length; ++i)
		{
			if (i < length) buf[i] = str[i];
			else buf[i] = other.str[i - length];
		}
		buf[i] = 0;
		delete[] str;
		length += other.length;
		capacity = length;
		str = new char[capacity];
		str = buf;
	}
	return *this;
}
String& String::operator +=(char _char)
{
	if (length < capacity)
	{
		str[length++] = _char;
	}
	else
	{
		char* buf;
		buf = new char[length + 16];
		int i = 0;
		for (; i <= length; ++i)
		{
			if (i < length) buf[i] = str[i];
			else buf[i] = _char;
		}
		buf[i] = 0;
		delete[] str;
		capacity = length + 16;
		str = new char[capacity];
		copy(buf);
		delete[] buf;
	}
	return *this;
}

char& String::operator[](int index) 
{
	return str[index];
}

int String::get_len()
{
	return length;
}

int String::get_capacity()
{
	return capacity;
}

void String::nullstring()
{
	int max = get_len();
	for (int i = 0; i < max; ++i)
	{
		str[i] = 0;
	}
}

String::~String()
{
	delete[] str;
}

std::ostream& operator << (std::ostream &out, const String &s)
{
	return out << s.str;
}

std::istream& operator >> (std::istream &in, String &s)
{
	s = "";
	char buf[31];
	do
	{
		in.clear();
		in.getline(buf, 31);
		s += buf;
	} while (strlength(buf) == 30);
	return in;
}