#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct List {
    int val;
    struct List *next; 
} List;

List *createNewNode(int value) {
    List *newNode = malloc(sizeof(List));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void    printList(List *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

List*    getMiddle(List *start, List *end) {

    List *slow = start; 
    List *fast = start;

    // fast moves with 2 steps, slow moves with one step
    
    while (fast && fast != end) {
        fast = fast->next;
        if (fast && fast != end) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

bool    binSearch(List *lst, int value) {
    List *start = lst;
    List *end = lst;
    while (end && end->next != NULL)
        end = end->next;
    
    while (start && end && end->next != start) {
        List *mid = getMiddle(start, end);
        if (start == end) return (start->val == value);
        if (mid->val == value) return 1;
        if (mid->val < value) start = mid->next;
        else end = mid;
    }
    return 0;
}

int main() {
    List *head = NULL;
    List *back = NULL; 
    int n;
    printf("Enter linked list size.\n");
    scanf("%d", &n);
    
    int last = INT_MIN; 
    for (int i = 0; i < n; i++) {
        printf("Enter element number %d: ", i + 1);
        int num; scanf("%d", &num);
        if (num < last) {
            printf("Linked list should be sorted.\n");
            return 0;
        }
        List *newNode = createNewNode(num);
        if (head == NULL) {
            head = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = back->next;
        }
        last = num;
    }

    printList(head);


    // queries:
    while (1) {
        int value;
        printf("Enter number that you are looking for: ");
        scanf("%d", &value);
        bool exist = binSearch(head, value);
        if (exist) printf("Number: %d exist.\n", value);
        else printf("Number: %d doesn't exist.\n", value);
    } 
}

