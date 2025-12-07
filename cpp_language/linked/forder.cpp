#include <stdio.h>
#include <stdlib.h>

// 定义分数结构体
typedef struct
{
    int numerator;   // 分子
    int denominator; // 分母
} Fraction;

// 计算最大公约数（欧几里得算法）
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b; //取余数
        a = temp;
    }
    return a;
}

// 比较两个分数的大小（用于排序）
int compareFractions(const Fraction *x, const Fraction *y)
{
    double vx = (double)x->numerator / x->denominator;
    double vy = (double)y->numerator / y->denominator;

    if (vx < vy)
        return -1;
    if (vx > vy)
        return 1;
    return 0;
}

// 生成法雷序列
int **fareySequence(int n, int *returnSize)
{
    // 估算最大可能的大小
    int maxSize = 3; // 初始包括 0/1 和 1/1
    for (int i = 2; i <= n; i++)
    {
        maxSize += i; // 简单估算，实际会少一些
    }

    // 创建数组存储所有可能的分数
    Fraction *fractions = (Fraction *)malloc(maxSize * sizeof(Fraction));
    if (!fractions)
    {
        printf("内存分配失败\n");
        *returnSize = 0;
        return NULL;
    }

    int count = 0;

    // 添加 0/1
    fractions[count].numerator = 0;
    fractions[count].denominator = 1;
    count++;

    // 生成所有可能的分数
    for (int d = 1; d <= n; d++)
    {
        for (int num = 1; num < d; num++)
        {
            // 只添加不可约分数（分子分母互质）
            if (gcd(num, d) == 1)
            {
                fractions[count].numerator = num;
                fractions[count].denominator = d;
                count++;
            }
        }
    }

    // 添加 1/1
    fractions[count].numerator = 1;
    fractions[count].denominator = 1;
    count++;

    // 按值排序
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (compareFractions(&fractions[j], &fractions[j + 1]) > 0)
            {
                Fraction temp = fractions[j];
                fractions[j] = fractions[j + 1];
                fractions[j + 1] = temp;
            }
        }
    }

    // 创建二维数组返回结果
    int **result = (int **)malloc(count * sizeof(int *));
    for (int i = 0; i < count; i++)
    {
        result[i] = (int *)malloc(2 * sizeof(int));
        result[i][0] = fractions[i].numerator;
        result[i][1] = fractions[i].denominator;
    }

    *returnSize = count;
    free(fractions);
    return result;
}

// 打印法雷序列
void printFareySequence(int n)
{
    int size;
    int **farey = fareySequence(n, &size);

    if (farey == NULL)
    {
        return;
    }

    printf("F_%d 法雷序列 (共 %d 个分数):\n", n, size);
    printf("{");

    for (int i = 0; i < size; i++)
    {
        printf(" %d/%d", farey[i][0], farey[i][1]);
        if (i < size - 1)
        {
            printf(",");
        }
    }
    printf(" }\n");

    // 释放内存
    for (int i = 0; i < size; i++)
    {
        free(farey[i]);
    }
    free(farey);
}

// 可选：更高效的生成算法（Stern-Brocot 树方法）
void generateFareyRecursive(int a, int b, int c, int d, int n)
{
    if (b + d > n)
    {
        return;
    }

    generateFareyRecursive(a, b, a + c, b + d, n);
    printf(" %d/%d,", a + c, b + d);
    generateFareyRecursive(a + c, b + d, c, d, n);
}

void printFareyEfficient(int n)
{
    printf("F_%d 法雷序列 (高效算法):\n{ 0/1,", n);
    generateFareyRecursive(0, 1, 1, 1, n);
    printf(" 1/1 }\n");
}

// 主函数
int main()
{
    int n;

    printf("请输入 n 的值: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("n 必须为正整数\n");
        return 1;
    }

    printFareySequence(n);

    return 0;
}
