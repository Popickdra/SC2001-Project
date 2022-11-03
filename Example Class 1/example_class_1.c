#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void mergeInsertionSort(int*,int,int,int);
void merge(int*,int,int);
void swap(int,int,int*);
void InsertionSort(int*,int,int);

long int comparisons;
int*tmp;

int main(int argc, const char * argv[]) {
    int i,j;
    int S;
    int*array=calloc(10000000,sizeof(int));
    tmp=malloc(sizeof(int)*10000000);
    
    printf("What is the threshold? ");
    scanf("%d",&S);
    
    srand(time(NULL));
    
    //Altering problem size with respect to S
    for(i=1000;i<=10000000;i+=500000){
        if (i==501000)
            i = 500000;

        for(j=0;j<i;j++)
            array[j]=(rand()%i+1);
        
        comparisons=0;
        clock_t begin=clock();
        mergeInsertionSort(array,0,i-1,S);
        clock_t end=clock();

        printf("Array Size: %d, Runtime: %lf seconds, Key Comparisons: %ld\n",i,(double)(end-begin)/CLOCKS_PER_SEC,comparisons);
    }
    //Altering S with respect to problem size
    /*for(i=0;i<1000000;i++)
        array[i]=(rand()%10000000+1);
    printf("Array Size: 10000000\n");
    for(S=1;S<=50;S++){
        for(i=0;i<10000000;i++)
            array[i]=(rand()%10000000+1);
        comparisons=0;
        clock_t begin=clock();
        mergeInsertionSort(array,0,9999999,S);
        clock_t end=clock();
        printf("Threshold: %d Runtime: %lf seconds, Key Comparisons: %ld\n",S,(double)(end-begin)/CLOCKS_PER_SEC,comparisons);
    }
    return 0;*/
}

void mergeInsertionSort(int* array,int start,int end,int S){
    if (start>=end)
        return;

    if(end-start>S){
        int mid=(start + end)/2;
        mergeInsertionSort(array,start,mid,S);
        mergeInsertionSort(array,mid+1,end,S);
        merge(array,start,end);
    }
    else
        InsertionSort(array,start,end);
}

void merge(int*array,int start,int end){

    int mid=(start+end)/2;
    int i=start,j=mid+1,k=0;
    if(end<=start)
        return;
    while(i<=mid && j<=end){ //while both subarrays are not empty
        comparisons++;
        if(array[i]<=array[j]){
            tmp[k++]=array[i++];
        }
        else
            tmp[k++]=array[j++];
    }
    while(i<=mid) //Fill the array with remaining elements from the non-empty sorted list
        tmp[k++]=array[i++];
    
    while(j<=end)
        tmp[k++]=array[j++];
    
    i=start;
    for(k=0;k<end-start+1;k++)
        array[i++]=tmp[k];
}

void swap(int index1,int index2,int *array){
    int tmp=array[index1];
    array[index1]=array[index2];
    array[index2]=tmp;
}

void InsertionSort(int*array,int start,int end){
    int i,j;
    for(i=start+1;i<=end;i++) //Traverse entries from left to right
        for(j=i;j>start;j--){ //Insert entry into sorted array from right to left
            comparisons++;
            if(array[j]<array[j-1])
                swap(j,j-1,array);
            else break;
        }
}