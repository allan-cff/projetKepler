#ifndef BASIC_IMPORT
#define BASIC_IMPORT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#endif

#ifndef PROGRAMM_JSON_H
#define PROGRAMM_JSON_H
void goTo(FILE *fp, char limit);
char *readProperty(FILE *fp);
char *readValue(FILE *fp);
void readSysteme(FILE *fp, int counter);
void readStar(FILE *fp, int counter);
void readPlanet(FILE *fp, int counter);
void readAllPlanets(FILE *fp);
#endif