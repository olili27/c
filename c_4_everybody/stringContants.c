#include <stdio.h>

int main() {
    char x[3] = "hi";
    char y[3] = {'h', 'i'};
    printf("x %s\n", x);
    printf("y %s\n", y);
    printf("%s\n", "hi");
    printf("%c%c\n", 'h', 'i');
}