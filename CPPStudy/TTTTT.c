#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char array[5][2] = {0};

	for (int i = 0; i < 5; i++)
	{
		scanf("%c %c", &array[i][0], &array[i][1]);
		getchar();
	}

	char b1, b2;
	char nn[5] = {array[0][1],array[0][2], array[0][3], array[0][4], array[0][5]};
	int nc[5];
	int c = 0;
	int n = 0;
	b1 = array[0][0];
	b2 = array[0][1];
	for (int i = 0; i < 5; i++)
	{
		if (array[i][0] == b1) c++;
		if (array[i][1] == b2) n++;
		if(array[i][1]==)
		printf("%c %d\n", array[i][0], array[i][1] - 48);
	}

	if (c == 5 && n == 5)
	{
		printf("900");
		return 0;
	}
	if (n == 4)
	{
		printf("800");
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{

	}
	if (c == 5)
	{
		printf("600");
		return 0;
	}
	if (n == 3)
	{
		printf("400");
		return 0;
	}
	if (n == 2)
	{
		printf("200");
	}

	printf("100");
	return 0;
}