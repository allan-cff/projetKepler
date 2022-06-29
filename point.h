#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#ifndef PROJET_KEPLER_POINT_H
#define PROJET_KEPLER_POINT_H
#include "vector.h"

struct point {
    struct vector* position;
    struct vector* speed;
    int time;
};

struct point* createEmptyPoint();
struct point* createPoint(struct vector* pos, struct vector* speed, int time);
bool isPointEmpty(struct point*);
struct vector* getPos(struct point*);
struct vector* getSpeed(struct point*);
int getTime(struct point*);
void setPos(struct point*, struct vector*);
void setSpeed(struct point*, struct vector*);
void setTime(struct point*, int);
void deletePoint(struct point**); // Also delete potential vectors contained  -> do not double free
void pointTest();

#endif