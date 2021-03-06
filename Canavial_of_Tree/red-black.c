#include <stdio.h>
#include <stdlib.h>

#include "red-black.h"
void aux_print()
{
    inorderTree(root);
}

int aux_height_RB()
{
    heightTree_RB(root);
}

aux_free_RB()
{
    printf("aki");
    free_RB(root);
}

void left_Rotate(struct rbtNode *x)
{
    struct rbtNode *y;
    y = x->right;  x->right = y->left;

    if( y->left != NULL)

    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if( x->parent == NULL)

    {
        root = y;
    }

    else if( (x->parent->left!=NULL) && (x->key == x->parent->left->key))

    {
        x->parent->left = y;
    }

    else
        x->parent->right = y;

    y->left = x; x->parent = y;
    return;

}

void right_Rotate(struct rbtNode *y)
{
    struct rbtNode *x;
    x = y->left;
    y->left = x->right;

    if ( x->right != NULL)
    {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if( y->parent == NULL)
    {
        root = x;
    }

    else if((y->parent->left!=NULL) && (y->key == y->parent->left->key))
    {
        y->parent->left = x;
    }

    else
        y->parent->right = x;

    x->right = y; y->parent = x;
    return;

}

void color_insert(struct rbtNode *z)

{
    struct rbtNode *y = NULL;

    while ((z->parent != NULL) && (z->parent->color == 'r'))
    {

        if ( (z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key))
        {
            if(z->parent->parent->right!=NULL)
                y = z->parent->parent->right;

            if ((y!=NULL) && (y->color == 'r'))
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';

                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }

            else
            {

                if ((z->parent->right != NULL) && (z->key == z->parent->right->key))
                {
                    z = z->parent;
                    left_Rotate(z);
                }

                z->parent->color = 'b';

                z->parent->parent->color = 'r';

                right_Rotate(z->parent->parent);

            }
        }

        else
        {

            if(z->parent->parent->left!=NULL)
                y = z->parent->parent->left;

            if ((y!=NULL) && (y->color == 'r'))
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';

                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }

            else
            {

                if ((z->parent->left != NULL) && (z->key == z->parent->left->key))

                {
                    z = z->parent;
                    right_Rotate(z);
                }

                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                left_Rotate(z->parent->parent);

            }

        }

    }
    root->color = 'b';
}

void insertRB(int val)

{
    struct rbtNode *x, *y;

    struct rbtNode *z = (struct rbtNode*)malloc(sizeof(struct rbtNode));
    z->key = val;
    z->left = NULL;
    z->right = NULL;
    z->color = 'r';
    x=root;

    if(searchRB(val)==1)

    {
        //printf("\nEntered element already exists in the tree\n");
        return;
    }

    if ( root == NULL )

    {
        root = z;
        root->color = 'b';

        return;
    }

    while ( x != NULL)
    {
        y = x;

        if ( z->key < x->key)
        {
            x = x->left;
        }

        else
            x = x->right;
    }

    z->parent = y;

    if ( y == NULL)

    {
        root = z;

    }

    else if( z->key < y->key )

    {
        y->left = z;
    }

    else
        y->right = z;

    color_insert(z);

    return;

}

void inorderTree(struct rbtNode* root)

{
    //struct rbtNode* temp = root;
    //printf("aqki\n");

    if (root == NULL)
    {
        //printf("TERMINOU\n");
        return;
    }
    inorderTree(root->left);
    printf(" %d--%c \n",root->key,root->color);
    inorderTree(root->right);
        //return;
    //printf("aaaaa");
}

void postorderTree(struct rbtNode* root)

{
    struct rbtNode* temp = root;

    if (temp != NULL)
    {
        postorderTree(temp->left);
        postorderTree(temp->right);
        printf("%d",temp->key);

    }
    return;
}


int searchRB(int val)

{
    struct rbtNode* temp = root;
    int diff;

    while (temp != NULL)
    {
        diff = val - temp->key;

        if (diff > 0)
        {
            temp = temp->right;
        }

        else if (diff < 0)
        {
            temp = temp->left;
        }
        else
        {
            //printf("Search Element Found!!\n");
            return 1;
        }

    }
    //printf("Given Data Not Found in RB Tree!!\n");

    return 0;

}

struct rbtNode* min(struct rbtNode *x)
{
    while (x->left)
    {
        x = x->left;
    }
    return x;

}

struct rbtNode* successor(struct rbtNode *x)
{
    struct rbtNode *y;

    if (x->right)
    {
        return min(x->right);
    }
    y = x->parent;

    while (y && x == y->right)
    {
        x = y;
        y = y->parent;

    }
    return y;

}

