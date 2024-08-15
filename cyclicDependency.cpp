#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

class Sample
{
  int m_Id; 
  public:
  // weak_ptr<Sample> m_Ptr; - Use weak_ptr as a member to avoid cyclic dependency
  
  shared_ptr<Sample> m_Ptr;
  Sample(int id) : m_Id(id)
  {
      cout << "Sample created with ID = "<<m_Id<<endl;
  }
  
  ~Sample()
  {
      cout << "Sample with ID = "<<m_Id <<" Is destroyed"<<endl;
  }
};

int main() {
    shared_ptr<Sample> sptr1 = make_shared<Sample>(1);
    shared_ptr<Sample> sptr2 = make_shared<Sample>(2);
    sptr1->m_Ptr = sptr2;
    sptr2->m_Ptr = sptr1;
    
    // use_count to get the reference count
    cout<<"sptr1 use count = "<<sptr1.use_count()<<endl;
    cout<<"sptr2 use count = "<<sptr2.use_count()<<endl;
    
    // Use lock() to convert weak pointer to shared pointer
    //shared_ptr<Sample> sp3 = sptr2->m_Ptr.lock();
    
    return 0;
}
