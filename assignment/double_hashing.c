#include <stdio.h>
#include <stdlib.h>

// Initialize the hash table and count
void init(int* table, int* count, int size) {
    for (int i = 0; i < size; i++)
        table[i] = -1;
    *count = 0;
}

// Hash function to get the index for the given key
int getHash(int key, int size) {
    return key % size;
}

// Secondary hash function for collision resolution
int secondHash(int key) {
    return (8 - (key % 8));
}

// Insert key into the hash table
void insert(int* table, int key, int size, int* count) {
    int k = getHash(key, size);
    int p = 1;
    while (table[k] != -1) {
        k = (getHash(key, size) + (p * secondHash(key))) % size;
        p++;
    }
    table[k] = key;
    (*count)++;
}

// Get the index of a key in the hash table
int get(int* table, int key, int size, int* count) {
    int k = getHash(key, size);
    int i = 0, p = 1;
    while (table[k] != -1 && i < size) {
        if (table[k] == key)
            return k;
        k = (getHash(key, size) + (p * secondHash(key))) % size;
        p++;
        i++;
    }
    return -1;
}

// Delete a key from the hash table
void delete(int* table, int key, int size, int* count) {
    int k = getHash(key, size);
    int i = 0, p = 1;
    while (table[k] != -1 && i < size) {
        if (table[k] == key)
            break;
        k = (getHash(key, size) + (p * secondHash(key))) % size;
        p++;
        i++;
    }
    if (i != size) {
        table[k] = -1;
        (*count)--;
    }
}

// Display the hash table
void display(int* table, int size) {
    printf("\nHash Table:\n");
    for (int i = 0; i < size; i++) {
        if (table[i] != -1)
            printf("%d -> %d\n", i, table[i]);
        else
            printf("%d -> NULL\n", i);
    }
}

// Menu for user interaction
void Menu() {
    int choice = 0, TS = 10, count = 0;
    int* arr = (int*)malloc(sizeof(int) * TS);
    init(arr, &count, TS);

    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Get\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                int key;
                scanf("%d", &key);
                insert(arr, key, TS, &count);
                break;
            case 2:
                printf("Enter key to get: ");
                int key1;
                scanf("%d", &key1);
                printf("Index: %d\n", get(arr, key1, TS, &count));
                break;
            case 3:
                printf("Enter key to delete: ");
                int key2;
                scanf("%d", &key2);
                delete(arr, key2, TS, &count);
                break;
            case 4:
                display(arr, TS);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }
    free(arr); // Free the allocated memory
}

int main() {
    Menu(); // Run the menu-driven program
    return 0;
}
