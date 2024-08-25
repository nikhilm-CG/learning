#include <iostream>
using namespace std;

template<typename T>
class nik_ptr
{
	T *ptr;
	public:
		// Constructor with 0 arguments
		nik_ptr():ptr(nullptr) {}

		// Parametirized Constructor
		nik_ptr(T* p) : ptr(p) {}

		// Copy Constructor deleted
		nik_ptr(const nik_ptr& r) = delete;

		// Assignment Operator deleted
		nik_ptr& operator=(const nik_ptr& r) = delete;

		// Destructor
		~nik_ptr()
		{
			cout << "Inside Destructor\n";
			delete ptr;
			ptr = nullptr;
		}

		// Move Constructor
		nik_ptr(nik_ptr&& rref)
		{
			cout << "Inside Move Constructor\n";
			if (this == &rref) return;

			ptr = rref.ptr;
			rref.ptr = nullptr;
		}

		// Move assignement operator
		nik_ptr& operator=(nik_ptr&& rref)
		{
			cout << "Inside Move assignement operator\n";

			if (this == &rref) return *this;

			delete ptr;
			ptr = rref.ptr;
			rref.ptr = nullptr;
			return *this;
		}

		// Arrow -> operator overloaded
		T* operator->()
		{
			return ptr;
		}
		
		// Star * operator overloaded
		T& operator*()
		{
			return *ptr;
		}
};

struct A
{
	int x;
	A(int a):x(a) {}
};

int main() {
	nik_ptr<A> ptr = new A(10);
	cout << ptr->x << endl;
    return 0;
}

/*
How to Remember
1.	operator->:
•	Think of it as "I want to access a member of the object my pointer points to."
•	Therefore, you need to return the pointer itself.
•	Return Type: T*
•	Return: ptr
2.	operator*:
•	Think of it as "I want to get the object my pointer points to."
•	Therefore, you need to return a reference to the object.
•	Return Type: T&
•	Return: *ptr
*/
