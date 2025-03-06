/* applications of BFS 
1. finding shortest path
2. social networking websities
3. GPS navigation system
4. web crawlers
5. finding path in network
6. in networking to broadcast packets

connectivity in graph - either connected or dissconnected
one single graph neing completely connected
if there is path between every pair of vertices = connected graph
one single graph not being connected completely = disconnected graph
to check if graph is connected or not, we traverse the graphs if there is atleast 1 node which is not marked visited then the graph is dissconnected
1. create an adjacent matrix and read it
2. create a visited[] array
3. start traversal from any source vertex and mark visited vertices
4. after traversalcheck the visited[] array, if any vertex is marked unvisited then graph is disconnected

checking for cycle - for each vertex if its unvisited - it enqueues it, marks visited and sets its parent, if its already visited and is not the parent = cycle detected*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define max 50
typedef struct graph
{
    int vertices;
    int adj_mat[max][max];
} GRAPH;

void create_matrix(GRAPH *g);
void display(GRAPH *g);
bool bfs_is_connected(GRAPH *g);
bool bfs_contains_cycle(GRAPH *g);
int main()
{
    GRAPH g;
    create_matrix(&g);
    display(&g);

    if (bfs_is_connected(&g)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    if (bfs_contains_cycle(&g)) {
        printf("The graph contains a cycle.\n");
    } else {
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

bool bfs_is_connected(GRAPH *g)
{
    int queue[max],front = 0,rear = 0;
    int visited[max] ={0};
    int start = 1; //starting from index 1
    queue[rear++] = start;
    visited[start] = 1;
    int count = 1;
    while(front < rear)
    {
        int current = queue[front++];
        for (int i=0;i<=g->vertices;i++)
        {
            if(g->adj_mat[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = 1;
                visited[i] = 1;
                count++;
            }
        }
    }
    return (count == g->vertices);
}

bool bfs_contains_cycle(GRAPH *g)
{
    int queue[max],front,rear,visited[max], parent[max];

    for (int i=1;i<=g->vertices;i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }

    for(int i = 1;i<=g->vertices;i++)
    {
        if(visited[i] == 0)
        {
            front = rear = 0;
            queue[rear++] = i;
            visited[i] = 1;

            while(front < rear)
            {
                int current = queue[front++];
                for(int i=1;i<=g->vertices;i++)
                {
                    if(g->adj_mat[current][i] == 1)
                    {
                        if(visited[i] == 0)
                        {
                            queue[rear++] = i;
                            visited[i] = 1;
                            parent[i] = current;
                        }
                        else if (i != parent[current])
                            return true;
                    }
                }
            } 
        }
    }
}