/*
项目名称：推箱子
项目作者：张娅蕾
学号:202010420127
专业班级：20级网络工程1班
项目时间：2021.05.06-2021.06.06
编程语言：C
目的：用简单的C语言编写推箱子小游戏
说明：由于使用easyx图形库 所以源文件后缀为cpp
*/

#include <stdio.h>             //标准输入输出头文件
#include <easyx.h>             //图形库头文件
#include<conio.h>              //getch()函数和kbhit()函数的头文件 用于读取用户的按键
#include<Windows.h>            //Sleep()函数的头文件
#include <stdlib.h>            //exit()函数和system()函数需要的头文件
#include <mmsystem.h>          //播放音乐头文件
#pragma comment(lib,"WINMM.LIB")     //告诉编译器 加载winmm.lib库文件

void Loadmap();                //获取当前关卡
void LoadImg();                //加载地图的图片
void drawmap();                //自定义一个贴图函数drawmap(用来画地图)
void playgame();               //自定义函数用于找到玩家位置并进行游戏操作
void judge();                  //自定义函数judge用于判断游戏输赢

char dir;                        //dir代表操作人物移动的方向
int flag;                        //判断游戏输赢
int x, y;                        //x和y分别表示玩家所在的行和列

IMAGE img[6];                     //需要6张图片组成地图和人物

//空地0 墙1 箱子2 人物3 目的地4
//人可以站在目的地上 3+4-->7
//箱子推到目的地    2+4-->6
int allMap[3][10][11] =            //自定义所有关卡的地图 一共两张地图
{
	//地图1
   {
	0,0,0,0,0,1,1,1,1,1,1,
	0,1,1,1,1,1,4,0,0,0,1,
	0,1,0,0,1,4,4,1,1,0,1,
	0,1,0,0,2,4,4,0,0,0,1,
	0,1,0,0,1,0,4,1,0,1,1,
	1,1,1,0,1,1,2,1,0,0,1,
	1,0,2,0,0,0,0,2,2,0,1,
	1,0,1,2,1,0,0,1,0,0,1,
	1,3,0,0,1,1,1,1,1,1,1,
	1,1,1,1,1,0,0,0,0,0,0
   },
	//地图2
   {
	1,1,1,1,1,1,1,1,1,0,0,
	1,0,0,0,0,0,0,0,1,0,0,
	1,0,0,2,0,2,0,2,1,0,0,
	1,1,0,1,2,1,1,0,1,0,0,
	0,1,0,4,4,0,4,4,1,1,0,
	0,1,1,4,4,0,4,4,0,1,0,
	0,0,1,0,1,1,2,1,0,1,1,
	0,0,1,2,0,2,0,2,0,0,1,
	0,0,1,0,0,0,0,0,0,3,1,
	0,0,1,1,1,1,1,1,1,1,1
   }
};
int nowmap[10][11];                    //当前关卡的地图
int level = 0;                         //当前关卡

int main()
{
	mciSendString("open back.mp3 alias bgm", 0, 0, 0);      //打开音乐
	mciSendString("play bgm repeat", 0, 0, 0);              //播放音乐
	//alias bgm 给音乐取个名字
	//repeat 表示循环播放

	initgraph(440, 400);      //每个方块的大小50*50 窗口大小就是550*500
	//加载地图素材

	LoadImg();             //加载图片
	Loadmap();             //加载当前地图
	drawmap();             //画地图
	playgame();            //获取玩家位置

	while (1)                 //重复执行
	{
		drawmap();               //画出地图
		judge();                 //判断游戏输赢

		if (flag == 2)                   //游戏赢了
		{
			//MessageBox的头文件是Windows.h
			if (MessageBox(GetHWnd(), "CONGRATULATIONS YOU WIN! NEXT LEVEL?", "WIN", MB_YESNO) == IDYES)         //弹窗:CONGRATULATIONS YOU WIN!NEXT LEVEL?并选择是否继续游戏
			{
				level++;                 //下一关
				if (level == 2)          //判断是否进行到第二关
				{
					if (MessageBox(GetHWnd(), "THE LAST LEVEL. TRY AGAIN?", "GAME OVER", MB_YESNO) == IDYES)     //弹窗:THE LAST LEVEL TRY AGAIN?并选择是否重新开始游戏
					{
						level = 0;       //重新开始游戏
					}
					else
						return 0;
				}
				Loadmap();              //下一关 要重新加载地图
				drawmap();              //地图变了要重新绘画
				playgame();             //地图变量要重新获取玩家位置
				flag = 0;               //正在游戏中
			}
			else
				return 0;
		}

		else if (flag == 1)               //游戏输了
		{
			if (MessageBox(GetHWnd(), "SORRY YOU LOSE! TRY AGAIN?", "LOSE", MB_YESNO) == IDYES)           //弹窗:SORRY YOU LOSE!并且选择是否重新开始当前关卡
			{
				Loadmap();               //重新加载本地图
				drawmap();               //绘图
				playgame();              //获取玩家位置
				flag = 0;                //游戏继续
			}
			else
				return 0;
		}
		playgame();                     //操作人物
	}

		getchar();                      //按任意键继续
		closegraph();                   //关闭绘图窗口
		return 0;
}

