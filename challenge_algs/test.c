#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"
#include "graph.h"

int main(){
    // probably not the best way to implement this but ¯\_(ツ)_/¯
    struct Node *node1 = new_node(1);
    struct Node *node2 = new_node(2);
    struct Node *node3 = new_node(3);
    struct Node *node4 = new_node(4);
    struct Node *node5 = new_node(5);
    struct Node *node6 = new_node(6);

    struct ArrayList *list1 = initialize();
    struct ArrayList *list2 = initialize();
    struct ArrayList *list3 = initialize();
    struct ArrayList *list4 = initialize();
    struct ArrayList *list5 = initialize();
    struct ArrayList *list6 = initialize();
    
    //Linking nodes
    insert(list1, node3);
    insert(list1, node5);
    insert(list1, node6);

    insert(list2, node1);
    insert(list2, node3);

    insert(list3, node4);

    insert(list6, node5);

    //Attach links to nodes
    node1->links = list1;
    node2->links = list2;
    node3->links = list3;
    node4->links = list4;
    node5->links = list5;
    node6->links = list6;

    //Add each node to our graph
    struct ArrayList *graph = initialize();
    insert(graph, node1);
    insert(graph, node2);
    insert(graph, node3);
    insert(graph, node4);
    insert(graph, node5);
    insert(graph, node6);

    //Sort (finally)
    topologicalSort(graph);

    // cleanup
    freeList(graph);
    freeList(list1);
    freeList(list2);
    freeList(list3);
    freeList(list4);
    freeList(list5);
    freeList(list6);
    deleteNode(node1);
    deleteNode(node2);
    deleteNode(node3);
    deleteNode(node4);
    deleteNode(node5);
    deleteNode(node6);
    return 0;
}
