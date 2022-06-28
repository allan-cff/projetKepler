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
    addPointTraj(getTraj(obj), p);
}

void addFromVect(struct object* obj, struct vector* pos, struct vector* speed){
    struct point* newPoint = createPoint(pos, speed, trajLen(getTraj(obj)));
    addPoint(obj, newPoint);
}


void processEulerNextPoint(struct object* obj, double deltaTime){
    struct point* prevPoint = seeLastPointTraj(getTraj(obj));
    struct vector* prevPos = getPos(prevPoint);
    struct vector* prevSpeed = getSpeed(prevPoint);
    struct vector* distance = vectMultiplication(prevSpeed, deltaTime);
    struct vector* nextPos = vectAddition(prevPos, distance);
    struct vector* pointToCenter = vectSubstraction(parentPos(obj), prevPos);
    struct vector* acceleration = vectMultiplication(pointToCenter,GRAVITATIONAL_CONSTANT*parentMass(obj)/pow(norm(pointToCenter), 3));
    struct vector* deltaSpeed = vectMultiplication(acceleration, deltaTime);
    struct vector* nextSpeed = vectAddition(prevSpeed, deltaSpeed);
    deleteVect(&distance);
    deleteVect(&pointToCenter);
    deleteVect(&deltaSpeed);
    deleteVect(&acceleration);
    addFromVect(obj, nextPos, nextSpeed);
}


void processAsymEulerNextPoint(struct object* obj, double deltaTime){
    struct point* prevPoint = seeLastPointTraj(getTraj(obj));
    struct vector* prevPos = getPos(prevPoint);
    struct vector* prevSpeed = getSpeed(prevPoint);
    struct vector* distance = vectMultiplication(prevSpeed, deltaTime);
    struct vector* nextPos = vectAddition(prevPos, distance);
    struct vector* pointToCenter = vectSubstraction(parentPos(obj), nextPos);
    struct vector* acceleration = vectMultiplication(pointToCenter,GRAVITATIONAL_CONSTANT*parentMass(obj)/pow(norm(pointToCenter), 3));
    struct vector* deltaSpeed = vectMultiplication(acceleration, deltaTime);
    struct vector* nextSpeed = vectAddition(prevSpeed, deltaSpeed);
    deleteVect(&distance);
    deleteVect(&pointToCenter);
    deleteVect(&deltaSpeed);
    deleteVect(&acceleration);
    addFromVect(obj, nextPos, nextSpeed);
}


void readAllPoints(struct object* obj){
    if(isObjectEmpty(obj) || isTrajEmpty(getTraj(obj))){
        return;
    }
    char* name = getName((obj));
    printf("{\"%s\": [", name);
    while(trajLen(getTraj(obj))>0){
        struct point* p = readFirstPointTraj(getTraj(obj));
        printf("[[%e, %e, %e],\n", getX(getPos(p)), getY(getPos(p)), getZ(getPos(p)));
        printf("[%e, %e, %e],\n", getX(getSpeed(p)), getY(getSpeed(p)), getZ(getSpeed(p)));
        printf("%d],\n", getTime(p));
        deleteTrajFirst(getTraj(obj));
    }
    printf("]");
}


void addToFile(FILE* p1, struct object* obj) {
    if (isObjectEmpty(obj) || isTrajEmpty(getTraj(obj))) {
        return;
    }

    fprintf(p1, "\"%s\": [", getName(obj));
    while (trajLen(getTraj(obj)) > 1) {
        struct point* p = readFirstPointTraj(getTraj(obj));
        fprintf(p1, "[[%e, %e, %e],", getX(getPos(p)), getY(getPos(p)), getZ(getPos(p)));
        fprintf(p1, "[%e, %e, %e],", getX(getSpeed(p)), getY(getSpeed(p)), getZ(getSpeed(p)));
        fprintf(p1, "%d],\n", getTime(p));
        deleteTrajFirst(getTraj(obj));
    }
    struct point* p = readFirstPointTraj(getTraj(obj));
    fprintf(p1, "[[%e, %e, %e],", getX(getPos(p)), getY(getPos(p)), getZ(getPos(p)));
    fprintf(p1, "[%e, %e, %e],", getX(getSpeed(p)), getY(getSpeed(p)), getZ(getSpeed(p)));
    fprintf(p1, "%d]]\n", getTime(p));
    deleteTrajFirst(getTraj(obj));
}


void deleteObject(struct object** obj){
    if(obj == NULL){
        return;
    }
    if(isObjectEmpty(*obj)){
        return;
    }
    struct traj* objTraj = getTraj(*obj);
    deleteTraj(&objTraj);
    free(*obj);
    *obj = NULL;
}


void objectTest() {
    if(!isObjectEmpty(NULL)){
        error("is object empty should return true with null pointer");
    }
    struct object* newObject = createEmptyObject();
    struct object* parentObject = createEmptyObject();
    setName(newObject, "test");
    setMass(newObject, 10000);
    setPeri(newObject, 23.98765);
    setParent(newObject, parentObject);
    setMass(parentObject, 999);
    if(isObjectEmpty(newObject)){
        error("is object empty should return false with freshly created object");
    }
    if(getTraj(newObject)!=newObject->traj){
        error("get Traj should return object traj");
    }
    if(getMass(newObject)!=newObject->mass){
        error("getMass should return object mass");
    }
    if(getPeri(newObject)!=newObject->perihelion){
        error("getPeri should return object perihelion");
    }
    if(getName(newObject)!=newObject->name){
        error("getName should return object name");
    }
    if(getParent(newObject)!=newObject->parent){
        error("getParent should return object parent");
    }
    struct point* newPoint = createPoint(createEmptyVect(), createEmptyVect(), 0);
    addPoint(parentObject, newPoint);
    if(parentPos(newObject)!=getPos(newPoint)){
        error("parent pos should return parent last point pos");
    }
    if(parentSpeed(newObject)!=getSpeed(newPoint)){
        error("parent speed should return last point speed");
    }
    if(parentMass(newObject)!=parentObject->mass){
        error("parent mass invalid return");
    }
    deleteObject(&newObject);
    deleteObject(&parentObject);
}