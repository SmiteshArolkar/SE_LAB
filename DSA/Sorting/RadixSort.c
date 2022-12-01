#include "stdio.h"
#include "malloc.h"

struct node
{
    int info;
    struct node *next;
} *start = NULL;

typedef struct node node;

void radixSort();
int largest_digit();
int digit(int number, int k);

int main()
{
}
int digit(int number, int k)
{
    int digit;
    for (int i = 1; i <= k; k++)
    {
        digit = number % 10;
        number = number / 10;
    }
    return digit;
}
int largest_digit()
{
    struct node *p = start;
    int large = 0, ndig = 0;
    while (p != NULL)
    {
        if (p->info > large)
            large = p->info;
        p = p->next;
    }
    while (large != 0)
    {
        ndig++;
        large = large / 10;
        /* code */
    }

    return ndig;
}

void radixSort()
{
    int digit_i, lsb, msb;
    struct node *p, *rear[10], *front[10];
    lsb = 1;                    // units place
    msb = largest_digit(start); // msb 's place

    for (int k = lsb; k <= msb; k++) // 0-msb times construct sort table
    {
        for (int i = 0; i <= 9; i++) // init to null
        {
            rear[i] = NULL;
            front[i] = NULL;
        }
        for (p = start; p != NULL; p = p->next) // process for kth place
        {
            digit_i = digit(p->info, k); // extract k'th place digit for list element
            if (front[digit_i] == NULL)  // check if already inserted element
            {
                front[digit_i] = p; // insert at front
            }
            else
                rear[digit_i]->next = p; // insert at back

            rear[digit_i] = p; // update back
        }
        int i;
        for (i = 0; front[i] != NULL; i++) // to check if inital fronts are not null
        {
        }
        start = front[i];

        while (i < 9) // number of digits 0-9 [table connection]
        {
            if (front[i + 1] != NULL)         // check if empty slot
                rear[i]->next = front[i + 1]; // if not make connection
            else
                rear[i + 1] = rear[i]; // update empty slot rear
            i++;
        }
        rear[9]->next = NULL; // make final rear to null
    }
}