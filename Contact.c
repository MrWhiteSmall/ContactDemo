#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//输入people信息
static void InputPeopleinfo(struct Contacts* con,int i) {
	do
	{
		printf("please input name:>");
		scanf("%s", &(con->people[i].name));
	} while (!(con->people[i].name));
	do
	{
		printf("please input age:>");
		scanf("%d", &(con->people[i].age));
	} while (!con->people[i].age);
	do
	{
		printf("please input gender:>");
		scanf("%s", &(con->people[i].gender));
	} while (!con->people[i].gender);
	do
	{
		printf("please input tel:>");
		scanf("%s", &(con->people[i].tel));
	} while (!con->people[i].tel);
	do
	{
		printf("please input address:>");
		scanf("%s", &(con->people[i].address));
	} while (!con->people[i].address);
}
//输出people头部框架信息
static void OutputPeopleHeader() {
	printf("%-20s\t%-4s\t%-4s\t%-11s\t%-40s\t\n"
		, "姓名", "年龄", "性别", "电话", "地址");
}
//输出people信息
static void OutputPeopleInfo(struct Contacts* con, int i) {
	printf("%-20s\t%-4d\t%-4s\t%-11s\t%-40s\t\n",
		con->people[i].name, con->people[i].age,
		con->people[i].gender, con->people[i].tel,
		con->people[i].address);
}
//查找peopleInfo信息,根据name
static int FindInfoByName(const struct Contacts* con) {
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < con->size; ++i) {
		if (strcmp(name, con->people[i].name) == 0) {
			return i;
		}
	}
	return -1;
}

void InitContact(struct Contacts* con) {
	memset(con, 0, sizeof(con->people));
	con->size = 0;

	printf("initializing data for test....\n");
	char name[3][MAX_NAME] = { {"zhangsan"},{"lisi"},{"wangwu"} };
	int age[3] = { 12,23,45 };
	char gender[3][MAX_GENDER] = { "male","female","male" };
	char tel[3][MAX_TEL] = { {"17312324259"},{"17312324250"},{"17312324270"} };
	char  address[3][MAX_ADDRESS] = { "翻斗大街101号","江宁区银河路12号","南京晓庄学院" };
	for (int i = 0; i < 3; ++i) {
		strcpy(con->people[i].name, name[i]);
		con->people[i].age = age[i];
		strcpy(con->people[i].gender, gender[i]);
		strcpy(con->people[i].tel, tel[i]);
		strcpy(con->people[i].address, address[i]);
		con->size++;
	}
	ShowContact(con);
}

void AddContact(struct Contacts* con) {
	if (con->size == NUM) {
		printf("通讯录已满,无法添加新数据");
	}
	else {
		InputPeopleinfo(con, con->size);
		
		con->size++;
		printf("your contactInfo has added\n");
	}
}
void DelContact(struct Contacts* con) {
	printf("please input who's name you want to delete:>");
	int pos = FindInfoByName(con);
	if ( pos != -1) {
		if (pos == con->size - 1) {
			memset(&con->people[pos], 0, sizeof(con->people[pos]));
		}
		else {
			for (int i = pos; i < con->size - 1 ; ++i) {
				strcpy(con->people[i].name, con->people[i + 1].name);
				con->people[i].age = con->people[i + 1].age;
				strcpy(con->people[i].gender, con->people[i+1].gender);
				strcpy(con->people[i].tel, con->people[i+1].tel);
				strcpy(con->people[i].address, con->people[i+1].address);
			}
		}
		con->size--;
		printf("you have delete this info by name\n");
	}
	else {
		printf("not find this name,maybe not true\n");
	}
}
void SearchContact(const struct Contacts* con) {
	printf("please input who's name you want to search:>");
	int pos = FindInfoByName(con);
	if ( pos != -1) {
		printf("have found!\n");
		OutputPeopleHeader();
		OutputPeopleInfo(con,pos);
	}
	else {
		printf("not find this name,maybe not true\n");
	}
}
void ShowContact(const struct Contacts* con) {
	if (con->size == 0) {
		printf("通讯录中为空,无显示数据\n");
	}
	else {
		OutputPeopleHeader();
		for (int i = 0; i < con->size; ++i) {
			OutputPeopleInfo(con, i);
		}
	}
}
void ModifyContact(struct Contacts* con) {
	printf("please input who's name you want to modify:>");
	int pos = FindInfoByName(con);
	if (pos != -1) {
		printf("you have found this info by name,start modify\n");
		InputPeopleinfo(con, pos);
		printf("modify has success\n");
	}
	else {
		printf("not find this name,maybe not true\n");
	}
}
static void ExchangePeopleInfo(struct Contacts* con,int a,int b) {
	struct People tmp = { 0 };
	memcpy(&tmp, &con->people[a], sizeof(con->people[a]) );
	memcpy(&con->people[a], &con->people[b], sizeof(con->people[b]) );
	memcpy(&con->people[b], &tmp , sizeof(tmp ) );
}
void SortContact(struct Contacts* con) {
	//sort by name a->z bubble
	for (int i = 0; i < con->size - 1; ++i) {
		int flag = 0;
		for (int j = 0; j < con->size - 1; ++j) {
			if (strcmp(con->people[j].name, con->people[j + 1].name) > 0) {
				flag = 1;
				ExchangePeopleInfo(con, j, j + 1);
			}
		}
		if (!flag)break;//if flag = 0 no exchange and break
	}
}