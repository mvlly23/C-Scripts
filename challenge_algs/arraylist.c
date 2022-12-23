#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arraylist.h"

#define ARRAY_SIZE 4

typedef struct ArrayList Arraylist;


Arraylist* initialize(){
    Arraylist *list = malloc(sizeof(Arraylist));
    if(list == NULL){
        return NULL;
    }

    list -> len = 0;
    list -> data = malloc(sizeof(void*) * ARRAY_SIZE);
    if(list->data == NULL){
        free(list);
        return NULL;
    }

    list -> capacity = ARRAY_SIZE; 
    list -> size = sizeof(list->data);

    return list;
}

void resize(Arraylist *list){
    list -> capacity += ARRAY_SIZE;
    list -> size = list->capacity * sizeof *(list->data);
    
    list -> data = realloc(list->data, list->size);
    if(list -> data == NULL){
        freeList(list);

        // TODO will potentially leave a big memory leak
        exit(2);
    }
}

void insert(Arraylist *list, void* newData){
    if(list->len + 1 >= list->capacity){
        resize(list);
    }
    list->data[list->len] = newData;
    list->len++;
    list->size = sizeof(list->data);
}

void freeList(Arraylist *list){
    free(list->data);
    free(list);
}

void printAll(Arraylist *list){
    if(list->len < 1) return;
    for(int i=0; i<list->len; i++){
        printf("%p\n", list->data[i]);
    }
}