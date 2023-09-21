#include <iostream>
#include <vector>

using namespace std;

int Bad_alloc() {
    try {
        int* arr = new int[100000000000000];
    } catch (const bad_alloc& e) {
        cout << e.what() << endl;
    }

    return 0;
}

int Out_of_range() {
    vector<int> vec{1, 2, 3};

    try {
        int val = vec.at(4);
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}

int divide(int a, int b) {
    if (b == 0) {
        throw domain_error("std::domain_error");
    }
    return a / b;
}

int Domain_error() {
    try {
        divide(1, 0);
    } catch (const domain_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}

class Test {
   public:
    virtual ~Test() {}
};

class Inherited : public Test {};

int Bad_cast() {
    try {
        Test test;
        Inherited& test2 = dynamic_cast<Inherited&>(test);
    } catch (const bad_cast& e) {
        cout << e.what() << endl;
    }

    return 0;
}

int main() {
    Bad_alloc();
    // Out_of_range();
    // Domain_error();
    // Bad_cast();
    return 0;
}