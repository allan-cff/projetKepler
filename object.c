#include "object.h"

struct object* createEmptyObject(){
    struct object* newObject = malloc(sizeof(struct object));
    if(newObject){
        newObject -> name = "undefined";
        newObject -> perihelion = 0;
        newObject -> mass = 0;
        newObject -> traj = NULL;
    } else {
        printf("***** MALLOC ERROR : cannot create new trajectory *****");
    }
    return newObject;
}

bool isObjectEmpty(struct object* object){
    return object == NULL;
}

struct object* getTraj(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->traj;
}


double getMass(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->mass;
}


double getPeri(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->perihelion;
}


char* getName(struct object* obj){
    if(isObjectEmpty(obj)){
        return NULL;
    }
    return obj->name;
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