#include <new>     // for placement new
#include <cstdlib> // for malloc, free
#include <iostream>

struct Foo {
    Foo(int x) { std::cout << "Foo constructor ran"; }
    ~Foo() { std::cout << "Foo destructor ran"; }
};

int main() {
    void* buf = std::malloc(sizeof(Foo));
    Foo* f = new (buf) Foo(10); // construct Foo at buf
    f->~Foo();                 // must call destructor manually
    std::free(buf);            // and free memory manually
}