/*
��Ŀ���ƣ��������� 
���ߣ������ 
ѧ�ţ�202010420127
�༶������һ�� 
������ԣ�C���� 
���ڣ�2021/03/21
Ŀ�ģ�ʵ�ֿ��������㷨 
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

//�Զ��庯�� Quick_sort 
void Quick_sort(int array, int low, int high)
{
    if (low < high)                    //�ж�low��high�Ĵ�С 
    {
        int i = low;                   //�Զ������ͱ��� 
        int j = high;                  //�Զ������ͱ��� 
        int k = arr[low];              //�Զ����������� 
        while (i < j)                  //�Ƚ�i��j�Ĵ�С 
        {
            while(i < j && arr[j] >= k)     // ���������ҵ�һ��С��k����
            {
                j--;                   //j��ǰ�ƶ�һλ 
            }
 
            if(i < j)                   //�ٴαȽ�i��j�Ĵ�С 
            {
                arr[i++] = arr[j];      
            }
 
            while(i < j && arr[i] < k)      // ���������ҵ�һ�����ڵ���k����
            {
                i++;
            }
 
            if(i < j)
            {
                arr[j--] = arr[i];
            }
        }
 
        arr[i] = k;                     //k��ֵ����a[i] 
 
        // �ݹ����
        QuickSort(arr, low, i - 1);     // ����k���
        QuickSort(arr, i + 1, high);    // ����k�ұ�
    }
}
 
// ������
int main()
{
    int array[N];                   //����һ���������� 
    
    printf("����ǰ������:\n");
    //����forѭ�������������� 
    for(i=0;i<N;i++)
    scanf("%d",&array[i]);
    
    QuickSort(array, 0, N-1);  // ���ú���ʹ�ÿ������� 
    
    printf("����������\n");
    //����forѭ����ӡ���������� 
    for(i=0;i<N;i++) 
    printf("%d ",a[i]);
    printf("\n");
    return 0;
}
