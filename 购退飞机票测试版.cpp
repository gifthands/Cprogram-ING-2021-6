#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#define MaxNum 50       //航次所能接受最大的顾客数量
#define MaxTicket 100       //每个航次最多的票数
#define M 10                      //航班的数目

//用户的信息
struct People
{
	char name[100];		//用户姓名；
	int buyticket;			//用户已经购买的票；
};

//航班的信息
struct Flight
{
	int name;		//航班的名称，在此用数字代替；
	int currentticket;		//航班现存的最大票数；
	int numpeople;		//航班现存的顾客数目；
	People* Plist[MaxNum];				//该航班的顾客队列；
};

void menu();								//打印可进行的操作；
void InitFlight(Flight* flight, int index, int maxticket);   //创建航班；
void InitFlightList(Flight* flightlist[], int num);						//初始化航班列表；
void InitPeople(People* people, char pn[], int bt);						//创建顾客信息
void InsertTail(Flight* flight, People* people);  //在航班末尾处插入新顾客信息；
int Search(Flight* flight, char name[]);   //查找在某航班中顾客姓名所对应在顾客队列中的序号；
void DeleteCustomer(Flight* flight, int index);   //清除指定顾客信息；
void BorRticket(Flight* flightlist[]);						//退票和购票操作；
void PrintfTicket(Flight* flight);					//打印航次信息；
void FindPTicket(Flight* flight, char name[]);					//查询用户在该航班购票数；

int main()
{
	Flight* flightlist[M];
	InitFlightList(flightlist, M);
	while (true)
	{
		menu();
		char str;
		str = _getch();
		switch (str)
		{
		case '0':
			return 0;
			break;
		case '1':
			BorRticket(flightlist);
			break;
		case '2':
			for (int i = 0; i < M; i++)
				PrintfTicket(flightlist[i]);
			system("pause");
			system("cls");
			break;
		case '3':
			char customername[100];
			printf("请输入您的姓名：");
			scanf("%s", &customername);
			for (int i = 0; i < M; i++)
			{
				FindPTicket(flightlist[i], customername);
			}
			system("pause");
			system("cls");
			break;
		default:
			printf("无效操作！\n\n\n");
			break;
		}
		printf("\n\n\n\n");
	}
	return 0;
}


