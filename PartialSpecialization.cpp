// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

// generic template class
template <typename t1, typename t2>
class TemplateTest
{
  t1 m_member1;
  t2 m_member2;
  
  public:
  TemplateTest(){}
  TemplateTest(t1 param1, t2 param2) : m_member1(param1),m_member2(param2)
  {}
  
  void print()
  {
      cout << "This is from Generic template class. Member1 = " << m_member1 << " Member2 = "<< m_member2 << endl;
  }
};

// Full Template Specialization
template <>
class TemplateTest <double, double>
{
  double m_member1;
  double m_member2;
  
  public:
  TemplateTest(){}
  TemplateTest(double param1, double param2) : m_member1(param1),m_member2(param2)
  {}
  
  void print()
  {
      cout << "This is from Full template specialization class. Member1 = " << m_member1 << " Member2 = "<< m_member2 << endl;
  }
};

// Partial specialization for the case where both types are the same
template <typename T>
class TemplateTest<T, T> {
    T m_member1;
    T m_member2;
public:
    TemplateTest(T a, T b) : m_member1(a), m_member2(b) {}
    void print()
    {
        cout << "This is from Partial template specialization class. Member1 = " << m_member1 << " Member2 = "<< m_member2 << endl;
    }
};


int main() {
    TemplateTest<string,int> test1("Nik", 21);
    test1.print();
    
    TemplateTest<double, double> test2(1.2, 2.1);
    test2.print();
    
    TemplateTest<int, int> test3(1, 2);
    test3.print();
    return 0;
}

/* OUTPUT */
/* 
This is from generic template class. Member1 = Nik Member2 = 21
This is from full template specialization class. Member1 = 1.2 Member2 = 2.1
This is from Partial template specialization class. Member1 = 1 Member2 = 2 
*/
