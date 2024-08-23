// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// FUNCTOR
/* Functor is an object which behaves like a function. It is widely used with STL algorithm functions such as std::sort. To use functor we need to overload () operator in our class*/

class sortHelper
{
    public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

// Functor to square a number
class Square {
public:
    int operator()(int x) const {
        return x * x;
    }
};

int main() {
    vector<int> list{5,8,9,71,23,225,54};
    sort(list.begin(),list.end(),sortHelper());
    for(int a : list){
        cout << " "<< a;
    }
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << std::endl; 
    // Use the Square functor with std::transform to square each element
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), Square());
    cout << "Printing squares\n";
    // Output the squared numbers
    for (int num : numbers) {
        std::cout << num << " "; // Output: 1 4 9 16 25
    }
    std::cout << std::endl;
    return 0;
}

