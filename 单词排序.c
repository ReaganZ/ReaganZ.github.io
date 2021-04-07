/*
项目名称：单词排序
作者：张娅蕾
学号：202010420127
班级：20网工一班
编程语言：C语言
目的：对输入的N个单词进行排序
日期：2021/03/15
*/

#include <stdio.h>
#include <string.h>
#define N 50
#define M 26

int main()
{
	char word[N][M];
	int n=0;
	int i=0;
	while(n<1||n>50)
	{
		printf("请输入将要排序的单词数(1-50):\n");
		scanf("%d",&n);
	}
	printf("请输入%d个单词,以空格分开(单词长度不超过%d,若超出,程序会自动忽略超出部分):\n",n,M-1);
	
	for(i=0;i<n;i++)
	scanf("%s",&word[i]);
	
	WordSort(word,n);
	
	for(i=0;i<n;i++)
	printf("%s ",&word[i]);
	
	return 0;
 } 
 
 void WordSort(char word[][M],int n)
 {
 	char key[M];
 	int i,j;
 	for(i=1;i<n;i++)
 	{
 		strcpy(key,word[i]); 
 		j=i;
 		while(j>=1&&strcmp(word[j-1],key)>0)
 		{
 			strcpy(word[j],word[j-1]);
 			j--;
		 }
		 strcpy(word[j],key);
	 }
 }
