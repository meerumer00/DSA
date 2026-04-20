#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root, int data){
    if(root == NULL)
        return createNode(data);
    else{
        struct Node* queue[100];
        int front =-1, rear =-1;
        queue[++rear] = root;
        front++;
        while(front <=rear){
            struct Node* temp = queue[front++];
            if(temp->left == NULL){
                temp->left = createNode(data);
                break;
            }
            else if(temp->right == NULL){
                temp->right = createNode(data);
                break;
            }
            else{
                queue[++rear] = temp->left;
                queue[++rear] = temp->right;
            }
        }
        return root;
    }
}
void preOrder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
struct Node* search(struct Node* root, int val){
    if(root == NULL || root->data == val)
    return root;
    if(val < root->data)
    return search(root->left, val);
    else
    return search(root->right, val);
}
struct Node* delete(struct Node* root, int val){
    if(root == NULL)
    return NULL;
    else if(val > root->data)
    root->right = delete(root->right, val);
    else{
        //zero child
        if(root->left == NULL && root->right == NULL)
        return NULL;
        // one child
        else if(root->right == NULL)
        return root->left;
        //two child
        else{
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
int main(){
    int choice,value;
    struct Node* root = NULL;
    while(1){
        printf("\n*****Binary Tree Menu*****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. search\n");
        printf("6.Delete\n");
        printf("7.Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                root = insert(root,value);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                postOrder(root);
                break;
            case 5:
            printf("Enter value: ");
            scanf("%d", &value);
            if(search(root,value)==NULL)
            printf("Element not found!!!\n");
            else
            printf("Element found!!!\n");
            break;
            case 6:
            printf("Enter Element To Delete: ");
            scanf("%d", &value);
            if(delete(root, value)== NULL)
            printf("Deleted element not found!!\n");
            else
            printf("Element Deleted!!\n");
            break;
            case 7:
                exit(0);
            default:
                printf("invalid Choice!!!\n");
        }
    }
    return 0;
}
