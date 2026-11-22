#include <stdio.h>
#include <stdlib.h>

typedef struct service_node *spointer;
struct service_node {
    char cname[10];
    int cnum;
    spointer next;
};
spointer ptr = NULL;

void cbuild(spointer inode) {
    if (!ptr) {
        inode->next = inode;
        ptr = inode;
    } else {
        inode->next = ptr->next;
        ptr->next = inode;
    }
}

void print_consultant() {
    spointer temp = ptr;
    if (ptr) {
        do {
            temp = temp->next;
            printf("%s: %d\n", temp->cname, temp->cnum);
        } while (temp != ptr);
    }
}

spointer find_minimum_waiting() {
    spointer temp, mptr;
    mptr = ptr;
    temp = ptr->next;
    while (temp != ptr) {
        if (temp->cnum < mptr->cnum)
            mptr = temp;
        temp = temp->next;
    }

    return mptr;
}

int main() {
    int sslot, i;
    spointer temp;

    printf("Input the number of consultants: ");
    scanf("%d", &sslot);

    for (i = 0; i < sslot; i++) {
        temp = (spointer)malloc(sizeof(struct service_node));
        printf("Input consultant name and the number of waiting customers: ");
        scanf("%s %d", temp->cname, &(temp->cnum));
        cbuild(temp);
    }

    printf("The data contain in the circular linked list ==== \n");
    print_consultant();

    temp = find_minimum_waiting();
    printf("minimum waiting line = %s: %d\n", temp->cname, temp->cnum);

    return 0;
}
