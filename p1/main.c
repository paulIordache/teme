#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void append(Node **aRef, Node **bRef) {
    if (*aRef == NULL) {
        printf("The List is NULL. Cannot append to the end of the list\n");
        return;
    }

    Node *temp = *aRef;

    while(temp->next)
        temp = temp->next;


    if(*bRef != NULL)
        temp->next = *bRef;
    else printf("The List is NULL. Cannot append to the end of the list\n");

}

void create_List(Node **head, int data) {
    Node *temp = malloc(sizeof(Node));

    if(*head == NULL) {
        temp->data = data;
        temp->next = NULL;

        *head = temp;
    }

    (*head)->next = temp;
    temp->next = NULL;
    temp->data = data;
}

void print_list(Node *head) {
    while(head) {

        if(head->next == NULL)
            printf("(0x%p)\"%d\"", head, head->data);
        else
            printf("(0x%p)\"%d\" -> ", head, head->data);

        head = head->next;
    }
}

void delete(Node **bRef) {
    if(*bRef == NULL) return;

    else {
        while(*bRef) {
            Node *del = *bRef;
            *bRef = (*bRef)->next;
            free(del);
        }
    }
}



int main() {
    Node *head1 = NULL;

    create_List(&head1, 1);
    create_List(&head1, 2);

    Node *head2 = NULL;
    Node *head3 = NULL;
    Node *head4 = NULL;

    create_List(&head2, 3);
    create_List(&head2, 4);

    //Try to appoint head1 to NULL List "head3"
    append(&head1, &head3);

    //Append head1 to the end of head2
    append(&head1, &head2);

    //Append NULL List "head4" to head1
    append(&head4, &head1);

    print_list(head1);
    delete(&head2);
    print_list(head2);

    return 0;
}
