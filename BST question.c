#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct
{
    int floor;  /*��m*/
    int count;  /*�ĴX��*/
}Data;
Data lift[MAX];

int main()
{
    int i,n,start,target,rear=-1,front=-1,success=0,up, down;
    int k[MAX],visit[MAX]={0};
    FILE *fin,*fout;
    fin=fopen("6input_3.txt","r");
    fout=fopen("output.txt","w");
    fscanf(fin,"%d %d %d",&n,&start,&target);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&k[i]);

    memset(lift,0,sizeof(lift));
    lift[++rear].floor=start;
    while(rear!=front)
    {
        Data temp;
        temp=lift[++front];  /*�qqueue���X�W�@�ӫ��X����*/
        visit[temp.floor]=1;  /*�N���X�L���Ӽh�Ь�1*/
        up=temp.floor+k[temp.floor];  /*�p��W�U�ӫ᪺�Ӽh��m*/
        down=temp.floor-k[temp.floor];
        if(up==target || down==target)
        {
            success=1;
            fprintf(fout,"%d\n",temp.count+1);
            break;
        }
        if(up>0 && up<=n && !visit[up])
        { /*�W�Ӥ��W�L�Ӽh�d��B�ӼӼh�����Q���X----->�i���\�W��*/
            lift[++rear].floor=up;  /*�N�s��m��Jqueue*/
            lift[rear].count=temp.count+1;  /*���q�誺����+1*/
        }
        if(down>0 && down<=n && !visit[down])
        {
            lift[++rear].floor=down;
            lift[rear].count=temp.count+1;
        }
    }
    if(!success)
        fprintf(fout,"-1\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
