#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#include "point.h"

struct Cell{
    struct point* value;
    struct Cell* next;
    struct Cell* previous;
};

struct Cell* createCell(struct Cell*, struct point*, struct Cell*);
bool isCellEmpty(struct Cell*);
void setNext(struct Cell*, struct Cell*);
void setPrevious(struct Cell*, struct Cell*);
struct point* readCell(struct Cell*);
void deleteCell(struct Cell**);