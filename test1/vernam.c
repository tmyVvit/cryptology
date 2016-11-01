#include <stdio.h>
#include <string.h>

#define MAX 20

void d2b(int n)
{
	char bin[8];
	int i;
	for(i = 6; i >= 0 ; i--)
    {
		bin[i] = n%2 ? '1' : '0';
		n = n >> 1;
	}
	bin[7] = '\0';
	printf("%s", bin);
}

void print2(char *c, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		d2b(c[i]);
		printf("%c", 0x20);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	char input[MAX], output[MAX], key[MAX];

	printf("输入明文:");
	scanf("%s", input);

	printf("输入密钥:");
	scanf("%s", key);

	int i, k, lenth;
	for(i = 0; key[i] != '\0'; i++);
	lenth = i;

	for(i = 0, k = 0; input[i] != '\0'; i++)
	{
		output[i] = input[i] ^ key[k++];
		k = k % lenth;
	}
	lenth = i;
	print2(output, lenth);
}
