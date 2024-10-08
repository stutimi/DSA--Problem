#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

int count = 0;

// Function to create a new node
struct node* create_node(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Insert a node at the beginning
void insert_start() {
    int data;
    printf("Enter Your Node: ");
    scanf("%d", &data);

    struct node *newnode = create_node(data);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Node Inserted at Start\n");
    count++;
}

// Insert a node at a specified position
void insert_pos() {
    int pos, i = 1, data;
    printf("Enter the position to insert the node: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter Your Node: ");
    scanf("%d", &data);

    if (pos == 1) {
        insert_start();
        return;
    }

    struct node *newnode = create_node(data);
    struct node *temp = head;

    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;

    printf("Node Inserted at position %d\n", pos);
    count++;
}

// Insert a node at the end
void insert_end() {
    int data;
    printf("Enter Your Node: ");
    scanf("%d", &data);

    struct node *newnode = create_node(data);

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Node Inserted at End\n");
    count++;
}

// Delete the first node
void delete_start() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    free(temp);
    printf("First node deleted\n");
    count--;
}

// Delete a node at a specified position
void delete_pos() {
    int pos, i = 1;
    printf("Enter the position to delete the node: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        delete_start();
        return;
    }

    struct node *temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    struct node *todel = temp->next;
    temp->next = todel->next;

    if (todel->next) {
        todel->next->prev = temp;
    }

    free(todel);
    printf("Node at position %d deleted\n", pos);
    count--;
}

// Delete the last node
void delete_end() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    printf("Last node deleted\n");
    count--;
}

// Search for a value in the list
void search() {
    int num, pos = 1;
    printf("Enter the value you want to search: ");
    scanf("%d", &num);

    struct node *trav = head;
    while (trav != NULL) {
        if (trav->data == num) {
            printf("Number found at position %d\n", pos);
            return;
        }
        trav = trav->next;
        pos++;
    }
    printf("Number not found\n");
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *trav = head;
    while (trav != NULL) {
        printf("%d\n", trav->data);
        trav = trav->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter Your Choice\n");
        printf("1. Insert from Start\n");
        printf("2. Insert from Specified Position\n");
        printf("3. Insert from End\n");
        printf("4. Delete From Start\n");
        printf("5. Delete From Specified Position\n");
        printf("6. Delete From End\n");
        printf("7. Search by Value\n");
        printf("8. Display List\n");
        printf("9. Exit\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_start(); break;
            case 2: insert_pos(); break;
            case 3: insert_end(); break;
            case 4: delete_start(); break;
            case 5: delete_pos(); break;
            case 6: delete_end(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0); break;
            default: printf("Invalid Input!\n");
        }
    }
    return 0;
}
