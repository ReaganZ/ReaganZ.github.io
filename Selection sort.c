/*
项目名称：选择排序
作者：张娅蕾 
学号：202010420127 
编程语言：C语言 
班级：网工一班
日期：2021/03/20
目的：实现选择排序算法 
*/ 

#include <stdio.h>
#include <stdlib.h>       //引用system的头文件 
#define N 5

int main()
{
    int i,a[N];
    //利用for循环输入数组 
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    Selection_sort(a,N);             //引用函数
	//利用for循环输出数组 
    for(i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
    system("pause");                //屏幕冻结 
    return 0;
}

//自定义的函数Selection_sort解决选择排序问题 
void Selection_sort(int a[],int n)
{
	int i,j;                     //自定义循环变量 
	int temp;                   //自定义临时变量 
	//n个数进行n-1次循环 
	for(i=0;i<n-1;i++)
	{
		int min=i;               //默认a[i]为最小数 
		//选出第i+1小的数 
		for(j=i+1;j<n;j++)
		if(a[min]>a[j])            //比较每个数与最小数的大小 
		{
			min=j;                //使得a[j]为第i+1轮的最小数 
		} 
		if(i!=min)              //判断最小数的下标是否等于i 
		{
			//数字交换,将第i+1小的数放在i的位置 
			temp=a[i];           
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
