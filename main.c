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

/*    FILE *fp1 = fopen("./../../panel/systemsList.json", "r");  // running with Valgrind errors
    if (fp1 == NULL) {
        printf("Error in opening file");
        return 1;
    }
    char systemsList[MAX_SYSTEMS_NUMBER][MAX_SYSTEM_NAME_LEN];
    char currentCharacter;
    unsigned int j = 0;
    unsigned int k = 0;
    while (!feof(fp1)) {
        currentCharacter = fgetc(fp1);
        if (currentCharacter >= 'a' && currentCharacter <= 'z' || currentCharacter >= 'A' && currentCharacter <= 'Z' ||
            currentCharacter == ',') {
            if (currentCharacter == ',' || k == MAX_SYSTEM_NAME_LEN) {
                j++;
                k = 0;
            } else {
                systemsList[j][k] = currentCharacter;
                k++;
            }
        }
        if (j == MAX_SYSTEMS_NUMBER) {
            break;
        }
    }
    fclose(fp1);

    int selection;
    do {
        printf("\nMenu principal :\nChoix du système à générer : \n");
        for (unsigned int i = 0; i < (j + 1); i++) {
            printf("%d-%s\n", i + 1, systemsList[i]);
        }
        printf("Votre choix :");
        scanf("%d", &selection);
    } while (selection < 1 || selection > j+1);


    char* directory = malloc(32*sizeof(char));
    if(directory!=NULL) {
        strcat(directory, "\n./../../panel/systems/");
        strcat(directory, systemsList[selection - 1]);
        strcat(directory, "/config.json");
        printf("\n\nOuverture du fichier : %s", directory);
    }
    free(directory);
*/


    /*FILE *fp2;
    fp2 = fopen("./../../panel/systems/solarSystem/config.json", "r");
    if (fp2 == NULL) {
        printf("\nError in opening file");
        return 1;
    }*/


// Not implemented yet
    /*char currentWord[32];
    currentCharacter = '\n';
    goTo(fp2, '{');
    readSysteme(fp2, 0);
    */


// Malloc error
    //printf("\n\nEntrer le nombre de points à calculer : ");
    //int numberOfPoints;
    //scanf("%d", &numberOfPoints);

    printf("\nGénération de la trajectoire");
    struct object *Soleil = initialize(1.988e30, 0, NULL);
    setName(Soleil, "Soleil");
    struct object *Mercure = initialize(3.3011e23, 46001200000, Soleil);
    setName(Mercure, "mercury-euler");
    struct object *MercureA = initialize(3.3011e23, 46001200000, Soleil);
    setName(MercureA, "mercury-asym");
    struct object *Venus = initialize(4.8675e24, 107476000000, Soleil);
    setName(Venus, "venus-euler");
    struct object *VenusA = initialize(4.8675e24, 107476000000, Soleil);
    setName(VenusA, "venus-asym");
    struct object *Terre = initialize(5.9736e24, 147098074000, Soleil);
    setName(Terre, "earth-euler");
    struct object *TerreA = initialize(5.9736e24, 147098074000, Soleil);
    setName(TerreA, "earth-asym");
    struct object *Mars = initialize(6.4185e23, 206655000000, Soleil);
    setName(Mars, "mars-euler");
    struct object *MarsA = initialize(6.4185e23, 206655000000, Soleil);
    setName(MarsA, "mars-asym");
    struct point *origin = createPoint(createVect(0, 0, 0), createVect(0, 0, 0), 0);
    addPoint(Soleil, origin);
    setFirstPoint(Terre, 149597887500, 0.01671022);
    setFirstPoint(TerreA, 149597887500, 0.01671022);
    setFirstPoint(Mercure, 57909050000, 0.2056);
    setFirstPoint(MercureA, 57909050000, 0.2056);
    setFirstPoint(Venus, 108209500000, 0.00678);
    setFirstPoint(VenusA, 108209500000, 0.00678);
    setFirstPoint(Mars, 227944000000, 0.09339);
    setFirstPoint(MarsA, 227944000000, 0.09339);
    processMecEnergy(Mercure);
    processMecEnergy(MercureA);
    processMecEnergy(Venus);
    processMecEnergy(VenusA);
    processMecEnergy(Terre);
    processMecEnergy(TerreA);
    processMecEnergy(Mars);
    processMecEnergy(MarsA);
    for (unsigned i = 0; i < 60000; i++) {
        processEulerNextPoint(Mercure, 8640);
        processMecEnergy(Mercure);
        processAsymEulerNextPoint(MercureA, 8640);
        processMecEnergy(MercureA);
        processEulerNextPoint(Venus, 8640);
        processMecEnergy(Venus);
        processAsymEulerNextPoint(VenusA, 8640);
        processMecEnergy(VenusA);
        processEulerNextPoint(Terre, 8640);
        processMecEnergy(Terre);
        processAsymEulerNextPoint(TerreA, 8640);
        processMecEnergy(TerreA);
        processEulerNextPoint(Mars, 8640);
        processMecEnergy(Mars);
        processAsymEulerNextPoint(MarsA, 8640);
        processMecEnergy(MarsA);
    }

    FILE *p1;
    p1 = fopen("./../../panel/systems/solarSystem/trajectory.json", "w");
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
    printf("\n*** Précision de la trajectoire : ***");
    printf("\nAverage Energy variation for mercury euler : %e", getAvEnergy(Mercure));
    printf("\nAverage Energy variation for mercury asymetric : %e", getAvEnergy(MercureA));
    printf("\nAverage Energy variation for venus euler : %e", getAvEnergy(Venus));
    printf("\nAverage Energy variation for venus asymetric : %e", getAvEnergy(VenusA));
    printf("\nAverage Energy variation for earth euler : %e", getAvEnergy(Terre));
    printf("\nAverage Energy variation for earth asymetric : %e", getAvEnergy(TerreA));
    printf("\nAverage Energy variation for mars euler : %e", getAvEnergy(Mars));
    printf("\nAverage Energy variation for mars asymetric : %e", getAvEnergy(MarsA));
    deleteObject(&Soleil);
    deleteObject(&Terre);
    deleteObject(&TerreA);
    deleteObject(&Mercure);
    deleteObject(&MercureA);
    deleteObject(&Venus);
    deleteObject(&VenusA);
    deleteObject(&Mars);
    deleteObject(&MarsA);
    printf("\n\nFichier trajectoire mis à jour dans le répertoire panel/systems/solarSystem");
    return 0;
}
