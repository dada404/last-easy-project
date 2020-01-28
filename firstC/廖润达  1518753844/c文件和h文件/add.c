#include "head.h"
#include "add.h"

 // 添加信息操作     
 //传入链表头指针    传出链表头指针 

INF *add (INF *head)    
{
	INF *add_mem;
	int tip;//做判断是否添加完毕
	 
	add_mem = (INF*)malloc(LEN);
	
	printf("\n欢迎来到信息添加系统\n");

	do
	{
		
		printf("\n请输入姓名:");
		inptst(add_mem->name,9);
		
		printf("\n请输入学号:");
		inptst(add_mem->stu_number,12);

		printf("\n请输入电话号码:");
		inptst(add_mem->phone_number,13);
		
		printf("\n请输入专业和班级 (例:网工（1）班 ):");
		inptst(add_mem->major_class,20);
				
		printf("\n请确认所在部门(输入0-4数字)\n");
		printf("0.移动互联网部   1.游戏部  2.产品部   3.硬件部  4.设计部\n");
		printf("-----------------------------------------------------------\n");
		add_mem->dep_tip; 
		scanf("%d",&add_mem->dep_tip);
		
		while (add_mem->dep_tip!=0 && add_mem->dep_tip!=1 && add_mem->dep_tip!=2 && add_mem->dep_tip!=3 && add_mem->dep_tip!=4)
		{
			absorb_char();
			printf("\n部门确认错误，请重新输入数字（0-4）：");
			scanf("%d",&add_mem->dep_tip); 
		} 
		
		//写入部门的信息 
		switch (add_mem->dep_tip)
		{
			case 0 : strcpy(add_mem->department,"移动互联网部");
					 break;
			case 1 : strcpy(add_mem->department,"游戏部");
					 break;
			case 2 : strcpy(add_mem->department,"产品部");
					 break;
			case 3 : strcpy(add_mem->department,"硬件部");
					 break;
			case 4 : strcpy(add_mem->department,"设计部");
					 break;
		}
	
		//部员部长身份确认	
		printf("\n若为部长请按0 ， 若为部员请按1\n");
		add_mem->identity_tip = -1;   
		scanf("%d",&add_mem->identity_tip);
		
		while ( add_mem->identity_tip != 0 && add_mem->identity_tip != 1)
		{
			absorb_char();
			printf("\n身份确认错误，请重新输入数字（0-1）：");
			scanf("%d",&add_mem->identity_tip); 
		}
		 		
		if (add_mem->identity_tip== 0)
		{
			strcpy(add_mem->identity,"部长");	 
		}
		else
		{
			strcpy(add_mem->identity,"部员"); 
		}
		
		printf("以下是您添加的成员信息：\n"); 
		info_print(add_mem);
		printf("\n请查核您的添加的信息\n");
		
		//判断是否输入是否有误 
		printf("输入信息无误请按1，输入信息有误需重新输入请按0\n");
		printf("按下数字后请按下回车键\n");
		scanf("%d",&tip); 
		
		if (tip == 1)//判断账户是否确认完毕 
		{	
			printf("\n账号初始化为：123456\n");
			printf("密码初始化为：123456\n");
			strcpy(add_mem->number,"123456");
			strcpy(add_mem->password,"123456");
			
			printf("信息添加完毕，按下任何键回到主页面....\n");
			getch(); 
			system("cls");
			
			//将信息插入链表
			add_mem->next = head;	
			head = add_mem;
		} 
		else 
		{		
			system("cls");
			printf("开始重新输入....\n");
		}
	}while (tip != 1);//输入成功才可退出循环	 
			
	switch (add_mem->dep_tip)  
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
	n++;
	
	return head; 
	 
}
