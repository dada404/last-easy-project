#include "head.h"
#include "system_enter.h"
#include "inptst.h"

//注册操作：对账户信息进行注册
void login() 
{	
	FILE *fp; 
	INF acc;   //用户的结构 
	char psw[7]="IMA666";  //部长系统保护机制
	char psw1[7];
	char password1[9];
	char password2[9];
	 
	 

	
	if ((fp=fopen("inf_file","rb")) == NULL)   
		//判断是否各个部门文件的有无 区分打开方式 
	{
		fp=fopen("inf_file","wb+");
	}
	else fp=fopen("inf_file","ab");
	
	int tip1;   //做提示是否确认输入账号完毕作用 
	
	do  
	{		
		printf("欢迎来到IMA部员注册系统\n");
		printf("请确认所在部门(输入0-4数字)\n");
		printf("-----------------------------------------------------------\n");
		printf("0.移动互联网部   1.游戏部  2.产品部   3.硬件部  4.设计部\n");
		printf("-----------------------------------------------------------\n");
		acc.dep_tip = -1;  //防止未成功输入后随机值未进入循环 
		scanf("%d",&acc.dep_tip);
		
		while (acc.dep_tip!=0 && acc.dep_tip!=1 && acc.dep_tip!=2 && acc.dep_tip!=3 && acc.dep_tip!=4)
		{
			absorb_char();
			printf("\n部门确认错误，请重新输入数字（0-4）：");
			scanf("%d",&acc.dep_tip); 
		} 
		
		//写入部门的信息 
		switch (acc.dep_tip)
		{
			case 0 : strcpy(acc.department,"移动互联网部") ;
					 break;
			case 1 : strcpy(acc.department,"游戏部");
					 break;
			case 2 : strcpy(acc.department,"产品部");
					 break;
			case 3 : strcpy(acc.department,"硬件部");
					 break;
			case 4 : strcpy(acc.department,"设计部");
					 break;
		}

		//部员部长身份确认
		printf("\n若为部长请按0 ， 若为部员请按1\n");
		acc.identity_tip = -1;   
		scanf("%d",&acc.identity_tip);
		
		while (acc.identity_tip !=0 && acc.identity_tip!=1)
		{
			absorb_char();
			printf("\n身份确认错误，请重新输入数字（0-1）：");
			scanf("%d",&acc.identity_tip); 
		} 
		
		if (acc.identity_tip == 0)
		{	
	
			int cnt =2;
			while(1)
			{
				printf("\n请输入部长注册所需的注册密码:");
				inptst(psw1,7);
				
				if(strcmp(psw1,psw) == 0)
				{
					strcpy(acc.identity,"部长");
					printf("\n请继续完成后续的操作....\n");
					break;
				}
				
				else 
				{	
					if(cnt == 0)
					{
						printf("\n请按下任意键退出系统...\n");
						getch();
						exit(0); 
					}
						printf("\n您还能重新输入密码%d次\n",cnt--);
				}
			}		 
		}
		else
		{
			strcpy(acc.identity,"部员"); 
		}
		
		//账号密码输入与确认
   	 	//账户录入 			
		printf("\n请输入您的账号（请不要超过8位）:");
		inptst(acc.number,9); 
		
		while(1)
		{
			printf("\n请输入您的密码（请不要超过8位）:");
			inptst(password1,9);
			printf("请再次输入您的密码：");
			inptst(password2,9);
			
			if (strcmp(password1,password2) == 0)
			{	
				strcpy(acc.password,password1);
				printf("\n密码确认成功...\n");
				break;
			}
			else printf("\n两次密码输入不相同请重新输入\n"); 
		}
		
		 		
		//重读出信息 
		printf("\n以下为您的账户信息:\n"); 
		printf("账号:%s\n",acc.number);
		printf("密码:%s\n",acc.password);
		printf("部门:%s\n",acc.department);
		printf("身份:%s\n",acc.identity);
		printf("\n请查核您的账户信息:\n");
		printf("账户密码是否超过8位\n");
		printf("账户密码是否与原先相同\n"); 
	
		
		//账户信息确认
	
		printf("\n输入信息无误请按1，输入信息有误需重新输入请按0\n");
		tip1 = -1;
		scanf("%d",&tip1);				
		 
		
		//对于输入错误的处理		
		while (tip1 != 1 && tip1 != 0)
		{	
			absorb_char();
			printf("请重新输入数字（1 或 0）");
			scanf("%d", &tip1); 
		} 
		
		//重输信息 
		if(tip1 == 0)
		{
			system("cls");
			printf("开始重新输入....\n"); 			
		} 

	}while (tip1 != 1);//输入成功才可退出循环
	
	//个人信息的输入
	system("cls"); 
	printf("账号注册完毕，正在进行信息完善....\n");
	
	int tip2;     //作为个人信息输入是否确认完毕的标志 
			
	do 
	{ 
		printf("\n请输入姓名:");
		inptst(acc.name,9);
		
		printf("\n请输入学号:");
		inptst(acc.stu_number,12);

		
		printf("\n请输入电话号码:");
		inptst(acc.phone_number,13);
		
		printf("\n请输入专业和班级 (例:网工（1）班 ):");
		inptst(acc.major_class,20);
		
		//重读出信息并核查 
		printf("\n以下是您的信息:\n");
		printf("姓名:%s\n",acc.name); 
		printf("学号:%s\n",acc.stu_number);  
		printf("电话号码:%s\n",acc.phone_number); 
		printf("专业和班级:%s\n",acc.major_class); 
		printf("\n请查核您的个人信息是否与原先输入相同\n");
		
		//账户信息确认
		printf("\n输入1确认信息输入正确\n输入0则重新输入\n");
		tip2 = -1;  
		scanf("%d",&tip2);
		
		//输错处理		
		while ( tip2 != 1 && tip2!= 0 )
		{	
			absorb_char();
			printf("请重新输入1确认输入正确，或输入0进行重新输入:");
			scanf("%d", &tip2); 
		}
		if( tip2 == 0) 
		{	
			system("cls");
			printf("开始重新输入....\n"); 
		}  
		
	} while (tip2 != 1);//作为判断是否确认输入完毕
			
	printf("信息录入完毕，按下任何键后退出窗口重新登入....\n");
	getch(); 
	system("cls");
			
	//写入文件 
	fwrite(&acc,LEN,1,fp);
	fclose(fp);	
	
	//退出系统 
	exit(0);
	 
						// OK ！！！！ 
	
}

