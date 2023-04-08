#include "vector.h"

vector createVector(size_t n) {
    vector vec = (vector) {malloc(sizeof(int) * n),
                           0,
                           n};
    if (vec.capacity > SIZE_MAX) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity <= SIZE_MAX) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        v->capacity = newCapacity;
        v->size = newCapacity < v->size ? newCapacity : v->size;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return *(v->data + i);
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    if (v->capacity == 0) {
        v->capacity++;
        reserve(v, v->capacity);
    }

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    } else {
        v->size--;
    }
}