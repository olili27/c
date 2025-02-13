#include<stdio.h>

void cough(void) {
    printf("coughing\n");
}

int main() {
    for (int i = 0; i < 3; i++) {
        cough();
    }
    return 0;
}