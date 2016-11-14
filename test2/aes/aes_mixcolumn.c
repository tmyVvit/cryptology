#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mixcolumns(unsigned char *c1, unsigned char *c2);
unsigned char xtime(unsigned char n);
void print_b(unsigned char c);

int main(int argc, char **argv)
{
	unsigned char a[4];
	unsigned char b[4];

	/*if(argc != 5)
	{
		printf("input error!\n");
		exit(1);
	}*/
    int i, j;
	unsigned char ch[4][2];
	// 给a[i]赋值
	for(i = 0; i < 4; i++)
	{
		printf("a[%d]:", i);
		scanf("%s", ch[i]);		
	}
	for(i = 0; i < 4; i++)
	{
		//*ch = *argv[i + 1];
		//int len = strlen(ch);
		for( j = 0; j < 2; j++)
		{	
			if(ch[i][j] >= '0' && ch[i][j] <= '9')
				ch[i][j] = ch[i][j] - '0';
			else if(ch[i][j] >= 'A' && ch[i][j] <='F')
				ch[i][j] = ch[i][j] - 'A' + 0x0A;
			else if(ch[i][j] >= 'a' && ch[i][j] <= 'f')
				ch[i][j] = ch[i][j] - 'a' + 0x0A;
			else
			{
				printf("input error!!!\n");
				exit(1);
			}
			

		}
		//tmp1 = (ch[0] << 4) & 0xF0;
		//tmp2 = ch[1] & 0x0F;
		a[i] = ((ch[i][0] << 4) & 0xF0) ^ (ch[i][1] & 0x0F);
	}

	mixcolumns(a, b);

	for(i = 0; i < 4; i++)
	{
		printf("b[%d]:", i);
		print_b(b[i]);
	}
	printf("\n");
}

void mixcolumns(unsigned char *c1,unsigned char *c2)
{
	int i;
	for(i = 0; i < 4; i++)
	{
		c2[i] =  xtime(c1[i])
	        ^  ((c1[(i+1)%4] ^ xtime(c1[(i+1)%4]))) 
		   	^	c1[(i+2)%4] 
			^	c1[(i+3)%4] ;
	}
}

unsigned char xtime(unsigned char n)
{
	unsigned char c;
	if(n & 0x80)
		c = (n << 1) ^ 0x1b;
	else
		c = n << 1;

	return c;
}

void print_b(unsigned char c)
{
	printf("%x%x ",(c >> 4) & 0x0f, c & 0x0f);
}


