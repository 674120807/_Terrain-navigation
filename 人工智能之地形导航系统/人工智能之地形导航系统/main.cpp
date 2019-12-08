# include <iostream>
# include <fstream> //���ļ�����
# include <string>
# include <stdlib.h>
using namespace std;

# define N 128

bool isPeak(int grid[N][N],int r, int c);

int main(void){
	int nrows, ncols;
	int map[N][N];
	string filename;//�ļ���
	ifstream file; 

	cout<<"�������ļ���:\n";
	cin >>filename;

	file.open(filename.c_str());
	if (file.fail())
	{
		cout<<"�������ļ�����.\n";
		exit(1);	//�쳣����
	}

	file>>nrows>>ncols;

	if (nrows > N || ncols > N)
	{
		cout<<"����̫��,��������.\n";
		exit(1);
	}

	//�������ļ���ȡ���ݵ���ά����
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j  < ncols; j ++)
		{
			file>>map[i][j];
		}
	}

	//�жϲ���ӡ��ֵ��λ��
	for (int i = 1; i < nrows - 1; i++)
	{
		for (int  j= 1;  j< ncols - 1; j++)
		{
			if (isPeak(map,i,j))
			{
				cout<<"����������:"<<i<<"��"<< j <<endl;
			}
		}
	}

	system("pause");

	//�ر��ļ�
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
