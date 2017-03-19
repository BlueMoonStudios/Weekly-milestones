#pragma once 

class User
{
public:
	enum Type
	{
		fireBorn,
		iceBorn
	};
	//constructor
	User(char _name[25],int len, char _type, int _exp);
	User();
	//accessors
	const char* get_name();
	int get_exp();
	void print_type();
	//mutator
	void set_exp(int _exp);
private:
	Type type;
	char name[25];
	int exp;
};
