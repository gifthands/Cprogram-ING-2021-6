#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#define MaxNum 50       //�������ܽ������Ĺ˿�����
#define MaxTicket 100       //ÿ����������Ʊ��
#define M 10                      //�������Ŀ

//�û�����Ϣ
struct People
{
	char name[100];		//�û�������
	int buyticket;			//�û��Ѿ������Ʊ��
};

//�������Ϣ
struct Flight
{
	int name;		//��������ƣ��ڴ������ִ��棻
	int currentticket;		//�����ִ�����Ʊ����
	int numpeople;		//�����ִ�Ĺ˿���Ŀ��
	People* Plist[MaxNum];				//�ú���Ĺ˿Ͷ��У�
};

void menu();								//��ӡ�ɽ��еĲ�����
void InitFlight(Flight* flight, int index, int maxticket);   //�������ࣻ
void InitFlightList(Flight* flightlist[], int num);						//��ʼ�������б�
void InitPeople(People* people, char pn[], int bt);						//�����˿���Ϣ
void InsertTail(Flight* flight, People* people);  //�ں���ĩβ�������¹˿���Ϣ��
int Search(Flight* flight, char name[]);   //������ĳ�����й˿���������Ӧ�ڹ˿Ͷ����е���ţ�
void DeleteCustomer(Flight* flight, int index);   //���ָ���˿���Ϣ��
void BorRticket(Flight* flightlist[]);						//��Ʊ�͹�Ʊ������
void PrintfTicket(Flight* flight);					//��ӡ������Ϣ��
void FindPTicket(Flight* flight, char name[]);					//��ѯ�û��ڸú��๺Ʊ����

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
			printf("����������������");
			scanf("%s", &customername);
			for (int i = 0; i < M; i++)
			{
				FindPTicket(flightlist[i], customername);
			}
			system("pause");
			system("cls");
			break;
		default:
			printf("��Ч������\n\n\n");
			break;
		}
		printf("\n\n\n\n");
	}
	return 0;
}