void Loadmap()                    //获取当前关卡地图
{
	for(int i=0;i<10;i++)
		for (int j = 0;j < 11;j++)
		{
			nowmap[i][j] = allMap[level][i][j];               //选定当前关卡
		}
}

void LoadImg()                              //自定义函数LoadImg用于加载图片
{
	//加载组成地图的图片
	loadimage(&img[0], "land.jpg", 40, 40);         //加载空地   大小是40*40
	loadimage(&img[1], "wall.jpg", 40, 40);         //加载墙     大小是40*40
	loadimage(&img[2], "BoxYellow.jpg", 40, 40);    //加载箱子  大小是40*40
	loadimage(&img[3], "ManDOWN1.jpg", 40, 40);     //加载人物(向下走的一个动作)  大小是40*40
	loadimage(&img[4], "aim.jpg", 40, 40);          //加载目的地  大小是40*40
	loadimage(&img[5], "BoxRed.jpg", 40, 40);       //加载成功到达目的地的箱子 大小是40*40
}

void drawmap()                   //自定义一个贴图函数drawmap(用来画地图)
{
	system("cls");               //清屏
	BeginBatchDraw();            //开始画图 防止闪屏

	//循环绘制地图
	for (int i = 0;i < 10;i++)          //循环每一行
	{
		for (int j = 0;j < 11;j++)      //循环每一列
		{
			//单独贴图
			switch (nowmap[i][j])
			{
			case 0:putimage(j * 40, i * 40, &img[0]);      //空地
				break;
			case 1:putimage(j * 40, i * 40, &img[1]);      //墙
				break;
			case 2:putimage(j * 40, i * 40, &img[2]);      //未到达目的地的箱子
				break;
			case 3:                 //人物不在目的地上
			case 7:                 //人物站在目的地上
					putimage(j * 40, i * 40, &img[3]);     //人物
				break;
			case 4:putimage(j * 40, i * 40, &img[4]);      //目的地(一个圆点)
				break;
			case 6:putimage(j * 40, i * 40, &img[5]);      //到达目的地的箱子
				break;
			}
		}
	}
	EndBatchDraw();                //结束绘图
}

