#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

struct ArrayList {
    void* *data;
    int len;
    int capacity;
    size_t size;
};

struct ArrayList* initialize();
void insert(struct ArrayList *list, void* newData);
void freeList(struct ArrayList *list);
void printAll(struct ArrayList *list);

#endif //ARRAYLIST_H_