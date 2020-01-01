#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct
{
    int floor;  /*位置*/
    int count;  /*第幾次*/
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
        temp=lift[++front];  /*從queue取出上一個拜訪的值*/
        visit[temp.floor]=1;  /*將拜訪過的樓層標為1*/
        up=temp.floor+k[temp.floor];  /*計算上下樓後的樓層位置*/
        down=temp.floor-k[temp.floor];
        if(up==target || down==target)
        {
            success=1;
            fprintf(fout,"%d\n",temp.count+1);
            break;
        }
        if(up>0 && up<=n && !visit[up])
        { /*上樓不超過樓層範圍且該樓層不曾被拜訪----->可成功上樓*/
            lift[++rear].floor=up;  /*將新位置放入queue*/
            lift[rear].count=temp.count+1;  /*坐電梯的次數+1*/
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