void playgame()                    //玩家操作
{
	if (_kbhit())                  //kbhit()函数用于检查是否有键盘输入，有返回非0，无返回0
	{
		//循环地图找到人物的位置
		for (int i = 0;i < 10;i++)          //循环每一行
		{
			for (int j = 0;j < 11;j++)      //循环每一列
			{
				if (nowmap[i][j] == 3 || nowmap[i][j] == 7)     //3代表人物 7代表人物站在目的地上
				{
					//找到人物位置
					x = i;
					y = j;
				}
			}
		}

		//等待玩家操作 wsad分别为上下左右方向键 
		dir = _getch();                //dir用于储存玩家输入的按键
		//玩家操作
		switch (dir)
		{
		 case 'w':     
		 case 72:                         //'w'的ASCII码值是72
			if (nowmap[x - 1][y] == 0 || nowmap[x - 1][y] == 4)       //玩家的上边是空地或者目的地
			{
				nowmap[x][y] = nowmap[x][y] - 3;                    //玩家向上移动 离开当前位置
				nowmap[x - 1][y] = nowmap[x- 1][y] + 3;            //玩家移动到上面
			}
			if (nowmap[x- 1][y] == 2 || nowmap[x- 1][y] == 6)      //玩家的上边是(在目的地的)箱子
			{
				if (nowmap[x - 2][y] == 0 || nowmap[x - 2][y] == 4)     //箱子的上边是空地或者目的地
				{
					nowmap[x][y] = nowmap[x][y] - 3;                   //玩家向上移动 离开当前位置
					nowmap[x - 1][y] = nowmap[x - 1][y] + 3 - 2;       //玩家移动到上面 上面的箱子移动到上边的空地或者目的地
					nowmap[x - 2][y] = nowmap[x - 2][y] + 2;           //箱子移动到空地或者目的地
				}
			}
			break;

		 case 's':            
		 case 80:                        //'s'的ASCII码值是80
			if (nowmap[x + 1][y] == 0 || nowmap[x + 1][y] == 4)       //玩家的下边是空地或者目的地
			{
				nowmap[x][y] = nowmap[x][y] - 3;                    //玩家向下移动 离开当前位置
				nowmap[x + 1][y] = nowmap[x + 1][y] + 3;            //玩家移动到下面
			}
			if (nowmap[x + 1][y] == 2 || nowmap[x + 1][y] == 6)      //玩家的下边是(在目的地的)箱子
			{
				if (nowmap[x + 2][y] == 0 || nowmap[x + 2][y] == 4)    ////箱子的下边是空地或者目的地
				{
					nowmap[x][y] = nowmap[x][y] - 3;                   //玩家向下移动 离开当前位置
					nowmap[x + 1][y] = nowmap[x + 1][y] + 3 - 2;       //玩家移动到下面 下面的箱子移动到下边的空地或者目的地
					nowmap[x + 2][y] = nowmap[x + 2][y] + 2;           //箱子移动到空地或者目的地
				}
			}
			break;

		 case 'a':    
		 case 75://'a'的ASCII码值是75
			if (nowmap[x][y - 1] == 0 || nowmap[x][y - 1] == 4)      //玩家的左边是空地或者目的地
			{
				nowmap[x][y] = nowmap[x][y] - 3;                   //玩家向左移动 离开当前位置
				nowmap[x][y - 1] = nowmap[x][y - 1] + 3;               //玩家移动到左边
			}
			if (nowmap[x][y - 1] == 2 || nowmap[x][y- 1] == 6)        //玩家的左边是(在目的地的)箱子
			{
				if (nowmap[x][y - 2] == 0 || nowmap[x][y - 2] == 4)   //箱子的左边是空地或者目的地
				{
					nowmap[x][y] = nowmap[x][y] - 3;                   //玩家向左移动 离开当前位置
					nowmap[x][y - 1] = nowmap[x][y - 1] + 3 - 2;       //玩家移动到左边 左边的箱子移动到左边的空地或者目的地
					nowmap[x][y - 2] = nowmap[x][y - 2] + 2;          //箱子移动到空地或者目的地
				}
			}
			break;

		 case'd':                     
		 case 77:                          //'d'的ASCII码值是77
			if (nowmap[x][y + 1] == 0 || nowmap[x][y + 1] == 4)      //玩家的右边是空地或者目的地
			{
				nowmap[x][y] = nowmap[x][y] - 3;                     //玩家向右移动 离开当前位置
				nowmap[x][y + 1] = nowmap[x][y + 1] + 3;               //玩家移动到右边
			}
			if (nowmap[x][y + 1] == 2 || nowmap[x][y + 1] == 6)        //玩家的右边是(在目的地的)箱子
			{
				if (nowmap[x][y + 2] == 0 || nowmap[x][y + 2] == 4)   //箱子的右边是空地或者目的地
				{
					nowmap[x][y] = nowmap[x][y] - 3;                  //玩家向右移动 离开当前位置
					nowmap[x][y + 1] = nowmap[x][y + 1] + 3 - 2;      //玩家移动到右边 右边的箱子移动到右边的空地或者目的地
					nowmap[x][y + 2] = nowmap[x][y + 2] + 2;          //箱子移动到空地或者目的地
				}
			}
			break;

			exit(0);                      //跳出函数
			break;
		}
		Sleep(100);                       //Sleep()函数的作用是使系统睡眠 是为了创造更好的游戏体验
	}
}

void judge()                     //判断游戏输赢
{
	int number = 0;              //记录有多少个没有到达目的地的箱子
	//赢-->地图上没有黄色箱子(所有箱子全部在目的地上)
	//输-->箱子相邻的两个或两个方向以上有障碍物(箱子或墙)
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 11;j++)
		{
			if (nowmap[i][j] == 2)                //循环地图寻找黄色箱子
			{
				flag = 0;                         //寻找到未到达目的地的箱子 游戏继续
				++number;                         //找到一个箱子 判断箱子是否在死角
				if (nowmap[i - 1][j] == 1 || nowmap[i + 1][j] == 1)         //箱子的上下至少有一堵墙
				{
					if (nowmap[i][j - 1] == 1 || nowmap[i][j + 1] == 1)     //箱子的左右至少有一堵墙
					{
						flag = 1;                  //箱子在死角 游戏结束
						return;                    //返回主函数
					}
				}
			}
		}
		//flag=0 表示游戏继续进行
		//flag=1 表示游戏输了
		//flag=2 表示游戏赢了
	}
	if (number == 0)                      //箱子全部到达目的地
		flag = 2;                         //游戏赢了
}
