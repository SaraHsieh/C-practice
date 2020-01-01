#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING 100
#define MAX_NAME_LENGTH 10
#define MAX_DATA 10
#define MAX_PATTERN 10

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int index;
}data;

int read_csv(data*, char*);
void insert(data*, char*, int);
int find_failfun(int*, char*);
void pop(char*, int*, char*, int);

int main()
{
    char mainstr[MAX_STRING];
    char pat[MAX_PATTERN];
    data *list;
    int* failfun;
    int num_name,plen,i;

    list=malloc((MAX_DATA)*sizeof(data));
    failfun=malloc(MAX_PATTERN*sizeof(int));
    num_name=read_csv(list,pat);
    printf("P:%s\n",pat);

    insert(list,mainstr,num_name);
    printf("Final string:%s\n",mainstr);

    plen=find_failfun(failfun,pat);
    pop(mainstr, failfun ,pat, plen);
    printf("Last string:%s\n",mainstr);
    printf("LPS:{");
    for (i=0;i<plen;i++)
    {
        if (i!=plen-1)
            printf("%d,",failfun[i]);
        else
            printf("%d",failfun[i]);
    }
    printf("}");
    system("PAUSE");
    return 0;
}

int read_csv(data* list,char* patt)
{
    FILE *fin;
    int i=0;
    char P;
    fin=fopen("20input.txt","r");
    while(!feof(fin) && P!='P')  /*當檔案未結束，且確認Pattern已讀到即可跳出迴圈*/
    {
        fscanf(fin,"%[a-z]%*c%d\n",&list[i].name,&list[i].index);
        printf("%s,%d\n",list[i].name,list[i].index);
        fscanf(fin,"%[P]%*c%s",&P,patt);
        i++;
    }
    fclose(fin);
    return i;
}

void insert(data* list, char* mainstr, int num)
{
    int i,len,pos;
    char temp[MAX_STRING];
    for (i=0;i<num;i++)
    {
        len=strlen(list[i].name);
        if(list[i].index>len)
            printf("error");
        if (i==0)
        {
            pos=0;
            strcpy(mainstr,list[i].name);
        }
        else
        {
            pos=pos+list[i-1].index;
            strncpy(temp,mainstr,pos);
            strcat(temp,list[i].name);
            strcat(temp,mainstr+pos);
            strcpy(mainstr,temp);
            memset(temp,'\0',sizeof(temp));
        }
    }
}

int find_failfun(int* fail, char *p)
{
    int i,j,len_p;
    len_p=strlen(p);
    fail[0]=0;
    for (j=1;j<len_p;j++)
    {
        i=fail[j-1];
        while (p[j]!=p[i] &&  i!=0)
            i=fail[i-1];
        if (p[j]==p[i])
            fail[j]=i+1;
        else
            fail[j]=0;
    }
    return len_p;
}

void pop(char* mainstr, int* fail,char *p, int plen)
{
    int i=0,j=0,lenstr,pos;
    char temp[MAX_STRING];
    lenstr=strlen(mainstr);
    while (i<lenstr  &&  j<plen)
    {
        if(mainstr[i]==p[j])
        {
            i++;j++;
        }
        else if (j==0)
            i++;
        else
            j=fail[j-1];
    }
    if (j==plen)
    {
        pos=i-j;
        strncpy(temp,mainstr,pos);
        strcat(temp,mainstr+i);
        strcpy(mainstr,temp);
    }
}
