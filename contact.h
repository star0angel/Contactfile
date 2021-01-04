#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CONTACT 3
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

typedef struct Peoinfo  //通讯录的结构体
{
	char name[20];
	int age;
	char sex[5];
	char tele[12];
	char addr[30];

}Peoinfo;
//通讯录类型
typedef struct Contact
{
	struct Peoinfo* data;
	int size;//记录当前已有通讯录的个数
	int capacity;//当前通讯录的最大容量
}Contact;

enum options
{
	EXIT,
	ADD,
	DEL,
	SERCH,
	MODIFY,
	SHOW,
	SORT
};



 void initcontact(Contact* ps);//初始化通讯lu
 void addcontact(struct Contact*);//增加通讯录
 void delcontact(struct Contact*);//删除通讯录
 void serchcontact(struct Contact*);//查找通讯录
 void modifycontact(struct Contact*);//修改通讯录
 void showycontact(struct Contact*);//显示通讯录
 void sortcontact(struct Contact*);//排序通讯录
 void savecontact(struct Contact*);//保存通讯录


