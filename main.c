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
    fscanf(fin,"%[^\n]",&s);   /*讀檔，因檔案格式中有空格，用[^/n]跳過所有空格*/
    printf("%s",s);
    lens=strlen(s);
    printf("\nOutput 1:\n");
    for (i=0;i<lens;i++)
    {
        if (s[i]==' ')  /*當字元為空白時，印出空白*/
            printf("");
        else if (isalpha(s[i]))  /*當字元為英文字母時，不放入stack直接print*/
            printf("%c",s[i]);
        else      /*除去以上兩種條件，剩下的即是當字元為運算子的情況*/
            if (precedence(s[i]) > precedence(stack[top]))  /*當字元的predence>stack內運算子的predence時，壓得住，因此push*/
            {
                stack[++top]=s[i];
            }
            else  /*反之當壓不住時*/
            {
                while (precedence(s[i]) <=precedence(stack[top])  &&  top>-1)
                {  /*stack內所有運算子都必須比較precedence，因此用while迴圈
                    當壓不住且top>-1時pop一個運算子並print*/
                    printf("%c",stack[top--]);
                }
                stack[++top]=s[i];  /*如果stack為空 (top==0)也要將運算子push*/
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
/*--------------以下重複步驟做input2----------------------*/
    top=-1;     /*只需要改檔名以及將stack歸0top=-1  */
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
