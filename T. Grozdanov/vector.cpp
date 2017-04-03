#include <iostream>
#include <assert.h>

template<typename T>
class Vector
{
public:
	Vector() : size(0), capacity(32)
	{
		vect = new T[capacity];
		assert(vect != nullptr);
	}
	Vector(int _capacity) : size(0), capacity(_capacity)
	{
		vect = new T[capacity];
		assert(vect != nullptr);
	}
	Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity)
	{
		copyVector(other);
	}
	Vector& operator=(const Vector<T>& other)
	{
		if (this != other)
		{
			delete[] vect;
			copyVector(other);
		}
		return *this;
	}
	T operator[](int i)
	{
		assert(i < capacity);
		return vect[i];
	}
	void operator+=(const Vector<T>& other)
	{
		Vector<T> v(*this);
		delete[] vect;
		capacity += other.capacity;
		size += other.size;
		vect = new T[capacity];
		assert(vect != nullptr);
		for (int i = 0; i < size; ++i)
		{
			if (i < lne - other.size)
				vect[i] = v.vect[i];
			else vect[i] = other.vect[i];
		}
		delete v;
	}
	~Vector()
	{
		delete[] vect;
	}
	int get_size()
	{
		return size;
	}
	int get_capacity()
	{
		return capacity;
	}
	void addAt(int index, T newMem)
	{
		if (index > size)
		{
			std::cout << "Wrong index.\n";
			return;
		}
		if (size + 1 <= capacity)
		{
			for (int i = size - 1; i >= index; --i)
				vect[i + 1] = vect[i];
			vect[index] = newMem;
			++size;
		}
		else
		{
			sizeUp();
			addAt(index, newMem);
		}
	}
	void removeAt(int index)
	{
		assert(index >= 0);
		if (index < size - 1)
		{
			for (int i = index + 1; i < size; ++i)
				vect[i - 1] = vect[i];

		}
		--size;
	}
	void printVector()
	{
		for (int i = 0; i < size; ++i)
			std::cout << vect[i] << " ";
		std::cout << " size: " << size << " capacity: " << capacity;
		if (size > 0) std::cout << "\n";
	}
private:
	void copyVector(const Vector<T> &other)
	{
		capacity = other.capacity;
		size = other.size;
		vect = new T[capacity];
		for (int i = 0; i < size; ++i)
			vect[i] = other.vect[i];
	}
	void sizeUp()
	{
		Vector<T> v(*this);
		delete[] vect;
		capacity += 32;
		vect = new T[capacity];
		assert(vect != nullptr);
		for (int i = 0; i < size; ++i)
		{
			vect[i] = v.vect[i];
		}
		delete v;
	}
	T* vect;
	int size;
	int capacity;

};
//int main()  //TEST
//{
//	Vector<int> a(2);
//	for (int i = 0; i < 2; ++i)
//		a.addAt(i, i+1);
//	a.printVector();
//	a.removeAt(1);
//	a.printVector();
//	a.addAt(1, 2);
//	a.addAt(33, 4);
//	a.printVector();
//	std::cin.get();
//	std::cin.ignore();
//	return 0;
//}