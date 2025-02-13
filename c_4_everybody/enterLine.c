#include <stdio.h>

int main() {
    char line[1000];
    printf("Enter line\n");
    scanf("%[^\n]1000s", line); // match any character that is not a new line. read upto the a newline character(only 1000 characters)
    printf("Line: %s\n", line);
}