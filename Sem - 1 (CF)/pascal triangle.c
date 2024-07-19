#include <stdio.h>

int main() {
    int n, co;


    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        for (int space = 0; space < n - i - 1; space++) {
            printf("  ");
        }

        co = 1;
        for (int j = 0; j <= i; j++) {

            printf("%d   ", co);
            co = co * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}

