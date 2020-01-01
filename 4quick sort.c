#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void swap(int* ,int*);
void quick_sort(FILE*, int [],int, int, int);

int main()
{
    int array[MAX],array_length=0,i;
    FILE *fin,*fout;
    fin=fopen("4input_2.txt","r");
    fout=fopen("output.txt","w");
    if(fin==NULL)
        printf("Can't find the file.\n");
    while(!feof(fin))
    {
        fscanf(fin,"%d",&array[array_length++]);
    }
    fclose(fin);
    quick_sort(fout,array,0,array_length-1,array_length);
    fclose(fout);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}

void quick_sort(FILE* fout,int arr[], int left, int right, int length)
{
    int pivot,i,j,k;
    if(left<right)
    {
        i=left;
        j=right+1;
        pivot=arr[left];
        do
        {
            do i++; while(arr[i]<pivot);
            do j--; while(arr[j]>pivot);
            if(i<j)
            {
                swap(&arr[i],&arr[j]);
                for(k=0;k<length;k++)
                    fprintf(fout,"%2d ",arr[k]);
                fprintf(fout,"\n");
            }
        }while(i<j);
        if(left!=j)
        {
            swap(&arr[left],&arr[j]);
            for(k=0; k<length; k++)
                fprintf(fout,"%2d ",arr[k]);
            fprintf(fout,"\n");
        }
        quick_sort(fout,arr,left,j-1,length);
        quick_sort(fout,arr,j+1,right,length);
    }
}
