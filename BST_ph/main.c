#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>

#define EXP 20230402

typedef struct NodeT
{
    uint32_t price, amount, dateOfExpiration, dateOfManufacturing;
    char name[63];
    struct NodeT *left, *right;
}NodeT;

void preorder(NodeT *root)
{
    if(root == NULL)
        return;
    else
    {
        printf("%s ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

NodeT *newNode(uint32_t price, uint32_t amount, uint32_t dateOfExpiration, uint32_t dateOfManufacturing, const char *name)
{
    NodeT *temp = (NodeT *)malloc(sizeof(NodeT));

    strcpy(temp->name, name);
    temp->price = price;
    temp->amount = amount;

    temp->dateOfExpiration = dateOfExpiration;
    temp->dateOfManufacturing = dateOfManufacturing;
    temp->left = temp->right = NULL;

    return temp;
}



NodeT *insert(NodeT *root, uint32_t price, uint32_t amount, uint32_t dateOfExpiration, uint32_t dateOfManufacturing, const char *name)
{
    char s[63];
    char t[63];
    strcpy(s, name);
    strupr(s);
    if(root)
    {
        strcpy(t, root->name);
        strupr(t);
    }
    if (root == NULL)
        return newNode(price, amount, dateOfExpiration, dateOfManufacturing, name);
    else if (strcmp(s, t) <= 0)
        root->left = insert(root->left, price, amount, dateOfExpiration, dateOfManufacturing, name);
    else
        root->right = insert(root->right, price, amount, dateOfExpiration, dateOfManufacturing, name);


    return root;
}

NodeT *minValueNode(NodeT *root)
{
    NodeT *current = root;

    while(current->left)
        current = current->left;

    return current;
}

NodeT *deleteNode(NodeT *root, const char *key)
{
    if(root == NULL)
        return root;
    else if(strcmp(key, root->name) < 0)
        root->left = deleteNode(root->left, key);
    else if(strcmp(key, root->name) > 0)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
           return NULL;
        }
        else if(root->left == NULL)
        {
            NodeT *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            NodeT *temp = root->left;
            free(root);
            return temp;
        }

        NodeT *temp = minValueNode(root->right);

        strcpy(root->name, temp->name);

        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}
void searchNode(NodeT **root, const char *name) {
    if (*root == NULL) {
        printf("\nCouldn't find %s", name);
        return;
    } else if (strcmp((*root)->name, name) == 0) {

        printf("ok\n");
        char key[63], price[10], amount[10], dateOfManufacturing[10], dateOfExpiration[10];
        scanf("%s %s %s %s %s", key, price, amount, dateOfManufacturing,
              dateOfExpiration);

        if(strcmp(key, "~") != 0)
            strcpy((*root)->name, key);

        if(strcmp(price, "~") != 0)
            (*root)->price = atoi(price);

        if(strcmp(amount, "~") != 0)
            (*root)->amount = atoi(amount);

        if(strcmp(dateOfManufacturing, "~") != 0)
            (*root)->dateOfManufacturing = atoi(dateOfManufacturing);

        if(strcmp(dateOfExpiration, "~") != 0)
            (*root)->dateOfExpiration = atoi(dateOfExpiration);

        fflush(stdin);
        return;

    } else if (strcmp(name, (*root)->name) < 0)
        searchNode(&(*root)->left, name);
    else if (strcmp(name, (*root)->name) > 0)
        searchNode(&(*root)->right, name);
}
void expired(NodeT *root, NodeT **root_exp)
{
    if(root == NULL)
        return;

    if(root->dateOfExpiration > EXP)
        *root_exp = insert(*root_exp, root->price, root->amount, root->dateOfExpiration, root->dateOfManufacturing, root->name);
    expired(root->left, root_exp);
    expired(root->right, root_exp);
}



int main()
{
    NodeT *root = NULL, *root_exp = NULL;
    char buff[7];
    printf("\nInput command:");
    scanf("%s", buff);
    while(strcmp(buff, "s") != 0)
    {
        if(strcmp(buff, "i") == 0)
        {
            uint32_t price, amount, dateOfExpiration, dateOfManufacturing;
            char name[63];
            printf("\nRead inputs(name, price, amount, dataOfManufacturing, dateOfExpiration):");
            scanf("%s %d %d %d %d", name, &price, &amount, &dateOfManufacturing, &dateOfExpiration);
            root = insert(root, price, amount, dateOfExpiration, dateOfManufacturing, name);
        }
        else if(strcmp(buff, "d") == 0)
        {
            char name[63];
            scanf("%s", name);
            root = deleteNode(root, name);
        }
        else if(strcmp(buff, "u") == 0)
        {
            char s[63];
            scanf("%s", s);
            searchNode(&root, s);
        }
        else if(strcmp(buff, "ce") == 0)
            expired(root, &root_exp);
        else printf("\nPlease input a valid command");

        fflush(stdin);
        printf("\nInput command:");
        scanf("%s", buff);

    }

    preorder(root);
    puts("\n");
    preorder(root_exp);
    return 0;
}
