#include <stdio.h>
#include "op.h"
int a[1000000];
int main(){
    Node *head = NULL;
    puts("\n\t--Start--\t\n");
    char word[20];
    int nr_of_elements = 0;
    printf("\nRead instruction:");
    scanf("%s", word);
    strupr(word);
    if(!strcmp(word, "STOP"))
        printf("\n\t--Exiting the program!--\n");
    while(strcmp(word, "STOP"))
    {
        if(!strcmp(word, "AF"))
        {
            printf("\nChoose an integer:");
            int x;
            scanf("%d", &x);
            a[x]++;
            if(a[x] > 1)
                printf("\nPlease introduce a different value! This one is already in use.");
            else
            {
                nr_of_elements++;
                AF(x, &head);
            }

        }
        else
            if(!strcmp(word, "AL"))
        {
            printf("\nChoose an integer:");
            int x;
            scanf("%d", &x);
            a[x]++;
            if(a[x] > 1)
                printf("\nPlease introduce a different value! This one is already in use.");
            else
            {
                nr_of_elements++;
                AL(x, &head);
            }

        }
        else
            if(!strcmp(word, "DF"))
        {
            if(head == NULL)
                printf("\nNothing to delete. Please add a node!");
            else
            {
                a[(*head).data] = 0;
                printf("\nDeleted the first element!");
                DF(&head);
                nr_of_elements--;
            }
        }
        else
            if(!strcmp(word, "DL"))
        {
            if(head == NULL)
                printf("\nNothing to delete. Please add a node!");
            else
            {
                Node *temp = head;
                while((*temp).next)
                    temp = (*temp).next;
                a[(*temp).data] = 0;
                printf("\nDeleted the last element!");
                DL(&head);
                nr_of_elements--;
            }
        }
        else
            if(!strcmp(word, "DOOM_THE_LIST"))
        {
            if(head == NULL)
                printf("\nDoom nothing?");
            else
            {
                for(int i = 0; i <= 999999; i++)
                    a[i] = 0;
                printf("\nDeleted the whole list!");
                doom_the_list(&head);
                nr_of_elements = 0;
            }
        }
        else
            if(!strcmp(word, "PRINT_ALL"))
        {
            if(!head)
                printf("\nThere are no elements available!");
            else
            {
                printf("\nList: ");
                print_all(head);
            }
        }
        else
            if(!strcmp(word, "DE"))
        {
            int x;
            printf("\nChoose an integer:");
            scanf("%d", &x);
            if(a[x])
            {
                DE(x, &head);
                printf("\nDeleted the node of key %d!", x);
                a[x] = 0;
                nr_of_elements--;
            }
            else printf("\nWhat should I delete?");
        }
        else if(!strcmp(word, "PRINT_F"))
        {
            int x;
            printf("\nChoose an integer:");
            scanf("%d", &x);
            if(x == 0 || !head)
                printf("\nCannot print 0 elements!");
            else if(x <= nr_of_elements)
            {
                printf("\nList: ");
                PRINT_F(x, head);
                printf("\nPrinted the first %d elements!", x);
            }
            else if(x > nr_of_elements)
                print_all(head);
        }
        else if(!strcmp(word, "PRINT_L"))
        {
            int x;
            printf("\nChoose an integer:");
            scanf("%d", &x);
            if(x == 0 || !head)
                printf("\nPrint the last 0 elements?");
            else if(x <= nr_of_elements)
            {
                printf("\nList: ");
                PRINT_L(x, head, nr_of_elements);
                printf("\nPrinted the last %d elements!", x);
            }

            else if(x > nr_of_elements)
                print_all(head);
        }
        puts("\n__________________________________");
        printf("\nRead instruction:");
        scanf("%s", word);
        strupr(word);
        if(!strcmp(word, "STOP"))
            printf("\n\t--Exiting the program!--\t\n");

    }
    return 0;
}