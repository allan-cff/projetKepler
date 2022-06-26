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

struct object {
    char* name;
    double perihelion;
    double mass;
    struct traj* traj;
};

struct object* createEmptyObject();
bool isObjectEmpty(struct object* object);
struct object* getTraj(struct object*);
double getMass(struct object*);
double getPeri(struct object*);
char* getName(struct object*);
void setMass(struct object*, double);
void setPeri(struct object*, double);
void setName(struct object*, char*);
//TODO: Ajouter fonctions de calcul de trajectoire (prendre en compte position de l'object autour duquel on est en orbite (pas forcément 0)
void deleteObject(struct object**);
void objectTest();

#endif