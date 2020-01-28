#include "head.h"
#include "change_info.h"
#include "change_psw.h"



//功能：对修改的选择进行操作
//传入: 一个结构的指针 和  头指针 操作对应的数字  传出:  传入的指针 
INF* info_change_select(INF *p,INF *head,int i) 
{	
	system("cls");
	int flag = -1;    //做是否确认修改信息的标志 
	
	//对应操作
	switch(i)
	{	//修改姓名 
		case 1:	{
					char change_name[9];
					//输出输入过程 
					printf("账户原姓名信息为:%s",p->name);
					printf("\n请输入新姓名信息:");
					inptst(change_name,9);
					
					//确认过程 
					printf("\n是否确认将 %s 改为 %s ",p->name,change_name);
					printf("\n确认请输入1,取消请按0\n");
					scanf("%d",&flag);
					
					//确认过程 
					while( flag != 1 && flag != 0 )
					{	
						absorb_char();
						printf("确认失败,请重新输入(0或1):");
						scanf("%d",&flag);
					}
					
					//确认完毕 
					if ( flag == 1 )
					{
						strcpy(p->name,change_name);
						printf("\n修改成功!请按下任意键回到主页面\n");
						getch();
					}
					
					if ( flag == 0 )
					{
						printf("\n取消成功!请按下任意键回到主页面\n");
						getch(); 
					}  
					break;
			
				}
				
		//修改学号 
		case 2: {
					char change_stunum[12];
					//输出输入过程 
					printf("账户原学号信息为:%s",p->stu_number);
					printf("\n请输入新学号信息:");
					inptst(change_stunum,12);
					
					//确认过程 
					printf("\n是否确认将 %s 改为 %s ",p->stu_number,change_stunum);
					printf("\n确认请输入1,取消请按0\n");
					scanf("%d",&flag);
									
					while( flag != 1 && flag != 0 )
					{	
						absorb_char();
						printf("确认失败,请重新输入(0或1):");
						scanf("%d",&flag);
					}
					

					//确认完毕 
					if ( flag == 1 )
					{
						strcpy(p->stu_number,change_stunum);
						printf("\n修改成功!请按下任意键回到主页面\n");
						getch();
					}
					
					if ( flag == 0 )
					{
						printf("\n取消成功!请按下任意键回到主页面\n");
						getch(); 
					}  
					break;
				}
				
				
				
		//修改电话号码 
		case 3:	{
					char change_phonum[13];
					//输出输入过程 
					printf("账户原电话号码为:%s",p->phone_number);
					printf("\n请输入新电话号码:");
					inptst(change_phonum,13);
					
					//确认过程 
					printf("\n是否确认将 %s 改为 %s ",p->phone_number,change_phonum);
					printf("\n确认请输入1,取消请按0\n");
					scanf("%d",&flag);
					
					while( flag != 1 && flag != 0 )
					{	
						absorb_char();
						printf("确认失败,请重新输入(0或1):");
						scanf("%d",&flag);
					}
					
					//确认完毕 
					if ( flag == 1 )
					{
						strcpy(p->phone_number,change_phonum);
						printf("\n修改成功!请按下任意键回到主页面......\n");
						getch();
					}
					
					if ( flag == 0 )
					{
						printf("\n取消成功!请按下任意键回到主页面......\n");
						getch(); 
					}  
					break;
				} 
				
		//修改专业和班级
		case 4: {
					char change_majorclass[20];
					//输出输入过程 
					printf("账户原专业和班级为:%s",p->major_class);
					printf("\n请输入新专业和班级信息:");
					inptst(change_majorclass,20);
					
					//确认过程 
					printf("\n是否确认将 %s 改为 %s ",p->major_class,change_majorclass);
					printf("\n确认请输入1,取消请按0\n");
					scanf("%d",&flag);
					
					while( flag != 1 && flag != 0 )
					{	
						absorb_char();
						printf("确认失败,请重新输入(0或1):");
						scanf("%d",&flag);
					}
					
					//确认完毕 
					if ( flag == 1 )
					{
						strcpy(p->major_class,change_majorclass);
						printf("\n修改成功!请按下任意键回到主页面......\n");
						getch();
					}
					
					if ( flag == 0 )
					{
						printf("\n取消成功!请按下任意键回到主页面......\n");
						getch(); 
					}  
					break;
				}
				
				
		//修改账号 
		case 5: {
					char change_number[9];
					//输出输入过程 
					printf("账户原账号为:%s",p->number);
					printf("\n请输入新账号:");
					inptst(change_number,9);
					
					//确认过程 
					printf("\n是否确认将 %s 改为 %s ",p->number,change_number);
					printf("\n确认请输入1,取消请按0\n");
					scanf("%d",&flag);
					
					while( flag != 1 && flag != 0 )
					{	
						absorb_char();
						printf("确认失败,请重新输入(0或1):");
						scanf("%d",&flag);
					}
					
					//确认完毕 
					if ( flag == 1 )
					{
						strcpy(p->number,change_number);
						printf("\n修改成功!请按下任意键回到主页面......\n");
						getch();
					}
					
					if ( flag == 0 )
					{
						printf("\n取消成功!请按下任意键回到主页面......\n");
						getch(); 
					}  
					break;
				}
				
		//修改密码
		case 6 : change_psw(p,head);
				 break;			 				
	 } 
}


//功能:自身信息修改
//传入：链表头指针   传出：链表头指针 
INF* self_change_info (INF *head)
{
	INF *p;  
	p = head;
	int tip ;//做系统操作的提示
		
	system("cls");
	
	
	
	//遍历链表 
	while (p != NULL)
	{
		if (p->oloff == 1)
		{	
				
			system("cls");
			printf("欢迎来到自身信息修改系统.\n"); 
			printf("       _________________________________________________________________ \n");
			printf("      |       1.修改姓名          2.修改学号       3.修改电话号码       |\n");
			printf("      |       4.修改专业和班级    5.修改账号       6.修改密码           |\n");
			printf("      |GDUT-IMA                                                         |\n");	       
			printf("      |_________________________________________________________________|\n");
			printf("请输入操作对应数字数字（1-7）:");
			tip = -1;
			scanf("%d",&tip);
			
			//输错处理 
			while(tip != 1 && tip != 2 && tip != 3 && tip != 4 && tip != 5 && tip != 6 && tip != 7 )
			{	
				absorb_char();
				printf("输入错误，请重新输入数字（1-7）");
				scanf("%d",&tip); 
			}
			
			//选择操作 
			if( tip != 7)
			{
				p = info_change_select(p,head,tip);
			}
			break;
		}
		p = p->next;
    }

		
 	return head;
} 
