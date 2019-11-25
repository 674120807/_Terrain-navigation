# include <stdio.h>
# include <iostream>
# include <graphics.h>
# include <windows.h>
# include <MMSystem.h>				//播放音乐需要的头文件
# pragma comment(lib,"winmm.lib")	//告诉编译器,加载winmm.lib库文件

# define COUNT 148

using namespace std;

int main()
{
	IMAGE images[COUNT];
	char fileName[128];

	cout<<"正在加载...."<<endl;

	//预先加载资源
	for (int i = 1; i < 148; i++)
	{
		sprintf(fileName,"E:\\项目5-极乐净土图片帧\\images2\\_%04d_图层-%d.jpg",148-i,i);
		loadimage(&images[i-1],fileName);  //&取地址
	}
	
	initgraph(800,450);

	//重复播放"天份.mp3"
	mciSendString(_T("play 极乐净土.mp3 repeat"),0,0,0);

	while (1)
	{
	//依次播放各个图片
		for (int i = 0; i <148; i++)
		{
			/*
			sprintf(fileName,"E:\\项目5-极乐净土图片帧\\images2\\_%04d_图层-%d.jpg",148-i,i);
			loadimage(0,fileName); //很耗时 优化方案:预先加载
			*/

			putimage(0,0,&images[i]);
			Sleep(75);		
		}
	}

	system("pause");
    closegraph();
	return 0;
}