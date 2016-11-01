#include<stdio.h>
#include<string.h>

//置换密码1, 将明文中的字母顺序倒过来然后截成固定长度的字母作为密文

#define MAX 50 //明密文长度MAX
#define LENTH 5 //固定长度

int main(int argc, char **argv)
{
    char plaintext[MAX], cipher[MAX], tmp;
	int i, j;
	int flag = 0;

	for(i = 0; i < MAX; i++)
	{
		plaintext[i] = '0';
		cipher[i] = '0';
	}

	printf("输入明文：");
	fgets(plaintext, MAX, stdin);
	for( i =0 ; plaintext[i] != '\0'; i++);
	flag = i; // 明文lenth
	for(j = 0, i = 1; i < flag; i++)
	{
		tmp = plaintext[flag - i - 1];
		if (tmp == ' ') ;
		else
		{
			cipher[j] = tmp;
			j ++;
		}
	}
	flag = j;
	for( j = 0, i = 0; i < flag; i++)
	{ 
		if( j != 0 && j%LENTH == 0)
		{
			printf(" ");
			j = 0;
		}
		printf("%c",cipher[i]);
		j ++;
	}
	printf("\n");
}

