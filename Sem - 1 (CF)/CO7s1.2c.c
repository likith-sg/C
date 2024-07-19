
#include <stdio.h>

int isPerfect(int num) {
    int sum = 1; 

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

void printPerfectNumbersInRange(int start, int end) {
    printf("Perfect numbers in the range %d to %d are:\n", start, end);

    for (int i = start; i <= end; ++i) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int start, end;

    printf("Enter the starting number of the range: ");
    scanf("%d", &start);
    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    printPerfectNumbersInRange(start, end);

    return 0;
}
