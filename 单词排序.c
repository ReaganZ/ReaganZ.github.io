/*
��Ŀ���ƣ���������
���ߣ������
ѧ�ţ�202010420127
�༶��20����һ��
������ԣ�C����
Ŀ�ģ��������N�����ʽ�������
���ڣ�2021/03/15
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
		printf("�����뽫Ҫ����ĵ�����(1-50):\n");
		scanf("%d",&n);
	}
	printf("������%d������,�Կո�ֿ�(���ʳ��Ȳ�����%d,������,������Զ����Գ�������):\n",n,M-1);
	
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
