#include <iostream>
#include <map>
using namespace std;

/* What happens if we do not overload < operator?
We get compiler error if we try to insert anything into the map.
error: no match for 'operator<' (operand types are 'const Test' and 'const Test')
*/

// SO ITS IMPORTANT TO OVERLOAD operator < with const as param and const as a definition

// Lets see how we can store an object as a key in a map
class student
{
    int roll_no;
    public:
    student(int rNo) : roll_no(rNo){}  
    bool operator < (const student& s1) const
    {
        return roll_no < s1.roll_no;
    }
    
    friend ostream& operator<<(ostream& cout, const student& s);
};

ostream& operator<<(ostream& cout, const student& s)
{
    cout << s.roll_no;
    return cout;
}

int main() {
    map<student,int> students;
    
    students[student(45)] = 8;
    students[student(5)] = 8;
    students[student(85)] = 8;
    students[student(12)] = 8;
    students[student(87)] = 8;
    students[student(1)] = 8;
    
    cout << "Printing students \n";
    for(auto iter : students)
    {
        cout << " " << iter.first; 
    }
    
    return 0;
}
