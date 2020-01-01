#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct node *nodeptr;
typedef struct node
{
    char name[10];
    nodeptr link;
}node;

void kill(FILE* f, nodeptr head, int skip)
{
    int i;
    nodeptr bye,pre;
    while (head->link!=head)
    {
        bye=head;
        for (i=1;i<skip;i++)
        {
            pre=bye;
            bye=bye->link;
            printf("%s is killed.\n",bye->name);
            fprintf(f,"%s is killed.\n",bye->name);
        }
        pre->link=bye->link;
        head=pre->link;
    }
    if(head->link=head)
    {
        printf("%s is survived.",head->name);
        fprintf(f,"%s is survived.",head->name);
    }

}

int main()
{
    FILE *fin,*fout;
    int skip;
    fin=fopen("16input.txt","r");
    fout=fopen("16output.txt","w");
    nodeptr first,pre,now;
    first=malloc(sizeof(node));
    fscanf(fin,"%[a-zA-Z]",first->name);
    pre=first;//printf("%s is appended\n",first->name);
    while (!feof(fin))
    {
        now=malloc(sizeof(node));
        fscanf(fin,"%*c%[a-zA-Z]",now->name);
        pre->link=now;//printf("%s is appended\n",now->name);
        pre = now;    /*move the pointer to the next position*/
        fscanf(fin," %d",&skip);
    }
    pre->link=first;
    fclose(fin);
    kill(fout,first,skip);
    fclose(fout);
}
