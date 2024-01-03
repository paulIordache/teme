#include "op.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern short a[MAX_RANGE];

unsigned int ascii(char *word) {
    unsigned int index = 0;
    for (int i = 0; i < strlen(word); i++)
        index += word[i];
    return index;
}

void add_node(Node **head, char *word, Node **tail) {
        unsigned int index;
        index = ascii(word);
        if(a[index]++ == 0) {
            char s[strlen(word)];
            char t[strlen((**head).name)];
            strcpy(s, word);
            strcpy(t, (**head).name);
            strupr(s);
            strupr(t);
            if(strcmp(t, s) >= 0) {
                Node *tmp = malloc(sizeof(Node));
                (*tmp).right = *head;
                (*tmp).left = NULL;
                (**head).left = tmp;
                strcpy((*tmp).name, word);
                *head = (**head).left;
            }
            else {
                if (!(**head).right) {
                    if (strcmp(t, s) <= 0) {
                        Node *tmp = malloc(sizeof(Node));
                        (**head).right = tmp;
                        (*tmp).left = *head;
                        (*tmp).right = NULL;
                        strcpy((*tmp).name, word);
                    }

                }
                else {
                    Node *tmp = (**head).right;
                    while ((*tmp).right) {
                        char z[strlen((*tmp).name)];
                        strcpy(z, (*tmp).name);
                        strupr(z);
                        if (strcmp(z, s) >= 0) {
                            Node *add = malloc(sizeof(Node));
                            Node *left = (*tmp).left;
                            strcpy((*add).name, word);
                            (*left).right = add;
                            (*add).left = left;
                            (*add).right = tmp;
                            (*tmp).left = add;
                            break;
                        } else tmp = (*tmp).right;
                    }
                    if (!(*tmp).right) {
                    char z[strlen((*tmp).name)];
                    strcpy(z, (*tmp).name);
                    strupr(z);
                    if (strcmp(z, s) >= 0) {
                        *tail = tmp;
                        Node *add = malloc(sizeof(Node));
                        Node *left = (*tmp).left;
                        strcpy((*add).name, word);
                        (*left).right = add;
                        (*add).left = left;
                        (*add).right = tmp;
                        (*tmp).left = add;
                    } else {
                        Node *add = malloc(sizeof(Node));
                        strcpy((*add).name, word);
                        (*add).left = tmp;
                        (*tmp).right = add;
                        (*add).right = NULL;
                        *tail = add;
                    }
                }
            }
            }
        }
    }
