#include <stdio.h>
typedef enum{
    mon, tue, wed, thu, fri, sat, sun
}weekday;//mon=0, tue=1, wed=2, thu=3, fri=4, sat=5, sun=6


int main(){
    weekday day;
    day = mon;
    printf("day = %d\n",day);
    return 0;
}