/*
	Вычислить частичную сумму ряда
	SUM[1,n] = (i^i + i! - x^i +(x+1)^i ) / ( (x+i)! (2i)! )
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define NOERRORS 0

void getnums(int* num, int* x);
long double part(int i, int x);
long double factor(int factof);
long double Ipow(int base, int power);

int main(void)
{
	//Добавление переменных и ввод чисел
	int n, x;
	getnums(&n, &x);

	//Цикл перебирает значения от 1 до n,
	//прибавляет каждый новый элемент ряда в сумму
	long double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		long double partOfSum = part(i, x);
		printf("%d-й член ряда равен %.16lf\n", i, partOfSum);
		sum += partOfSum;
	}

	printf("\nРезультат: %.16lf\n", sum);	//Вывод
	return NOERRORS;
}

/*Ввод числа витков num и коэфициента x
с проверкой на корректность*/
void getnums(int* num, int* x)
{
	//Ввод числа витков
	do
	{
		printf("Введите число витков i, большее или равное 1: ");
		scanf("%d", num);
		if (*num > 0)
			break;
		printf("Число i должно быть больше или равно 1\n");
	} while (TRUE);

	//Ввод числа x
	do
	{
		printf("Введите x : ");
		if (scanf("%d", x))
			return;
		printf("Неправильное число x!\n");
	} while (TRUE);
}

/*Функция вычисления факториала числа
При передаче числа <=1 осуществляется возврат 1*/
long double factor(int factof)
{
	long double ret = 1;
	int i = 1;
	while (i <= factof)
		ret *= i++;
	return ret;
}

//Функция вычисления i-го члена ряда с параметром x
long double part(int i, int x)
{
	long double numerat = (Ipow(i, i) + factor(i) - Ipow(x, i) + Ipow((x + 1), i));
	long double denumer = (factor(x + i) + factor(2 * i));
	return numerat / denumer;
}

//Функция подсчёта base в степени power
long double Ipow(int base, int power)
{
	long double result = 1.0;
	for (int i = 0; i < power; ++i)
		result *= base;
	return result;
}
