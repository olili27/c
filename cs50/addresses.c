#include <cs50.h>
#include <stdio.h>

// & -  address of(at what address is this variable)
// * - dereference operator(take an address and go it to see whats actually there)

int main(void) {
    // int n = 50;
    // int *p = &n; // pointer 8bytes on 64 and 4bytes on 32

    // int v = *p; // get tha value at this address, dereference
    // // %p format code for printing an address

    // printf("%i\n", n);
    // printf("%p\n", p);
    // printf("%i\n", v);

    string s = "HI!"; // char *s = "HI!";
    printf("%p\n", s);
    char *name = get_string("name: ");
}

// pointer - address of a variable int *p = &n;