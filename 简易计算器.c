/*
项目名称：简易计算器 
作者：张娅蕾 
学号：202010420127
班级：网工一班 
编程语言：C语言 
*/

#include <stdio.h>
#include <math.h>         //该头文件的作用是引用sqrt函数 

int main()

{
	int num;        //自定义整型变量 
	char answer;     //自定义字符型变量 

	do
	{
		printf("--------简易计算器V2.0--------\n");
		printf("输入1进行平方根运算,输入2进行倒数运算,输入3进行求幂次方运算.\n");
		scanf("%d", &num);        //输入一个数字选择要进行的计算类型 

        //平方根运算 
		if (num == 1)
		{
			int a;           //自定义整型变量,该变量为求平方根的数 
			double b;       //自定义浮点型变量,显示求平方根的结果 
			printf("Please input a number:");
			scanf("%d", &a);
			b = sqrt(a);      //利用sqrt函数求平方根 
			printf("%d的平方根为%.1f", a, b);    //输出 
		}
          
        //倒数运算 
		if (num == 2)
		{
			int a;            //自定义整型变量,该变量为求倒数的数 
			float b;         //自定义浮点型变量,显示求倒数的结果 
			printf("Please input a number:");
			scanf("%d", &a);
			b = (float)1 / a;        //将整型变量强制转化为浮点型变量 
			printf("%d的倒数是%.3f", a, b);   //输出 
		}

        //求幂次方运算 
		if (num == 3)
		{
			int x, y, n;           //自定义整型变量 
			printf("x=");
			scanf("%d", &x);
			printf("n=");
			scanf("%d", &n);
			y = pow(x, n);          //引用pow函数求数的幂次方 
			printf("%d的%d次方为%d", x, n, y);   //输出 
		}

		printf("\n是否还需要再次计算,如果需要,键入y,否则n：\n");
		answer = getch();         //getch()的功能为读取一个键入字符 
	} while (answer == 'y');      //若读取的字符与y相同，则再次进行循环 

	return 0;
}
