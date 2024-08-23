#include <iostream>

using namespace std;

template<typename t>
void print(t param)
{
    cout << "Thiis is generic template function \n";
}

template<>
void print<double>(double param)
{
    cout << "This is full template specialization \n";
}

void print(double param)
{
    cout << "normal function is invoking if available instead of specialized template function\n";
}

int main() {
    print("nik");
    print(3);
    print(5.0);
    return 0;
}
