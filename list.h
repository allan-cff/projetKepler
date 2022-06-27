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
void deleteFirst(struct List*);
void deleteLast(struct List*);
void deleteList(struct List**);
void listTest();