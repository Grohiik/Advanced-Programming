/* https://onlinejudge.org/external/106/10608.pdf */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 30000

typedef struct Node {
    int num_friends;
    int rank;
    Node *parent;
} Node;

void init_nodes(int n, Node **nodes) {
    int i = 0;
    Node *current_node;
    for (i; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        current_node = nodes[i];
        current_node->num_friends = 1;
        current_node->rank = 0;
        current_node->parent = current_node;
    }
}

int main() {
    int people, links;
    int person1, person2;
    int times;
    scanf("%d", &times);

    while (times--) {

        scanf("%d%d", &people, &links);

        Node **nodes = (Node *)malloc(people * sizeof(Node));
        init_nodes(people, nodes);

        int max_friend_circle = 1;

        while (links--) {
            scanf("%d%d", person1, person2);
        }

        int i = 0;
        for (i; i < people; i++) {
            free(nodes[i]);
        }
        free(nodes);
    }
}