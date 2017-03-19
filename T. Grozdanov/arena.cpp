#include "arena.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

//constructor
Arena::Arena(char _type)
{
	if(_type=='w')type = warriorArena;
	if (_type == 'r')type = rangeArena;
}
Arena::Arena()
{
	srand(time(NULL));
	if (rand() % 2) type = warriorArena;
	else type = rangeArena;
}
//accessor
char Arena::get_type()
{
	if (type == warriorArena)return 'w';
	else return 'r';
}
//mutator
void Arena::set_type(char T)
{
	if (T == 'w') type = warriorArena;
	else if (T == 'r')type = rangeArena;
	else std::cout << "No such type.\n";
}
//methodes
void Arena::placeCard(int index, int cardID)
{
	arena[(index / 10) % 10][index % 10] = cardID;

}
void Arena::removeCard(int index)
{
	arena[(index / 10) % 10][index % 10] = 0;
}
void Arena::endTurn()
{
	int arenaCopy[4][4];
	for (int i = 0; i < 16; i++)
	{
		arenaCopy[i / 4][i % 4] = arena[i / 4][i % 4];
	}
	for (int i = 0; i < 16; i++)
	{
		arena[i / 4][i % 4] = arenaCopy[3 - i / 4][i % 4];
	}
}
void Arena::drawConsoleArena()
{
	std::cout << "\n";
	for (int i = 0; i < 16; i++)
	{
		if (i % 4 == 0) std::cout << "| ";
		std::cout << arena[0][i] <<" | ";
		if (i % 4 == 3)std::cout << "\n";
	}
}