#include <stdio.h>
//结构体类型的定义
typedef struct  human_being {
    char    name[10];
    int     age;
    float   salary;
} human_being_t;

//ANSI C允许结构体之间相互赋值
int main()
{
    human_being_t person1, person2;
    
    person1.age = 10;
    person2 = person1;

    printf("person2.age = %d\n", person2.age);
    return 0;
}

