#include "vector.h"

struct vector* createEmptyVect(){
    struct vector* newVector;
    newVector = malloc(sizeof(struct vector));
    if(newVector){
        newVector -> x = 0;
        newVector -> y = 0;
        newVector -> z = 0;
    } else {
        printf("***** MALLOC ERROR : cannot create new vector *****");
    }
    return newVector;
}


struct vector* createVect(double x, double y, double z){
    struct vector* newVector = createEmptyVect();
    setX(newVector, x);
    setY(newVector, y);
    setZ(newVector, z);
    return newVector;
}


bool isVectorEmpty(struct vector* v){
    return v == NULL;
}

double getX(struct vector* v){
    if(isVectorEmpty(v)){
       return 0;
    }
    return v -> x;
}

double getY(struct vector* v){
    if(isVectorEmpty(v)){
        return 0;
    }
    return v -> y;
}

double getZ(struct vector* v){
    if(isVectorEmpty(v)){
        return 0;
    }
    return v -> z;
}

void setX(struct vector* v, double d){
    if(isVectorEmpty(v)){
        return;
    }
    v -> x = d;
}

void setY(struct vector* v, double d){
    if(isVectorEmpty(v)){
        return;
    }
    v -> y = d;
}

void setZ(struct vector* v, double d){
    if(isVectorEmpty(v)){
        return;
    }
    v -> z = d;
}

struct vector* vectAddition(struct vector* v1, struct vector* v2){
    if(isVectorEmpty(v1) || isVectorEmpty(v2)){
        return NULL;
    }
    struct vector* newVect = createEmptyVect();
    setX(newVect, getX(v1) + getX(v2));
    setY(newVect, getY(v1) + getY(v2));
    setZ(newVect, getZ(v1) + getZ(v2));
    return newVect;
}

struct vector* vectSubstraction(struct vector* v1, struct vector* v2) {
    if(isVectorEmpty(v1) || isVectorEmpty(v2)){
        return NULL;
    }
    struct vector *newVect = createEmptyVect();
    setX(newVect, getX(v1) - getX(v2));
    setY(newVect, getY(v1) - getY(v2));
    setZ(newVect, getZ(v1) - getZ(v2));
    return newVect;
}

struct vector* vectMultiplication(struct vector* v, double x){
    if(isVectorEmpty(v)){
        return;
    }
    struct vector *newVect = createEmptyVect();
    setX(newVect, getX(v) * x);
    setY(newVect, getY(v) * x);
    setZ(newVect, getZ(v) * x);
    return newVect;
}

double norm(struct vector* v){
    return sqrt(pow(getX(v), 2) + pow(getY(v), 2) + pow(getZ(v), 2));
}

void deleteVect(struct vector** v){
    if(v == NULL){
        return;
    }
    if(isVectorEmpty(*v)){
        return;
    }
    free(*v);
    *v = NULL;
}