void menu()                         //��ӡ�ɽ��еĲ�����
{
	printf("**********��ѡ�����***********\n");
	printf("***\t1:����Ʊ\n");
	printf("***\t2:��ѯ��������Ʊ��\n");
	printf("***\t3:��ѯ�û�������Ʊ��\n");
	printf("***\t0:�˳�\n");
	printf("*******************************\n");
}
void InitFlightList(Flight* flightlist[], int num)						//��ʼ�������б�
{
	for (int i = 0; i < M; i++)
	{
		Flight* f = new Flight;
		InitFlight(f, i + 1, MaxTicket);
		flightlist[i] = f;
	}
}
void InitFlight(Flight* flight, int index , int maxticket)	 //�������ࣻ
{
	flight->name = index;
	flight->currentticket = maxticket;
	flight->numpeople = 0;
}
void InitPeople(People* people, char pn[], int bt)	//�����˿���Ϣ
{
	strcpy(people->name, pn);
	people->buyticket = bt;
}
void InsertTail(Flight* flight, People* people)	//�ں���ĩβ�������¹˿���Ϣ��
{
	flight->currentticket -= people->buyticket;
	flight->numpeople++;										//�û������ӣ�
	flight->Plist[flight->numpeople-1] = people;     //����û���
}
int Search(Flight* flight, char name[])			//������ĳ�����й˿���������Ӧ�ڹ˿Ͷ����е���ţ�
{
	for (int i = 0; i < flight->numpeople; i++)
	{
		if (strcmp(name, flight->Plist[i]->name) == 0)
			return i+1;
	}
	return -1;       //˵��ԭ�˿Ͷ������޴˹˿ͣ�
}
void DeleteCustomer(Flight* flight, int index)			 //���ָ���˿���Ϣ��
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
		char name[100];		//�û��ǳƣ�
		int flightindex;			//�������ţ�
		int peopleindex;		//�û��ں�������е���ţ�
		printf("**********��ѡ�����******\n");
		printf("**\t1����Ʊ\n");
		printf("**\t2����Ʊ\n");
		printf("**\t0���˳�����Ʊ����\n");
		printf("**************************\n");
		int ticketnum;    //��Ҫ��������˻ص�Ʊ����
		char ch;				//ָ�
		ch = _getch();
		if (ch == '0')
		{
			system("cls");
			return;
		}
		printf("\n\n�������û�������");
		scanf("%s", &name);
		printf("��ǰ���������У�%d����\n", M);
		while (true)
		{
			printf("##��������Ҫ�����ĺ������У�");
			scanf("%d", &flightindex);
			if (flightindex<1 || flightindex>M)
			{
				printf("!!!�޸ú�����Ϣ������������!\n");
				continue;
			}
			peopleindex = Search(flightlist[flightindex - 1], name);  //�����û���
			break;
		}
		int currentticket = flightlist[flightindex - 1]->currentticket;   //���൱ǰ��Ʊ��
		int boughtticket = (peopleindex > 0) ? flightlist[flightindex - 1]->Plist[peopleindex - 1]->buyticket : 0;   //���û��Ѿ������Ʊ����
		printf("----��ǰ%d�ź�����Ʊ��%d, ���Ѷ���Ʊ����%d����%d���Ѷ����ú���\n", flightindex, currentticket, boughtticket, flightlist[flightindex - 1]->numpeople);
		switch (ch)
		{
		case '1':
			printf("##�����빺Ʊ����");
			scanf("%d", &ticketnum);
			if (ticketnum > flightlist[flightindex - 1]->currentticket)
			{
				printf("!!!��Ʊ��%d���󣡸ú�����Ʊ����(��Ʊ��%d)\n\n", ticketnum, flightlist[flightindex - 1]->currentticket);
			}
			else if (ticketnum > 0)
			{
				if (boughtticket != 0)
				{
					flightlist[flightindex - 1]->Plist[peopleindex - 1]->buyticket += ticketnum;
					flightlist[flightindex - 1]->currentticket -= ticketnum;
					printf("^^��Ʊ�ɹ����û���Ϣ���޸�\n\n");
				}
				else
				{
					People* customer = new People;
					InitPeople(customer, name, ticketnum);      //�����û���Ϣ��
					InsertTail(flightlist[flightindex - 1], customer);    //�����Ϣ��
					printf("^^��Ʊ�ɹ����������û���Ϣ\n\n");
				}
			}
			else
			{
				printf("!!!Ʊ������ȷ��\n\n");
			}
			break;
		case '2':
			printf("##��������Ʊ����");
			scanf("%d", &ticketnum);
			if (boughtticket == 0)
			{
				printf("!!!��Ʊ������\n");
			}
			else
			{
				if (boughtticket < ticketnum)
				{
					printf("!!!��Ʊ������\n\n");
				}
				else if (boughtticket == ticketnum)
				{
					DeleteCustomer(flightlist[flightindex - 1], peopleindex);
					flightlist[flightindex - 1]->currentticket += ticketnum;
					printf("^^��Ʊ�ɹ���������û���Ϣ\n\n");
				}
				else
				{
					flightlist[flightindex - 1]->Plist[peopleindex - 1]->buyticket -= ticketnum;
					flightlist[flightindex - 1]->currentticket += ticketnum;
					printf("^^��Ʊ�ɹ������޸��û���Ϣ\n\n");
				}
			}
			break;
		default:
			printf("!!!��Ч��������������ҳ��\n\n");
			break;
		}
		system("pause");
		system("cls");
	}
}
void PrintfTicket(Flight* flight)					//��ӡ������Ϣ��
{
	printf("%d�ź��Σ����й˿�%dλ����ǰ��ƱΪ%d\n", flight->name, flight->numpeople, flight->currentticket);
}
void FindPTicket(Flight* flight, char name[])						//��ѯ�û��ڸú��๺Ʊ����
{
	for (int i = 0; i < flight->numpeople; i++)
	{
		if (strcmp(flight->Plist[i]->name, name) == 0)
		{
			printf("===����%d�ź����ѹ�Ʊ����%d\n", flight->name, flight->Plist[i]->buyticket);
			return;
		}
	}
	printf("===δ��%d�ź����ѯ��������Ϣ\n", flight->name);
}



