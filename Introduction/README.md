<date>--- 19-08-2023 ---</date><br>
## 1. History and Versions
The first standard for C++ was established by ISO/IEC in 1998 (ISO/IEC 14882:1998). This was followed by the standards in 2003, which were more of a corrective nature. A new standard for C++ was then created in 2011, introducing many innovations to the language. This was followed by the standards in 2014, 2017, and 2020. The current standard under development is for 2023.

These standards are commonly referred to as C++98, C++03, C++11, C++14, C++17, C++20, and C++23. Additions to C++ can be categorized into two types: "core language features" and additions to the standard library. The period up to C++11 is often referred to as classic C++. The most significant additions were made with the C++11 standards. C++11 and beyond are often referred to as "Modern C++". It was established that standards will now be developed every three years. This rapid development cycle brought about various challenges.

The initial standards for the C Programming Language were established by ISO in 1990 under the name "ISO/IEC 9899:1990". This is commonly referred to as C90. (In fact, ANSI, the American National Standards Institute, had established the C standards in 1989. The ISO standards of 1990 were created by adopting these ANSI standards and modifying certain section numbers.) A new standard for C, known as C99, was established in 1999. Subsequently, in 2011, another standard for C was created, referred to as C11. Finally, the last version of C was released in 2017, known as C17. However, C17 did not introduce new features; it primarily addressed issues from C11. The most recent version of the C standard being worked on is C23, with an expected release in 2024.

The rapid three-year update cycle of C++ standards led to the emergence of design errors and regrets. Consequently, certain nuances for Modern C++ may vary from version to version. It is not recommended to directly read C++ standards.

C++ standards, and some other standards as well, can be considered documents suitable for providing a "complete description" for those already familiar with C++. In recent years, an initiative named "C++ Reference" has become popular, providing an annotated explanation of C++ standards. In our course, we will frequently refer to the C++ Reference site rather than directly referencing the standards. The site can be accessed through the following link:

[cppreference.com](https://en.cppreference.com/w/)

## 2. Compilation in Different Environments

A C++ program can be compiled and executed easily through Integrated Development Environments (IDEs) by performing compilation and linking. The most commonly used IDE for Windows systems is Microsoft's "Visual Studio." Another IDE option for C++ is "Qt Creator," which is cross-platform and can be used on Windows, macOS, and Linux systems. However, compilers are fundamentally command-line programs. Microsoft's C and C++ compiler is named "cl.exe." Compilation using this compiler can be done in the command line as follows:

```bash
cl sample.cpp
```

By default, the compiler also invokes the linker after compilation. If desired, the name of the executable file can be changed using the `/Fe` option:

```bash
cl /Fe:test.exe sample.cpp
```

On UNIX/Linux and macOS systems, the g++ and clang++ compilers can be used for C++. Typical compilation from the command line looks like:

```bash
g++ sample.cpp
```

Here, after compilation, the compiler again runs the linker, resulting in an executable file named `a.out`. To change the name of the executable file, the `-o` option is used, for example:

```bash
g++ -o sample sample.cpp
```

On UNIX/Linux systems, remember to prepend `./` to the program file name to execute it, for example:

```bash
./sample
```

Since C++ has various standards, compilation can be performed by specifying these standards. In Visual Studio IDE, this can be adjusted through the menus. With the g++ compiler, the `-std` option is used to specify the standard. For instance:

```bash
-std=c++11
-std=c++14
-std=c++17
-std=c++20
-std=c++2a
-std=c++2b
# For example
g++ -std=c++2a -o sample sample.cpp
```

C++ programs can also be compiled using gcc. In this case, gcc essentially runs the g++ compiler. However, when compiling with gcc, it is necessary to involve the libstdc++ library in the linking stage using the `-lstdc++` command-line argument. If no version is specified, the default version used is C++14.

## Adhering to Standards

In both C and C++, programs written without adhering to the syntax and semantic rules specified by the standards can still be successfully compiled by the compiler. This is because the standards state that compilers must be able to compile valid programs. However, there is no definitive rule about whether non-compliant programs will be compiled or not. The standards only require compilers to issue diagnostic messages for invalid cases. Therefore, valid programs must always be compiled successfully, while invalid programs may or may not be compiled. Hence, trying to learn the language rules solely based on the success of compilation is not a good approach. Additionally, compilers in C and C++ can have "extensions" not present in other compilers. It is crucial for the programmer to be aware of what constitutes an extension. If we use an extension of one compiler, that code might not compile successfully with another compiler. Familiarity with the extensions of the compilers you are working with is important.

## Types of Differences Between C++ and C

The differences between C++ and C are often in the form of "extras" in C++. Some of these extras were added to C++ to make it a better C. These are referred to as "Extras and Differences in C++ that are Not Directly Related to Object-Oriented Programming in C". We will first discuss these and then delve into the aspects of C++ that are specific to Object-Oriented Programming. Thus, our course comprises three main sections:

1. Extras and Differences in C++ that are Not Directly Related to Object-Oriented Programming in C
2. Extras and Differences in C++ that are Directly Related to Object-Oriented Programming in C
3. Other Important Features of C++ and the Standard Library

# Section 1: Extras and Differences in C++ that are Not Directly Related to Object-Oriented Programming in C

In this section, we will discuss "Extras and Differences in C++ that are Not Directly Related to Object-Oriented Programming in C" in a list format. Each item will begin with a summarized sentence, followed by a detailed explanation.

1. C++ introduced the ability to use `//` for single-line comments. This feature was not present in C90, but it was added to C with C99.
2. In C++, local variables can be declared anywhere within a block. In contrast, in C90, local

variables had to be declared at the beginning of a block. However, with C99, local variables in C can also be declared anywhere within a block. The scope of a local variable in C++ extends from its declaration point to the end of the block. Similarly, in nested or separate blocks, local variables with the same name can be declared, but not within the same block.
3. In C++, the first part of a `for` loop can include declarations. This feature was not present in C90, but it was added to C with C99. Additionally, in C++, declarations can also be made within the parentheses of other statements. The ability to declare within the first part of a `for` loop, as seen in C++, is also present in languages like Java and C# that have taken their syntax from C++. This feature simplifies loop constructs.

```cpp
#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 10; ++i)
		cout << i << " ";
	cout << endl;

	return 0;
}
```

<aside>
📝 Local variables declared in the first part of a `for` loop have their scope limited to the `for` loop. Thus:
	`for (declaration; condition; expression)
		<statement>`

is equivalent to:

	`{
		declaration;

		for (; condition; expression)
			<statement>
	}`

</aside>

```cpp
// Multiple variables of the same type can be declared in the first part of a `for` loop in C++. For example:

for (int i = 0,  k = 100; i + k > 50; ++i, k -= 2) {
		//...
}

// However, these variables cannot be of different types. For example:

for (int i = 0, long k = 100; ...) {		// Invalid!..
}
```

<aside>
❗ An identically named variable in an outer scope and an inner scope represents different variables.

</aside>