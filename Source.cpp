#include <stdio.h>
#include <math.h>

const char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const char *teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
"nineteen" };
const char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

//каждый if выводит название первого(в некоторых случа€х первых двух) разр€до
//и возвращает число без выведеных разр€дов, в main цикл вызова функции продолжаетс€
//пока не выведены все разр€ды


long nameForNumber(long number) {
	//проверка на ноль
	if (number == 0) {
		printf("zero ");
		return 0;
	}
	//выводит последний разр€д
	if (number < 10) {
		printf("%s ", ones[number]);
		return 0;
	}
	//выводит дес€тки от 10-20
	if (number < 20) {
		printf("%s ", teens[number - 10]);
		return 0;
	}
	//если число 2 разр€дное выводит колво дес€тков > 20
	if (number < 100) {
		printf("%s ", tens[number / 10]);
		return number % 10;
	}
	//если число 3 разр€дное выводит колво сотен
	if (number < 1000) {
		printf("%s hundred ", ones[number / 100]);
		return number % 100;
	}
	//если число 4 разр€дное выводит колво тыс€ч
	if (number < 10000) {
		printf("%s thousand ", ones[number / 1000]);
		return number % 1000;
	}
	//если у числа первые два разр€да из диапазона 10-20 выодит колво дес€тков тыс€ч
	if (number < 20000) {
		printf("%s thousand ", teens[number / 1000 - 10]);
		return number % 1000;
	}
	//если число 5 разр€дное выводит колво дес€тков тыс€ч > 20
	if (number < 100000) {
		printf("%s ", tens[number / 10000]);
		return number % 10000;
	}
	//если число 6 разр€дное выводит колво сотен тыс€ч
	if (number < 1000000) {
		printf("%s hundred ", ones[number / 100000]);
		return number % 100000;
	}
	// если число 7 разр€дное выводит колво миллионов
	if (number < 10000000) {
		printf("%s million ", ones[number / 1000000]);
		return number % 1000000;
	}
}

int main() {
	long input;
	printf("Please enter a number:\n");
	scanf_s("%li", &input);
	//обработка отрицательных чисел
	if (input < 0) {
		printf("minus ");
		input = abs(input);
	}
	//цикл вызывающий функцию
	do {
		input = nameForNumber(input);
	} while (input > 0);
	getchar();
	getchar();
	return 0;
}
