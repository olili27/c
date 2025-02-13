#include<stdio.h>

int main() {
    printf("Tell us about yourself: ");

    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}