#include <stdio.h>
#include <math.h>

const char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const char *teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
"nineteen" };
const char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };


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
