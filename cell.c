#include "cell.h"

struct Cell* createCell(struct Cell* prev, struct point* val, struct Cell* next) {
    struct Cell* newCell = malloc(sizeof(struct Cell));
    if (newCell != NULL) {
        newCell->value = val;
        newCell->next = next;
        newCell->previous = prev;
    } else {
        printf("***** MALLOC ERROR : cannot create new cell *****");
    }
    return newCell;
}


bool isCellEmpty(struct Cell* c){
    return c == NULL;
}


void setNext(struct Cell* c, struct Cell* next){
    if(isCellEmpty(c)){
        return;
    }
    c->next = next;
}


void setPrevious(struct Cell* c, struct Cell* prev){
    if(isCellEmpty(c)){
        return;
    }
    c->previous = prev;
}


struct point* readCell(struct Cell* c){
    if(isCellEmpty(c)){
        return NULL;
    }
    return c->value;
}

void deleteCell(struct Cell** c){
    if(c == NULL){
        return;
    }
    if(isCellEmpty(*c)){
        return;
    }
    struct point* pointToDelete = readCell(*c);
    deletePoint(&pointToDelete);
    free(*c);
    *c = NULL;
}