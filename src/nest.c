#include <stdio.h>
#include <stdlib.h>

struct Edge {
    float value;
};

void print_edge(struct Edge * e)
{
    printf("PRINTING EDGE\n");
    printf("%.2f\n",e->value);
}

struct Node {
    char * name;
    int edge_count;
    struct Edge *edges;
};

void print_node(struct Node * n)
{
    printf("PRINTING NODE\n");
    printf("Name: %s\nEdge count: %d\n", n->name, n->edge_count);
    for(int i = 0; i < n->edge_count; i++)
    {
        print_edge(&n->edges[i]);
    }
}

struct Graph {
    char * name;
    int node_count;
    struct Node *nodes;
};

void print_graph(struct Graph * g)
{
    printf("PRINTING GRAPH\n");
    printf("Name: %s\nNode count: %d\n", g->name, g->node_count);
    for(int i = 0; i < g->node_count; i++)
    {
        print_node(&g->nodes[i]);
    }
}

// add node to graph

int main(int argc, char ** argv)
{
    struct Edge e;
    e.value = 10;
    print_edge(&e);
    struct Node n;
    n.name = "Node name";
    n.edge_count = 1;
    n.edges[0] = e;
    print_node(&n);
    struct Graph g;
    g.name = "Graph name";
    g.node_count = 1;
    g.nodes[0] = n;
    print_graph(&g);
    return 0;
}
