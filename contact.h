#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//ȡ��scanf����ֵ�ľ���

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

typedef struct Peoinfo  //ͨѶ¼�Ľṹ��
{
	char name[20];
	int age;
	char sex[5];
	char tele[12];
	char addr[30];

}Peoinfo;
//ͨѶ¼����
typedef struct Contact
{
	struct Peoinfo* data;
	int size;//��¼��ǰ����ͨѶ¼�ĸ���
	int capacity;//��ǰͨѶ¼���������
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



 void initcontact(Contact* ps);//��ʼ��ͨѶlu
 void addcontact(struct Contact*);//����ͨѶ¼
 void delcontact(struct Contact*);//ɾ��ͨѶ¼
 void serchcontact(struct Contact*);//����ͨѶ¼
 void modifycontact(struct Contact*);//�޸�ͨѶ¼
 void showycontact(struct Contact*);//��ʾͨѶ¼
 void sortcontact(struct Contact*);//����ͨѶ¼
 void savecontact(struct Contact*);//����ͨѶ¼


