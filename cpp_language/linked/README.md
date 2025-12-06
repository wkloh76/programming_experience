# 鏈表和結構體

## 結構體自定義

- `typedef struct{}Person` 初始定义
- `typedef struct` 结构定义法
- `{}` 新曾类型组员，可以是 int,float,char 等
- `Person` 新结构名字
- 以下是范例：

```
typedef struct{
    char *name;
    int age;
    double height;
} Person;
```

程式參考:[linked.cpp](./linked.cpp)
![linked.cpp](./linked.cpp)

## 鏈表自定義

- `typedef struct starlink{ starlink *next}Node` 初始定义，“starlink” 可以是任何名字，类型组员組必須要有一个定义成同一个链表结构，组员也可以是其它名字。
- `typedef struct` 结构定义法
- `starlink` 自定义链表表名字
- `{ starlink *next}` 组员必自帶同款链表类型
- `Node` 新链表名字
- 以下是简单范例：

```
typedef struct node{
int data;
struct node *next;
}Node;
```

- 以下是简单+字串范例：

```
typedef struct node{
int data;
char *name;
struct node *next;
}Node;
```

程式參考：[advlinked.cpp](./advlinked.cpp)
![advlinked.cpp](./advlinked.cpp)

# 鏈表原理

## 烤串

![图片描述](./src/bbq.png)
来源：[知乎](https://www.zhihu.com/column/p/32742113)

- 一个烤串条里可以有不同食材，每个食材有固定的大小。你可以想象的是链表就是一个烤串条，节点就是食材。
- 试想想节点结构的`data`就是食材,`next`就是指向下一个节点坐标。当我们要开始串，想好地个节是什么，下一个节的坐标給注册`next`，以此类推。。。參考`linked.cpp`.

```
// 2.创建链表节点(a,c,b,d)
    Node a;
    Node b;
    Node c;
    Node d;
```

```
// 3.初始化节点数据(放入食材如：洋蔥、黃瓜、雞肉、黃燈籠椒)
    a.data = 1;
    b.data = 3;
    c.data = 5;
    d.data = 10;
```

```
// 4.链接节点（設定下個節點座標）
    a.next = &b;//下一个节点的位置
    b.next = &c;//下一个节点的位置
    c.next = &d;//下一个节点的位置
    d.next = NULL;// 定義最後一個節點的下一个节点的位置資料爲NULL,結束while的循環
```

```
// 5.创建链表头（開頭）
    Node *head = &a;
```

```
// 6.使用链表（执行--烧烤后，开始顺吃洋蔥、黃瓜、雞肉、黃燈籠椒）
    while(head != NULL){//檢查鏈表資料是否是NULL
        int currentData = head->data;
        printf("currentData = %i\n", currentData);
        head = head->next;
    }
```

1. 练习题: 如何合并多个有序链表为单一链表。以下是范例：
![linked_merge.cpp](./linked_merge.cpp)
