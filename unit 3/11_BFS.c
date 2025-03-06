//traversals of graphs - visiting the vertices in a particular way starting from any arbitary vertex

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 1. BREADTH FIRST SEARCH ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
/* explores all neighbour nodes in first level from an arbitary node before moving to next level, uses queues behaviour
QUEUES
1. BFS using adjacent matrix 
 */
/* #include<stdio.h>
#include <stdlib.h>
#define max 50
int f =-1, r= -1;  //f = front & r= rear
typedef struct graph
{
    int vertices;
    int adj_mat[max][max];
} GRAPH;

void create_matrix(GRAPH *g);
void display(GRAPH *g);
int isempty(int *q);
void enqueue(int *q, int data);
int dequeue(int *q);
void BFS_matrix(GRAPH *g);
int main()
{
    GRAPH g;
    create_matrix(&g);
    display(&g);
    BFS_matrix(&g);
    return 0;
}
void create_matrix(GRAPH *g)
{
    printf("enter the number of vertices requires: \n");
    scanf("%d", &g->vertices);
    int from, to;
    for (int i = 1; i <= g->vertices; i++)
    {
        g->adj_mat[0][i] = i;
        g->adj_mat[i][0] = i;
        for (int j = 1; j <= g->vertices; j++)
            g->adj_mat[i][j] = 0; // assign to 0 first
    }

    while (1)
    {
        printf("enter from and to vertex and (-1 -1) to exit\n");
        scanf("%d %d", &from, &to);

        if (from == -1 && to == -1)
            break;
        if (from > 0 && from <= g->vertices && to > 0 && to <= g->vertices)
        {
            g->adj_mat[from][to] = 1;
            // g->adj_mat[to][from] = 1;  //for undirected graph
            // in case of weighted graphs take input of weight aswell and put that value instead of 1
        }
        else
            printf("invalid vertices");
    }
}

void display(GRAPH *g)
{

    for (int i = 0; i <= g->vertices; i++)
    {
        printf("\n");
        for (int j = 0; j <= g->vertices; j++)
        {
            if (i == 0 && j == 0)
                printf("_");
            else
                printf("%d", g->adj_mat[i][j]);
        }
    }
}

int isempty(int *q)  //checks if the queue is empty , returns 1 if empty and 0 otherwise
{
    return (f == r && f == -1); 
}
void enqueue(int *q, int data)
{
    if(isempty(q))  //checks if queue is emmpty, if yes then updates f to 0 and keeps on adding data to queue imcrementing rear indexing
        f++;
    q[++r] = data;
}

int dequeue(int *q)
{
    int d = q[f];  // d stores the front element the first entered element
    if( f == r && f!=-1)  // checks if its the only element present in the queue, if yes it makes the f = r = -1
        f=r= -1;
    else  // else increments f for further dequeuing
        f++;
    return d; // returns the element
}

void BFS_matrix(GRAPH *g)
{
    int source, v; //source = source of choice from where the traversal needs to start
    v = g->vertices; // v = number of vertices present in matrix
    printf("enter the ource vertex\n");
    scanf("%d",&source);
    int *queue = (int *)calloc(v,sizeof(int));  //dynamically allocating queue and visited
    int *visited = (int *)calloc(v+1,sizeof(int));
    enqueue(queue,source);   // enqueue source first, mark it visisted and print it
    visited[source] = 1;
    printf("%d - >",source);
    while(!isempty(queue))  // until the q is not empty - dequeue element
    {
        int d = dequeue(queue);
        for(int i=1;i<=v;i++)  // starting from 1 to all the vertices
        {
            if(g->adj_mat[d][i] == 1 && visited[i] == 0) // if the neighbouring vertices are not visited, enqueue them, make visited = 1 and then print
            {
                enqueue(queue,i);
                visited[j] =1;
                printf("%d->",i);
            }
        }
    }
} */


// 2.BFS using adjacent list
#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct node
{
    int data;
    struct node *nextnode;
} NODE;

NODE adj_list[max];
int f = -1,r=-1;
void create_list();
void display();
int isempty(int *q);
void enqueue(int *q, int data);
int dequeue(int *q);
void BFS_list();

int main()
{
    create_list();
    display();
    BFS_list();
    return 0;
}

void create_list()
{
    int v, from, to;
    NODE *nn,*temp;
    printf("enter the total number of vertices\n");
    scanf("%d", &v);
    adj_list[0].data = v;
    adj_list[0].nextnode = NULL;
    for (int i = 1; i <= adj_list[0].data; i++)
    {
        adj_list[i].data = i; // assign everynode to NULL initially
        adj_list[i].nextnode = NULL;
    }

    while (1)
    {
        printf("enter from and to vertices and enter (-1 -1)to exit\n");
        scanf("%d %d", &from, &to);
        if (from == -1 && to == -1)
            break;
        if (from > 0 && from <= v && to > 0 && to <= v)
        {
            nn = (NODE *)malloc(sizeof(NODE));
            nn->data = to;
            nn->nextnode = NULL;
            temp = &adj_list[from];
            while (temp->nextnode != NULL)
                temp = temp->nextnode;
            temp->nextnode = nn;
        }
        else
            printf("entered values do not exist\n");
    }
}

void display()
{
    NODE *temp;
    for(int i=0;i<=adj_list[0].data;i++)
    {
        printf("%d - > ",adj_list[i].data);
        temp = &adj_list[i];
        while(temp->nextnode != NULL)
        {
            temp = temp->nextnode;
            printf("%d->",temp->data);
        }
        printf("\n");
    }
}

int isempty(int *q)  //checks if the queue is empty , returns 1 if empty and 0 otherwise
{
    return (f == r && f == -1); 
}
void enqueue(int *q, int data)
{
    if(isempty(q))  //checks if queue is emmpty, if yes then updates f to 0 and keeps on adding data to queue imcrementing rear indexing
        f++;
    q[++r] = data;
}

int dequeue(int *q)
{
    int d = q[f];  // d stores the front element the first entered element
    if( f == r && f!=-1)  // checks if its the only element present in the queue, if yes it makes the f = r = -1
        f=r= -1;
    else  // else increments f for further dequeuing
        f++;
    return d; // returns the element
}

void BFS_list()
{
    int source,v;
    v = adj_list[0].data; // the total number of vertices
    int *queue = (int *)calloc(v,sizeof(int));
    int *visited = (int *)calloc(v+1,sizeof(int));
    printf("enter the source vertex\n");
    scanf("%d",&source);  //put the source into queue, mark it visited and print it out
    enqueue(queue,source);
    visited[source] = 1;
    printf("%d -> ",source);
    while(!isempty(queue))   //until the queue is empty run the loop
    {
        int i=dequeue(queue);  // dequeue the recent element inserted
        NODE *temp = &adj_list[i];  // temporaray node pointing to array with index i which is connected to its neighbouring nodes
        while(temp->nextnode != NULL)  // until its neighbouring nodes exist run the loop
        {
            temp = temp->nextnode; // move to next node and store data in some other variable
            int j = temp->data;
            if(visited[j] == 0)  // check is node is visited
            {
                enqueue(queue,j); // if not then insert it to queue, mark it visited and print it out
                visited[j] = 1;
                printf("%d->",j);
            }
        }

    }
    

}
