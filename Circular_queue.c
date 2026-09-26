#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert element
void insert(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;
    }
}

// Delete element
void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

// Display elements
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    // Insert 10, 20, 30 and 40
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    // Delete two elements
    delete();
    delete();

    // Insert 50 and 60
    insert(50);
    insert(60);

    // Display queue
    display();

    return 0;
}