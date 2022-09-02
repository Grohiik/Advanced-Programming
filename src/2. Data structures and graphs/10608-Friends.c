/*
https://onlinejudge.org/external/106/10608.pdf
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 30000

typedef struct Node {
    int size;
    struct Node *parent;
} Node;

int max_friend_circle;

void init_nodes(int n, Node **nodes) {
    int i = 0;
    Node *current_node;
    for (i; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        current_node = nodes[i];
        current_node->size = 1;
        current_node->parent = current_node;
    }
}

/* find with Path splitting, one pass path compression */
Node *FindRoot(Node *node) {
    while (node->parent != node) {
        Node *temp = node;
        node = node->parent;
        temp->parent = node->parent;
    }
    return node;
}

/* union by size */
void Union(Node *node_big, Node *node_small) {
    node_big = FindRoot(node_big);
    node_small = FindRoot(node_small);

    if (node_big != node_small) {
        if (node_big->size < node_small->size) {
            Node *temp = node_big;
            node_big = node_small;
            node_small = temp;
        }
        node_small->parent = node_big;
        node_big->size += node_small->size;

        if (max_friend_circle < node_big->size) {
            max_friend_circle = node_big->size;
        }
    }
}

int main() {
    int people, links;
    int person1, person2;
    int times;
    scanf("%d", &times);

    while (times--) {

        scanf("%d%d", &people, &links);

        Node **nodes = (Node **)malloc(people * sizeof(Node *));
        init_nodes(people, nodes);

        max_friend_circle = 1;

        while (links--) {
            scanf("%d%d", &person1, &person2);
            Union(nodes[person1-1], nodes[person2-1]);
        }
        printf("%d\n", max_friend_circle);

        int i = 0;
        for (i; i < people; i++) {
            free(nodes[i]);
        }
        free(nodes);
    }
}