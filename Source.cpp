#include <stdio.h>
#include <math.h>

const char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const char *teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
"nineteen" };
const char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

//������ if ������� �������� �������(� ��������� ������� ������ ����) �������
//� ���������� ����� ��� ��������� ��������, � main ���� ������ ������� ������������
//���� �� �������� ��� �������


long nameForNumber(long number) {
	//�������� �� ����
	if (number == 0) {
		printf("zero ");
		return 0;
	}
	//������� ��������� ������
	if (number < 10) {
		printf("%s ", ones[number]);
		return 0;
	}
	//������� ������� �� 10-20
	if (number < 20) {
		printf("%s ", teens[number - 10]);
		return 0;
	}
	//���� ����� 2 ��������� ������� ����� �������� > 20
	if (number < 100) {
		printf("%s ", tens[number / 10]);
		return number % 10;
	}
	//���� ����� 3 ��������� ������� ����� �����
	if (number < 1000) {
		printf("%s hundred ", ones[number / 100]);
		return number % 100;
	}
	//���� ����� 4 ��������� ������� ����� �����
	if (number < 10000) {
		printf("%s thousand ", ones[number / 1000]);
		return number % 1000;
	}
	//���� � ����� ������ ��� ������� �� ��������� 10-20 ������ ����� �������� �����
	if (number < 20000) {
		printf("%s thousand ", teens[number / 1000 - 10]);
		return number % 1000;
	}
	//���� ����� 5 ��������� ������� ����� �������� ����� > 20
	if (number < 100000) {
		printf("%s ", tens[number / 10000]);
		return number % 10000;
	}
	//���� ����� 6 ��������� ������� ����� ����� �����
	if (number < 1000000) {
		printf("%s hundred ", ones[number / 100000]);
		return number % 100000;
	}
	// ���� ����� 7 ��������� ������� ����� ���������
	if (number < 10000000) {
		printf("%s million ", ones[number / 1000000]);
		return number % 1000000;
	}
}

int main() {
	long input;
	printf("Please enter a number:\n");
	scanf_s("%li", &input);
	//��������� ������������� �����
	if (input < 0) {
		printf("minus ");
		input = abs(input);
	}
	//���� ���������� �������
	do {
		input = nameForNumber(input);
	} while (input > 0);
	getchar();
	getchar();
	return 0;
}
