#include <stdio.h>

struct cut_store
{
    char name[30];
    int acc_num;
    int acc_Bal;
};

void balance_check(int a);

int main()
{
    struct cut_store c1;

    printf("Enter name: ");
    scanf("%s", c1.name);

    printf("Enter account number: ");
    scanf("%d", &c1.acc_num);

    printf("Enter account balance: ");
    scanf("%d", &c1.acc_Bal);

    balance_check(c1.acc_Bal);

    return 0;
}

void balance_check(int a)
{
    if (a < 200)
    {
        printf("Balance is less than 200\n");
    }
    else if (a > 1000)
    {
        a = a + 100;
        printf("Balance after adding Rs. 100: %d\n", a);
    }
}
