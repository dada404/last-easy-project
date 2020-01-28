#include "head.h"
#include "read_write.h" 
#include "change_psw.h"

//功能：修改密码
//传入一个结构指针 ，并传出该指针 
INF* change_psw (INF*p,INF*head)
{
	char old_psw[9];//旧密码 
	char new_psw[9];//首次输入新密码 
	char new_psw1[9];//确认密码
	int cnt = 3; 
	
	
	
	while (cnt > 0)
	{   

		printf("\n请输入原密码：");
		inptst(old_psw,9);
		
		//输入新密码 
		if(strcmp(old_psw,p->password) == 0)
		{	
			printf("原密码输入正确\n");
			 
			int tip = 0;
			do
			{
				printf("\n请输入新密码：");
				inptst(new_psw,9);
			 
				printf("\n再次输入新密码：");
				inptst(new_psw1,9);
				
				if(strcmp(new_psw,new_psw1) == 0)
				{
					tip = 1;
					strcpy(p->password,new_psw1);
				}
				else 
				{
					printf("\n两次输入密码不同，请重新输入\n");
				}
			}while (tip == 0);
			
			system("cls"); 
			printf("密码修改完毕，请按下任意键退出总系统后重新登录.....");
			write_out(head);
			getch(); 
			printf("\n\n");
			exit(0);
			
		} 
		else
		{
		 	printf("\n原密码输入错误,您还有%d次机会重新输入",cnt);
			cnt--; 
		}
		 
		 //对输错的处理 
		if ( cnt == 0)
		{
			printf("\n操作错误,请按下任意键退出系统.");
			getch(); 
			exit(0); 
		} 
	}
	return p; 
	
}
