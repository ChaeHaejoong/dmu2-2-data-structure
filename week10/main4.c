#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct simple_list *simple_pointer;
struct simple_list {
    int count;
    char state[100];
    simple_pointer next;
} simple_list;
simple_pointer ptr = NULL;
simple_pointer state_list() {
    simple_pointer node1, node2;
    node1 = (simple_pointer)malloc(sizeof(struct simple_list));
    node2 = (simple_pointer)malloc(sizeof(struct simple_list));
    strcpy(node1->state, "NY");
    node1->count = 5;
    node1->next = node2;
    strcpy(node2->state, "FL");
    node2->count = 10;
    node2->next = NULL;
    return node1;
}
void append(simple_pointer ptr, simple_pointer inode) {
    simple_pointer before = NULL;
    while (ptr != NULL) {
        before = ptr;
        ptr = ptr->next;
    }
    before->next = inode;
    inode->next = NULL;
}
void print_list(simple_pointer ptr) {
    printf("The singly linked list continas: \n");
    while (ptr != NULL) {
        printf("%s: %d\n", ptr->state, ptr->count);
        ptr = ptr->next;
    }
}
int main(void) {
    simple_pointer ptr, inode1, inode2;
    ptr = state_list();
    inode1 = (simple_pointer)malloc(sizeof(struct simple_list));
    strcpy(inode1->state, "TX");
    inode1->count = 7;
    append(ptr, inode1);
    inode2 = (simple_pointer)malloc(sizeof(struct simple_list));
    strcpy(inode2->state, "SL");
    inode2->count = 3;
    append(ptr, inode2);
    print_list(ptr);
    return 0;
}
