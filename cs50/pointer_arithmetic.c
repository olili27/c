#include <stdio.h>

//  doing math on addresses

int main(void) {
    int i[] = {1,2,3};
    char s[] = "there";
    char *ss = "there again";

    printf("%c\n", *ss); // ss[0]
    printf("%c\n", *(ss + 1)); // ss[1]
    printf("%c\n", *(ss + 2)); // ss[2]
}