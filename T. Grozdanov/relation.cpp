#include <iostream>

template<typename T1, typename T2>
class Relation
{
public:
	Relation() : first(0), second(0)
	{
		relation[0] = '=';
		relation[1] = 0;
	}
	Relation(T1 a, T2 b, char rel[]) : first(a), second(b)
	{
		int len = strlen(rel);
		for (int i = 0; i < len && i < 2; i++)
			relation[i] = rel[i];
		relation[len] = 0;
	}
	Relation(Relation<T1, T2> &other) : first(other.first), second(other.second), relation(other.relation) {}
	void printRelation()
	{
		std::cout << "(" << first << ", " << second << ") belongs to the relation: " << relation << "\n";
	}

private:
	T1 first;
	T2 second;
	char relation[5];
};

//int main()	//TEST
//{
//	Relation<int, int> a;
//	Relation<int, double> b(10, 10.001, "<=");
//	a.printRelation();
//	b.printRelation();
//	std::cin.get();
//	std::cin.ignore();
//	return 0;
//}