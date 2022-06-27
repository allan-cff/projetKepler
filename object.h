#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#ifndef PROJET_KEPLER_OBJECT_H
#define PROJET_KEPLER_OBJECT_H

#include "trajectory.h"
#include "constant.h"

struct object {
    char* name;
    double perihelion;
    double mass;
    struct traj* traj;
    struct object* parent;
};

struct object* createEmptyObject();
bool isObjectEmpty(struct object* object);
struct traj* getTraj(struct object*);
double getMass(struct object*);
double getPeri(struct object*);
char* getName(struct object*);
struct object* getParent(struct object*);
struct vector* parentPos(struct object*);
struct vector* parentSpeed(struct object*);
double parentMass(struct object*);
void setMass(struct object*, double);
void setPeri(struct object*, double);
void setName(struct object*, char*);
void setParent(struct object* obj, struct object* parent);
struct object* initialize(double parent_mass, double perihelion, struct object* parent);
void setFirstPoint(struct object*, double equatorial_radius, double eccentricity);
void addPoint(struct object*, struct point*);
void processEulerNextPoint(struct object* obj, double deltaTime);
void deleteObject(struct object**);
void objectTest();

#endif