#include <stdio.h>
#define MAX 100

int main()
{
    int size, map[MAX][MAX]={{0}};
    int i,j,out[MAX]={0},in[MAX]={0};
    FILE *fin, *fout;
    fin=fopen("2input_1.txt","r");
    fout=fopen("output.txt","w");
    fscanf(fin,"%d",&size);

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            fscanf(fin,"%d",&map[i][j]);
            if(map[i][j])
            {
                out[i]++;
                in[j]++;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        fprintf(fout,"%d %d %d\n",i+1,in[i],out[i]);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
