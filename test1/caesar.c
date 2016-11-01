/*****************
caesar密码
encrypt & decrypt
只接受26个英文字母的大小写，输入其他字符将出错
最多接受MAX个字符
******************/

#include<stdio.h>
#include<string.h>

#define MAX 30  //接受字符最大长度

char input[MAX];
char output[MAX];

int encrypt( char plaintext[], char code[])
{
    int offset;
    while(1)
    {
        printf("please enter offset(1 to 25):");
        //fflush(stdin);
        scanf("%d",&offset);
        if(offset < 1 || offset > 25)
        {
            printf("offset between 1 and 25!\n");
        }
        else break;
    }
    for(int i = 0; plaintext[i] != '\n';i++ )
    {
      //  printf("%d\n",plaintext[i]);
        int tmp = plaintext[i] + offset;
       //空格
        printf("%c, %d, %c\n", plaintext[i], i, tmp);
        if(plaintext[i] == 32)
        {
            code[i] = plaintext[i];
        }
     //大写字母
        else if((plaintext[i] < 91) && (plaintext[i] > 64))
        {
            code[i] = (tmp > 90) ? tmp - 26 : tmp ; 
        } 
     //小写字母
        else if((plaintext[i] < 123) && (plaintext[i] > 96))
        {
            code[i] = (tmp > 122) ? tmp - 26 : tmp ;
        }
     //其他字符
        else
        {
            printf("only 26 letters accepted!\n");
            return 0;
        }
    }

    printf("code: %s\n", code);
}


int decrypt( char code[], char plaintext[])
{
    int offset;
    printf("offset\t\t%s",code);
    for(offset = 1; offset < 26; offset++)
    {
        printf(" %2d  \t\t",offset);
        for( int i = 0; code[i] != '\n'; i++)
        {
            int tmp = code[i] - offset;
           // printf("%c", code[i]);
          //空格
            if(code[i] == 32)
            {
                plaintext[i] = code[i];
            }
         //大写字母
            else if(code[i] < 91 && code[i] > 64)
            {
                plaintext[i] = (tmp < 65) ? tmp + 26 : tmp ;
            }
          //小写字母
            else if(code[i] < 123 && code[i] > 96)
            {
                plaintext[i] = (tmp < 97) ? tmp + 26 : tmp ;
            }
           //其他字符
            else
            {
                printf("only 26 letters accepted!\n");
                return 0;
            }
        }
        printf("%s\n",plaintext);
    }
}

int main(int argc, char * argv[])
{   
    printf("1.encrypt     2.decrypt\n please choose:");
    int choice=0;  // 1:en   2:de
    scanf("%d",&choice);
   
    getchar(); // 读取choice时缓冲区里还有一个‘\n’,用getchar()读取掉，防止影响
               // 下面fgets()函数

    printf("please enter plaintext or code(less than %d letters!):", MAX);
    
    fgets(input,MAX,stdin);

    printf("input: %s\n",input);
    if(choice == 1)
        encrypt(input, output);
    else if(choice == 2)
        decrypt(input, output);
    else printf("please enter 1 or 2!\n");
    
}
