#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256

typedef uint64_t hashfunction(const char*, size_t);

typedef struct Racheta {
    char *name;
    uint32_t an_fabricatie;
    uint32_t putere_de_propulsie;
    struct Racheta *next;
}Racheta;

typedef struct hash_table {
    uint32_t size;
    hashfunction *hash;
    Racheta **entry;
}hash_table;

size_t hash_table_index(hash_table *ht, const char *key) {
    size_t result = (ht->hash(key, strlen(key)) % ht->size);
    return result;
}

uint64_t hash(const char *name, size_t length) {
    uint64_t hash_value = 0;
    for(uint32_t i = 0; i < length; i++) {
        hash_value += *(name + i);
        hash_value = hash_value * *(name + i);
    }
    return hash_value;
}

hash_table *create_rocket(hashfunction *hf, uint32_t size) {
    hash_table *ht = malloc(sizeof(hash_table));
    ht->size = size;
    ht->hash = hf;
    ht->entry = calloc(sizeof(Racheta), size);
    return ht;
}

Racheta *hash_table_lookup(hash_table *ht, const char *key) {
    if(key == NULL || ht == NULL) return NULL;

    size_t index = hash_table_index(ht, key);

    Racheta *tmp = ht->entry[index];
    while (tmp != NULL && strcmp(tmp->name, key) != 0)
        tmp = tmp->next;

    if (tmp == NULL)
        return NULL;
    return tmp;
}

bool insert(hash_table *ht, const char *key, uint32_t pdp, uint32_t af) {
    size_t index = hash_table_index(ht, key);
    if (hash_table_lookup(ht, key) != NULL) return false;

    Racheta *tmp = malloc(sizeof(Racheta));
    tmp->name = strdup(key);
    tmp->putere_de_propulsie = pdp;
    tmp->an_fabricatie = af;

    tmp->next = ht->entry[index];
    ht->entry[index] = tmp;
    return true;

}

void search_str(hash_table *ht, const char *key, FILE *fp) {
    if(key == NULL || ht == NULL) return;
    for(uint32_t i = 0; i < ht->size; i++) {
        Racheta *tmp = ht->entry[i];
        while(tmp) {
            if(strstr(tmp->name, key) != NULL)
                fprintf(fp, "%u\t%s\t%d\t%d\n", i, tmp->name, tmp->an_fabricatie, tmp->putere_de_propulsie);
            tmp = tmp->next;
        }
    }
}

void output_table(hash_table *ht, FILE *fp) {
    if(ht == NULL) return;
    for(uint32_t i = 0; i < ht->size; i++) {
        Racheta *tmp = ht->entry[i];
        while (tmp) {
            fprintf(fp, "%u\t%s\t%d\t%d\n", i, tmp->name, tmp->an_fabricatie, tmp->putere_de_propulsie);
            tmp = tmp->next;
        }
    }
}

float average_hash(hash_table *ht) {
    if(ht == NULL) return (float)INT32_MIN;

    float avg = 0;
    for(uint32_t i = 0; i < ht->size; i++) {
        Racheta *tmp = ht->entry[i];
        while(tmp) {
            avg += (float)tmp->putere_de_propulsie;
            tmp = tmp->next;
        }
    }

    return avg;
}

int main() {
    FILE *fp = fopen("input.txt.", "r");
    FILE *wp = fopen("output.txt", "w+");
    uint32_t size = (1 << 20);

    hash_table *table = create_rocket(hash, size);
    char *buffer = malloc(MAX_NAME);
    uint32_t pdp, af;
    uint32_t numwords = 0;
    fprintf(wp, "\nAverage: %f\n\n", average_hash(table)/(float)numwords);

    while(!feof(fp) && fscanf(fp, "%s %d %d", buffer, &af, &pdp)) {
        insert(table, buffer, pdp, af);
        numwords++;
    }

    output_table(table, wp);
    puts("\n");
    search_str(table, "i", wp);
    Racheta *tmp = hash_table_lookup(table, "Stresan");
    if(tmp != NULL)
        fprintf(wp, "\n0x%p", tmp);
    else fprintf(wp, "\nCouldn't find the name");
    fprintf(wp, "\nAverage: %f", average_hash(table)/(float)numwords);

    return 0;
}
