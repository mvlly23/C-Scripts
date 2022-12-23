#include "graph.h"

typedef struct ArrayList Arraylist;
typedef struct Node node;

node* new_node(int val){
    node* n = malloc(sizeof(node));
    n -> value = val;
    n -> links = NULL;
    n -> pmark = false;
    n -> tmark = false;
    return n;
}

void deleteNode(node* n){
    free(n);
}

void deleteNodesList(Arraylist *list){
    for(int i=0; i<list->len; i++){
        deleteNode(list->data[i]);
    }
}

void visit(node *n, Arraylist *list){
    printf("Visiting node: %d\n", n->value);
    if(n->pmark)
        return;
    else if(n->tmark){
        printf("Uh-oh cycle D:\n");
        exit(1);
    }

    n->tmark = true;

    for(int i=0; i<n->links->len; i++){
        visit(n->links->data[i], list);
    }

    n -> tmark = false;
    n -> pmark = true;
    insert(list, n);
}

void topologicalSort(Arraylist *graph){
    Arraylist *list = initialize();
    for(int i=0; i<graph->len; i++){
        visit(graph->data[i], list);
    }
    printf("\n\n\nDone sorting, printing results......\n\n\n");
    for(int i=list->len; i>0; i--){
        node *n = list->data[i - 1];
        printf("%d\n", n->value);
    }
    freeList(list);
}