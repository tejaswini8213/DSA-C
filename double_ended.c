#include <stdio.h>

// Double Ended Queue
// Queue One: 8 7 10 9
// Queue Two: 1 9 6 3
// Total Queue: 8 7 10 9 1 9 6 3

int hold = -1;
int queue_one_front = 0;
int queue_two_front = 0;
int queue_one_rear = 0;
int queue_two_rear = 0;

void enqueue_one(int queue[], int val)
{
    if (queue_one_rear + queue_two_rear == 5)
    {
        printf("Overflow");
    }
    {
        queue[queue_one_rear] = val;
        queue_one_front = 0;
        queue_one_rear++;
        queue_two_rear++;
    }
}

void enqueue_two(int queue[], int val)
{
    if (queue_one_rear + queue_two_rear == 5)
    {
        printf("Overflow");
    }
    else
    {
        queue[queue_two_rear] = val;
        queue_two_rear++;
        queue_one_rear++;
    }
}

int dequeue_one(int queue[])
{
    int size = sizeof(*queue / queue[0]);
    int val = queue[queue_one_front];
    for (int i = 0; i < size; i++)
    {
        queue[queue_one_rear] = queue[queue_one_rear--];
    }
    return val;
}

int dequeue_two(int queue[])
{
    int size = sizeof(*queue / queue[0]);
    int val = queue[queue_two_front];
    queue_two_front++;
    for (int i = 0; i < size; i++)
    {
        queue[queue_two_rear] = queue[queue_one_rear--];
    }
    return val;
}

void main()
{
    int array[5];
    enqueue_one(array, 3);
    enqueue_one(array, 4);
    enqueue_one(array, 2);
    enqueue_two(array, 1);
    enqueue_two(array, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    // printf("Dequeue value one %/d \n", val_one);
}