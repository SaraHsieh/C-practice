#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct
{
    int floor;  /*竚*/
    int count;  /*材碭Ω*/
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
        temp=lift[++front];  /*眖queue砐*/
        visit[temp.floor]=1;  /*盢砐筁加糷夹1*/
        up=temp.floor+k[temp.floor];  /*璸衡加加糷竚*/
        down=temp.floor-k[temp.floor];
        if(up==target || down==target)
        {
            success=1;
            fprintf(fout,"%d\n",temp.count+1);
            break;
        }
        if(up>0 && up<=n && !visit[up])
        { /*加ぃ禬筁加糷絛瞅赣加糷ぃ纯砆砐----->Θ加*/
            lift[++rear].floor=up;  /*盢穝竚queue*/
            lift[rear].count=temp.count+1;  /*Г筿辫Ω计+1*/
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
