#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isempty(struct Queue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct Queue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct Queue *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Queue is full\n");
    }

    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = val;
        printf("Elment in the queue is %d\n", val);
    }
}
int dequeue(struct Queue *ptr)
{
    int a = -1;
    if (isempty(ptr))
    {
        printf("Queue is empty\n"); /* code */
    }
    else
    {
        ptr->f=(ptr->f+1)%ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct Queue q;

    q.size = 4;
    q.f = q.r = -0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 4);
    enqueue(&q, 42);
    enqueue(&q, 41);
    
    printf("Element dequeued from queue is %d\n", dequeue(&q));
    printf("Element dequeued from queue is %d\n", dequeue(&q));
    printf("Element dequeued from queue is %d\n", dequeue(&q));
    // printf("Element dequeued from queue is %d\n", dequeue(&q));
    enqueue(&q, 49);
     enqueue(&q, 42);
      enqueue(&q, 2);
    enqueue(&q, 9);

}