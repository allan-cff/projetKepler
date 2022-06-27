#include "object.h"

#ifndef ERROR_FUNCTION
#define ERROR_FUNCTION
/*void error(char* message){
    printf("***** ERROR VECTOR : ");
    printf("%s", message);
    printf(" *****\n");
}*/
#endif


int main() {
/*    vectorTest();
    pointTest();
    listTest();
    trajTest();
    objectTest();*/

    struct object* Soleil = initialize(1.988*pow(10,30), 0, NULL);
    setName(Soleil, "Soleil");
    struct object* Terre = initialize(5.973*pow(10,24), 147098074, Soleil);
    setName(Terre, "Terre");
    setFirstPoint(Terre, 149597887, 0.01671022);
    processEulerNextPoint(Terre, 8640);

    return 0;
}
