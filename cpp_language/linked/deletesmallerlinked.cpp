#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义链表节点结构
struct Node
{
    int data;
    struct Node *next;
};

// 创建新节点
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾插入节点
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// 打印链表
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("链表为空\n");
        return;
    }

    struct Node *current = head;
    printf("[");
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}

// 释放链表内存
void freeList(struct Node *head)
{
    struct Node *current = head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

// 查找并删除最小元素的函数
int findAndDeleteMin(struct Node **head)
{
    // 如果链表为空，返回INT_MIN表示错误
    if (*head == NULL)
    {
        return INT_MIN;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *minNode = *head;
    struct Node *minPrev = NULL;
    int minValue = (*head)->data;

    // 遍历链表查找最小元素及其前驱节点
    while (current != NULL)
    {
        if (current->data < minValue)
        {
            minValue = current->data;
            minNode = current;
            minPrev = prev;
        }
        prev = current;
        current = current->next;
    }

    // 从链表中删除最小元素节点
    // 情况1：最小元素是头节点
    if (minNode == *head)
    {
        *head = minNode->next;
    }
    // 情况2：最小元素不是头节点
    else
    {
        minPrev->next = minNode->next;
    }

    // 释放最小元素节点的内存
    free(minNode);

    return minValue;
}

// 主函数 - 测试示例
int main()
{
    struct Node *head = NULL;
    int minValue;

    // 创建一个无序链表
    printf("创建无序链表:\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 3);

    printf("原始链表: ");
    printList(head);

    // 查找并删除最小元素
    minValue = findAndDeleteMin(&head);
    if (minValue != INT_MIN)
    {
        printf("\n删除的最小元素: %d\n", minValue);
        printf("删除最小元素后的链表: ");
        printList(head);
    }

    // 再次查找并删除最小元素
    minValue = findAndDeleteMin(&head);
    if (minValue != INT_MIN)
    {
        printf("\n删除的最小元素: %d\n", minValue);
        printf("删除最小元素后的链表: ");
        printList(head);
    }

    // 测试边界情况
    printf("\n=== 测试边界情况 ===\n");

    // 测试空链表
    struct Node *emptyList = NULL;
    printf("\n测试空链表:\n");
    minValue = findAndDeleteMin(&emptyList);
    if (minValue == INT_MIN)
    {
        printf("链表为空，未找到最小元素\n");
    }

    // 测试只有一个节点的链表
    struct Node *singleNodeList = createNode(42);
    printf("\n测试单节点链表:\n");
    printf("原始链表: ");
    printList(singleNodeList);

    minValue = findAndDeleteMin(&singleNodeList);
    printf("删除的最小元素: %d\n", minValue);
    printf("删除后的链表: ");
    printList(singleNodeList);

    // 清理内存
    freeList(head);
    freeList(singleNodeList);

    return 0;
}
