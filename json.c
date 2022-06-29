#include "json.h"

void goTo(FILE *fp, char limit) {
    char currentCharacter;
    do {
        currentCharacter = fgetc(fp);
    } while (!feof(fp) || currentCharacter != limit);
}

char *readProperty(FILE *fp) {
    char currentWord[32];
    char currentCharacter = '\n';
    while (!feof(fp) || currentCharacter != ':') {
        currentCharacter = fgetc(fp);
        if (currentCharacter >= 'a' && currentCharacter <= 'z' ||
            currentCharacter >= 'A' && currentCharacter <= 'Z' ||
            currentCharacter >= '0' && currentCharacter <= '9') {
            strcat(currentWord, &currentCharacter);
        }
    }
    return currentWord;
}

char *readValue(FILE *fp) {
    char currentWord[32];
    char currentCharacter = '\n';
    while (!feof(fp) || currentCharacter != ',' || currentCharacter != '}') {
        currentCharacter = fgetc(fp);
        if (currentCharacter >= 'a' && currentCharacter <= 'z' ||
            currentCharacter >= 'A' && currentCharacter <= 'Z' ||
            currentCharacter >= '0' && currentCharacter <= '9' || currentCharacter == '+' || currentCharacter == '-' ||
                currentCharacter == '#') {
            strcat(currentWord, currentCharacter);
        }
    }
    return currentWord;
}

void readSysteme(FILE *fp, int counter) {
    char* property = readProperty(fp);
    if (property == "star") {
        goTo(fp, '{');
        readStar(fp, 0);
        counter++;
        if (counter >= 5) {
            return;
        } else {
            readSysteme(fp, counter);
        }
    }
    if (property == "method") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 5) {
            return;
        } else {
            readSysteme(fp, counter);
        }
    }
    if (property == "deltaTime") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 5) {
            return;
        } else {
            readSysteme(fp, counter);
        }
    }
    if (property == "id") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 5) {
            return;
        } else {
            readSysteme(fp, counter);
        }
    }
    if (property == "name") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 5) {
            return;
        } else {
            readSysteme(fp, counter);
        }
    }
}

void readStar(FILE *fp, int counter) {
    char* property = readProperty(fp);
    if (property == "name") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readStar(fp, counter);
        }
    }
    if (property == "color") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readStar(fp, counter);
        }
    }
    if (property == "mass") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readStar(fp, counter);
        }
    }
    if (property == "children") {
        readAllPlanets(fp);
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readStar(fp, counter);
        }
    }
}

void readAllPlanets(FILE *fp){
    readPlanet(fp, 0);
    char c;
    do {
        c = fgetc(fp);
    }
    while(c != "," || c != "}");
    if(c == ","){
        readAllPlanets(fp);
    }
}

void readPlanet(FILE *fp, int counter) {
    char* property = readProperty(fp);
    if (property == "mass") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readPlanet(fp, counter);
        }
    }
    if (property == "perihelion") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readPlanet(fp, counter);
        }
    }
    if (property == "eqRadius") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readPlanet(fp, counter);
        }
    }
    if (property == "eccentricity") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readPlanet(fp, counter);
        }
    }
    if (property == "color") {
        printf("%s",readValue(fp));
        counter++;
        if (counter >= 4) {
            return;
        } else {
            readPlanet(fp, counter);
        }
    }
}