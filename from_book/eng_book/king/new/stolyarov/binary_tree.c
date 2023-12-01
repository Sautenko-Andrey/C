#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *left, *right;
};


void int_bin_tree_print_rec(struct node *tree);

int main(void)
{
    return 0;
}


void int_bin_tree_print_rec(struct node *tree)
{
    if(!tree){
        return;
    }
    
    int_bin_tree_print_rec(tree->left);
    printf("%d\n", tree->value);
    int_bin_trr_print_rec(tree->right);
}
