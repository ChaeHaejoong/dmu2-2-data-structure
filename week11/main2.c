#include <stdio.h>
#include <stdlib.h>

typedef struct node *node_pointer;
struct node {
    node_pointer llink;
    int id;
    char grade;
    node_pointer rlink;
};
node_pointer head = NULL;

void dinsert(node_pointer inode, node_pointer newnode) {
    newnode->llink = inode;
    newnode->rlink = inode->rlink;
    inode->rlink->llink = newnode;
    inode->rlink = newnode;
}

void ddelete(node_pointer deleted) {
    if (head == deleted) {
        printf("Deletion of head node not permitted.\n");
    } else {
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
        free(deleted);
    }
}

void dprint() {
    node_pointer node = head->rlink;
    while (node != head) {
        printf("%d %c\n", node->id, node->grade);
        node = node->rlink;
    }
}

int main(void) {
    node_pointer newnode;
    int i;
    head = (node_pointer)malloc(sizeof(struct node));
    head->llink = head->rlink = head;
    for (i = 0; i < 3; i++) {
        newnode = (node_pointer)malloc(sizeof(struct node));
        printf("id 와 grade 입력: ");
        scanf("%d %c", &newnode->id, &newnode->grade);
        dinsert(head, newnode);
    }
    printf("삽입 후 출력: \n");
    dprint();
    printf("\n\n삭제 후 출력: \n");
    ddelete(head->rlink);
    dprint();
    return 0;
}
