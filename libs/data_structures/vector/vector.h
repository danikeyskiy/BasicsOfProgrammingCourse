#include <stdio.h>
#include <stdlib.h>

#ifndef GIT_PROJECT_VECTOR_H
#define GIT_PROJECT_VECTOR_H

typedef struct vector {
    int *data;        // указатель на элементы вектора
    size_t size;      // размер вектора
    size_t capacity;  // вместимость вектора
} vector;

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

#endif //GIT_PROJECT_VECTOR_H
