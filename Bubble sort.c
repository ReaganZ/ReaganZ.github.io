/*
��Ŀ���ƣ�ð������ 
���ߣ������ 
ѧ�ţ�202010420127
�༶������һ�� 
������ԣ�C���� 
���ڣ�2021/03/20
Ŀ�ģ�ʵ��ð�������㷨 
*/

#include <stdio.h>
#define N 5

int main()
{
	int i,a[N];
    //����forѭ���������� 
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    Bubble_sort(a,N);             //���ú���
	//����forѭ��������� 
    for(i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
    return 0;
 } 
 
 //�Զ���ĺ���Bubble_sortΪ���ð����������
 void  Bubble_sort(int a[],int n)
 {
 	int i,j;                       //�Զ���ѭ������ 
 	int temp;                      //�Զ�����ʱ���� 
 	for(i=0;i<n-1;i++)            //n��������n-1��ѭ�� 
 	{
 	for(j=i+1;j<n-1-i;j++)         //ÿ��ѭ������n-1-i�����ֱȽ� 
 	{
 		if(a[j-1]>a[j])            //�Ƚ����������Ĵ�С���������ֽ��� 
 		{
 			temp=a[j];
 			a[j]=a[j-1];
 			a[j-1]=temp;
		}
	}
}
  } 
