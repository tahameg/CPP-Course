#include <iostream>

using namespace std;
int iteration;

int foo()
{
    cout << "iteration is : " << iteration << endl;
    return iteration >= 10 ? 0 : 1;
}

int main()
{
    // I C++ language, variables can be declared inside the brackets of
    //statements like if, while
    while (int i = foo()){
        iteration++;
    }
    return 0;
}