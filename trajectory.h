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
struct traj* createEmptyTraj();                 // create a new trajectory instance
struct point* seeLastPointTraj(struct traj*);   // see last point but don't delete it
void addPointTraj(struct traj*, struct point*); // add a point at last position
struct point* readFirstPointTraj(struct traj*); // returns first point AND delete it
int trajLen(struct traj*);                      // number of points in traj
void deleteTrajFirst(struct traj*);             // delete first (head) point in traj
void deleteTraj(struct traj**);                 // delete instance, list and all contained points
void trajTest();

#endif