#include <assert.h>

#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector vec = createVector(0);
    pushBack(&vec, 0);
    pushBack(&vec, 8);
    pushBack(&vec, 5);

    assert(vec.data[0] == 0 && vec.data[1] == 8 && vec.data[2] == 5 && vec.size == 3 && vec.capacity == 4);
}

void test_pushBack_fullVector() {
    vector vec = createVector(3);
    pushBack(&vec, 1);
    pushBack(&vec, 2);
    pushBack(&vec, 3);

    assert(vec.data[0] == 1 && vec.data[1] == 2 && vec.data[2] == 3 && vec.size == 3 && vec.capacity == 3);
}

void test_popBack_notEmptVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptVector();
}

int main() {
    test();

    return 0;
}