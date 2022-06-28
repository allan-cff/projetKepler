#include "object.h"

#ifndef ERROR_FUNCTION
#define ERROR_FUNCTION
void error(char* message){
    printf("***** ERROR VECTOR : ");
    printf("%s", message);
    printf(" *****\n");
}
#endif


int main() {
/*    vectorTest();
    pointTest();
    listTest();
    trajTest();
    objectTest();*/

    struct object* Soleil = initialize(1.988e30, 0, NULL);
    setName(Soleil, "Soleil");
    struct object* Mercure = initialize(3.3011e23, 46001200000, Soleil);
    setName(Mercure, "mercyry-euler");
    struct object* MercureA = initialize(3.3011e23, 46001200000, Soleil);
    setName(MercureA, "mercury-asym");
    struct object* Venus = initialize(4.8675e24, 107476000000, Soleil);
    setName(Venus, "venus-euler");
    struct object* VenusA = initialize(4.8675e24, 107476000000, Soleil);
    setName(VenusA, "venus-asym");
    struct object* Terre = initialize(5.9736e24, 147098074000, Soleil);
    setName(Terre, "earth-euler");
    struct object* TerreA = initialize(5.9736e24, 147098074000, Soleil);
    setName(TerreA, "earth-asym");
    struct object* Mars = initialize(6.4185e23, 206655000000, Soleil);
    setName(Mars, "mars-euler");
    struct object* MarsA = initialize(6.4185e23, 206655000000, Soleil);
    setName(MarsA, "mars-asym");
    struct point* origin = createPoint(createVect(0, 0, 0), createVect(0, 0, 0), 0);
    addPoint(Soleil, origin);
    setFirstPoint(Terre, 149597887500, 0.01671022);
    setFirstPoint(TerreA, 149597887500, 0.01671022);
    setFirstPoint(Mercure, 57909050000, 0.2056);
    setFirstPoint(MercureA, 57909050000, 0.2056);
    setFirstPoint(Venus, 108209500000, 0.00678);
    setFirstPoint(VenusA, 108209500000, 0.00678);
    setFirstPoint(Mars, 227944000000, 0.09339);
    setFirstPoint(MarsA, 227944000000, 0.09339);
    for(unsigned i = 0; i < 40000; i++){
        processEulerNextPoint(Mercure, 8640);
        processAsymEulerNextPoint(MercureA, 8640);
        processEulerNextPoint(Venus, 8640);
        processAsymEulerNextPoint(VenusA, 8640);
        processEulerNextPoint(Terre, 8640);
        processAsymEulerNextPoint(TerreA, 8640);
        processEulerNextPoint(Mars, 8640);
        processAsymEulerNextPoint(MarsA, 8640);
    }

    FILE *p1;
    p1 = fopen("./sysSolaire.json", "w");
    if (p1 == NULL) {
        printf("Error in opening file");
        return 1;
    }
    fprintf(p1, "{");
    addToFile(p1, Mercure);
    fprintf(p1, ",");
    addToFile(p1, MercureA);
    fprintf(p1, ",");
    addToFile(p1, Venus);
    fprintf(p1, ",");
    addToFile(p1, VenusA);
    fprintf(p1, ",");
    addToFile(p1, Terre);
    fprintf(p1, ",");
    addToFile(p1, TerreA);
    fprintf(p1, ",");
    addToFile(p1, Mars);
    fprintf(p1, ",");
    addToFile(p1, MarsA);
    fprintf(p1, "}");
    fclose(p1);
    deleteObject(&Soleil);
    deleteObject(&Terre);
    deleteObject(&Terre);
    deleteObject(&Mercure);
    deleteObject(&MercureA);
    deleteObject(&Venus);
    deleteObject(&VenusA);
    deleteObject(&Mars);
    deleteObject(&MarsA);
    return 0;
}
