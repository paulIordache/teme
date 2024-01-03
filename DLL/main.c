#include <stdio.h>
#include "op.h"
#include <stdlib.h>
#include <string.h>
short a[MAX_RANGE];

int main() {
    FILE *file = fopen("input.txt", "r");
    FILE *file2 = fopen("output.txt", "w+");
    char word[MAX_NAME];

    Node *head = malloc(sizeof(Node));
    Node *cod;
    fscanf(file, "%s", word);

    strcpy((*head).name, word);
    (*head).right = NULL;
    (*head).left = NULL;

    unsigned int index = ascii(word);
    a[index] = 1;

    while(fscanf(file, "%s", word) != EOF)
        add_node(&head, word, &cod);

    while(head) {
        fprintf(file2, "%30s: %d\t|\t%10s: %d \n", (*head).name, a[ascii((*head).name)], (*cod).name, a[ascii((*cod).name)]);
        head = (*head).right;
        cod = (*cod).left;
    }

    fclose(file2);
    fclose(file);
    free(head);
    return 0;
}