//功能：登录操作    
//传入一个链表的头指针 传出登录者的身份   （来分系统操作 （部长系统  部员系统））
int  enter_in(INF *p)   
{	
	char enter_number[9];
	char enter_password[9];
	int tip = 0;   //作为提示来确认是否输入成功
	int cnt = 0;   //计算输入次数
	INF *p1 ; 
	p1 = p;  //保留输入的地址
	
	printf("欢迎来到IMA登录系统"); 
	
	do    //循环输入当输入成功退出循环进入操作界面   输入错误重新输入至三次退出窗口      
	{
		//输入账号
		printf("\n请输入您的账号：") ; 
		inptst(enter_number,9);
		
		//输入密码
		printf("\n请输入您的密码："); 
		inptst(enter_password,9);
		 
		//遍历链表  确认账号密码是否正确 
		
		p = p1;//使p1指针位置回到原来的位置 
		
		do
		{
			if (strcmp(enter_number,p->number) == 0 && strcmp(enter_password,p->password) == 0 )
			{
				printf("登录成功...\n");
				printf("请按下任意键进入管理系统\n");
				getch();
				tip =  1; 
				p->oloff = 1 ;  //显示在线状态                                
				break;  
			 }
			 p = p->next; 
		}while( p != NULL );
		cnt ++;

		//对输错的处理	
		if (tip == 0 && cnt!= 3)//只有三次的输入机会  3次输错就退出登陆系统 
		{
			printf("账号或密码错误,您还有%d次机会\n",3-cnt); 
		 }
		if (tip == 0 && cnt == 3)
		{
			printf("登录出错，请按下任意键退出登陆系统\n");
			getch();
			exit(1);
		}
	}while (tip == 0);
							//OK！！！ 
	return (p->identity_tip);     
}

//功能：登陆系统 
//传入链表头指针  传出登陆者身份 
int system_enterin(INF *head)
{
	system("cls");
	
	printf("      		|                       IMA部员管理登录系统                       |\n");
	printf("      		|_________________________________________________________________| \n");
	printf("      		|                                                                 |\n");
	printf("      		|                                                                 |\n");
	printf("      		|          1.登录                               2.注册            |\n"); 	
	printf("      		|          3.修改密码                                             |\n");
	printf("	        |GDUT-IMA                                 （请最大化使用效果更佳）|\n");	       
	printf("      		|_________________________________________________________________|\n");
	printf("请选择你需要的操作(填入数字1-3):\n");
	
	//区分登录系统的操作  
	int tip;
	tip = -1; 
	scanf("%d",&tip);
	
	//对输错的处理 
	while (tip != 1 && tip != 2 && tip != 3)
	{	
		absorb_char();
		printf("\n请重新输入数字（1-3）\n");
		scanf("%d",&tip); 
	}
	 
	//登录操作 
	if ( tip == 1)
	{	
		//得到登录者的身份   为后续的分系统操作准备 
		int id ;
		id = enter_in(head); //传入head 传出登录者身份 
		return id; 
	}
	
	//注册操作 
	if( tip == 2)
	{	
		system("cls");
		login(); 
	}
	
	//修改密码 
	if( tip == 3)
	{	
		system("cls"); 
		INF* p;
		p = head;
		char number1[9];
	
		printf("欢迎来到密码修改系统\n"); 
		printf("请输入您的账号：");
		inptst(number1,9);
		
		while(p != NULL)
		{
			if(strcmp(number1,p->number) == 0)
			{
				printf("已找到对应账号");
				change_psw (p,head);  
			}
			p = p->next;
		} 
		printf("未找到对应账号信息,按下任意键退出系统");
		getch(); 
		exit(0); 
		
	}	
}
