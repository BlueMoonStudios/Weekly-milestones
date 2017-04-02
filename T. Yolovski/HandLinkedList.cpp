#include <iostream>

using namespace std;

class Hand
{
private:
	struct card
	{
		int id;
		card* nextCard;
		card(int _id, card* _p=nullptr): id(_id), nextCard(_p){}
	};

	card* first;
	int _size = 5;
public:
	bool empty() const
	{
		return (first == nullptr);
	}

	void putCardOnTheField()
	{
		card* tmp = first;
		first = first->nextCard;
		delete tmp;
		--_size;
	}

	void drawCard(int randomId)
	{
		card* newCard = new card(randomId, first);
		first = newCard;
		++_size;
	}
};

int main()
{
	Hand yourHand;
	yourHand.drawCard(24);
	yourHand.drawCard(64);


}