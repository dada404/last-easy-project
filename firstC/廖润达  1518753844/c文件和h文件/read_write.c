//读入操作 ：将文件内容读入所在程序链表 
// 传入头指针  传出这个头指针

#include "head.h"
#include "read_write.h"
#define LEN sizeof(INF)
 
INF *read_in (INF *head) 
{	
	FILE *fp; 	
	INF test;//判断注册表是否为空的测试结构体 
	
   	if ((fp=fopen("inf_file","rb")) == NULL || (fread(&test,LEN,1,fp)) == 0 ) //判断是否已有注册表 或 注册表内是否有内容   否 则进入注册系统 
	{
		printf("注册表没有注册信息,请按任意键前往注册系统\n");
		getch();
		system("cls");
		login();
	} 
	else
	{
		INF*p1,*p2;//链表建立所需指针变量 
		head = NULL;
				
		rewind(fp); 
	
		while ( feof(fp) == 0 )//链表建立 读到文件最后 
	{
		n++;
		if (n == 1)
		{
			p1 = p2 =(INF*)malloc(LEN); 
			fread(p1,LEN,1,fp);
			head = p1;
		 } 
		else
		{
			p2->next = p1;
		}
		p2 = p1 ;
		
		//统计每个部门的人数		
		switch (p1->dep_tip)  
		{
			case 0 : n_network++;
					 break;
			case 1 : n_game++; 
					 break;
			case 2 : n_produce++;
					 break;
			case 3 : n_hardware++;
					 break;
			case 4 : n_design++;
					 break;
		} 
		
		p1 = (INF*)malloc(LEN);
		fread(p1,LEN,1,fp); 
	}
	
	p2->next = NULL;
	
	}
	
	fclose(fp);
	return (head);
	    				//OK! 
}

//写入操作：将链表内容写至文件操作 
//   传入链表的头指针 
void write_out(INF *head)   
{
	FILE *fp; 		
	INF *p = head;  //写出链表指针	
	

	fp = fopen("inf_file","wb+");
	
	while (p != NULL)//写入操作 
	{
		fwrite(p,LEN,1,fp);
		p = p->next;
	} 
	fclose(fp);
	   				//OK！ 
}
