#include "object.c"
#ifndef ERROR_FUNCTION
#define ERROR_FUNCTION
void error(char* message){
    printf("***** ERROR VECTOR : ");
    printf("%s", message);
    printf(" *****\n");
}
#endif


int main() {
    vectorTest();
    pointTest();
    listTest();
    trajTest();
    objectTest();
    return 0;
}
