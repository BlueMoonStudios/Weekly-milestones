#include<iostream>

using namespace std;

template<typename T>
class Calc
{
private:
	T firstNumber;
	T secondNumber;
public:
	Calc(T _firstNumber = 0, T _secondNumber = 1) : firstNumber(_firstNumber), secondNumber(_secondNumber) {};
	T sum()
	{
		return firstNumber + secondNumber;
	}

	T product()
	{
		return firstNumber * secondNumber;
	}
	T difference()
	{
		return firstNumber - secondNumber;
	}
	T devide()
	{
		return firstNumber / secondNumber;
	}
};

int main()
{
	Calc  <int> first (40, 10);
	cout << first.product() << endl;

	Calc <double> second(2.0, 30.0);
	cout << second.devide() << endl;



}
