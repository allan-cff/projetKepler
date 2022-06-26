#include "point.h"

struct point* createEmptyPoint(){
    struct point* newPoint = malloc(sizeof(struct point));
    if(newPoint){
        newPoint -> position = NULL;
        newPoint -> speed = NULL;
        newPoint -> time = -1;
    } else {
        printf("***** MALLOC ERROR : cannot create new point *****");
    }
    return newPoint;
}

bool isPointEmpty(struct point* p){
    return p == NULL;
}

struct vector* getPos(struct point* p){
    if(isPointEmpty(p)){
        return NULL;
    }
    return p->position;
}

struct vector* getSpeed(struct point* p){
    if(isPointEmpty(p)){
        return NULL;
    }
    return p->speed;
}

int getTime(struct point* p){
    if(isPointEmpty(p)){
        return -1;
    }
    return p->time;
}

void setPos(struct point* p, struct vector* v){
    if(isPointEmpty(p)){
        return;
    }
    p -> position = v;
}

void setSpeed(struct point* p, struct vector* v){
    if(isPointEmpty(p)){
        return;
    }
    p -> speed = v;
}

void setTime(struct point* p, int t){
    if(isPointEmpty(p)){
        return;
    }
    p -> time = t;
}

void deletePoint(struct point** p){
    if(p == NULL){
        return;
    }
    if(isPointEmpty(*p)){
        return;
    }
    struct vector* speed = getSpeed(*p);
    deleteVect(&speed);
    struct vector* pos = getPos(*p);
    deleteVect(&pos);
    free(*p);
    *p = NULL;
}

void pointTest(){
    if(!isPointEmpty(NULL)){
        error("is point empty should return true with null");
    }
    struct point* newPoint = createEmptyPoint();
    if(isPointEmpty(newPoint)){
        error("is point empty should return false with not empty point");
    }
    if(getPos(NULL) != NULL){
        error("get pos should return NULL with null pointer");
    }
    if(getSpeed(NULL) != NULL){
        error("get speed should return NULL with null pointer");
    }
    if(getTime(NULL) != -1){
        error("get time should return -1 with null pointer");
    }
    if(getPos(newPoint) != NULL){
        error("get pos should return NULL with freshly created point");
    }
    if(getSpeed(newPoint) != NULL){
        error("get speed should return NULL with freshly created point");
    }
    if(getTime(newPoint) != -1){
        error("get time should return -1 with freshly created point");
    }
    struct vector* v1 = createEmptyVect();
    struct vector* v2 = createEmptyVect();
    setPos(newPoint, v1);
    setSpeed(newPoint, v2);
    setTime(newPoint, 5);
    if(getPos(newPoint) != v1){
        error("get pos return value incorrect");
    }
    if(getSpeed(newPoint) != v2){
        error("get speed return value incorrect");
    }
    if(getTime(newPoint) != 5){
        error("get time return value incorrect");
    }
    deletePoint(&newPoint); // should delete vectors too -> check valgrind
    struct point* p1 = createEmptyPoint();
    deletePoint(&p1); // don't have vectors inside to delete -> check valgrind
    deletePoint(&p1); // delete already deleted point
    deletePoint(NULL); // should not try to free
}