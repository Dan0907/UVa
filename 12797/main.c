#include <stdio.h>

struct node {
    int dis;
    char low[10];
    char up[10];
};


struct queue {
    struct node *node_queue;
    int len;
    int front;
    int rear;
};


void enqueue(struct queue *q, struct node *n)
{
    if ((q.rear + 2) % q.len == q.front) {
        int new_len = len * 2;
        struct node *temp = malloc(sizeof(struct node) * new_len);
        int i;
        for (i = 0; i < len - 1; i++) {
            temp[i] = q.node_queue[front];
            front = (front + 1) % len;
        }
        free(q.node_queue);
        q.node_queue = temp;
        q.front = 0;
        q.rear = q.len - 2;
        q.len = new_len;
    }
    q.rear = (q.rear + 1) % q.len;
    q.node_queue[rear] = n;
}

struct node dequeue(struct queue q)
{
    /*if ((q.rear + 1) % q.len == q.front) {
      }
    */
    return q.node_queue[q.front++];
}

int main(void)
{
    return 0;
}
