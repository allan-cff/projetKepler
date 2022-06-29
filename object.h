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
    double lastPointMecEnergy;
    double averageMecEnergy;
    struct traj* traj;
    struct object* parent;
};

struct object* createEmptyObject();
bool isObjectEmpty(struct object* object);
struct traj* getTraj(struct object*);
double getMass(struct object*);
double getPeri(struct object*);
double getLastEnergy(struct object*);
double getAvEnergy(struct object*);
char* getName(struct object*);
struct object* getParent(struct object*);
struct vector* parentPos(struct object*);   // returns position vector of parent last point
struct vector* parentSpeed(struct object*); // returns speed vector of parent last point
double parentMass(struct object*);
void setMass(struct object*, double);
void setPeri(struct object*, double);
void setLastEnergy(struct object*, double);
void setAvEnergy(struct object*, double);
void setName(struct object*, char*);
void setParent(struct object* obj, struct object* parent);
struct object* initialize(double mass, double perihelion, struct object* parent);   // initialize object : mandatory before starting adding points
void setFirstPoint(struct object*, double equatorial_radius, double eccentricity);  // to call only once : used to determine speed of object at perihelion (point 0)
void addPoint(struct object*, struct point*);
void processEulerNextPoint(struct object* obj, double deltaTime);       // to determine next trajectory point based on euler's method
void processAsymEulerNextPoint(struct object* obj, double deltaTime);   // to determine next trajectory point based on asymetrical euler's method
void processMecEnergy(struct object* obj);  // to mesure Average Mechanical energy variation between current point and precedent
void readAllPoints(struct object*);
void addToFile(FILE*, struct object*); // to export data in JSON
void deleteObject(struct object**); // also delete all contained elements
void objectTest();

#endif