void color_delete(struct rbtNode *x)

{
    while (x != root && x->color == 'b')
    {
        struct rbtNode *w = NULL;

        if ((x->parent->left!=NULL) && (x == x->parent->left))
        {
            w = x->parent->right;

            if ((w!=NULL) && (w->color == 'r'))
            {
                w->color = 'b';
                x->parent->color = 'r';
                left_Rotate(x->parent);
                w = x->parent->right;
            }

        if ((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->left->color == 'b') && (w->right->color == 'b'))
        {
            w->color = 'r';
            x = x->parent;
        }

        else if((w!=NULL) && (w->right->color == 'b'))
        {
            w->left->color = 'b';
            w->color = 'r';
            right_Rotate(w);
            w = x->parent->right;
        }

        if(w!=NULL)
        {
            w->color = x->parent->color;
            x->parent->color = 'b';
            w->right->color = 'b';
            left_Rotate(x->parent);
            x = root;

        }

        }

        else if(x->parent!=NULL)

        {
            w = x->parent->left;

            if ((w!=NULL) && (w->color == 'r'))
            {

                w->color = 'b';
                x->parent->color = 'r';
                left_Rotate(x->parent);

                if(x->parent!=NULL)

                    w = x->parent->left;

            }

            if ((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->right->color == 'b') && (w->left->color == 'b'))
            {
                x = x->parent;
            }

            else if((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->left->color == 'b'))
            {
                w->right->color = 'b';
                w->color = 'r';
                right_Rotate(w);
                w = x->parent->left;
            }

            if(x->parent!=NULL)
            {
                    w->color = x->parent->color;
                    x->parent->color = 'b';
            }

            if(w->left!=NULL)
                w->left->color = 'b';

            if(x->parent !=NULL)
                left_Rotate(x->parent);

            x = root;

        }

    }
    x->color = 'b';
}

struct rbtNode* delete_RB(int var)
{
    struct rbtNode *x = NULL, *y = NULL, *z;
    z=root;

    if((z->left ==NULL ) &&(z->right==NULL) && (z->key==var))
    {
        root=NULL;
        printf("\nRBTREE is empty\n");
        return;
    }

    while(z->key !=var && z!=NULL)
    {
        if(var<z->key)
            z=z->left;

        else
            z=z->right;

        if(z== NULL)
        return;

    }

    if((z->left==NULL)||(z->right==NULL))
    {
        y = z;
    }
    else
    {
        y = successor(z);
    }

    if (y->left!=NULL)
    {
        x = y->left;
    }

    else
    {
        if(y->right !=NULL)
            x = y->right;

    }

    if((x!=NULL) && (y->parent !=NULL))
        x->parent = y->parent;

    if ((y !=NULL) && (x!=NULL) && (y->parent==NULL))
    {
        root=x;
    }

    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }

    else
    {
        y->parent->right = x;
    }

    if (y != z)
    {
        z->key = y->key;
    }

    if ((y!=NULL) && (x!=NULL) && (y->color == 'b'))
    {
        color_delete(x);
    }
    return y;
}

void read_RB()
{
    int numero;

    FILE* file = fopen ("values.txt", "r");

    //fscanf (file, "%d", &numero);

    while (!feof(file))
    {
        fscanf(file, "%d", &numero);
        insertRB(numero);

        //fscanf(file, "%d", &numero);

    }
    fclose(file);
    //return b;
}

void read_search_txt_RB(FILE* result_search_RB)
{
    int number;

    FILE* busca = fopen("search.txt", "r");

    //fscanf(busca, "%d", &number);

    while(!feof(busca))
    {
        fscanf(busca, "%d", &number);

        fprintf(result_search_RB,"%d \n",searchRB(number));
        //fscanf(busca, "%d", &number);

    }
    fclose(busca);
}
void read_delete_txt_RB(FILE* result_remove_RB)
{
    int num ,height;

    FILE* file = fopen ("remove.txt", "r");

    //fscanf (file, "%d", &num);

    while (!feof(file)){

        fscanf (file, "%d", &num);

        delete_RB(num);

        //fscanf(file, "%d", &num);

    }
    fclose(file);
}

int heightTree_RB(struct rbtNode *root)
{
   if (root == NULL)
      return -1;
   else {
      int heightLeft = heightTree_RB(root->left);
      int heightRight = heightTree_RB(root->right);
      if (heightLeft < heightRight)
        return heightRight + 1;
      else return heightLeft + 1;
   }
}

void free_RB(struct rbtNode *root)
{
    if(root != NULL)
    {
        free_RB(root->left);
        free_RB(root->right);
        free(root);
    }
}
