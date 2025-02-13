#include <stdio.h>

int main() {
    int val, max, min, first = 1;

    while(scanf("%d", &val) != EOF) {
        if(first || val > max)
            max = val;
        if (first || val < min)
            min = val;

        first = 0;
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
}