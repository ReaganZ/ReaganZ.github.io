/*
项目名称：快速排序 
作者：张娅蕾 
学号：202010420127
班级：网工一班 
编程语言：C语言 
日期：2021/03/21
目的：实现快速排序算法 
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

//自定义函数 Quick_sort 
void Quick_sort(int array, int low, int high)
{
    if (low < high)                    //判断low和high的大小 
    {
        int i = low;                   //自定义整型变量 
        int j = high;                  //自定义整型变量 
        int k = arr[low];              //自定义整型数组 
        while (i < j)                  //比较i和j的大小 
        {
            while(i < j && arr[j] >= k)     // 从右向左找第一个小于k的数
            {
                j--;                   //j向前移动一位 
            }
 
            if(i < j)                   //再次比较i和j的大小 
            {
                arr[i++] = arr[j];      
            }
 
            while(i < j && arr[i] < k)      // 从左向右找第一个大于等于k的数
            {
                i++;
            }
 
            if(i < j)
            {
                arr[j--] = arr[i];
            }
        }
 
        arr[i] = k;                     //k的值赋给a[i] 
 
        // 递归调用
        QuickSort(arr, low, i - 1);     // 排序k左边
        QuickSort(arr, i + 1, high);    // 排序k右边
    }
}
 
// 主函数
int main()
{
    int array[N];                   //定义一个整型数组 
    
    printf("排序前的数组:\n");
    //利用for循环输入乱序数组 
    for(i=0;i<N;i++)
    scanf("%d",&array[i]);
    
    QuickSort(array, 0, N-1);  // 调用函数使用快速排序法 
    
    printf("排序后的数组\n");
    //利用for循环打印排序后的数组 
    for(i=0;i<N;i++) 
    printf("%d ",a[i]);
    printf("\n");
    return 0;
}
