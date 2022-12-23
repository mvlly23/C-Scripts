#include <stdio.h>
#include <stdlib.h>

struct link {
    struct link *left;
    struct link *right;
    int value;
};

struct link* addLink(int val, struct link *prev){
    struct link *root = malloc(sizeof(struct link));
    if(prev != NULL){
        root -> left = prev;
        root -> value = val;
        prev -> right = root;
    }
    else{
        root -> left = NULL;
        root -> value = val;
    }

    root -> right = NULL;
    return root;
}

void rmLink(struct link *del){
    if(del -> right != NULL){
        struct link *left = del -> left;
        struct link *right = del -> right;
        left -> right = right;
        right -> left = left;
    }
    else if(del -> left != NULL)
        del -> left -> right = NULL;
    del -> left = NULL;
    del -> right = NULL;
    free(del);
}

struct link* gotoEnd(struct link* root){
    while(root -> right != NULL){
        root = root -> right;
    }
    return root;
}

void removeAllLinks(struct link *root){
    struct link *end = gotoEnd(root);
    while(end -> left != NULL){
        end = end -> left;
        rmLink(end -> right);
    }
    rmLink(root);
}

void printLinks(struct link *root){
    while(root -> right != NULL){
        printf("%d\n", root -> value);
        root = root -> right;
    }
    printf("%d\n", root -> value);
}

void printLinksReverse(struct link *root){
    struct link *end = gotoEnd(root);
    while(end -> left != NULL){
        printf("%d, ", end -> value);
        end = end -> left;
    }
    printf("%d\n", end -> value);
}

struct link *root;

int main(){
    root = addLink(0, NULL);
    struct link *prev = root;
    for(int i=1; i<6; i++){
        struct link *newLink = addLink(i, prev);
        prev = newLink;
    }

    printLinks(root);
    printLinksReverse(root);
    removeAllLinks(root);

    return 0;
}