#include <stdio.h>

int main() {
    int myMult();

    int retVal = myMult(6, 7);
    printf("%d", retVal);
}

int myMult(a, b) int a, b; {
    return a * b;
}