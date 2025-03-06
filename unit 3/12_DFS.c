//DFS = depth first search - uses stack implementation

//  1. DFS using adjacenct-matrix
/* #include<stdio.h>
#include <stdlib.h>
#define max 50

typedef struct graph
{
    int vertices;
    int adj_mat[max][max];
} GRAPH;

void create_matrix(GRAPH *g);
void display(GRAPH *g);
void DFS_matrix(GRAPH *g, int source);

int main()
{
    GRAPH g;
    create_matrix(&g);
    display(&g);
    int source;
    printf("enter the source vertex\n");
    scanf("%d",&source);
    DFS_matrix(&g,source);
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
            g->adj_mat[to][from] = 1;  //for undirected graph
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

void DFS_matrix(GRAPH *g,int source)
{
    static int visited[max];
    printf("%d->",source);
    visited[source] = 1;
    for(int i=1;i<=g->vertices;i++)
    {
        if(g->adj_mat[source][i] == 1 && visited[i] == 0)
            DFS_matrix(g,i);
    }
} */


//  2. DFS using adjacent_list

#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct node
{
    int data;
    struct node *nextnode;
} NODE;

NODE adj_list[max];

void create_list();
void display();
void DFS_list(NODE *adj_list,int source);

int main()
{
    create_list();
    display();
    int source;
    printf("enter source\n");
    scanf("%d",&source);
    DFS_list(adj_list,source);
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

void DFS_list(NODE *adj_list,int source)
{
    NODE *temp = &adj_list[source];  //a temporray node pointing to source list
    static int visited[max]; // defining visited array
    printf("%d->",source);  //printing source and marking it visited
    visited[source] = 1;
    while(temp->nextnode != NULL)  // check if the temp node has any neighbours
    {
        temp = temp->nextnode;  // traverse thru all the neighbours and mark them visited and recursively repeat this
        if(visited[temp->data] == 0)
            DFS_list(adj_list,temp->data);
    }
}