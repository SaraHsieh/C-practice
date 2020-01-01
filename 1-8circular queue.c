#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 6

int add(FILE* f,int front,int rear,int num,int *queue)
{  /*加一個值到queue的副函式*/
    if(front==((rear+1)%MAX))
    {
        printf("Queue is full.\n");
        fprintf(f,"Queue is full.\n");
    }
    else
    {
        rear=(rear+1)%MAX;
        queue[rear]=num;
    }
    return rear;
}

int del(FILE* f,int front, int rear, int *queue)
{  /*從queue pop一個值*/
    if (front==rear)
    {
        printf("The queue is empty.\n");
        fprintf(f,"The queue is empty.\n");
    }
    else
    {
        front=(front+1)%MAX;
    }
    return front;
}
int main()
{
    int queue[MAX],rear,front,num,sel,i;
    front=0;
    rear=0;
    FILE *fin;
    FILE *fout;
    fout=fopen("8ouput.txt","w");
    fin=fopen("8input.txt","r");
    printf("Output 1:\n");
    fprintf(fout,"Output 1:\n");
    while(!feof(fin))
    {
        fscanf(fin,"%d",&sel);
        if (sel==1)
        {
            fscanf(fin,"%d",&num);
            rear=add(fout,front,rear,num,queue);
        }
        else if (sel==2)
        {
            front=del(fout,front,rear,queue);
        }
        else
        {
            if(front==rear)
            {
                printf("The queue is empty");
                fprintf(fout,"The queue is empty");
            }

            else
            {
                for(i=(front+1)%MAX;i<=rear;i++)
                {
                    printf("%d ",queue[i]);
                    fprintf(fout,"%d ",queue[i]);
                }
            }
            printf("\n");
            fprintf(fout,"\n");
        }
    }
    fclose(fin);

    printf("\nOutput 2:\n");
    fprintf(fout,"\nOutput 2:\n");
    rear=0;
    front=0;
    fin=fopen("8input-2.txt","r");
    while(!feof(fin))
    {
        fscanf(fin,"%d",&sel);
        if (sel==1)
        {
            fscanf(fin,"%d",&num);
            rear=add(fout,front,rear,num,queue);
        }
        else if (sel==2)
        {
            front=del(fout,front,rear,queue);
        }
        else
        {
            if(front==rear)
            {
                printf("The queue is empty");
                fprintf(fout,"The queue is empty");
            }

            else
            {
                for(i=(front+1)%MAX;i<=rear;i++)
                {
                    printf("%d ",queue[i]);
                    fprintf(fout,"%d ",queue[i]);
                }
            }
            printf("\n");fprintf(fout,"\n");
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
