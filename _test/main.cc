#include <new>     // for placement new
#include <cstdlib> // for malloc, free
#include <iostream>

struct Foo {
    Foo(int x) {
        std::cout << "Constructor";
    }
    ~Foo() {
        std::cout << "Destructor222";
    }
};

int main() {
  void* buf = std::malloc(sizeof(Foo));
  
  Foo* f = new (buf) Foo(10);

  f->~Foo();
  std:free(buf);
}