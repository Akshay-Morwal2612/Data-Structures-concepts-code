# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * createNode(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

struct node *insertFirst(int value, struct node *head) {
    struct node *newNode;
    newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    return head;
}

struct node* insertEnd(int value, struct node *head){
    struct node *newNode;
    struct node *temp;
    newNode = createNode(value);

    if(head == NULL){
        head = newNode;
        return head;
    }

    temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
    return head;
}

struct node* deleteEnd(struct node *head){
    struct node *temp;
    struct node *prev;
    if(head == NULL){
        printf("List is Empty.\n");
        return NULL;
    }
    
    if(head -> next == NULL){
        free(head);
        head = NULL;
        return NULL;
    }
    
    temp = head;
    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    
    prev -> next = NULL;
    free(temp);
    return head;
}

struct node* deleteFirst(struct node *head){
    struct node *temp;

    if(head == NULL){
        printf("List is Empty.\n");
        return NULL;
    }

    temp = head -> next;
    free(head);
    head = temp;
    return head;    
}


struct node* insert_in_between_bnode(struct node *head, int value,int key){
    struct node *newNode;
    struct node *temp;
    struct node *prev;
    
    newNode = createNode(value);

    if(head == NULL){
        return newNode;
    }

    if (head->data == key) {
        newNode->next = head;
        return newNode;
    }

    temp = head;
    while(temp != NULL && temp -> data != key){
        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL) {
        printf("Key not found.\n");
        free(newNode);
        return head;
    }

    newNode -> next = prev -> next;
    prev -> next = newNode;
    return head;
}

struct node* insert_in_between_anode(struct node *head, int value, int key){
    struct node *newNode;
    struct node *temp;
    newNode = createNode(value);

    if(head == NULL){
        return newNode;
    }

    temp = head;
    while(temp != NULL && temp -> data != key){
        temp = temp -> next;
    }

    if (temp == NULL) {
        printf("Key not found.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main() {
    struct node *head = NULL;

    printf("Initial list:\n");
    display(head);

    // 1. Insert at beginning
    printf("\n1. Insert First:\n");
    head = insertFirst(20, head);
    head = insertFirst(10, head);
    display(head);

    // 2. Insert at end
    printf("\n2. Insert End:\n");
    head = insertEnd(30, head);
    head = insertEnd(40, head);
    display(head);

    // 3. Insert before a node
    printf("\n3. Insert Before 30:\n");
    head = insert_in_between_bnode(head, 25, 30);
    display(head);

    // 4. Insert after a node
    printf("\n4. Insert After 30:\n");
    head = insert_in_between_anode(head, 35, 30);
    display(head);

    // 5. Delete first node
    printf("\n5. Delete First:\n");
    head = deleteFirst(head);
    display(head);

    // 6. Delete last node
    printf("\n6. Delete End:\n");
    head = deleteEnd(head);
    display(head);

    // 7. Insert before the first node
    printf("\n7. Insert Before First Node:\n");
    head = insert_in_between_bnode(head, 5, 20);
    display(head);

    // 8. Insert after the first node
    printf("\n8. Insert After First Node:\n");
    head = insert_in_between_anode(head, 15, 5);
    display(head);

    // 9. Try inserting before a key that doesn't exist
    printf("\n9. Insert Before Non-existing Key:\n");
    head = insert_in_between_bnode(head, 100, 999);
    display(head);

    // 10. Try inserting after a key that doesn't exist
    printf("\n10. Insert After Non-existing Key:\n");
    head = insert_in_between_anode(head, 200, 999);
    display(head);

    // 11. Delete all nodes
    printf("\n11. Deleting All Nodes:\n");

    while (head != NULL) {
        head = deleteFirst(head);
        display(head);
    }

    // 12. Try deleting from an empty list
    printf("\n12. Delete From Empty List:\n");
    head = deleteFirst(head);

    printf("\nProgram completed successfully.\n");

    return 0;
}
