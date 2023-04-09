#include <assert.h>

#include "vector.h"

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

void test_popBack_notEmptyVector() {
    vector vec = createVector(0);
    pushBack(&vec, 10);
    assert(vec.size == 1);
    popBack(&vec);
    assert(vec.size == 0);
    assert(vec.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector vec = createVector(3);
    vec.size = 3;
    vec.data[0] = 2;
    vec.data[1] = 3;
    vec.data[2] = 5;

    assert(*atVector(&vec, 1) == 3);
}

void test_atVector_requestToLastElement() {
    vector vec = createVector(3);
    vec.size = 3;
    vec.data[0] = 2;
    vec.data[1] = 3;
    vec.data[2] = 5;

    assert(*atVector(&vec, vec.size - 1) == 5);
}

void test_back_oneElementInVector() {
    vector vec = createVector(1);
    vec.size = 1;
    vec.data[0] = 11;

    assert(*back(&vec) == 11);
}

void test_front_oneElementInVector() {
    vector vec = createVector(1);
    vec.size = 1;
    vec.data[0] = 11;

    assert(*front(&vec) == 11);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}