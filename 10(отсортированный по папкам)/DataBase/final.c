#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

int calculateHash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % MAX_SIZE;
}

void addCityToHashTable(HashTable* hashTable, City* city) {
    int index = calculateHash(city->name);

    if (hashTable->cities[index] != NULL) {
        printf("Shit! This city %s could not be added.\n", city->name);
        return;
    }

    hashTable->cities[index] = city;
    printf("YES!!! City %s is added to database.\n", city->name);
}

void removeCityFromHashTable(HashTable* hashTable, char* cityName) {
    int index = calculateHash(cityName);

    if (hashTable->cities[index] == NULL) {
        printf("O my Gosh!!! NO!!! City %s could not be find in database.\n", cityName);
        return;
    }

    free(hashTable->cities[index]);
    hashTable->cities[index] = NULL;
    printf("Why???? ARE YOU SERIOUSLY?!?! City %s has been deleted from database.\n", cityName);
}

void listCitiesInHashTable(HashTable* hashTable) {
    printf("Nice) Your list of cities:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (hashTable->cities[i] != NULL) {
            printf("%s (zombie people: %d)\n", hashTable->cities[i]->name, hashTable->cities[i]->population);
        }
    }
}

int main() {
    HashTable hashTable;
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable.cities[i] = NULL;
    }

    int choice;
    do {
        printf("1. Add city(Please)\n");
        printf("2. Delete city(No, no, no....)\n");
        printf("3. Show list of cities(Check your balance)\n");
        printf("4. Exit(Bye, bye, duck!!!)\n");
        printf("Choose option(Better then doing nothing): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of your city(of course, you write a Moscow, because we are living in Moscow, but it is not right!):");
                char cityName[50];
                scanf("%s", cityName);

                if (hashTable.cities[calculateHash(cityName)] != NULL) {
                    printf("WHAT ARE YOU DOING????? THIS CITY %s IS ALREADY EXIST! TRY THINK BETTER!\n", cityName);
                    break;
                }

                int population;
                printf("How many zombie-people live in your city? Answer clearly, without any fakes...: ");
                scanf("%d", &population);

                City *city = (City *) malloc(sizeof(City));
                strcpy(city->name, cityName);
                city->population = population;

                addCityToHashTable(&hashTable, city);
                break;

            case 2:
                printf("This city will be destroyed by nuclear bomb: ");
                char cityToRemove[50];
                scanf("%s", cityToRemove);

                removeCityFromHashTable(&hashTable, cityToRemove);
                break;

            case 3:
                listCitiesInHashTable(&hashTable);
                break;

            case 4:
                printf("Does the President want to leave out this game? So you must take out your custom.\n");
                break;

            default:
                printf("Who are you? The list with operations is been here.Please read it!\n");
        }

    }while (choice != 4);

    return 0;
}