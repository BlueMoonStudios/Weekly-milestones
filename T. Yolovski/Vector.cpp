

#include <iostream>

using namespace std;
template <typename T>
class Vector
{
private:
	T* elements;
	size_t size;
	size_t maxSize;

	void resize()
	{
			maxSize *= 2;
	}
public:
	Vector(size_t _maxSize = 256, size_t _size = 1) : maxSize(_maxSize), size(_size)
	{
		elements = new T[_maxSize];
		///check for NULL
	}

	Vector(const Vector<T>& other)
	{
		maxSize = other.maxSize;
		size = other.size;
		elements = new T[maxSize];
		for (int ind = 0; ind < size; ++ind)
			elements[ind] = other.elements[ind];
	}
	Vector<T>& operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			delete[] elements;
			maxSize = other.maxSize;
			size = other.size;
			elements = new T[maxSize];
			for (int ind = 0; ind < size; ++ind)
				elements[ind] = other.elements[ind];
		}
		return *this;
	}

	size_t getMaxSize() const
	{
		return maxSize;
	}

	size_t getSize() const
	{
		return size;
	}

	T& operator[] (size_t ind) const
	{
		return elements[ind];
	}

	void push_back(T elem)
	{
		if (size == maxSize) resize();
		elements[size] = elem;
		++size;
	}
	void push_front(T elem)
	{
		if (size == maxSize) resize();
		for (int i = getSize(); i >=0; i--)
		{
			elements[i + 1] = elements[i];
		}
		elements[0] = elem;
		++size;
	}

	T pop_back()
	{
		size--;
		return elements[size];
	}

	~Vector()
	{
		delete[] elements;
	}
};

template <typename T>
ostream& operator<<(ostream& os, const Vector<T>& obj)
{
	os << "<" << obj.getSize() << "> :";
	os <<'('<< obj[0]; 
	for (int ind = 1; ind < obj.getSize(); ++ind)
		os << ", " << obj[ind];
	os << ')';
	os << endl;
	return os;
}



int main()
{
	Vector <int> input(20, 5);
	for (int i = 0; i < 5; i++)
	{
		input[i] = 2*i;
	}
    cout << input << endl;	
	Vector <int>otherVector1(6, 6);
	for (int i = 0; i < otherVector1.getSize(); i++)
	{
		otherVector1[i] = 10 * i;
	}
	Vector <int> otherVector(input);
	cout << otherVector << endl; //copyconstructor test

	otherVector = otherVector1;
	cout << otherVector << endl; //operator = test
	otherVector.pop_back(); // pop back test
	cout << otherVector << endl;
	otherVector1.push_front(53);
	cout << otherVector1 << endl;	//push_front test


	Vector <char> a;			
	cout << a << endl; //default constructor


	return 0;
}