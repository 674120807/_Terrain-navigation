#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h> //getch()使用
#include "hacker.h"

using namespace std;

# define WIDTH 40
# define HEIGHT 15

//设置终端界面的大小
void init(void){
	char cmd[128];
	sprintf(cmd,"mode con cols= %d lines= %d",WIDTH,HEIGHT);
	system(cmd);
}

void inputPwd(char pwd[],int size){
	char c;
	int i=0;

	//请输入密码:123456
	//保存到字符数组pwd:'1','2','3','4','5','6','\0'
	while (1)
	{
		//如果读到回车符,返回'\r'
		c = getch();//不会回显

		if (c == '\r')
		{
			pwd[i]=0;//字符串结束符
			break;
		}
		pwd[i++]=c;
		cout<<'*';
	}
	cout<<endl;
}

//账号输入
void login(void){
	string name;
	//string pwd;
	char pwd[32];

	while (1)
	{
		system("cls");//清除屏幕
		cout << "请输入账号：";
		cin >> name;

		cout << "请输入密码：";
		//cin >> pwd;
		//实现密码的输入
		inputPwd(pwd,sizeof(pwd));

		//getch()读取字符,但是不回显


		if (name == "54hk" && !strcmp(pwd ,"123456")) {
			//break;
			return;
		} else
		{
			cout << "用户名或密码错误!" << endl;
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

//菜单显示
void menuShow(void)
{
	string menu[] ={
	"1.网站404攻击" ,
	"2.网站篡改攻击",
	"3.网站攻击修复",
	"4.查看攻击记录",
	"5.退出",
	};

	//计算菜单项的最大长度
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

//打印标题
printInMiddle("----黑客攻击系统-----");

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



//输入功能功能编号
int  menuChoise(void) 
{
	int n=0;
	while (1)
	{
		cin>>n;
		if(cin.fail())
			{
				cin.clear();
				cin.sync();		//清除缓存
				cout<<"无效输入,请重新输入."<<endl;
				system("pause");
			}
			else
			{
				break;
			}
	}
	return n;
}


//各个攻击分支
void attack404(void) {
	char response[MAXSIZE] ;
	char id[64];

	memset(response, 0, sizeof(response));

	system("cls");
	printInMiddle("---网站404攻击---");
	cout <<   "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));
	cout << "正在执行404攻击..." << endl;

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
	printInMiddle("---网站篡改攻击---");
	cout <<   "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));
	cout <<   "请输入嵌入的内容：";
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
	printInMiddle("---网站攻击修复---");
	cout <<   "请输入准备查询的网站ID：";
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
	printInMiddle("---攻击记录获取---");
	cout <<   "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));

	hk_record(id, response);
	
	string retStr = UTF8ToGBK(response);

	cout << retStr;
	system("pause");
}

int main(void) {
	init();
	login();//实现登录功能

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
				cout<<"无效输入,请重新输入"<<endl;
				system("pause");
				break;
		}
	}

	system("pause");
	return 0;
}
