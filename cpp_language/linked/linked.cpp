#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.定义链表节点
typedef struct node{
    int data;
    struct node *next;
}Node;
int main()
{

    // 2.创建链表节点
    Node a;
    Node b;
    Node c;
    Node d;

    // 3.初始化节点数据
    a.data = 1;
    b.data = 3;
    c.data = 5;
    d.data = 10;

    // 4.链接节点
    a.next = &b;//下一个节点的位置
    b.next = &c;//下一个节点的位置
    c.next = &d;//下一个节点的位置
    d.next = NULL;// 定義最後一個節點的下一个节点的位置資料爲NULL,結束while的循環

    // 5.创建链表头
    Node *head = &a;

    // 6.使用链表
    while(head != NULL){//檢查鏈表資料是否是NULL
        int currentData = head->data;
        printf("currentData = %i\n", currentData);
        head = head->next;
    }
    return 0;
}
//輸出結果
/* 
currentData = 1
currentData = 3
currentData = 5
currentData = 10
*/