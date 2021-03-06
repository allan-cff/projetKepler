#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#ifndef PROJET_KEPLER_VECTOR_H
#define PROJET_KEPLER_VECTOR_H

struct vector {
    double x;
    double y;
    double z;
};

struct vector* createEmptyVect();
struct vector* createVect(double x, double y, double z);
bool isVectorEmpty(struct vector*);
double getX(struct vector*);
double getY(struct vector*);
double getZ(struct vector*);
void setX(struct vector*, double);
void setY(struct vector*, double);
void setZ(struct vector*, double);
struct vector* vectAddition(struct vector*, struct vector*);    // Create a new vect and use malloc -> don't forget to delete
struct vector* vectSubstraction(struct vector*, struct vector*);// Create a new vect and use malloc -> don't forget to delete
struct vector* vectMultiplication(struct vector*, double);      // Create a new vect and use malloc -> don't forget to delete
double norm(struct vector*);
void deleteVect(struct vector**);
void vectorTest();

#endif