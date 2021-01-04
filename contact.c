#include "contact.h"

void checkcapac(struct Contact* ps)
{
	if (ps->size==ps->capacity)
	{
		struct Peoinfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct Peoinfo));
		if (ptr==NULL)
		{
			printf(strerror(errno));//判断开辟空间是否成功
			return;
		} 
		ps->data = ptr;//重新指向通讯录
		ps->capacity += 2;
	}
}

int findcontact(Contact* ps,char arr[])
{
	assert(arr != NULL);
	int i = 0;
	for (i = 0; i < ps->capacity; i++)
	{
		if (0==strcmp(ps->data[i].name,arr))
		{
			return i;//如果相等则返回下标
		}
	}
	return -1;

}


void addcontact(Contact* ps)
{
	//检测当前容量和数量  满增加  
	checkcapac(ps);
	printf("请输入姓名:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &ps->data[ps->size].age);
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].addr);
	printf("\n录入成功！\n");
	ps->size++;
}

void delcontact(Contact* ps)
{
	 char arr[MAX_NAME] = { 0 };
	printf("请输入你要查找的姓名：>");
	scanf("%s",arr);
	int ret=findcontact(ps,arr);//完成通讯录的查找功能返回下标
	if (ret==-1)//查无此人
	{
		printf("查无此人。\n");
	} 
	else
	{
		if (ret<ps->size)//如果数据是最后一个就直接总量减减  
		{
			for (int i=ret+1;i<ps->size;i++)//将ret后面所有的数据迁移
			{
				ps->data[i - 1] = ps->data[i];
			}
		} 
		ps->size--;
		printf("\n删除成功！\n");
	}

}

void serchcontact(Contact* ps)
{
	char arr[MAX_NAME] = { 0 };
	printf("请输入你要查找的姓名：>");
	scanf("%s", arr);
	int ret = findcontact(ps, arr);//完成通讯录的查找功能返回下标
	if (ret==-1)
	{
		printf("查无此人。\n");
	} 
	else
	{
		printf("%-20s\t%-4d\t%-4s\t%-12s\t%-20s\t\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr
		);
	}

}

void modifycontact(Contact* ps)
{
	assert(ps->size != 0);
	char arr[MAX_NAME] = { 0 };
	printf("请输入你要修改通讯的姓名：>");
	scanf("%s", arr);
	int ret = findcontact(ps, arr);//完成通讯录的查找功能返回下标
	printf("请输入姓名:>");
	scanf("%s", ps->data[ret].name);
	printf("请输入年龄:>");
	scanf("%d", &ps->data[ret].age);
	printf("请输入性别:>");
	scanf("%s", ps->data[ret].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ret].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ret].addr);
	printf("\n修改成功！\n");
}

void showycontact(Contact* ps)
{
	if (ps->size==0)
	{
		printf("\n通讯录为空！\n");
	} 
	else
	{
		printf("%-20s\t%-4s\t%-4s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "地址");
		for (int i=0;i<ps->size;i++)
		{
			printf("%-20s\t%-4d\t%-4s\t%-12s\t%-20s\t\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr
				);
		}
	}
}
int cmp_age(const void* e1, const void* e2)//比较函数 按年龄
{
	return ((Peoinfo*)e1)->age- ((Peoinfo*)e2)->age;
}
int cmp_name(const void* e1, const void* e2)//比较函数 按姓名
{
	//strcmp((char*)e1, (char*)e1);
	return strcmp(((Peoinfo*)e1)->name, ((Peoinfo*)e2)->name);
}
void sortcontact(Contact* ps)
{
	int input;
	if (ps->size == 0)
	{
		printf("\n通讯录为空！\n");

	}
	else
	{
		printf("请输入排序方式：1.按年龄   2.按姓名\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_age);
			break;
		case 2:
			qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_name);
			break;
		default:
			printf("选择错误,按默认排序显示：\n");
			break;
		}
		showycontact(ps);
	}
}

void savecontact(Contact* ps)
{
	FILE* p_fwrite = fopen("contact.con", "wb");//数据保存的位置
	if (p_fwrite==NULL)
	{
		printf("保存失败：%s", strerror(errno));
	} 
	else
	{

		//写通讯录中数据到文件中
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(Peoinfo), 1, p_fwrite);
		}
		printf("数据已保存。");
		fclose(p_fwrite);
		p_fwrite = NULL;
	}
}

void initcontact(Contact* ps)
{
	ps->size = 0;
	ps->capacity = MAX_CONTACT;
	Peoinfo* str = malloc(sizeof(Peoinfo) * MAX_CONTACT);
	if (str == NULL)
	{
		printf(strerror(errno));//判断开辟空间是否成功
	}
	else
		ps->data = str;

	//读取已有数据
	FILE* p_fread = fopen("contact.con", "rb");
	if (p_fread==NULL)
	{
		printf("读取数据失败：%s", strerror(errno));
		return;
	}
	//读取数据
	printf("读取数据成功。");
	while (fread(ps->data, sizeof(Peoinfo), 1, p_fread))
	{
		checkcapac(ps);
		ps->size++;
	}
	fclose(p_fread);
	p_fread = NULL;
}
