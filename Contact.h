#define _CRT_SECURE_NO_WARNINGS 1

#define NUM 100
#define MAX_NAME 20
#define MAX_GENDER 7
#define MAX_TEL 12
#define MAX_ADDRESS 40
#include<stdio.h>
#include<string.h>

//initialize data
void InitContact(struct Contacts*);
//add peopleInfo to Contact
void AddContact(struct Contacts*);
//delete peopleInfo from contact by name
void DelContact(struct Contacts*);
//searchPeopleInfo from contact by name
void SearchContact(const struct Contacts*);
//modify peopleInfo through search it by name
void ModifyContact(struct Contacts*);
//show All peopleInfo which in Contact
void ShowContact(const struct Contacts*);
//sort peopleInfo according to first char in name (a-Z)
void SortContact(struct Contacts*);

enum MENU {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct People {
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADDRESS];
};

struct Contacts {
	struct People people[NUM];
	int size;
};