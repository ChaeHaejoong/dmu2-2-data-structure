#include <stdio.h>
#include <stdlib.h>

typedef struct tnode *tree_pointer;
struct tnode {
    int num;
    int score;
    tree_pointer left_child;
    tree_pointer right_child;
};

// 중위
void inorder1(tree_pointer ptr) {
    if (ptr) {
        inorder1(ptr->left_child);
        printf("%d ", ptr->num);
        inorder1(ptr->right_child);
    }
}

void inorder2(tree_pointer ptr) {
    if (ptr) {
        inorder2(ptr->left_child);
        if (ptr->score >= 800)
            printf("%d %d\n", ptr->num, ptr->score);
        inorder2(ptr->right_child);
    }
}

// 전위
void preorder(tree_pointer ptr) {
    if (ptr) {
        printf("%d ", ptr->num);
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

// 후위
void postorder(tree_pointer ptr) {
    if (ptr) {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        printf("%d ", ptr->num);
    }
}

tree_pointer makeRootNode(int num, int score, tree_pointer L, tree_pointer R) {
    tree_pointer node = malloc(sizeof(struct tnode));
    node->num = num;
    node->score = score;
    node->left_child = L;
    node->right_child = R;
    return node;
}

tree_pointer ptr = NULL;
int main(void) {
    tree_pointer n10 = makeRootNode(10, 700, NULL, NULL);
    tree_pointer n9 = makeRootNode(9, 900, NULL, NULL);
    tree_pointer n8 = makeRootNode(8, 910, n10, NULL);
    tree_pointer n7 = makeRootNode(7, 550, NULL, NULL);
    tree_pointer n6 = makeRootNode(6, 500, n9, NULL);
    tree_pointer n5 = makeRootNode(5, 850, NULL, NULL);
    tree_pointer n4 = makeRootNode(4, 950, n7, n8);
    tree_pointer n3 = makeRootNode(3, 600, n5, n6);
    tree_pointer n2 = makeRootNode(2, 750, n4, NULL);
    tree_pointer n1 = makeRootNode(1, 800, n2, n3);
    ptr = n1;
    printf("===== inorder1 =====\n");
    inorder1(ptr);
    printf("\n\n");
    printf("===== inorder2 =====\n");
    inorder2(ptr);
    printf("\n\n");
    printf("===== preorder =====\n");
    preorder(ptr);
    printf("\n\n");

    return 0;
}
