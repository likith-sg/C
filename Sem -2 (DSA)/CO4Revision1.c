#include <stdio.h>

int main() {
    char *c;
    int *i;
    float *f;
    double *d;

    printf("char : %lu bytes int : %lu bytes float : %lu bytes double : %lu bytes" ,sizeof(c), sizeof(i), sizeof(f), sizeof(d));
    return 0;
}
