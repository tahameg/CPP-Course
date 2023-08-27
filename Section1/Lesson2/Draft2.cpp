#include <iostream>

using namespace std;


//In C++ language there is implicit conversation for bool type
int main()
{
    bool b;
    int s[10];

    //All above code is valid
    b = 2;
    b = 2.3;
    b = s; //null pointer value is parsed to false, other is parse true
    bool c = true + true;
    int i = true + true;
    return 0;
}