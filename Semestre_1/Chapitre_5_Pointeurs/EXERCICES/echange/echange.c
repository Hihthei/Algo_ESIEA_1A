#include<stdlib.h>
#include<stdio.h>

int echange(char* c1, char* c2) {
    if(c1 == NULL || c2 == NULL) return -1;
    else {
        char tmp = *c1;
        *c1 = *c2;
        *c2 = tmp;
    }
    return 0;
}