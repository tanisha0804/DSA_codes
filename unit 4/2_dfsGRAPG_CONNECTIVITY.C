// Application of DFS
/* 1. detecting whether cycle exists in a graph
    2. finding path in network
    3. topological soting - used in job scheduling
    4. to check if graph is strongly connected or not

path = sequence of edges that allows user to go from 1 vertex to another
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 50
typedef struct graph
{
    int vertices;
    int adj_mat[max][max];
} GRAPH;

void create_matrix(GRAPH *g);
void display(GRAPH *g);
bool dfs_is_connected(GRAPH *g);
bool dfs_contains_cycle(GRAPH *g);
int main()
{
    GRAPH g;
    create_matrix(&g);
    display(&g);

    if (dfs_is_connected(&g))
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }

    if (dfs_contains_cycle(&g))
    {
        printf("The graph contains a cycle.\n");
    }
    else
    {
        printf("The graph does not contain any cycles.\n");
    }
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

bool dfs_is_connected(GRAPH *g)
{
    int visited[max] = {0};
    int stack[max];
    int top = -1;
    int count;
    int start = 1;
    stack[++top] = start;
    visited[start] = 1;
    count = 1;
    while (top >= 0)
    {
        int current = stack[top--];
        for (int i = 1; i <= g->vertices; i++)
        {
            if (g->adj_mat[start][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                stack[++top] = i;
                count++;
            }
        }
    }
    return (count == g->vertices);
}

bool dfs_contains_cycle(GRAPH *g)
{
    int visited[max] = {0};
    for (int i = 0; i <= g->vertices; i++)
    {
        if (visited[i] == 0)
        {
            int stack[max], parent[max], top = -1;
            stack[++top] = i;
            parent[i] = -1;
            visited[i] = 1;

            while (top >= 0)
            {
                int current = stack[top--];
                for (int j = 1; j <= g->vertices; j++)
                {
                    if (g->adj_mat[i][j] == 1)
                    {
                        if(visited[j] == 0)
                        {
                            stack[++top] = j;
                            parent[j] = current;
                            visited[j] =1;
                            break;
                        }
                        else if ( i != parent[current])
                            return true;
                    }
                }
            }
        }
    }
}