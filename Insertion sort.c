/*
��Ŀ���ƣ���������
���ߣ������ 
ѧ�ţ�202010420127 
������ԣ�C����
�༶������һ��  
���ڣ�2021/03/20
Ŀ�ģ�ʵ�ֲ��������㷨 
*/

#include <stdio.h>
#define N 5

int main()
{
	int i;
	int a[N];
	//����forѭ��������������a��ֵ 
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	Insertion_sort(a,N);       //���ú��� 
	//����forѭ��������������Ľ�� 
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}

//�Զ���ĺ���Insertion_sort��������������� 
void Insertion_sort(int a[],int n)
{
	int i,j;                   //�Զ���ѭ������ 
	int temp;                  //����������Ԫ�� 
	//����n-1��ѭ�� 
	for(i=1;i<n;i++)
	{
		temp=a[i];            //���������Ԫ�ظ�ֵ����ʱ���� 
		j=i;
		while(j>=1&&a[j-1]>temp)      //�Ƚ�����Ԫ�ش�С����δ��������ĵ�һ��Ԫ�� 
		{
			a[j]=a[j-1];       //����Ԫ�غ��� 
			j--;               //�±��һ 
		}
		a[j]=temp;           //��������Ԫ�ز��� 
	}
}
