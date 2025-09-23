#include <stdio.h>
#include <string.h>
int main()
{
    char str[11];              // 字符串数组末尾自己带有一个结束符'\0'
    strcpy(str, "HelloWorld"); // 字符串赋值，要用strcpy函数，别忘了头文件
    printf("%s\n", str);
}