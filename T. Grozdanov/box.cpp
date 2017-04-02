#include <iostream>

template<typename T>
class Box
{
public:
	Box() : capacity(10), prevBox(0), nextBox(0), size(0), serialNum(0)
	{
		object = new T[10];
	}
	Box(int n,Box<T>& prevB) : capacity(n), nextBox(&prevB), size(0)
	{
		serialNum = prevB.serialNum + 1;
		prevB.nextBox = this;
		object = new T[n];
	}
	Box(const Box<T>& other)
	{
		copyContainings(other)
	}
	Box<T>& operator=(const Box<T>& other)
	{
		if (this != &other)
		{
			delete[] object;
			copyContainings(other);
		}
		return *this;
	}
	~Box()
	{
		delete[] object;
	}
	int get_size()
	{
		return size;
	}
	int get_capacity()
	{
		return capacity;
	}
	int get_serialNum()
	{
		return serialNum;
	}
	void addObj(T obj)
	{
		if (size < capacity)
		{
			object[size] = obj;			
			++size;
		}
	}
	void removeObj()
	{
		if (size != 0)
		{
			--size;
		}
	}
	void printBox()
	{
		std::cout << "serial number: " << serialNum << " size: " << size << " capacity: " << capacity << "\n" << "objects: ";
		for (int i = 0; i < size; ++i)
			std::cout << object[i] << " ";
	}
private:
	void copyContainings(const Box<T>& other)
	{
		serialNum = other.serialNum;
		size = other.size;
		capacity = other.capacity;
		prevBox = other.prevBox;
		nextBox = other.nextBox;
		object = new T[capacity];
		for (int i = 0; i < size; i++)
			object[i] = other.object[i];
	}
	int serialNum;
	T* object;
	int size;
	int capacity;
	Box<T>* prevBox;
	Box<T>* nextBox;
};



//int main() //TEST
//{
//	Box<int> a;
//	Box<int> b(12, a);
//	b.addObj(13);
//	b.printBox();
//	std::cin.get();
//	std::cin.ignore();
//	return 0;
//}