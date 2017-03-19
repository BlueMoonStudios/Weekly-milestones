#include "user.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

User::User(char _name[25], int len, char _type, int _exp)
{
	for (int i = 0; i < len; i++)
	{
		name[i] = _name[i];
	}
	name[len] = 0;
	if(_type='f') type = fireBorn;
	else if (_type = 'i') type = iceBorn;
	assert(_exp >= 0 && _exp >= exp);
	exp = _exp;
}
User::User()
{
	char BM[9] = "BlueMoon";
	for (int i = 0; i < 8; i++)
		name[i] = BM[i];
	name[8] = '\0';
	srand(time(NULL));
	if (rand() % 2) type = fireBorn;
	else type = iceBorn;
	exp = 0;
}
//accessors
const char* User::get_name()
{
	return name;
}
int User::get_exp()
{
	return exp;
}
void User::print_type()
{
	if (type == fireBorn)std::cout << "fireBorn\n";
	if (type == iceBorn)std::cout << "iceBorn\n";

}
//mutator
void User::set_exp(int _exp)
{
	assert(_exp >= 0 && _exp >= exp);
	exp = _exp;
}
