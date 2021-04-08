/*
项目名称：单词排序
作者：张娅蕾
学号：202010420127
班级：20网工一班
编程语言：C语言
目的：对输入的N个单词进行排序
日期：2021/03/15
*/

#include <stdio.h>                              //标准输入输出 
#include <string.h>                            //调用strcmp()函数、strcpy()函数 
#define N 50                                   //单词不超过50个 
#define M 26                                   //单词长度不超过26 

//主函数 
int main()
{
	char word[N][M];                              //自定义字符型二维数组用于储存输入单词 
	int n=0;                                      //自定义整型变量n表示输入单词数 
	int i=0;                                      //自定义整型变量i 
	
	//控制输入的单词数在1-50 
	while(n<1||n>50)
	{
		printf("请输入将要排序的单词数(1-50):\n");
		scanf("%d",&n);
	}
	printf("请输入%d个单词,以空格分开(单词长度不超过%d,若超出,程序会自动忽略超出部分):\n",n,M-1);
	
	//输入单词 
	for(i=0;i<n;i++)
	scanf("%s",&word[i]);
	
	//调用自定义函数WordSort
	WordSort(word,n);
	
	//打印排序后的单词 
	for(i=0;i<n;i++)
	printf("%s ",&word[i]);
	
	return 0;
 } 
 
 //插入排序 
 void WordSort(char word[][M],int n)                        //自定义函数 
 {
 	char key[M];                                        //自定义字符型数组用于临时储存字符串 
 	int i,j;                                           //自定义整型变量用于循环
	  
 	//for循环实现插入排序 
 	for(i=1;i<n;i++)              
 	{
 		strcpy(key,word[i]);                           //将word[i]中的字符串复制到key数组中 
 		j=i;                                           
 		//while循环用于比较大小 
 		while(j>=1&&strcmp(word[j-1],key)>0)
 		{
 			strcpy(word[j],word[j-1]);                  //将数组中j-1位的字符串复制给数组的j位 
 			j--;                                        //j向前移动一位 
		 }
		 strcpy(word[j],key);                          //将key数组中的字符串复制给数组的j位 
	 }
 }
