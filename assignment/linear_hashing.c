#include<stdio.h>
#include<stdlib.h>

// Function to initialize the hash table and count
void init(int* _table, int* _count, int _TS) {
    for (int i = 0; i < _TS; i++) {
        _table[i] = -1;
    }
    *_count = 0;
}

// Function to calculate hash value for a key
int getHash(int _key, int TS) {
    return _key % TS;
}

// Function to insert a key into the hash table
void insert(int* _table, int _key, int _TS, int* _count) {
    int count = *_count;
    if (count == _TS) {
        fprintf(stdout, "size full");
        exit(1);
    }
    int k =  getHash(_key, _TS);
    while (_table[k] != -1) {
        k = (k + 1) % _TS;
    }
    _table[k] = _key;
    *_count += 1;
}

// Function to get the index of a key in the hash table
int get(int* _table, int _key, int _TS, int* _count) {
    int k =  getHash(_key, _TS);
    int i = 0;
    while (_table[k] != -1 && i < _TS) {   
        if (_table[k] == _key) {
            return k;
        }
        k = (k + 1) % _TS;
        i++;
    }
    printf("\nfail");
    return -1;
}

// Function to delete a key from the hash table
void delete(int* _table, int _key, int _TS, int* _count) {
    int count = *_count;
    if (count == 0) {
        fprintf(stdout, "size empty");
        exit(1);
    }
    int k =  getHash(_key, _TS);
    int i = 0;
    while (_table[k] != -1 || i < _TS) {   
        if (_table[k] == _key) {
            break;
        }
        k = (k + 1) % _TS;
        i++;
    }
    if (i != _TS) {
        _table[k] = -1;
        *_count -= 1;
        printf("\nsuc");
    } else {
        printf("\nfel");
    }
}

// Function to display the contents of the hash table
void display(int* _table, int _TS) {
    printf("\n");
    for (int i = 0; i < _TS; i++) {
        printf("\n%i ", _table[i]);
    }
    printf("\n");
}

// Menu function to interact with the hash table
void MEnu() {
    int choice = 0;
    int TS = 10;
    int count = 0;
    
    printf("Enter Hash Table Size: ");
    scanf("%i", &TS);
    
    int* arr = (int*) malloc(sizeof(int) * TS);
    init(arr, &count, TS);

    int key, key1, key2;

    printf("Menu:\n");
    printf("1. Insert\n");
    printf("2. Get\n");
    printf("3. Delete\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (choice != 5) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%i", &key);
                insert(arr, key, TS, &count);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%i", &key1);
                printf("%i\n", get(arr, key1, TS, &count));
                break;
            case 3:
                printf("Enter key: ");
                scanf("%i", &key2);
                delete(arr, key2, TS, &count);
                break;
            case 4:
                display(arr, TS);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }
}

int main() {
    MEnu();
    return 0;
}
