#include <stdio.h>

typedef struct bsinode *tree_pointer;
struct bsinode {
    int key;
    tree_pointer left_child;
    tree_pointer right_child;
};

void asort(tree_pointer root) {
    if (root) {
        asort(root->left_child);
        printf("%d ", root->key);
        asort(root->right_child);
    }
}

tree_pointer search(tree_pointer root, int key) {
    if (!root)
        return NULL;
    if (key == root->key)
        return root;
    if (key < root->key)
        return search(root->left_child, key);
    if (key > root->key)
        return search(root->right_child, key);
}

tree_pointer search2(tree_pointer tree, int key) {
    while (tree) {
        if (key == tree->key)
            return tree;
        if (key < tree->key)
            tree = tree->left_child;
        if (key > tree->key)
            tree = tree->right_child;
    }

    return NULL;
}

int main(void) {

    return 0;
}
