#include <stdio.h>

void print_hello() { puts("hello world"); }

int main() {
    void (*fn) ();
    fn = &print_hello;
    (*fn)();
    return 0;
}
