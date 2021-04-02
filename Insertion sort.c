/*
项目名称：插入排序
作者：张娅蕾 
学号：202010420127 
编程语言：C语言
班级：网工一班  
日期：2021/03/20
目的：实现插入排序算法 
*/

#include <stdio.h>
#define N 5

int main()
{
	int i;
	int a[N];
	//利用for循环依次输入数组a的值 
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	Insertion_sort(a,N);       //引用函数 
	//利用for循环依次输出排序后的结果 
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}

//自定义的函数Insertion_sort解决插入排序问题 
void Insertion_sort(int a[],int n)
{
	int i,j;                   //自定义循环变量 
	int temp;                  //储存待排序的元素 
	//进行n-1次循环 
	for(i=1;i<n;i++)
	{
		temp=a[i];            //将待排序的元素赋值给临时变量 
		j=i;
		while(j>=1&&a[j-1]>temp)      //比较两个元素大小并且未到达数组的第一个元素 
		{
			a[j]=a[j-1];       //将该元素后移 
			j--;               //下标减一 
		}
		a[j]=temp;           //将待排序元素插入 
	}
}
