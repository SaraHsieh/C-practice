#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int precedence(char o)
{
    switch (o)
    {
        case'+':
        case'-':
            return 1;
            break;
        case'*':
        case'/':
            return 2;
            break;
    }
    return 0;
}
int main()
{
    char stack[MAX],s[MAX];
    int i, top=-1,maxtop=0,lens;
    FILE *fin;

    fin=fopen("6input.txt","r");
    printf("Input 1:\n");
    fscanf(fin,"%[^\n]",&s);   /*Ū�ɡA�]�ɮ׮榡�����Ů�A��[^/n]���L�Ҧ��Ů�*/
    printf("%s",s);
    lens=strlen(s);
    printf("\nOutput 1:\n");
    for (i=0;i<lens;i++)
    {
        if (s[i]==' ')  /*��r�����ťծɡA�L�X�ť�*/
            printf("");
        else if (isalpha(s[i]))  /*��r�����^��r���ɡA����Jstack����print*/
            printf("%c",s[i]);
        else      /*���h�H�W��ر���A�ѤU���Y�O��r�����B��l�����p*/
            if (precedence(s[i]) > precedence(stack[top]))  /*��r����predence>stack���B��l��predence�ɡA���o��A�]��push*/
            {
                stack[++top]=s[i];
            }
            else  /*�Ϥ����������*/
            {
                while (precedence(s[i]) <=precedence(stack[top])  &&  top>-1)
                {  /*stack���Ҧ��B��l���������precedence�A�]����while�j��
                    ��������Btop>-1��pop�@�ӹB��l��print*/
                    printf("%c",stack[top--]);
                }
                stack[++top]=s[i];  /*�p�Gstack���� (top==0)�]�n�N�B��lpush*/
            };
        if(maxtop<top)
        {
            maxtop=top+1;
        }
    }
    for (i=top;i>-1;i--)
    {
        printf("%c ",stack[i]);
    }
    printf("\nmaxtop:%d\n\n",maxtop);
    fclose(fin);
/*--------------�H�U���ƨB�J��input2----------------------*/
    top=-1;     /*�u�ݭn���ɦW�H�αNstack�k0top=-1  */
    fin=fopen("6input-2.txt","r");
    printf("Input 2:\n");
    fscanf(fin,"%[^\n]",&s);
    printf("%s",s);
    lens=strlen(s);
    printf("\nOutput 2:\n");
    for (i=0;i<lens;i++)
    {
        if (s[i]==' ')
            printf("");
        else if (isalpha(s[i]))
            printf("%c",s[i]);
        else
            if (precedence(s[i]) > precedence(stack[top]))
            {
                stack[++top]=s[i];
            }
            else
            {
                while (precedence(s[i]) <=precedence(stack[top])  &&  top>-1)
                {
                    printf("%c",stack[top--]);
                }
                stack[++top]=s[i];
            }
        if(maxtop<top)
        {
            maxtop=top+1;
        }
    }
    for (i=top;i>-1;i--)
    {
        printf("%c",stack[i]);
    }
    printf("\nmaxtop:%d",maxtop);
    fclose(fin);
}
