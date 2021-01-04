#include "contact.h"

void menu()
{
	printf("\n\n\n     1. 增加成员 2. 删除成员 3. 查找成员\n     4. 修改成员 5. 显示成员 6. 成员排序\n     0. 退出系统");
}

int main()
{
	int n = 0;
	//struct Peoinfo con[1000];
	struct Contact con;//定义同学录 
	//初始化通讯录
	initcontact(&con);
	
	do
	{
		menu();
		printf("\n     当前同学录容量： %d    已用容量： %d",con.capacity,con.size);
		printf("\n\n\n请输入你的选择：>");
		scanf("%d", &n);
		switch (n)
		{
		case ADD:
			addcontact(&con);//增加成员
			break;
		case DEL:
			delcontact(&con);
			break;
		case SERCH:
			serchcontact(&con);
			break;
		case MODIFY:
			modifycontact(&con);
			break;
		case SHOW:
			showycontact(&con);
			break;
		case SORT:
			sortcontact(&con);
			break;
		case 0:
			savecontact(&con);
			printf("<退出>\n");
			break;
		default:
			printf("<选择错误>\n");
			break;
		}
	} while (n);
	free(con.data);
	con.data = NULL;
	return 0;
}