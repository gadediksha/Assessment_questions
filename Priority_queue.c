#include <stdio.h>

#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

// Insert element with priority
void insert(int value, int p)
{
    if (size == MAX)
    {
        printf("Priority Queue Overflow\n");
    }
    else
    {
        queue[size] = value;
        priority[size] = p;
        size++;
    }
}

// Delete element having highest priority
void deleteHighestPriority()
{
    int i, pos = 0;

    if (size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    // Find highest priority
    for (i = 1; i < size; i++)
    {
        if (priority[i] < priority[pos])
        {
            pos = i;
        }
    }

    printf("Deleted element: %d\n", queue[pos]);
    printf("Priority: %d\n", priority[pos]);

    // Shift remaining elements
    for (i = pos; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

// Display queue
void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Remaining elements with priorities:\n");

    for (i = 0; i < size; i++)
    {
        printf("Element = %d, Priority = %d\n",
               queue[i], priority[i]);
    }
}

int main()
{
    // Insert elements
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    // Delete highest priority element
    deleteHighestPriority();

    // Display remaining elements
    display();

    return 0;
}