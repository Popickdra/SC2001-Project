#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Weight C and n types of objects
//each object has weight w and profit p

int*weight;
int*profit;
int*lookUp;
int**dp;
int n = 3;

int knapsackDynamic(int);
int knapsackRecursive(int);

int main(){
    int C,i,j; //Capacity Weight
    
    
    printf("What is the capacity weight? "); scanf("%d",&C);
    // printf("How many objects are there? "); scanf("%d",&n);
    weight=malloc(n*sizeof(int));
    profit=malloc(n*sizeof(int));
    lookUp=calloc((C+1)*sizeof(int), 0);
    
    for(i=0;i<n;i++) {
        printf("Enter weight of object %d ", i+1);
        scanf("%d",&weight[i]);
    }
    printf("\n");
    for(i=0;i<n;i++) {
        printf("Enter profit of object %d ", i+1);
        scanf("%d",&profit[i]);
    }
    printf("\n");
    
    printf("Max Profit computed from dp: %d\n",knapsackDynamic(C));
    printf("Max Profit computed from recursion: %d\n",knapsackRecursive(C));

    printf("\nLookup table:\n");
    for(i=0;i<=C;i++)
        printf("%d ",lookUp[i]);

    /*printf("\nMatrix dp:\n");

    for (int x=0;x<=n;x++)
    {
        for (int y=0;y<=C;y++)
        {
            printf("%d ",dp[x][y]);
        }
        printf("\n");
    }*/

    return 0;
}

int max(int num1,int num2){
    if(num1>num2)
        return num1;
    return num2;
}
int knapsackDynamic(int C){
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++){
            if (i == 0 || j == 0)
                continue;
            else if(weight[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i][j-weight[i-1]]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][C];*/

    for(int i=0;i<=C;i++){
        for(int j=0;j<n;j++){
            if (weight[j]<=i)
                lookUp[i] = max(lookUp[i], lookUp[i-weight[j]] + profit[j]);
        }
    }
    return lookUp[C];
}

int knapsackRecursive(int C){
    int maxProfit=0;
    for(int i=0;i<n;i++)
        if(weight[i]<=C)
            maxProfit=max(maxProfit,profit[i]+knapsackRecursive(C-weight[i]));
    return maxProfit;
}