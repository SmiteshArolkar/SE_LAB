#include "stdio"

struct Node
{
    int data;
    struct node *next;
};

typedef struct Node node;

void getDigit(int number, int place)
{
    int digit = 0;
    for (int i = 0; i < place; i++)
    {
        digit = number % 10;
        number = number / 10;
    }
    return digit;
}
int getLargest(node *front)
{
    int largest = 0;
    while (front)
    {
        if (front->data > largest)
            largest = front->data;
        front = front->next;
    }
    int digit = 0;
    while (largest != 0)
    {
        largest /= 10;
        digit++;
    }
    return digit;
}

void radixSort(node *start)
{
    int lsb = 1, msb = getLargest(start);
    node *front[10], *rear[10];

    for (int i = lsb; i <= msb; i++)
    {
        for (int i = 0; i < 10; i++)
            front[i] = rear[i] = NULL;
        for (node *ptr = start; ptr != NULL; ptr = ptr->next)
        {
            int dig = getDigit(ptr->data, i);
            if (front[dig] == NULL)
                front[dig] = p;
            else
                rear[dig]->next = p;
            rear[dig] = p;
        }
        int j = 0;
        while (front[j] == NULL)
            j++;
        start = front[j];
        while (j < 10)
        {
            if (front[j + 1] != NULL)
            {
                rear[j]->next = front[j + 1];
            }
            else
                rear[j + 1] = rear[j];
            j++;
        }
        rear[9]->next = NULL;
    }
    return start;
}
void display(node *start)
{
    while (start)
    {
        printf("%d\t", start->data);
        start = start->next;
    }
    printf("\n");
}
int main()
{
    
}