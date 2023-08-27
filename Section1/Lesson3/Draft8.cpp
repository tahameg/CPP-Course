#include <iostream>

using namespace std;

int main(){
    char16_t name1[] = u"Taha Mert Gökdemir";
    char name2[] = u8"Taha Mert Gökdemir";
    char32_t name3[] = U"Taha Mert Gökdemir";

    cout << name1 << " : " << sizeof(name1) << endl;
    cout << name2 << " : " << sizeof(name2) << endl;
    cout << name3 << " : " << sizeof(name3) << endl;
    return 0;
}