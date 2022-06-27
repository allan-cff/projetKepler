#include "list.h"


struct List* createEmptyList() {
    struct List *newList = malloc(sizeof(struct List));
    if (newList != NULL) {
        newList->size = 0;
        newList->head = NULL;
        newList->queue = NULL;
    }
    return newList;
}


bool isListEmpty(struct List *l) {
    return l == NULL || l->size == 0;
}


void addFirst(struct List *l, struct point* value) {
    if(l == NULL){
        return;
    }
    if(isPointEmpty(value)){
        return;
    }
    struct Cell *newCell = createCell(NULL, value, NULL);
    if(isListEmpty(l)){
        l->queue = newCell;
    }
    else {
        setNext(newCell, l->head);
        setPrevious(l->head, newCell);
    }
    l->head = newCell;
    l->size++;
}


void addLast(struct List *l, struct point* value) {
    if(l == NULL){
        return;
    }
    if(isPointEmpty(value)){
        return;
    }
    struct Cell *newCell = createCell(NULL, value, NULL);
    if(isListEmpty(l)){
        l->head = newCell;
    }
    else {
        setPrevious(newCell, l->queue);
        setNext(l->queue, newCell);
    }
    l->queue = newCell;
    l->size++;
}


struct point* getFirst(struct List* l){
    if (isListEmpty(l)) {
        return NULL;
    }
    return readCell(l->head);
}


struct point* getLast(struct List* l){
    if (isListEmpty(l)) {
        return NULL;
    }
    return readCell(l->queue);
}


void deleteFirst(struct List* l) {
    if (!isListEmpty(l)) {
        struct Cell* precedentHead = l->head;
        l->head = l->head->next;
        setPrevious(l->head, NULL);
        l->size--;
        deleteCell(&precedentHead);
    }
}


void deleteLast(struct List* l) {
    if (!isListEmpty(l)) {
        struct Cell* precedentQueue = l->queue;
        l->queue = l->queue->previous;
        setNext(l->queue, NULL);
        l->size--;
        deleteCell(&precedentQueue);
    }
}


int listSize(struct List* l){
    if(isListEmpty(l)){
        return -1;
    }
    return l->size;
}


void deleteList(struct List** l) {
    if(l == NULL){
        return;
    }
    while (!isListEmpty(*l)) {
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}

void listTest(){
    if(!isListEmpty(NULL)){
        error("is list empty should return true with null pointer");
    }
    struct List* newList = createEmptyList();
    if(!isListEmpty(newList)){
        error("is list empty should return true with freshly created list (size 0)");
    }
    struct point* pA = createEmptyPoint();
    struct point* pB = createEmptyPoint();
    struct point* pC = createEmptyPoint();
    struct point* pD = createEmptyPoint();
    addFirst(newList, pA);
    if(isListEmpty(newList)){
        error("is list empty should return false with item added in first pos");
    }
    if(getLast(newList)!=pA){
        error("only element of list should be first and last");
    }
    addLast(newList, pB);
    addLast(newList, pC);
    struct vector* vA = createEmptyVect();
    struct vector* vB = createEmptyVect();
    setPos(pD, vA);
    setSpeed(pD, vB);
    addFirst(newList, pD);
    if(getFirst(newList)!=pD){
        error("getFirst wrong return : check all get and all set functions");
    }
    if(getLast(newList)!=pC){
        error("getLast wrong return : check all get and all set functions");
    }
    deleteFirst(newList); // should free point -> check valgrind
    deleteLast(newList); // should free point -> check valgrind
    if(getFirst(newList)!=pA){
        error("getFirst wrong return : check all get and all set functions");
    }
    if(getLast(newList)!=pB){
        error("getLast wrong return : check all get and all set functions");
    }
    deleteLast(newList); // should free point -> check valgrind
    deleteFirst(newList); // should free point -> check valgrind
    if(!isListEmpty(newList)){
        error("is list empty should return true with all items removed");
    }
    deleteList(&newList); //should have nothing to delete -> check valgrind
    struct point* p1 = createEmptyPoint();
    struct List* list1 = createEmptyList();
    addFirst(NULL, p1);
    addLast(NULL, p1);
    addFirst(list1, NULL);
    addLast(list1, NULL);
    if(getLast(list1)!=NULL){
        error("empty list should return null at read");
    }
    if(getFirst(list1)!=NULL){
        error("empty list should return null at read");
    }
    deleteLast(list1); //should have nothing to delete -> check valgrind
    deleteFirst(list1); //should have nothing to delete -> check valgrind
    deleteLast(NULL); //should have nothing to delete -> check valgrind
    deleteFirst(NULL); //should have nothing to delete -> check valgrind
    addLast(list1, p1);
    if(getFirst(list1)!=p1){
        error("only element of list should be first and last");
    }
    deleteList(&list1); //should delete completely 1 element (free cell and point)
    deleteList(NULL); //should have nothing to delete -> check valgrind
    struct List* l2 = createEmptyList();
    struct point* po1 = createEmptyPoint();
    struct point* po2 = createEmptyPoint();
    struct point* po3 = createEmptyPoint();
    struct point* po4 = createEmptyPoint();
    struct vector* ve1 = createEmptyVect();
    struct vector* ve2 = createEmptyVect();
    setSpeed(po2, ve1);
    setPos(po4, ve2);
    addFirst(l2, po1);
    addFirst(l2, po2);
    addLast(l2, po4);
    addFirst(l2, po3);
    deleteList(&l2); //should free everything above
}