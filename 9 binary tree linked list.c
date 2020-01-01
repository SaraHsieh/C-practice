#include <stdio.h>
#include <stdlib.h>

typedef struct node* node_ptr;
typedef struct node{
    int data;
    node_ptr left;
    node_ptr right;
    node_ptr parent;
}Node;
void insert(int num, node_ptr *trail)
{
    node_ptr ptr, temp;
    temp= malloc(sizeof(node_ptr));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    if(!*trail)
        *trail = temp;
    else
    {
        ptr=(*trail);
        while(ptr)
        {
            if(ptr->data == num)
            {
                printf("data is exist!");
                break;
            }
            else if(ptr->data > num)
            {
                if(ptr->left)
                    ptr = ptr->left;
                else
                {
                    temp->parent = ptr;
                    ptr->left = temp;
                    break;
                }

            }
            else
            {
                if(ptr->right)
                    ptr = ptr->right;
                else
                {
                    temp->parent = ptr;
                    ptr->right = temp;
                    break;
                }
            }
        }
    }
}
void in(node_ptr root){
    if(root){
        in(root->left);
        printf("%d ", root->data);
        in(root->right);
    }
}

void post(node_ptr root){
    if(root){
        post(root->left);
        post(root->right);
        printf("%d ", root->data);
    }
}

void pre(node_ptr root){
    if(root){
        printf("%d ", root->data);
        pre(root->left);
        pre(root->right);
    }
}


int main()
{
    int num[10],i=0,n;
    node_ptr root;
    root= malloc(sizeof(node_ptr));
    root=NULL;
    FILE *fp;
    fp = fopen("9input.txt","r");
    if(fp==NULL) printf("the file not load");
    while(!feof(fp))
    {
        fscanf(fp,"%d\t",&num[i]);
        insert(num[i],&root);
        i++;
    }
    in(root);
    printf("\n");
    post(root);
    printf("\n");
    pre(root);


    return 0;
}
