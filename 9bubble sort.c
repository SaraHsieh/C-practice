#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int arr[MAX]={0},i,j,temp,n;
    FILE *fin,*fout;
    fin=fopen("9input_2.txt","r");
    fout=fopen("output.txt","w");
    n=0;
    while(!feof(fin))
    {
        fscanf(fin," %d",&arr[n]);
        n++;
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        for(j=0;j<n;j++)
            fprintf(fout,"%d ",arr[j]);
        fprintf(fout,"\n");

    }
    fclose(fin);
    fclose(fout);
    return 0;
}
