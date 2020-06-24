#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *deallocate = NULL;

//display the list
void printList() {

    struct node *ptr = head;

    printf("\n[head] =>");
    //start from the beginning
    while (ptr != NULL) {
        printf(" %d =>", ptr->data);
        tail = ptr;
        ptr = ptr->next;
    }

    //printf("%d", tail->data);
    printf(" [null]\n");
}

void deleteElement(int position) {
    struct node *tmp = head;
    while (position - 1 > 0) {
        tmp = tmp->next;
        position = position - 1;
    }
    deallocate = tmp->next;
    tmp->next = tmp->next->next;
    free(deallocate);

}

void removeHeadNode() {
    struct node *tmp = head;
    tmp = tmp->next;
    head = tmp;
}

void removeFromEnd() {
    struct node *ptr = head;
    while (ptr->next != tail) {
        ptr = ptr->next;
    }
    ptr->next= NULL;
}

//insert link at the first location
void insert(int data) {
    //create a link
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    //set data to node
    newNode->data = data;
    newNode->next = head;
    //updating head
    head = newNode;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(1);
    insert(40);
    insert(56);

    printList();

    deleteElement(3);
    printList();

    removeHeadNode();
    printList();
    removeFromEnd();
    printList();
    return 0;
}
