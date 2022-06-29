#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#include "cell.h"


struct List{
    unsigned int size;
    struct Cell* head;
    struct Cell* queue;
};

struct List* createEmptyList();
bool isListEmpty(struct List*);
void addFirst(struct List*, struct point*);
void addLast(struct List*, struct point*);
struct point* getFirst(struct List*);
struct point* getLast(struct List*);
int listSize(struct List*);
void deleteFirst(struct List*); //Also delete all elements included -> do not double free
void deleteLast(struct List*);  //Also delete all elements included -> do not double free
void deleteList(struct List**); //Also delete all elements included -> do not double free
void listTest();