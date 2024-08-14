// Online C++ compiler to run C++ program online
#include <iostream>

// Virtual Inheritance - 
using namespace std;

class A{
  public:
  void print()
  {
      cout << "Hi\n";
  }
};

class B : virtual public A
{
};

class C :virtual public A
{
};

class D : public B, public C
{
};


int main() {
    D obj;
    obj.print(); // without virtual inheritance - error: request for member 'print' is ambiguous
    return 0;
}
