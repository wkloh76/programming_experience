#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.定义链表节点
typedef struct Node {
    int data;
    char *name;
    struct Node *next;
} Node;
int main()
{

    // 2.创建链表节点
    Node a;
    Node b;
    Node c;
    Node d;
    
    // 3.初始化节点数据
    a.data = 1;a.name=strdup( "wkloh"); // Copy the string content
    b.data = 3;b.name=strdup("enloh"); // Copy the string content
    c.data = 5;c.name=strdup("sschua"); // Copy the string content
    d.data = 10;d.name=strdup("end"); // Copy the string content

    // 4.链接节点
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    // 5.创建链表头
    Node *head = &a;

    // 6.使用链表
    while(head != NULL){
        int currentData = head->data;
        char *name = head->name;
        printf("currentData = %i and name is %s\n",currentData,name);
        printf("Node name is %s\n", name);
        head = head->next;
    }
    return 0;
}

// currentData = 1 and name is wkloh
// Node name is wkloh
// currentData = 3 and name is enloh
// Node name is enloh
// currentData = 5 and name is sschua
// Node name is sschua
// currentData = 10 and name is end
// Node name is end