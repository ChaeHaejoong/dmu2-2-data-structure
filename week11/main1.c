#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cnode *npointer;
struct cnode {
    int num;
    char grade;
    npointer link;
};
npointer ptr = NULL;

int length(npointer ptr) {
    npointer temp;
    int count = 0;
    if (ptr) {
        temp = ptr;
        do {
            count++;
            temp = temp->link;
        } while (temp != ptr);
    }
    return count;
}

void insert_front(npointer node) {
    if (!ptr) {
        node->link = node;
        ptr = node;
    } else {
        node->link = ptr->link;
        ptr->link = node;
    }
}

void c_print() {
    npointer temp = ptr;
    if (ptr) {
        do {
            temp = temp->link;
            printf("%d: %c\n", temp->num, temp->grade);
        } while (temp != ptr);
    }
}

int main(void) {
    int cond = 1;
    npointer temp;
    while (cond) {
        npointer temp = malloc(sizeof(*temp));
        printf("Enter id and grade: ");
        fflush(stdin);
        scanf("%d %c", &(temp->num), &(temp->grade));
        insert_front(temp);
        printf("Continue?(0/1): ");
        fflush(stdin);
        scanf("%d", &cond);
    }
    c_print();
    printf("The number of nodes in this list = %d\n", length(ptr));

    return 0;
}
