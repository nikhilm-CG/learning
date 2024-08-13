// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

using namespace std;

class mString
{
    char* pStr;
    public:
    
    mString():pStr(nullptr){}
    
    mString(const char* str)
    {
        if(str)
        {
            pStr = new char[strlen(str) + 1];
            strcpy(pStr, str);
        }
        else
        {
            pStr = nullptr;
        }
    }
    
    // copy constructor
    mString(const mString& rStr) : mString(rStr.pStr) 
    {
        
    }
    
    // assignment operator
    mString& operator=(const mString& rStr)
    {
        if(this != &rStr)
        {
            if(pStr != nullptr)
            {
                delete[] pStr;
                pStr = nullptr;
            }
            
            if (rStr.pStr) {
                pStr = new char[strlen(rStr.pStr) + 1];
                strcpy(pStr, rStr.pStr);
            } else {
                pStr = nullptr;
            }
        }
        return *this;
    }
    
    // Move constructor
    mString(mString&& rStr) noexcept : pStr(rStr.pStr) 
    {
        rStr.pStr = nullptr;
    }

    // Move assignment operator
    mString& operator=(mString&& rStr) noexcept 
    {
        if (this != &rStr) 
        {
            delete[] pStr;
            pStr = rStr.pStr;
            rStr.pStr = nullptr;
        }
        return *this;
    }

    
    ~mString()
    {
        delete[] pStr;
        pStr = nullptr;
    }
    
    friend ostream& operator<<(ostream& cout, mString& str);
    friend mString operator+(const mString& str1, const mString& str2);
};

mString operator+(const mString& str1, const mString& str2)
{
    int len1 = str1.pStr ? strlen(str1.pStr) : 0;
    int len2 = str2.pStr ? strlen(str2.pStr) : 0;
    
    char* newStr = new char[len1 + len2 + 1];
    
    if (str1.pStr) {
        strcpy(newStr, str1.pStr);
    }
    if (str2.pStr) {
        strcpy(newStr + len1, str2.pStr);
    }
    
    mString result(newStr);
    delete[] newStr;
    return result;
}

ostream& operator<<(ostream& cout, mString& str)
{
    cout<<str.pStr;
    return cout;
}

int main() {
    mString str1("Nikhil");
    mString str2 = str1;
    mString str3;
    str3 = str2;
    mString str4 = "abc" + str1;
    mString str5 = str4 + "def";
    mString str6 = str1 + str2;
    
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    cout << "str5 = " << str5 << endl;
    cout << "str6 = " << str6 << endl;
    return 0;
}


/* Output 
str1 = Nikhil
str2 = Nikhil
str3 = Nikhil
str4 = abcNikhil
str5 = abcNikhildef
str6 = NikhilNikhil */
