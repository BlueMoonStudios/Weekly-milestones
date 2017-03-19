#pragma once
#include "deck.hpp"

class Arena
{
public:
	enum special
	{
		warriorArena,
		rangeArena 
	};
	//constructors
	Arena(char _type);
	Arena();
	//accessor
	char get_type();
	//mutator
	void set_type(char T);
	//methodes
	void placeCard(int index, int cardID);
	void removeCard(int index);
	void endTurn();
	void drawConsoleArena();
private:
	special type;
	int arena[4][4] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
};