void menu()                         //打印可进行的操作；
{
	printf("**********请选择服务***********\n");
	printf("***\t1:订退票\n");
	printf("***\t2:查询各航班余票数\n");
	printf("***\t3:查询用户所购买票数\n");
	printf("***\t0:退出\n");
	printf("*******************************\n");
}
void InitFlightList(Flight* flightlist[], int num)						//初始化航班列表；
{
	for (int i = 0; i < M; i++)
	{
		Flight* f = new Flight;
		InitFlight(f, i + 1, MaxTicket);
		flightlist[i] = f;
	}
}
void InitFlight(Flight* flight, int index , int maxticket)	 //创建航班；
{
	flight->name = index;
	flight->currentticket = maxticket;
	flight->numpeople = 0;
}
void InitPeople(People* people, char pn[], int bt)	//创建顾客信息
{
	strcpy(people->name, pn);
	people->buyticket = bt;
}
void InsertTail(Flight* flight, People* people)	//在航班末尾处插入新顾客信息；
{
	flight->currentticket -= people->buyticket;
	flight->numpeople++;										//用户数增加；
	flight->Plist[flight->numpeople-1] = people;     //添加用户；
}
int Search(Flight* flight, char name[])			//查找在某航班中顾客姓名所对应在顾客队列中的序号；
{
	for (int i = 0; i < flight->numpeople; i++)
	{
		if (strcmp(name, flight->Plist[i]->name) == 0)
			return i+1;
	}
	return -1;       //说明原顾客队列中无此顾客；
}
void DeleteCustomer(Flight* flight, int index)			 //清除指定顾客信息；
{
	if (index == flight->numpeople)
		flight->numpeople--;
	else
	{
		for (int i = index-1; i < flight->numpeople-1; i++)
		{
			flight->Plist[i] = flight->Plist[i + 1];
		}
		flight->numpeople--;
	}
}
void BorRticket(Flight* flightlist[])
{
	while (true)
	{
		system("cls");
		char name[100];		//用户昵称；
		int flightindex;			//航班的序号；
		int peopleindex;		//用户在航班队列中的序号；
		printf("**********请选择服务******\n");
		printf("**\t1：购票\n");
		printf("**\t2：退票\n");
		printf("**\t0：退出购退票操作\n");
		printf("**************************\n");
		int ticketnum;    //需要购买或者退回的票数；
		char ch;				//指令；
		ch = _getch();
		if (ch == '0')
		{
			system("cls");
			return;
		}
		printf("\n\n请输入用户姓名：");
		scanf("%s", &name);
		printf("当前航班序列有：%d航次\n", M);
		while (true)
		{
			printf("##请输入需要操作的航班序列：");
			scanf("%d", &flightindex);
			if (flightindex<1 || flightindex>M)
			{
				printf("!!!无该航班信息，请重新输入!\n");
				continue;
			}
			peopleindex = Search(flightlist[flightindex - 1], name);  //查找用户；
			break;
		}
		int currentticket = flightlist[flightindex - 1]->currentticket;   //航班当前余票；
		int boughtticket = (peopleindex > 0) ? flightlist[flightindex - 1]->Plist[peopleindex - 1]->buyticket : 0;   //该用户已经购买的票数；
		printf("----当前%d号航班余票：%d, 您已订购票数：%d，共%d人已订购该航班\n", flightindex, currentticket, boughtticket, flightlist[flightindex - 1]->numpeople);
		switch (ch)
		{
		case '1':
			printf("##请输入购票数：");
			scanf("%d", &ticketnum);
			if (ticketnum > flightlist[flightindex - 1]->currentticket)
			{
				printf("!!!购票数%d错误！该航班余票不足(余票：%d)\n\n", ticketnum, flightlist[flightindex - 1]->currentticket);
			}
			else if (ticketnum > 0)
			{
				if (boughtticket != 0)
				{
					flightlist[flightindex - 1]->Plist[peopleindex - 1]->buyticket += ticketnum;
					flightlist[flightindex - 1]->currentticket -= ticketnum;
					printf("^^购票成功！用户信息已修改\n\n");
				}
				else
				{
					People* customer = new People;
					InitPeople(customer, name, ticketnum);      //生成用户信息；
					InsertTail(flightlist[flightindex - 1], customer);    //添加信息；
					printf("^^购票成功！已生成用户信息\n\n");
				}
			}
			else
			{
				printf("!!!票数不正确！\n\n");
			}
			break;
		case '2':
			printf("##请输入退票数：");
			scanf("%d", &ticketnum);
			if (boughtticket == 0)
			{
				printf("!!!退票数过大！\n");
			}
			else
			{
				if (boughtticket < ticketnum)
				{
					printf("!!!退票数过大！\n\n");
				}
				else if (boughtticket == ticketnum)
				{
					DeleteCustomer(flightlist[flightindex - 1], peopleindex);
					flightlist[flightindex - 1]->currentticket += ticketnum;
					printf("^^退票成功！已清除用户信息\n\n");
				}
				else
				{
					flightlist[flightindex - 1]->Plist[peopleindex - 1]->buyticket -= ticketnum;
					flightlist[flightindex - 1]->currentticket += ticketnum;
					printf("^^退票成功！已修改用户信息\n\n");
				}
			}
			break;
		default:
			printf("!!!无效操作！将返回主页面\n\n");
			break;
		}
		system("pause");
		system("cls");
	}
}
void PrintfTicket(Flight* flight)					//打印航次信息；
{
	printf("%d号航次，已有顾客%d位，当前余票为%d\n", flight->name, flight->numpeople, flight->currentticket);
}
void FindPTicket(Flight* flight, char name[])						//查询用户在该航班购票数；
{
	for (int i = 0; i < flight->numpeople; i++)
	{
		if (strcmp(flight->Plist[i]->name, name) == 0)
		{
			printf("===您在%d号航班已购票数：%d\n", flight->name, flight->Plist[i]->buyticket);
			return;
		}
	}
	printf("===未在%d号航班查询到您的信息\n", flight->name);
}



