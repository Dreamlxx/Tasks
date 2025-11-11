#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

// 多项式项的结构体
typedef struct {
    float coef;  // 系数
    int exp;     // 指数
} PolyTerm;

// 顺序表结构体（用于存储多项式）
typedef struct {
    PolyTerm *terms;  // 多项式项数组
    int length;        // 多项式项数
} Polynomial;

// 初始化多项式
Polynomial* InitPolynomial() {
    Polynomial *poly = (Polynomial *)malloc(sizeof(Polynomial));
    poly->terms = (PolyTerm *)malloc(MAXSIZE * sizeof(PolyTerm));
    poly->length = 0;
    return poly;
}

// 向多项式添加项（按指数降序排列）
int AddTerm(Polynomial *poly, float coef, int exp) {
    if (poly->length >= MAXSIZE) {
        printf("多项式已满，无法添加项\n");
        return 0;
    }
    
    // 查找插入位置（保持指数降序）
    int i;
    for (i = 0; i < poly->length; i++) {
        if (exp > poly->terms[i].exp) {
            break;  // 找到插入位置
        }
        else if (exp == poly->terms[i].exp) {
            // 指数相同，系数相加
            poly->terms[i].coef += coef;
            return 1;
        }
    }
    
    // 移动后续项，为新项腾出位置
    for (int j = poly->length; j > i; j--) {
        poly->terms[j] = poly->terms[j - 1];
    }
    
    // 插入新项
    poly->terms[i].coef = coef;
    poly->terms[i].exp = exp;
    poly->length++;
    return 1;
}

// 打印多项式
void PrintPolynomial(Polynomial *poly) {
    if (poly->length == 0) {
        printf("0\n");
        return;
    }
    
    for (int i = 0; i < poly->length; i++) {
        // 处理系数符号显示
        if (i > 0 && poly->terms[i].coef >= 0) {
            printf(" + ");
        }
        else if (i > 0) {
            printf(" - ");
        }
        
        // 处理系数和指数的显示
        float abs_coef = (poly->terms[i].coef < 0) ? -poly->terms[i].coef : poly->terms[i].coef;
        
        if (poly->terms[i].exp == 0) {
            printf("%.1f", abs_coef);  // 常数项
        }
        else if (poly->terms[i].exp == 1) {
            if (abs_coef == 1.0)
                printf("x");           // 系数为1的x项
            else
                printf("%.1fx", abs_coef);
        }
        else {
            if (abs_coef == 1.0)
                printf("x^%d", poly->terms[i].exp);  // 系数为1的高次项
            else
                printf("%.1fx^%d", abs_coef, poly->terms[i].exp);
        }
    }
    printf("\n");
}

// 多项式相加
Polynomial* AddPolynomials(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *result = InitPolynomial();
    int i = 0, j = 0;
    
    // 遍历两个多项式，按指数大小合并
    while (i < poly1->length && j < poly2->length) {
        if (poly1->terms[i].exp > poly2->terms[j].exp) {
            // poly1的当前项指数更大
            AddTerm(result, poly1->terms[i].coef, poly1->terms[i].exp);
            i++;
        }
        else if (poly1->terms[i].exp < poly2->terms[j].exp) {
            // poly2的当前项指数更大
            AddTerm(result, poly2->terms[j].coef, poly2->terms[j].exp);
            j++;
        }
        else {
            // 指数相同，系数相加
            float sum_coef = poly1->terms[i].coef + poly2->terms[j].coef;
            if (sum_coef != 0) {  // 系数不为0才添加
                AddTerm(result, sum_coef, poly1->terms[i].exp);
            }
            i++;
            j++;
        }
    }
    
    // 处理剩余项
    while (i < poly1->length) {
        AddTerm(result, poly1->terms[i].coef, poly1->terms[i].exp);
        i++;
    }
    
    while (j < poly2->length) {
        AddTerm(result, poly2->terms[j].coef, poly2->terms[j].exp);
        j++;
    }
    
    return result;
}

// 主函数测试
int main() {
    printf("=== 顺序表实现一元多项式相加 ===\n");
    
    // 创建第一个多项式：3x^3 + 2x^2 + 5x + 1
    Polynomial *poly1 = InitPolynomial();
    AddTerm(poly1, 3, 3);
    AddTerm(poly1, 2, 2);
    AddTerm(poly1, 5, 1);
    AddTerm(poly1, 1, 0);
    printf("多项式1: ");
    PrintPolynomial(poly1);
    
    // 创建第二个多项式：2x^3 - x^2 + 4x - 2
    Polynomial *poly2 = InitPolynomial();
    AddTerm(poly2, 2, 3);
    AddTerm(poly2, -1, 2);
    AddTerm(poly2, 4, 1);
    AddTerm(poly2, -2, 0);
    printf("多项式2: ");
    PrintPolynomial(poly2);
    
    // 多项式相加
    Polynomial *result = AddPolynomials(poly1, poly2);
    printf("相加结果: ");
    PrintPolynomial(result);
    
    // 释放内存
    free(poly1->terms);
    free(poly1);
    free(poly2->terms);
    free(poly2);
    free(result->terms);
    free(result);
    
    return 0;
}