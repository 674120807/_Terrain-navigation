#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h> //getch()ʹ��
#include "hacker.h"

using namespace std;

# define WIDTH 40
# define HEIGHT 15

//�����ն˽���Ĵ�С
void init(void){
	char cmd[128];
	sprintf(cmd,"mode con cols= %d lines= %d",WIDTH,HEIGHT);
	system(cmd);
}

void inputPwd(char pwd[],int size){
	char c;
	int i=0;

	//����������:123456
	//���浽�ַ�����pwd:'1','2','3','4','5','6','\0'
	while (1)
	{
		//��������س���,����'\r'
		c = getch();//�������

		if (c == '\r')
		{
			pwd[i]=0;//�ַ���������
			break;
		}
		pwd[i++]=c;
		cout<<'*';
	}
	cout<<endl;
}

//�˺�����
void login(void){
	string name;
	//string pwd;
	char pwd[32];

	while (1)
	{
		system("cls");//�����Ļ
		cout << "�������˺ţ�";
		cin >> name;

		cout << "���������룺";
		//cin >> pwd;
		//ʵ�����������
		inputPwd(pwd,sizeof(pwd));

		//getch()��ȡ�ַ�,���ǲ�����


		if (name == "54hk" && !strcmp(pwd ,"123456")) {
			//break;
			return;
		} else
		{
			cout << "�û������������!" << endl;
			system("pause");
		}
	}	
}

void printInMiddle(string msg) {
	int space = (WIDTH - msg.length()) /2 ;
	for (int i=0; i<space; i++) {
		cout << " ";
	}
	cout << msg << endl;
}

//�˵���ʾ
void menuShow(void)
{
	string menu[] ={
	"1.��վ404����" ,
	"2.��վ�۸Ĺ���",
	"3.��վ�����޸�",
	"4.�鿴������¼",
	"5.�˳�",
	};

	//����˵������󳤶�
int max = 0;
int menuCount = sizeof(menu)/sizeof(menu[0]);
for (int i = 0; i < menuCount; i++)
{
	if (menu[i].length()>max)
	{
		max = menu[i].length();
	}
}

system("cls");

//��ӡ����
printInMiddle("----�ڿ͹���ϵͳ-----");

int leftSpace = (WIDTH - max)/2;
for (int i = 0; i < menuCount; i++)
{
	for (int i = 0; i < leftSpace; i++)
	{
		printf(" ");
	}
	cout << menu[i] << endl;
}

}



//���빦�ܹ��ܱ��
int  menuChoise(void) 
{
	int n=0;
	while (1)
	{
		cin>>n;
		if(cin.fail())
			{
				cin.clear();
				cin.sync();		//�������
				cout<<"��Ч����,����������."<<endl;
				system("pause");
			}
			else
			{
				break;
			}
	}
	return n;
}


//����������֧
void attack404(void) {
	char response[MAXSIZE] ;
	char id[64];

	memset(response, 0, sizeof(response));

	system("cls");
	printInMiddle("---��վ404����---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout << "����ִ��404����..." << endl;

	hk_404(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	system("pause");
}

void siteEdit(void) {
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printInMiddle("---��վ�۸Ĺ���---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout <<   "������Ƕ������ݣ�";
	cin >> attackText;

	GBKToUTF8(attackText);

	hk_tamper(id,  (char*)(attackText.c_str()), response);

	
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void siteRepair(void) {
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printInMiddle("---��վ�����޸�---");
	cout <<   "������׼����ѯ����վID��";
	scanf_s("%s", id, sizeof(id));

	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attckRecord(void) {
	char response[MAXSIZE] ;
	char id[64];

	system("cls");
	printInMiddle("---������¼��ȡ---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));

	hk_record(id, response);
	
	string retStr = UTF8ToGBK(response);

	cout << retStr;
	system("pause");
}

int main(void) {
	init();
	login();//ʵ�ֵ�¼����

	while(1){
		menuShow();
		int n=menuChoise();

		switch (n)
		{
			case 1:
						attack404();
						break;
			case 2:
						siteEdit();
						break;
			case 3:
						siteRepair();
						break;
			case 4:
						attckRecord();
						break;
			case 5:
						return 0;
			default:
				cout<<"��Ч����,����������"<<endl;
				system("pause");
				break;
		}
	}

	system("pause");
	return 0;
}
