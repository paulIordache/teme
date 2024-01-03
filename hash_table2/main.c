#include <stdio.h>
#include <string.h>
#include "hash.h"
#define MAX_LINE 256

void mycleanup(void *p) {
    printf("destroying %p\n", p);
    free(p);
}

int main() {

    FILE *fp = fopen("input.txt", "r");
    char buffer[MAX_LINE];
    const uint32_t tablesize = (1<<20);
    hash_table *table = hash_table_create(tablesize, hash, mycleanup);

    uint32_t numwords = 0;
    while (feof(fp) == 0 && fgets(buffer, MAX_LINE, fp) != NULL) {
        buffer[strcspn(buffer, "\n\r")] = 0;
        char *newentry = malloc(strlen(buffer) + 1);
        strcpy(newentry, buffer);
        hash_table_insert(table, newentry, newentry);
        numwords++;
    }
    fclose(fp);
    printf("Loaded %d words into the table.\n", numwords);

    hash_table_print(table);
    const char *p = hash_table_lookup(table, "Razvan");
    if(p == NULL) printf("Couldn't find the name\n");
    else printf("Found %s\n", p);
    hash_table_destroy(table);
    return 0;
}
