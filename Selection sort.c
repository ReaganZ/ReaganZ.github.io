/*
��Ŀ���ƣ�ѡ������
���ߣ������ 
ѧ�ţ�202010420127 
������ԣ�C���� 
�༶������һ��
���ڣ�2021/03/20
Ŀ�ģ�ʵ��ѡ�������㷨 
*/ 

#include <stdio.h>
#include <stdlib.h>       //����system��ͷ�ļ� 
#define N 5

int main()
{
    int i,a[N];
    //����forѭ���������� 
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);
    Selection_sort(a,N);             //���ú���
	//����forѭ��������� 
    for(i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
    system("pause");                //��Ļ���� 
    return 0;
}

//�Զ���ĺ���Selection_sort���ѡ���������� 
void Selection_sort(int a[],int n)
{
	int i,j;                     //�Զ���ѭ������ 
	int temp;                   //�Զ�����ʱ���� 
	//n��������n-1��ѭ�� 
	for(i=0;i<n-1;i++)
	{
		int min=i;               //Ĭ��a[i]Ϊ��С�� 
		//ѡ����i+1С���� 
		for(j=i+1;j<n;j++)
		if(a[min]>a[j])            //�Ƚ�ÿ��������С���Ĵ�С 
		{
			min=j;                //ʹ��a[j]Ϊ��i+1�ֵ���С�� 
		} 
		if(i!=min)              //�ж���С�����±��Ƿ����i 
		{
			//���ֽ���,����i+1С��������i��λ�� 
			temp=a[i];           
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
