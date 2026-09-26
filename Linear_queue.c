#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert element into queue
void insert(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
    }
}

// Delete element from front
void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        
        // Reset pointers if the queue becomes empty
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

// Display queue
void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Remaining elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    // Insert 10, 20 and 30
    insert(10);
    insert(20);
    insert(30);

    // Delete two elements
    delete();
    delete();

    // Insert 40
    insert(40);

    // Display remaining elements
    display();

    return 0;
}