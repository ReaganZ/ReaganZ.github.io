/*
项目名称：冒泡排序 
作者：张娅蕾 
学号：202010420127
班级：网工一班 
编程语言：C语言 
日期：2021/03/20
目的：实现冒泡排序算法 
*/

#include <stdio.h>
#define N 5

int main()
{
	int i,a[N];
    //利用for循环输入数组 
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    Bubble_sort(a,N);             //引用函数
	//利用for循环输出数组 
    for(i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
    return 0;
 } 
 
 //自定义的函数Bubble_sort为解决冒泡排序问题
 void  Bubble_sort(int a[],int n)
 {
 	int i,j;                       //自定义循环变量 
 	int temp;                      //自定义临时变量 
 	for(i=0;i<n-1;i++)            //n个数进行n-1轮循环 
 	{
 	for(j=i+1;j<n-1-i;j++)         //每次循环进行n-1-i次数字比较 
 	{
 		if(a[j-1]>a[j])            //比较相邻两数的大小并进行数字交换 
 		{
 			temp=a[j];
 			a[j]=a[j-1];
 			a[j-1]=temp;
		}
	}
}
  } 
