#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize table
void init() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Insert using quadratic probing
void insert(int key) {
    int index = key % SIZE;

    int i = 0;
    while(hashTable[(index + i*i) % SIZE] != -1) {
        i++;
    }

    hashTable[(index + i*i) % SIZE] = key;
}

// Display table
void display() {
    printf("Hash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    return 0;
}