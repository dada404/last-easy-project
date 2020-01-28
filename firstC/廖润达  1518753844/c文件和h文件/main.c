#include "head.h"
#include "system_enter.h"
#include "read_write.h"
#include "system_minster.h"
#include "system_member.h"




int n = 0;    			//记录IMA总人数
int n_network = 0;     	//记录移动互联网部的人数
int n_game = 0;		   	//记录游戏部的人数
int n_produce = 0;	   	//记录产品部的人数
int n_hardware = 0;	   	//记录硬件部的人数
int n_design = 0;   	//记录设计部的人数



int main()
{
	INF*head;   
	int flag;   //做标识作用   区分登录者是部长还是部员  来分系统操作 
	
	//读入链表 
	head = read_in(head);	
	//登录系统
	flag = system_enterin(head);
	
	int arr[10];
	
	
 
	if ( flag == 0 ) 
	{
		//部长操作系统界面
		head = system_minister(head); 
	} 
	if ( flag == 1 )
	{
		//部员操作界面
		head = system_member(head); 
	}
	write_out(head);
	return 0; 
}
