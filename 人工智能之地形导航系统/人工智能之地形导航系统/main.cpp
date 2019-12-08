# include <iostream>
# include <fstream> //对文件操作
# include <string>
# include <stdlib.h>
using namespace std;

# define N 128

bool isPeak(int grid[N][N],int r, int c);

int main(void){
	int nrows, ncols;
	int map[N][N];
	string filename;//文件名
	ifstream file; 

	cout<<"请输入文件名:\n";
	cin >>filename;

	file.open(filename.c_str());
	if (file.fail())
	{
		cout<<"打开输入文件出错.\n";
		exit(1);	//异常结束
	}

	file>>nrows>>ncols;

	if (nrows > N || ncols > N)
	{
		cout<<"网格太大,调整程序.\n";
		exit(1);
	}

	//从数据文件读取数据到二维数组
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j  < ncols; j ++)
		{
			file>>map[i][j];
		}
	}

	//判断并打印峰值的位置
	for (int i = 1; i < nrows - 1; i++)
	{
		for (int  j= 1;  j< ncols - 1; j++)
		{
			if (isPeak(map,i,j))
			{
				cout<<"峰点出现在行:"<<i<<"列"<< j <<endl;
			}
		}
	}

	system("pause");

	//关闭文件
	file.close();

	return 0;
}

bool isPeak(int grid[][N],int r, int c){
	if ((grid[r][c] > grid[r-1][c])&&(grid[r][c] > grid[r+1][c])&&(grid[r][c] > grid[r][c-1])&&(grid[r][c] > grid[r][c+1]))
	{
		return true;
	}//else false

	return false;
}
