#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int src, dest, weight;
};

 
struct Subset {
    int parent, rank;
};

 
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}


void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}

 
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to perform Kruskal's algorithm and print the MCST
void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
    struct Subset *subsets = (struct Subset *)malloc(numVertices * sizeof(struct Subset));
    struct Edge *result = (struct Edge *)malloc((numVertices - 1) * sizeof(struct Edge));

    // Initialize subsets and result
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    int i = 0; // Index used to pick edges from sorted edges
    int j = 0; // Index used to pick edges for result

    while (j < numVertices - 1) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[j++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    
    printf("Edges in the Minimum Cost Spanning Tree (MCST):\n");
    for (int i = 0; i < numVertices - 1; i++) {
        printf("(%d - %d) with weight %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
    free(result);
}

int main() {
    int numVertices = 5;
    int numEdges = 7;

     
    struct Edge edges[] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 5},
        {2, 4, 6},
        {3, 4, 7}
    };

     
    printf("Minimum Cost Spanning Tree using Kruskal's algorithm:\n");
    kruskalMST(edges, numVertices, numEdges);

    return 0;
}
