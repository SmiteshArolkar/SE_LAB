#include "stdio.h"


struct NODE
{
    /* data */
    int data;
    struct NODE* next;
};

typedef struct NODE node;



int base_convert(int n, int base);
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
int gcd(int a, int b);
void reverse_a_string(char*);

int main()
{
    base_convert(12, 2);
    printf("\n");
    towerOfHanoi(3, 'A', 'B', 'C');

    printf("%d\n", gcd(98, 56));
    char a[] = "abcdef";
    reverse_a_string(a);
}

int base_convert(int n, int base)
{

    if (n == 0)
    {
        printf("0");
        return 0;
    }
    if (n == 1)

    {
        printf("1");
        return 0;
    }
    else
    {
        base_convert(n / base, base);
    }
    printf("%d", n % base);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c \n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

void reverse_a_string(char *a)
{
    if (*a)
    {
        reverse_a_string(a + 1);
        printf("%c", *a);
    }
}