/*
项目名称：解一元二次方程组 
作者：张娅蕾 
学号：202010420127
班级：网工一班 
编程语言：C语言 
*/

#include <stdio.h>
#include <math.h>               //该头文件的作用是引用sqrt函数

int main()

{
	int a, b, c,d;                //自定义整型变量 
	float x1, x2,e,f;             //自定义浮点型变量 
	printf("Please input 3 numbers:\n");
	printf("a=");                
	scanf_s("%d", &a);              //输入方程中二次项的常数项 
	printf("b=");
 	scanf_s("%d", &b);              //输入方程中一次项的常数项 
	printf("c=");
	scanf_s("%d",&c);               //输入方程中的常数项 
	d = b * b - 4*a*c;            //该表达式用于判断方程是否有解以及求方程的根 

    //方程无解 
	if (d < 0)
	{
		printf("该方程无解.");
	}
    
    //方程有两个相同解 
	else if (d == 0)
	{
		x1 = x2 =(float) -b / (2*a);      //利用一元二次方程求根公式求解方程的根,并强制转化为浮点型 
		printf("该方程有两个相同解，且x1=x2=%.2f", x1);   //打印 
	}

    //方程有两个不同解 
	else
	{
		x1 = (float)(-b + sqrt(d)) / (2 * a);     //利用一元二次方程求根公式求解方程的根,并强制转化为浮点型 
		x2 = (float)(-b - sqrt(d)) / (2 * a);     //利用一元二次方程求根公式求解方程的根,并强制转化为浮点型 
		printf("该方程有两个不同解，且x1=%.2f,x2=%.2f",x1 , x2);  //打印 
	}

	return 0;
}
