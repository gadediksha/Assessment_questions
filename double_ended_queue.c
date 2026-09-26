#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert from Front
void insertFront(int value)
{
    if (front == 0)
    {
        printf("Deque Overflow at Front\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            front--;
        }

        deque[front] = value;
    }
}

// Insert from Rear
void insertRear(int value)
{
    if (rear == MAX - 1)
    {
        printf("Deque Overflow at Rear\n");
    }
    else
    {
        if (rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }

        deque[rear] = value;
    }
}

// Delete from Front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
    }
    else
    {
        printf("Deleted from Front: %d\n", deque[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

// Delete from Rear
void deleteRear()
{
    if (rear == -1)
    {
        printf("Deque Underflow\n");
    }
    else
    {
        printf("Deleted from Rear: %d\n", deque[rear]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear--;
        }
    }
}

// Display Deque
void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Remaining elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }

        printf("\n");
    }
}

int main()
{
    // Insert 10 from Front
    insertFront(10);

    // Insert 20 from Rear
    insertRear(20);

    // Insert 30 from Front
    insertFront(30);

    // Delete one element from Front
    deleteFront();

    // Delete one element from Rear
    deleteRear();

    // Display remaining elements
    display();

    return 0;
}