#include "trajectory.h"

struct traj* createEmptyTraj(){
    struct traj* newTraj = malloc(sizeof(struct traj));
    if(newTraj){
        newTraj -> pointList = createEmptyList();
    } else {
        printf("***** MALLOC ERROR : cannot create new trajectory *****");
    }
    return newTraj;
}


bool isTrajEmpty(struct traj* traj){
    return traj == NULL;
}


struct point* seeLastPointTraj(struct traj* traj){
    if(isTrajEmpty(traj)){
       return NULL;
    }
    return getLast(traj->pointList);
}


void addPointTraj(struct traj* traj, struct point* p){
    if(isTrajEmpty(traj)){
        return;
    }
    addLast(traj->pointList, p);
}


struct point* readFirstPointTraj(struct traj* traj){
    if(isTrajEmpty(traj)){
        return NULL;
    }
    struct point* result = getFirst(traj->pointList);
    deleteFirst(traj->pointList);
    return result;
}


int trajLen(struct traj* t){
    if(isTrajEmpty(t)){
        return -1;
    }
    return listSize(t->pointList);
}


void deleteTraj(struct traj** traj){
    if(traj == NULL){
        return;
    }
    if(isTrajEmpty(*traj)){
        return;
    }
    deleteList(&((*traj)->pointList));
    free(*traj);
    *traj = NULL;
}

void trajTest(){
    if(!isTrajEmpty(NULL)){
        error("is traj empty should return true with null pointer");
    }
    struct traj* newTraj = createEmptyTraj();
    if(isTrajEmpty(newTraj)){
        error("is traj empty should return false with freshly created traj");
    }
    addPointTraj(newTraj, NULL); // should add nothing : check with debugger
    if(seeLastPointTraj(NULL) != NULL){
        error("see last point should return null for null pointer");
    }
    if(seeLastPointTraj(newTraj) != NULL){
        error("see last point should return null for empty traj");
    }
    if(readFirstPointTraj(NULL) != NULL){
        error("read first point should return null for null pointer");
    }
    if(readFirstPointTraj(newTraj) != NULL){
        error("read first point should return null for empty traj");
    }
    struct point* p1 = createEmptyPoint();
    addPointTraj(NULL, p1); // should add nothing : check with debugger
    addPointTraj(newTraj, p1);
    if(seeLastPointTraj(newTraj) != p1){
        error("see last point bad return for NON empty traj");
    }
    if(readFirstPointTraj(newTraj) != p1){
        error("read first point bad return for NON empty traj");
    }
    deleteTraj(&newTraj);
    deleteTraj(NULL);
    struct traj* traj2 = createEmptyTraj();
    struct point* p2 = createEmptyPoint();
    struct point* p3 = createEmptyPoint();
    addPointTraj(traj2, p2);
    addPointTraj(traj2, p3);
    if(seeLastPointTraj(traj2) != p3){
        error("see last point bad return for NON empty traj");
    }
    deleteTraj(&traj2); //should clean everything -> check with valgrind
}