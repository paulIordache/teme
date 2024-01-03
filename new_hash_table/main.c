#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NAME 256

typedef uint64_t hashfunction (const char*, size_t);
typedef void cleanupfunction(void *);

typedef struct {
    char *name;
    void *object;
}entry;

typedef struct {
    uint32_t size;
    hashfunction *hash;
    cleanupfunction *cleanup;
    entry **elements;
    //..other stuff
}hash_table;

void mycleanup(void *p) {
    printf("destroying %p\n", p);
    free(p);
}

uint64_t hash(const char *name, size_t length) {

    size_t len = strlen(name);
    uint64_t hash_value = 0;

    for(uint32_t i = 0; i < len; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % length;
    }

    return hash_value;
}

hash_table *create_hash_table(size_t size, hashfunction *hf, cleanupfunction *cf) {
    hash_table *table = malloc(sizeof(hash_table));
    table->size = size;
    table->hash = hf;
    if (cf != NULL) table->cleanup = cf;
    else table->cleanup = free;
    table->elements = calloc(sizeof(entry *), table->size);
    return table;
}

void print_table(hash_table *table) {
    printf("Start table\n");
    for(uint32_t i = 0; i < table->size; i++) {
        entry *tmp = table->elements[i];
        if (tmp != NULL)
            printf("\t%i\t\"%s\"(%p)\n", i, tmp->name, tmp->object);
    }
    printf("End table\n");
}

bool hash_table_insert(hash_table *table, const char *key, void *obj) {
    if(table == NULL || key == NULL) return false;
    size_t index = hash(key, table->size);

    entry *e = malloc(sizeof(entry));
    e->object = obj;
    e->name = strdup(key);
    if(table->elements[index] != NULL) {
        uint32_t i = index;
        i++;
        while(1)
        {
            if(i == table->size)
                i = 0;
            if(table->elements[i] == NULL)
            {
                table->elements[i] = e;
                return true;
            }
            if(i == index) return false;
            i++;
        }
    }

    table->elements[index] = e;
    return true;
}

void *hash_table_lookup(hash_table *table, const char *key) {
    size_t index = hash(key, table->size);
    if(table->elements[index] != NULL) {
        entry *tmp = table->elements[index];
        if(strcmp(key, tmp->name) == 0) return tmp->object;
        else {
            size_t i = index;
            i++;
            while (1) {
                if (i == table->size)
                    i = 0;
                if (strcmp(key, tmp->name) == 0) return tmp->object;
                if(i++ == index) return NULL;
            }
        }
    }
    return NULL;
}

void hash_table_destroy(hash_table *table) {
    for(uint32_t i = 0; i < table->size; i++) {
        if(table->elements[i] != NULL) {
            entry *tmp = table->elements[i];
            free(tmp->name);
            table->cleanup(tmp->object);
            free(tmp);
        }
    }
    free(table->elements);
    free(table);
}

int main() {

    size_t size = (600);
    hash_table *table = create_hash_table(size, hash, mycleanup);
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
        return -1;
    char buffer[MAX_NAME];

    uint32_t numwords = 0;
    while(!feof(fp) && fgets(buffer, MAX_NAME, fp) != NULL) {
        buffer[strcspn(buffer, "\n\r")] = 0;
        //char *newentry = malloc(sizeof(strlen(buffer) + 1));
        char *newentry = malloc(MAX_NAME);
        strcpy(newentry, buffer);
        hash_table_insert(table, newentry, newentry);
        numwords++;
    }

    fclose(fp);
    printf("Loaded %d words into the table.\n", numwords);
    print_table(table);
    const char *tmp = hash_table_lookup(table, "David Wesley");
    if (tmp != NULL)
        printf("\nFound %s\n", tmp);
    hash_table_destroy(table);

    return 0;
}
