#include <stdio.h>

int main() {
    char c[5];
    int i[5];
    float f[5];
    double d[5];

    char (*cp)[5] = &c;
    int (*ip)[5] = &i;
    float (*fp)[5] = &f;
    double (*dp)[5] = &d;

    printf("char: %lu bytes int: %lu bytes float: %lu bytes double: %lu bytes ", sizeof(cp),sizeof(ip),sizeof(fp),sizeof(dp));

    printf("char: %lu bytes int: %lu bytes float: %lu bytes double: %lu bytes", sizeof(c),sizeof(i),sizeof(f), sizeof(d));
    return 0;
}
