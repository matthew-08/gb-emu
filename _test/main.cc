#include <new>     // for placement new
#include <cstdlib> // for malloc, free
#include <iostream>

struct Foo {
    Foo(int x) {
        std::cout << "Hello constructor";
    }
    ~Foo() {
        std::cout << "Hello destructor";
    }
};

int main() {

    void* buf = operator new(sizeof(Foo));

    Foo* f = new (buf) Foo(42);

    f->~Foo;
    std::free(buf);




}