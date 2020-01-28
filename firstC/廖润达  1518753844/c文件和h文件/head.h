#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define LEN sizeof(INF)

extern int n; //记录IMA总人数
extern int n_network;  //记录移动互联网部的人数
extern int n_game;		//记录游戏部的人数
extern int n_produce;	//记录产品部的人数
extern int n_hardware;	//记录硬件部的人数
extern int n_design; 	//记录设计部的人数


typedef struct account    
{		

	
	//个人信息 :名字 学号 电话 部门 
	char name[9];
	char stu_number[12];
	char phone_number[13];	
	char identity[10];
	char major_class[20]; 
	char department[20];
	

	
	//账户信息 ：账户 密码 	 
	char number[9];
	char password[9];
	
	//标识信息    
	int identity_tip;        // 0为部员   1为部长
	int dep_tip;     // 0为移动互联网部  1为游戏部  2为产品部   3为硬件部  4为设计部 
	int oloff;   //    判断操作系统的用户  1为正在使用的用户 

	struct account *next;    
	
 }INF;
 
#endif
