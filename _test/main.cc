#include <new>     // for placement new
#include <cstdlib> // for malloc, free
#include <iostream>

struct Foo {

    Foo(int x) {
        std::cout << "Constructor ran";
    }
    ~Foo() {
        std::cout << "Destructor ran";
    }
};

int main() {


    void* buf = operator new(sizeof(Foo));

    Foo* f = new (buf) Foo(10);
    f->~Foo();

    std::free(buf);



}