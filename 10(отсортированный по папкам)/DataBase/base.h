
#ifndef INC_10_BASE_H
#define INC_10_BASE_H

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int population;
} City;

typedef struct {
    City* cities[MAX_SIZE];
} HashTable;

int calculateHash(char* key);
void addCityToHashTable(HashTable* hashTable, City* city);
void removeCityFromHashTable(HashTable* hashTable, char* cityName);
void listCitiesInHashTable(HashTable* hashTable);

#endif //INC_10_BASE_H
