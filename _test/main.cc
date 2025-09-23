#include <new>     // for placement new
#include <cstdlib> // for malloc, free
#include <iostream>

struct Foo {
    Foo(int x) {
        std::cout << "hello c";
    }
    ~Foo() {
        std::cout << "hello d";
    }
};

int main() {
    void* buf = std::malloc(sizeof(Foo));

    Foo* f = new (buf) Foo(42);

    f->~Foo();
    std::free(buf);
}