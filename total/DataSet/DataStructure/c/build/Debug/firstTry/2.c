#include <stdio.h>
int main(){
    int i[]={1,2,3,4,5};
    for (int j = 0; j < sizeof(i) / sizeof(i[0]); j++)
    {
        printf("%d\n",i[j]);
    }
    return 0;
}