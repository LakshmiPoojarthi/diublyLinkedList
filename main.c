#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to find an element in the doubly linked list
struct Node* find_element(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to persist elements into a text file
void persist_to_text_file(struct Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }

    fclose(file);
}

// Function to persist elements into a binary file
void persist_to_binary_file(struct Node* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        fwrite(&current->data, sizeof(int), 1, file);
        current = current->next;
    }

    fclose(file);
}

int main() {
    // Create the doubly linked list
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 10; node1->prev = NULL; node1->next = node2;
    node2->data = 20; node2->prev = node1; node2->next = node3;
    node3->data = 30; node3->prev = node2; node3->next = node4;
    node4->data = 40; node4->prev = node3; node4->next = NULL;

    // Find an element in the doubly linked list
    int target = 30;
    struct Node* targetNode = find_element(node1, target);
    if (targetNode != NULL) {
        printf("Element found: %d\n", targetNode->data);
    } else {
        printf("Element not found.\n");
    }

    // Persist elements into text file
    persist_to_text_file(node1, "doubly_linked_list.txt");

    // Persist elements into binary file
    persist_to_binary_file(node1, "doubly_linked_list.bin");

    // Clean up: free allocated memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}







