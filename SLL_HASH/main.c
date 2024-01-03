#include <stdio.h>
#include "op.h"
int a[1000000];
int main(){
    init_hash_table();
    print_table();

    instruction al = {"AL"};
    instruction af = {"AF"};
    instruction df = {"DF"};
    instruction dl = {"DL"};
    instruction doom = {"DOOM_THE_LIST"};
    instruction de = {"DE"};
    instruction pf = {"PRINT_F"};
    instruction pl = {"PRINT_L"};
    instruction pa = {"PRINT_ALL"};


    hash_table_insert(&al);
    hash_table_insert(&af);
    hash_table_insert(&df);
    hash_table_insert(&dl);
    hash_table_insert(&doom);
    hash_table_insert(&de);
    hash_table_insert(&pf);
    hash_table_insert(&pl);
    hash_table_insert(&pa);

    Node *head = NULL;
    puts("\n\t--Start--\t\n");

    char word[20];
    int nr_of_elements = 0;
    int x;

    printf("\nRead instruction:");
    scanf("%s", word);
    strupr(word);
    if(!strcmp(word, "STOP"))
        printf("\n\t--Exiting the program!--\n");
    while(strcmp(word, "STOP"))
    {
        switch(hash_table_lookup(word))
        {
            case -1:
                printf("\n?????\n");
                break;
            case 0:
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
                break;
            case 1:
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
                break;
            case 2:
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
                break;
            case 3:
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
                break;
            case 4:
                if(!head)
                    printf("\nThere are no elements available!");
                else
                {
                    printf("\nList: ");
                    print_all(head);
                }
                break;
            case 5:
                printf("\nChoose an integer:");
                scanf("%d", &x);
                a[x]++;
                if(a[x] > 1)
                    printf("\nPlease introduce a different value! This one is already in use.");
                else
                {
                    nr_of_elements++;
                    AL(x, &head);
                }
                break;
            case 6:
                printf("\nChoose an integer:");
                scanf("%d", &x);
                a[x]++;
                if(a[x] > 1)
                    printf("\nPlease introduce a different value! This one is already in use.");
                else
                {
                    nr_of_elements++;
                    AF(x, &head);
                }
                break;
            case 7:
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
                break;
            case 8:
                if(head == NULL)
                    printf("\nNothing to delete. Please add a node!");
                else {
                    a[(*head).data] = 0;
                    printf("\nDeleted the first element!");
                    DF(&head);
                    nr_of_elements--;
                }
                break;
            default:
                break;
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