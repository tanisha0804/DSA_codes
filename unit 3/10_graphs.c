// tree is also a graph
/* in tree with N nodes there are N-1 edges
graph - data structures that consists of set of vertices and set of edges that relate node to each other
set of edges - represents relationships among vertices
graph is defined as G=(V,E)
                    V=finite non-empty set of vertices
                    E- set of edges
check examples in slides
undirected graph - graph is undirected when pair of vertices representing any edge is unordered  ex: vertices A,B edges = (A,B) & (B,A)
directed graph - graph with all directed edges[has edges with directions mentioned] vertices A,B edges = either (A,B) or (B,A)
weighted graph - each edge has a numerical value called weight for it
GRAPH TERMINOLOGY:
1. adjacent node - node m is adjacent to node n if there is an edge from m to n
    if n is adjacent to m then n= successor and m= predecessor
2.path - sequence of vertices that connects 2 nodes in graph
3.cycle - path from node to itself[1st and last vertices are same]
    graph with atleast 1 cycle = cyclic graph
4. Acyclic graph - graph with no cycles
    directed acyclic graph = DAG
5. incident - node n is incident to edge x, if node is one of the 2 nodes the edge connects
6. degree = number of edges incident on vertex
7. in-degree = number of edges incident to vertex(incoming)
8. out-degree = number of edges incident from vertex(outgoing)

properties of graph ->
1. no of possible pairs in an n vertex graph = n*(n-1)
2. since edge (u,v) is not same as edge (v,u) , number of edges in a directed graph <= n*(n-1)
3. number of edges of undirected graph -> no of pairs = n*(n-1)
        edge (u,v) = (v,u) so the number of edges = n*(n-1)/2

*/

/*
depending on density of edge,ease of use and types
its divided to
1. adjacency matrix representation - 2D array
NxN matrix M, graph of n vertices
rows,columns represented as vertices
M[i][j] = 1 -> edge
M[i][j] = 0 -> no edge
note:  for undirected graph -> M is symmetric -> M[I][J] == M[J][I]
if no node from itself then the diagonals of the matrix are 0

in directed graph -> edge [I,J] IS NOT EQUAL TO [J,I]

in a weighted graph the value of weights are mentioned in the the matrix rather than 1
drawbacks - no of nodes needs to be known in prior
dynamic allocation cant be done,new matrix needs to be created
it takes time constant of order of (1)
takes order of (v^2) to visit all neighbouring nodes of each node
becomes sparse in case of graphs having very few edges (more of 0s than 1s)
when graph is dense -> matrix is adviced
and when graph isnt dense - linked list is used

linked list representation
L[i] -linked lost containing all ajacent nodes from vertex i in no particular order
see example in slides
in directed graph - only out-going edges are mentioned
in weighted graph -> LL contains 1 more member where the value of weight of node is represented
space complexity = order of (v+e) because it stored info of edges that actually exists in graphs
for undirected graphs it is order of (v+2e)
to detect presence of edge between 2 nodes, we need to traverse linked list of node*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ADJACENT-MATRIX REPRESENTATION OF GRAPHS - USING 2-D ARRAYS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* #include <stdio.h>
#include <stdlib.h>
#define max 50
typedef struct graph
{
    int vertices;
    int adj_mat[max][max];
} GRAPH;

void create_matrix(GRAPH *g);
void display(GRAPH *g);
int main()
{
    GRAPH g;
    create_matrix(&g);
    display(&g);
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
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ADJACENT-LIST GRAPH REPRESENTATION  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
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

int main()
{
    create_list();
    display();
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
        printf("%d - > \n",adj_list[i].data);
        temp = &adj_list[i];
        while(temp->nextnode != NULL)
        {
            temp = temp->nextnode;
            printf("%d->",temp->data);
        }
        printf("\n");
    }
}