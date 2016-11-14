#include <stdio.h>
#include <string.h>

int s5[4][16]={
	{2 ,12,4 ,1 ,7 ,10,11,6 ,8 ,5 ,3 ,15,13,0 ,14,9 },
	{14,11,2 ,12,4 ,7 ,13,1 ,5 ,0 ,15,10,3 ,9 ,8 ,6 },
	{4 ,2 ,1 ,11,10,13,7 ,8 ,15,9 ,12,5 ,6 ,3 ,0 ,14},
	{11,8 ,12,7 ,1 ,14,2 ,13,6 ,15,0 ,9 ,10,4 ,5 ,3 }};

// gcc des_sbox.c -o des_sbox
// ./des_sbox 'input1' 'input2'
// 输出： 输入差分：
//        output1  output2 
//        输出差分

int sfind(int input);  // 输入6位二进制对应的10进制数， 输出s盒对应数 
int b2d(char *n);      //2进制转10进制
void d2b(int n);       //10 转 2  输出6位

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("input error\n");
		return 0;
	}
	int input1, input2, in, output1, output2, ou;
	input1 = b2d(argv[1]);
	input2 = b2d(argv[2]);
	in = input1 ^ input2;

	output1 = sfind(input1);
	output2 = sfind(input2);
    ou = output1 ^ output2;

	printf("输入1：%s, 输入2：%s\n", argv[1], argv[2]);
	printf("输入差分：");d2b(in);printf("\n");
	printf("输出1："); d2b(output1);
	printf("输出2："); d2b(output2);printf("\n");
	printf("输出差分：");d2b(ou);printf("\n");
	
}

// 输入6位二进制对应的10进制数， 输出s盒对应数 
int sfind(int input)
{
	int row, col;
	int tmp1, tmp2;
	tmp1 = (input >> 5) << 1;
    tmp2 = input & 1;
	row = tmp1 + tmp2;

	tmp1 = input >> 1;
	col = tmp1 & 15;

	return s5[row][col];
}

int b2d(char *n)    //2进制转10进制
{
	int number = 0, tmp = 1, lenth, i;
	for(i = 0; n[i] != '\0'; i++) ;
    lenth = i - 1;
	for(i = lenth ; i >= 0; i--)
	{
		number += (n[i] - '0') * tmp;
		tmp = 2 * tmp;
	}

	return number;

}

void d2b(int n)  //10 转 2  输出6位
{
	char bin[7];
	int i;
	for(i = 5; i >= 0; i--)
	{
		bin[i] = n%2 ? '1' : '0';
		n = n >> 1;
	}
	bin[6] = '\0';
	printf("%s, ", bin);
}


