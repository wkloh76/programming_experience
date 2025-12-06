#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.定义链表节点
typedef struct node
{
    int data;
    struct node *next;
} Node;

node *create(int val)
{
    // 申请新动态内存分配额度
    node *newLinked = (node *)malloc(sizeof(node));
    newLinked->data = val;
    newLinked->next = NULL;
    return newLinked;
}

node *merging(node *origin, node *target)
{
    // 创建一个虚的节点，简化边界条件处理
    node dummy;
    node *temp = &dummy;
    dummy.next = NULL;
    while (origin != NULL && target != NULL)
    {
        if (origin->data <= target->data)
        {
            temp->next = origin;
            origin = origin->next;
        }
        else
        {
            temp->next = target;
            target = target->next;
        }
        temp = temp->next;
    }
    // 将剩余非空链表连接带结果链表的未尾
    if (origin != NULL)
        temp->next = origin;
    else
        temp->next = target;
    return dummy.next;
}

// 打印链表所有内容
void printAllNode(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        // 檢查鏈表資料是否是NULL
        int currentData = current->data;
        printf("currentData = %i", currentData);
        if (current->next != NULL)

            printf("--> to be continue...\n");
        else
            printf(" is last the node\n");
        current = current->next;
    }
    printf("\n -------End-------\n");
}

// 释放无用链表内存
void freenode(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{

    printf("===== 合并两个有序链表 ========");

    // 创建第一个有序链表 ，1,3,5,7（唯有节点机构相同，此法得以进行）
    node *list1 = create(1);             // 创造第一个节点
    list1->next = create(3);             // 增加第二新节点，连带指定下个节点坐标
    list1->next->next = create(5);       // 增加第三新节点，连带指定下个节点坐标
    list1->next->next->next = create(7); // 增加第四新节点，连带指定下个节点坐标

    // 创建第一个有序链表 ，2,4,6,8 （唯有节点机构相同，此法得以进行）
    node *list2 = create(2);             // 创造第一个节点
    list2->next = create(4);             // 增加第二新节点，连带指定下个节点坐标
    list2->next->next = create(6);       // 增加第三新节点，连带指定下个节点坐标
    list2->next->next->next = create(8); // 增加第四新节点，连带指定下个节点坐标

    printf("链表1:\n");
    printAllNode(list1);

    printf("链表2:\n");
    printAllNode(list2);

    // 合并启动
    node *merged = merging(list1, list2);
    printf("合并后：\n");
    printAllNode(merged);

    // 释放内存
    freenode(merged);
    return 0;
}
// 輸出結果
/*
===== 合并两个有序链表 ========链表1:
currentData = 1--> to be continue...
currentData = 3--> to be continue...
currentData = 5--> to be continue...
currentData = 7 is last the node

 -------End-------
链表2:
currentData = 2--> to be continue...
currentData = 4--> to be continue...
currentData = 6--> to be continue...
currentData = 8 is last the node

 -------End-------
合并后：
currentData = 1--> to be continue...
currentData = 2--> to be continue...
currentData = 3--> to be continue...
currentData = 4--> to be continue...
currentData = 5--> to be continue...
currentData = 6--> to be continue...
currentData = 7--> to be continue...
currentData = 8 is last the node

 -------End-------
*/