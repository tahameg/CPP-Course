#include <iostream>

using namespace std;

int main()
{
    //initialization with curly braces is called "Uniform Initialization" in C++ language
    int array[]{10, 9, 8, 4, 3, 1};
    double d{1.2}; //valid
    bool b{true}; //valid
    char c{'a'}; //valid
    double l = 10.3;
    int i{l}; // this is invalid. In C++ language, narrowing conversion is not alloweda with uniform initialization.


    for(int i = 0; i < 6; i++)
    {
        cout << *(array+i) << endl;
    }
    return 0;
}