void vectorTest(){
    if(!isVectorEmpty(NULL)){
        error("isVectorEmpty should return true with NULL pointer");
    }
    struct vector* newVector = createEmptyVect();
    if(isVectorEmpty(newVector)){
        error("isVectorEmpty should return false with freshly created vector pointer");
    }
    if(getX(newVector) != 0){
        error("getX should return 0 with freshly created vector");
    }
    if(getY(newVector) != 0){
        error("getY should return 0 with freshly created vector");
    }
    if(getZ(newVector) != 0){
        error("getZ should return 0 with freshly created vector");
    }
    setX(newVector, 123);
    if(getX(newVector) != 123){
        error("getX incorrect return value (with positive number tested) : check getX AND setX");
    }
    setX(newVector, -123);
    if(getX(newVector) != -123){
        error("getX incorrect return value (with negative number tested) : check getX AND setX");
    }
    setY(newVector, 10000000000000000000000000000000000.0);
    if(getY(newVector) != 10000000000000000000000000000000000.0){
        error("getX incorrect return value (with positive extreme high number tested) : check getX AND setX");
    }
    setY(newVector, -1000000000000000000000000000000.0);
    if(getY(newVector) != -1000000000000000000000000000000.0){
        error("getX incorrect return value (with negative extreme high number tested) : check getX AND setX");
    }
    setZ(newVector, 0.000000000000000000000000000001);
    if(getZ(newVector) != 0.000000000000000000000000000001){
        error("getX incorrect return value (with positive extreme low number tested) : check getX AND setX");
    }
    setZ(newVector, -0.000000000000000000000000000001);
    if(getZ(newVector) != -0.000000000000000000000000000001){
        error("getX incorrect return value (with negative extreme low number tested) : check getX AND setX");
    }
    deleteVect(&newVector); //Checking for memory leak -> check with valgrind
    struct vector* v1 = createEmptyVect();
    struct vector* v2 = createEmptyVect();
    setX(v1, 2);
    setX(v2, 3);
    setY(v1, -3.5);
    setY(v2, 5);
    setZ(v1, -10.0);
    setZ(v2, -11.5);
    struct vector* result = vectAddition(v1, v2);
    if(getX(result)!=5){
        error("addition of both entires positives numbers coordonate incorrect");
    }
    if(getY(result)!=1.5){
        error("addition of entire and float positive and negative numbers coordonate incorrect (can be normal with floating type and should be around 1.5");
        double additionResult = getY(result);
        printf("VALUE : %f\n", &additionResult);
    }
    if(getZ(result)!=-21.5){
        error("addition of both floating negative numbers coordonate incorrect (can be normal with floating type and should be around -21.5");
        double additionResult = getZ(result);
        printf("VALUE : %f\n", additionResult);
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectAddition(v1, NULL);
    if(result != NULL){
        error("vect addition by null pointer should return null");
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectAddition(NULL, NULL);
    if(result != NULL){
        error("vect addition by null pointer should return null");
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectAddition(NULL, v2);
    if(result != NULL){
        error("vect addition by null pointer should return null");
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectSubstraction(v1, v2);
    if(getX(result)!=-1){
        error("substraction of both entires positives numbers coordonate incorrect");
    }
    if(getY(result)!=-8.5){
        error("substraction of entire and float positive and negative numbers coordonate incorrect (can be normal with floating type and should be around -8.5");
        double substractionResult = getY(result);
        printf("VALUE : %f\n", &substractionResult);
    }
    if(getZ(result)!=1.5){
        error("substraction of both floating negative numbers coordonate incorrect (can be normal with floating type and should be around 1.5");
        double substractionResult = getZ(result);
        printf("VALUE : %f\n", &substractionResult);
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectSubstraction(v1, NULL);
    if(result != NULL){
        error("vect substraction by null pointer should return null");
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectSubstraction(NULL, NULL);
    if(result != NULL){
        error("vect substraction by null pointer should return null");
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    result = vectSubstraction(NULL, v2);
    if(result != NULL){
        error("vect substraction by null pointer should return null");
    }
    deleteVect(&result); //Checking for memory leak -> check with valgrind
    deleteVect(&v1); //Checking for memory leak -> check with valgrind
    vectMultiplication(NULL, 0); //Check for NULL -> may bring error to terminal/debugger or valgrind
    vectMultiplication(NULL, 225); //Check for NULL -> may bring error to terminal/debugger or valgrind
    v1 = createEmptyVect();
    vectMultiplication(v1, 0);
    if(getY(v1) != 0){
        error("Multiplication of freshly created vector should return 0 coordinates");
    }
    setY(v1, 225);
    vectMultiplication(v1, 0);
    if(getY(v1) != 0){
        error("Multiplication of vector by 0 should return 0 coordinates");
    }
    setY(v1, 1);
    setX(v1, 2.5);
    setZ(v1, -3);
    vectMultiplication(v1, 5);
    if(getY(v1) != 5){
        error("Vector Multiplication incorrect result");
    }
    if(getX(v1) != 12.5){
        error("Vector Multiplication incorrect result");
    }
    if(getZ(v1) != -15){
        error("Vector Multiplication incorrect result");
    }
    setY(v1, 0);
    setX(v1, 2);
    setZ(v1, 0);
    if(norm(v1) != 2){
        error("Vector norm incorrect result");
    }
    if(norm(NULL) != 0){
        error("Vector norm incorrect result for negative coordinate");
    }
    setY(v1, 0);
    setX(v1, 0);
    setZ(v1, -2);
    if(norm(v1) != 2){
        error("Vector norm incorrect result");
    }
    deleteVect(&v1); //Checking for memory leak -> check with valgrind
    deleteVect(&v2); //Checking for memory leak -> check with valgrind
    struct vector* v3 = createEmptyVect();
    deleteVect(&v3); // delete empty vect
    deleteVect(&v3); // delete already deleted vect
    deleteVect(NULL); //should not try to free
}