#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define linkedsize 10  // Define maximum size for the linked list

struct node {
    int info;
    struct node* next;
};

typedef struct node Node;
Node list[linkedsize]; // Array of nodes
int count = 0; // Current number of elements in the linked list

// Function prototypes
void traversal();
void insertbeg(int item);
void insertmid(int item, int pos);
void insertlast(int item);
void deletebeg();
void deletemid(int pos);
void deletelast();

void traversal() {
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i].info);
    }
    printf("\n");
}

void insertbeg(int item) {
    if (count >= linkedsize) {
        printf("List is full. Cannot insert at the beginning.\n");
        return;
    }
    for (int i = count; i > 0; i--) {
        list[i] = list[i - 1]; // Shift elements to the right
    }
    list[0].info = item; // Insert at the beginning
    count++;
}

void insertlast(int item) {
    if (count >= linkedsize) {
        printf("List is full. Cannot insert at the end.\n");
        return;
    }
    list[count].info = item; // Insert at the end
    count++;
}

void insertmid(int item, int pos) {
    if (count >= linkedsize) {
        printf("List is full. Cannot insert in the middle.\n");
        return;
    }
    if (pos < 0 || pos > count) {
        printf("Position does not exist.\n");
        return;
    }
    for (int i = count; i > pos; i--) {
        list[i] = list[i - 1]; // Shift elements to the right
    }
    list[pos].info = item; // Insert at the specified position
    count++;
}

void deletebeg() {
    if (count == 0) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
	printf("Deleted element from beginning: %d\n", list[0].info);
    for (int i = 0; i < count - 1; i++) {
        list[i] = list[i + 1]; // Shift elements to the left
    }
    count--;
}

void deletelast() {
    if (count == 0) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    printf("Deleted element from end: %d\n", list[count - 1].info);
    count--; // Simply reduce the count
}

void deletemid(int pos) {
    if (count == 0) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos < 0 || pos >= count) {
        printf("Position does not exist.\n");
        return;
    }
    printf("Deleted element from position %d: %d\n", pos, list[pos].info);
    for (int i = pos; i < count - 1; i++) {
        list[i] = list[i + 1]; // Shift elements to the left
    }
    count--;
}

int main() {
    char c, nap;
    int choice, num, position;
    do {
        printf("You want to edit your list:\n");
        printf("Tap 'y' for YES and 'n' for NO:\n");
        nap = getche();
        printf("\nPress 'i' for inserting an element:\n");
        printf("Press 'd' for deleting an element:\n");
        printf("Enter your choice: ");
        c = getche();
        printf("\n");

        if (c == 'i') {
            printf("Enter the position at which you want to enter the element: ");
            scanf("%d", &position);
            printf("Enter the element to insert: ");
            scanf("%d", &num);
            insertmid(num, position);
            traversal();  // Display the list after insertion
        } else if (c == 'd') {
            printf("Press 'b' to delete from beginning,\n");
            printf("Press 'm' to delete from middle,\n");
            printf("Press 'l' to delete from last: \n");
            char delChoice = getche();
            printf("\n");

            if (delChoice == 'b') {
                deletebeg();
                traversal();  // Display the list after deletion
            } else if (delChoice == 'm') {
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deletemid(position);
                traversal();  // Display the list after deletion
            } else if (delChoice == 'l') {
                deletelast();
                traversal();  // Display the list after deletion
            } else {
                printf("Invalid choice.\n");
            }
        } else {
            printf("You entered an incorrect choice\n");
        }
    } while (nap != 'n');
    return 0;
}
