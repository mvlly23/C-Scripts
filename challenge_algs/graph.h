#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "arraylist.h"

struct Node {
    int value;
    struct ArrayList *links;
    bool pmark, tmark;
};

struct Node* new_node(int value);
void deleteNode(struct Node *node);
void deleteNodeList(struct ArrayList *list);
void topologicalSort(struct ArrayList *graph);

#endif