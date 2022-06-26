#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#ifndef PROJET_KEPLER_TRAJECTORY_H
#define PROJET_KEPLER_TRAJECTORY_H
#include "list.h"

struct traj {
    struct List* pointList;
};

bool isTrajEmpty(struct traj*);
struct traj* createEmptyTraj();             // create a new trajectory instance
struct point* seeLastPoint(struct traj*);   // see last point but don't delete it
void addPoint(struct traj*, struct point*); // add a point at last position
struct point* readFirstPoint(struct traj*); // returns first point AND delete it
void deleteTraj(struct traj**);             // delete instance and all contained points
void trajTest();

#endif