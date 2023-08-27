// in Cpp  when a function is called, a declaration or prototype of the function should have been defined.

void foo();

int main()
{
    foo();
    //boo();// this is not valid and will cause compile time error
    return 0;
}

void boo();