#include <iostream>

class A {
    public:
    virtual void print();
};
class B : public A {
    public:
    virtual void print();
};
virtual void A::print() { std::cout << "This is from class A" << std::endl; }
virtual void B::print() { std::cout << "This is from class B" << std::endl; }

using namespace std;

int main() {

    A a;
    B b;

    a.print();
    b.print();
    A *c = &b;
    c->print();

    return 0;
}
