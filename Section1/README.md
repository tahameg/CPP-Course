### Conditional Statements with Declarations

In C++, conditional statements like `if`, `while`, and `switch` can contain declarations within their parentheses. This allows assigned values to undergo a test process. For instance:

```cpp
if (void *ptr = malloc(1024)) {
    //...
}

while (int a = foo()) {
    //...
}

switch (int a = rand() % 10) {
    //...
}

```

However, using the assigned value in the same expression after the declaration is not possible:

```cpp
while ((int i = foo() < 10) {  // Invalid! This syntax is not supported
    //...
}

```

### The bool Data Type

C++ introduces the `bool` data type along with `true` and `false` keywords. In C++, condition expressions within `if`, `while`, and similar statements are of `bool` type. If the condition expression isn't of `bool` type, the compiler implicitly converts it to a `bool`. Comparison operators in C++ produce `bool` values.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 0;
    bool result;

    result = a > 10;  // Comparison operators produce bool values
    cout << result << endl;

    result = true;     // true and false are keywords
    cout << result << endl;

    return 0;
}

```

### Using bool in Arithmetic Operations

In C++, `bool` can participate in arithmetic operations. It is automatically promoted to `int` due to integral promotions. `true` becomes 1, and `false` becomes 0 during conversions. Scalar types can also be implicitly converted to `bool`. Non-zero scalar values become `true`, and 0 becomes `false`. Similarly, address types can be converted to `bool`, where NULL addresses become `false`, and other addresses become `true`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, c;
    bool b = true;
    char s[10];

    c = a + b;    // Valid, bool promotes to int
    cout << c << endl;

    b = 120;      // Valid, non-zero values become true
    cout << b << endl;

    b = 0;        // Valid, 0 becomes false
    cout << b << endl;

    b = s;        // Valid, NULL pointer is false, other addresses are true
    cout << b << endl;

    return 0;
}

```

### Function Call and Declaration Order

In C++, a function must have a prototype or definition before it's called. Unlike C90, where the compiler assumed a function returns an `int`, C++ enforces the need for prototypes. When calling a library function, its prototype should be included through a header file.

```cpp
#include <iostream>
using namespace std;

int main() {
    foo();  // Valid in C90, invalid in C++ and C99

    return 0;
}

int foo(void) {
    return 0;
}

```

### Function Prototypes with Parameters

In C++, empty parentheses and `void` mean the same for function prototypes. However, in C, they had different meanings. In C++, void can be used for both prototype and definition of functions without parameters. There's a difference in C++ for prototypes, not definitions.

```cpp
#include <iostream>
using namespace std;

int foo();  // Valid in C, invalid in C++

int main() {
    foo(10, 20);  // Valid in C, invalid in C++

    return 0;
}

int foo(int a, int b) {
    return 0;
}

```

### Void Pointers and Type Safety

In both C and C++, you can assign any type of address to a void pointer. However, in C++, assigning a void pointer to a non-void pointer is invalid. C++ enforces using a type cast to convert a void address to a non-void pointer.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[10];
    void *pv;
    double *pd;

    pv = a;     // Valid in both C and C++
    pd = pv;    // Valid in C, invalid in C++

    pd = (double *)pv;  // Valid in both C and C++

    return 0;
}

```

### Strings in C and C++

In C, strings are considered as arrays of characters (`char` type). The characters of a string are placed in a statically allocated array of type `char`, including the null character. However, updating characters in a string leads to undefined behavior. In C++, strings are treated as `const char` arrays. Therefore, when assigning a string to a pointer of type `char`, the pointer should also be of type `const char`. For example:

```cpp
const char *str;
// ...

str = "ankara";  // Valid in C and C++

```

## Initializing Arrays in C and C++

In C, arrays of `char`, `signed char`, and `unsigned char` can be initialized with a character sequence enclosed in double quotes. However, in C++, this behavior is not valid. C++ requires the array to be at least `N + 1` characters long when initializing with an `N` character string. For example:

```cpp
char s[6] = "ankara";  // Valid in C, but invalid in C++

```

## Unicode Strings and Character Constants in C++

C++11 introduced UNICODE strings and character constants. Different prefixes are used for different UNICODE encodings (`u8` for UTF-8, `u` for UTF-16, `U` for UTF-32). These prefixes define the character encoding used in the strings. For example:

```cpp
const char *s = "Ankara";           // Default character table
const char16_t *k = u"Ağrı Dağı";   // UTF-16
const char32_t *t = U"Ağrı Dağı";   // UTF-32
const char8_t *m = u8"Ağrı Dağı";   // UTF-8

```

## Uniform Initializer Syntax

C++11 introduced the "Uniform Initializer Syntax," which allows initializing variables using curly braces directly. This syntax can be used for various types of variables, including scalar types. For example:

```cpp
int a{10};
const char *b{"ali"};
int c[]{1, 2, 3};
int d{};  // d = 0

```

## Narrowing Conversions

Narrowing conversions, which may result in information loss, are not allowed with the Uniform Initializer Syntax. For instance:

```cpp
int a{10.2};          // Invalid
int b = 10.2;          // Valid
double c{3.14};       // Valid
double d{c};           // Invalid

```

## Restrictions on Initialization

Uniform Initializer Syntax restricts narrowing conversions. You can initialize smaller integer types with constant expressions from larger integer types. However, the constant expression must not exceed the limits of the target type. Similarly, constant expressions within the limits of their target types can be used for initialization. For example:

```cpp
int a{10L};         // Valid
int b{100ull};      // Valid
short c{100};       // Valid
unsigned char d{256};  // Invalid
float e{3.14};      // Valid
double f{3.14l};    // Valid

```