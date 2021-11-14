#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

void menu() {
	printf("******************************\n");
	printf("**       1.add     2.del    **\n");
	printf("**       3.search  4.modify **\n");
	printf("**       5.show    6.sort   **\n");
	printf("**         0.exit           **\n");
	printf("******************************\n");
}

void test() {
	struct Contacts con;
	InitContact(&con);
	int choose = 0;;
	do {
		menu();
		printf("please choose:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case EXIT:
			printf("About to close...\n");
			break;
	  	case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (choose != 0);
	
}

int main() {
	test();
	//char name[MAX_NAME] = "abc", name2[MAX_NAME] = "bbc";
	//char ch[MAX_NAME] = "张三", ch2[MAX_NAME] = "李四";
	//printf("%d %d", strcmp(name, name2), strcmp(ch, ch2));
	//struct People p1 = { 0 };
	//struct People p2 = {"lisi",32,"male","118","nantong"};
	//memcpy(&p1, &p2, sizeof(p2));
	//puts(p1.name);
	return 0;
};