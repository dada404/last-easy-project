#include <stdio.h>
#include "head.h"
#include "info_print.h"

void info_print (INF *p)  //信息显示   传入一个结构 
{
	printf("\n姓名:%s\n",p->name);
	printf("学号:%s\n",p->stu_number);
	printf("电话号码:%s\n",p->phone_number);
	printf("专业和班级：%s\n",p->major_class);
	printf("部门:%s\n",p->department);
	printf("身份:%s\n",p->identity);
	
}
