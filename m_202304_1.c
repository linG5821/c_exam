#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 尾插法建立单链表
void createList(struct Node** headRef) {
    int data;
    struct Node* tail = *headRef;
    struct Node* newNode;

    printf("请输入一组整数，以-1结束：\n");
    scanf("%d", &data);

    while (data != -1) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (*headRef == NULL) {
            *headRef = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        scanf("%d", &data);
    }
}

// 遍历单链表并输出结果
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// 删除单链表中数据域值与给定整数相等的节点
void deleteNode(struct Node** headRef, int value) {
    struct Node* current = *headRef;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *headRef = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            current = prev == NULL ? *headRef : prev->next;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

// 直接插入排序算法
void insertionSort(struct Node** headRef) {
    struct Node* sortedList = NULL;
    struct Node* current = *headRef;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        if (sortedList == NULL || current->data >= sortedList->data) {
            current->next = sortedList;
            sortedList = current;
        }
        else {
            struct Node* ptr = sortedList;
            while (ptr->next != NULL && ptr->next->data > current->data) {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            ptr->next = current;
        }
        current = next;
    }
    *headRef = sortedList;
}

int main() {
    setbuf(stdout, 0);

    struct Node* head = NULL;
    int value;

    createList(&head);

    printf("建立的单链表为：\n");
    printList(head);

    printf("请输入要删除的整数：\n");
    scanf("%d", &value);
    deleteNode(&head, value);

    printf("删除后的单链表为：\n");
    printList(head);

    insertionSort(&head);
    printf("排序后的单链表为：\n");
    printList(head);

    // 释放内存
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}