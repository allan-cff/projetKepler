#include "object.h"

struct object* createEmptyObject(){
    struct object* newObject = malloc(sizeof(struct object));
    if(newObject){
        newObject -> name = "undefined";
        newObject -> perihelion = 0;
        newObject -> mass = 0;
        newObject -> traj = createEmptyTraj();
    } else {
        printf("***** MALLOC ERROR : cannot create new trajectory *****");
    }
    return newObject;
}

bool isObjectEmpty(struct object* object){
    return object == NULL;
}

struct traj* getTraj(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->traj;
}


double getMass(struct object* obj){
    if(isObjectEmpty(obj)){
        return 0;
    }
    return obj->mass;
}


double getPeri(struct object* obj){
    if(isObjectEmpty(obj)){
        return 0;
    }
    return obj->perihelion;
}


char* getName(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->name;
}

struct object* getParent(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->parent;
}


struct vector* parentPos(struct object* obj){
    struct object* parent = getParent(obj);
    if(isObjectEmpty(parent)){
        return NULL;
    }
    return getPos(seeLastPointTraj(parent->traj));
}


struct vector* parentSpeed(struct object* obj){
    struct object* parent = getParent(obj);
    if(isObjectEmpty(parent)){
        return NULL;
    }
    return getSpeed(seeLastPointTraj(parent->traj));
}


double parentMass(struct object* obj){
    struct object* parent = getParent(obj);
    if(isObjectEmpty(parent)){
        return 0;
    }
    return parent->mass;
}


void setMass(struct object* obj, double value){
    if(isObjectEmpty(obj)){
        return;
    }
    obj->mass = value;
}


void setPeri(struct object* obj, double value){
    if(isObjectEmpty(obj)){
        return;
    }
    obj->perihelion = value;
}


void setName(struct object* obj, char* name){
    if(isObjectEmpty(obj)){
        return;
    }
    obj->name = name;
}


void setParent(struct object* obj, struct object* parent){
    if(isObjectEmpty(obj)){
        return;
    }
    obj->parent = parent;
}


struct object* initialize(double mass, double perihelion, struct object* parent){
    struct object* newObj = createEmptyObject();
    setMass(newObj, mass);
    setPeri(newObj, perihelion);
    setParent(newObj, parent);
    return newObj;
}


void setFirstPoint(struct object* obj, double equatorial_radius, double eccentricity){
    struct vector* initial_speed = createVect(0, sqrt(GRAVITATIONAL_CONSTANT*parentMass(obj)*(1+eccentricity)/equatorial_radius*(1-eccentricity)), 0);
    struct vector* initial_pos = createVect(getPeri(obj),0,0);
    struct point* initial_point = createPoint(initial_pos, initial_speed, 0);
    addPoint(obj, initial_point);
}


void addPoint(struct object* obj, struct point* p){
    addPointTraj(obj->traj, p);
}

void addFromVect(struct object* obj, struct vector* pos, struct vector* speed){
    struct point* newPoint = createPoint(pos, speed, trajLen(obj->traj));
    addPoint(obj, newPoint);
}


void processEulerNextPoint(struct object* obj, double deltaTime){
    struct point* prevPoint = seeLastPointTraj(obj->traj);
    struct vector* prevPos = getPos(prevPoint);
    struct vector* prevSpeed = getSpeed(prevPoint);
    struct vector* nextPos = createEmptyVect();
    struct vector* distance = vectMultiplication(prevSpeed, deltaTime);
    nextPos = vectAddition(prevPos, distance);
    struct vector* pointToCenter = createEmptyVect();
    pointToCenter = vectSubstraction(parentPos(obj), prevPos);
    struct vector* acceleration = vectMultiplication(pointToCenter, -GRAVITATIONAL_CONSTANT*parentMass(obj)/pow(norm(pointToCenter), 3));
    struct vector* nextSpeed = createEmptyVect();
    struct vector* deltaSpeed = vectMultiplication(acceleration, deltaTime);
    nextSpeed = vectAddition(prevSpeed, deltaSpeed);
    deleteVect(&distance);
    deleteVect(&pointToCenter);
    deleteVect(&deltaSpeed);
    deleteVect(&acceleration);
    addFromVect(obj, nextPos, nextSpeed);
}


void deleteObject(struct object** obj){
    if(obj == NULL){
        return;
    }
    if(isObjectEmpty(*obj)){
        return;
    }
    deleteTraj(&((*obj)->traj));
    free(*obj);
    *obj = NULL;
}


void objectTest() {
    if(!isObjectEmpty(NULL)){
        error("is object empty should return true with null pointer");
    }
    struct object* newObject = createEmptyObject();
    if(isObjectEmpty(newObject)){
        error("is object empty should return false with freshly created object");
    }

}