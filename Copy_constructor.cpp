#include <iostream>
using namespace std;

class MyClass
{
private:
	int size;
public:
	int* pointer_data;

	MyClass(int size)
	{
		this->size = size;
		this->pointer_data = new int[size];
		for (int i = 0; i < size; i++)
		{
			pointer_data[i] = i + 1;
		}
		cout << "Constructor called " <<this<< endl;
	}
	MyClass(const MyClass& other)
	{
		this->size = other.size;
		this->pointer_data = new int[other.size];
		for (int i = 0; i < size; i++)
		{
			this->pointer_data[i] = other.pointer_data[i];
		}
		cout << "Copy Constructor called " <<this<< endl;

	}
	~MyClass()
	{
		delete[] pointer_data;
		cout << "Destructor called " << this << endl;
	}
	void GetData()
	{
		for (int i = 0; i < size; i++)
		{
			cout << pointer_data[i]<< endl;
		}
	}
};



int main()
{
	MyClass a(10);
	MyClass b(a);
	cout << "Array a: " << endl;
	a.GetData();
	cout << "Array b: " << endl;
	b.GetData();
	return 0;
}

