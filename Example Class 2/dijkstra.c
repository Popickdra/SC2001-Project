#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 40000

typedef struct pq{
    int vertex;
    int distance;
}pqNode;

typedef struct Dest{
    int vertex;
    int weight;
    struct Dest* next;
}Destination;

typedef struct H{
    Destination* head;
    Destination* tail;
    int size;
}Head;

int size;
long long int comparisons;
int visitedNodes;

int*predecessor;
int*distance;
int*S;

void dijkstra(int**,int,int);
void dijkstraList(Head*,int,int);
void initial(int*,int);
void initialMatrix(int**,int);


void insertPQ(pqNode*,int,int);
int extractMin(pqNode*);
void swap(pqNode*,int,int);

void insertPQ(pqNode *array,int V,int D){
    array[size].vertex=V;
    array[size].distance=D;

    //fixHeap
    int index=++size; //index of last element +1
    while(index>1 && array[index/2-1].distance>array[index-1].distance){
        swap(array,index/2-1,index-1);
        index/=2;
    }
}

int extractMin(pqNode* array){ //Extract min value and fix Heap
    int Extract=array[0].vertex;
    int index=1;
    int minChild=2;
    swap(array,0,--size);

    while(minChild<=size){
        if(index*2<size && array[index*2-1].distance>array[index*2].distance)
            minChild++;
        if(array[index-1].distance<array[minChild-1].distance)
            break;
        
        swap(array,index-1,minChild-1);
        index=minChild;
        minChild=index*2;
    }
    return Extract;
}

void swap(pqNode* array,int index1,int index2){
    pqNode tmp=array[index1];
    array[index1]=array[index2];
    array[index2]=tmp;
}

void Add(Head* adjList,int source,int destination,int w){
    
    Destination* cur=malloc(sizeof(Destination));
    cur->vertex=destination;
    cur->weight=w;
    cur->next=NULL;
    if(adjList[source].size==0)
        adjList[source].head=cur;
    else
        adjList[source].tail->next=cur;
    adjList[source].tail=cur;
    
    adjList[source].size++;
   
}

void dijkstra(int** adjMatrix,int V, int source){
    int i,flag;
    int MinNode,MinDistance;
    distance[source]=0;
    while(visitedNodes!=V){ //while there exists a node that has not been included in S
        for(i=0;i<V;i++){
            comparisons++;
            if(adjMatrix[source][i]>=0 && source!=i)
                if(distance[i]==-1 || distance[i]>distance[source]+adjMatrix[source][i])
                    distance[i]=distance[source]+adjMatrix[source][i];
                    //predecessor[i]=source;
        }
        S[source]=1; //Include the current source node into the set S
        visitedNodes++;
        
        //Extract cheapest node from queue
        MinNode=-1;
        MinDistance=-1;
        flag=0;
        
        for(i=0;i<V;i++){
            comparisons++;
            if(S[i]!=1 && distance[i]!=-1 && (MinDistance==-1 || distance[i] < MinDistance)){
                MinNode = i;
                MinDistance=distance[i];
                flag=1;
            }
        }
        if(flag==0) //If there does not exist a fringe node
            break;
        source=MinNode;
    }
}

void dijkstraList(Head*adjList,int V,int source){
    pqNode* priorityQueue=malloc(sizeof(pqNode)*15000);
    size=0;
    distance[source]=0;
    Destination* cur;
    
Skip:
    while(visitedNodes!=V){
        cur=adjList[source].head;
        while(cur!=NULL){
            if(distance[cur->vertex]==-1 || distance[cur->vertex]>distance[source]+cur->weight){
                distance[cur->vertex]=distance[source]+cur->weight;
                insertPQ(priorityQueue,cur->vertex,distance[cur->vertex]);
            }
            cur=cur->next;
        }
        S[source]=1;
        visitedNodes++;

        while(size!=0){
            source=extractMin(priorityQueue);
            if(S[source]==-1)
                goto Skip;
        }
        break;
    }
}



void initial(int*array,int size){
    int i;
    for(i=0;i<size;i++)
        array[i]=-1;
}

void initialMatrix(int**matrix,int vertices){
    for(int i=0;i<vertices;i++)
        for(int j=0;j<vertices;j++)
            matrix[i][j]=-1;
            
}

void decrease_Key(pqNode *array,int V,int D)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].vertex == V)
        {
            array[i].distance = D;
            while(i>1 && array[i/2-1].distance>array[i-1].distance){
                swap(array,i/2-1,i-1);
                i/=2;
            }   
        }
    }
}

int main() {
    
    srand(time(NULL)); //random seed
    
    int i,j,k; //for iteration
    int vertices;
    int edges;
    
    
    distance=malloc(MAX*sizeof(int));
    S=malloc(MAX*sizeof(int));
    //predecessor=malloc(MAX*sizeof(int));

    Head*adjList=malloc(sizeof(Head)*MAX);
    
    for(i=0;i<MAX;i++){
        adjList[i].head=NULL;
        adjList[i].tail=NULL;
        adjList[i].size=0;
    } //Initialise all the heads;
    
    int** terminalVertices=malloc(sizeof(int*)*MAX);
        for(i=0;i<MAX;i++)
            terminalVertices[i]=calloc(MAX,sizeof(int)); //Hashtable of edges exisiting in adjList
       
        int randomEdge;
       
        for(vertices=500;vertices<=MAX;vertices+=500){ //How many edges to add to a vertex
            for(i=0;i<vertices;i++){
                adjList[i].head=NULL;
                adjList[i].tail=NULL;
                adjList[i].size=0;
            } //Initialise all the heads;
            
            
            for(i=0;i<vertices;i++){
                for(j=0;j<vertices;j++){
                    if(i==j)
                        continue;
                    Add(adjList,i,j,rand()%51); //Generate random weight
                }
            }
            initial(distance,vertices);
            initial(S,vertices);
            visitedNodes=0;
            clock_t begin=clock();
            dijkstraList(adjList,vertices,0);
            clock_t end=clock();
            printf("%lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
        }
    return 0;
    Head*adjList=malloc(sizeof(Head)*MAX);
    
    for(i=0;i<MAX;i++){
        adjList[i].head=NULL;
        adjList[i].tail=NULL;
        adjList[i].size=0;
    } //Initialise all the heads;
    
    int** terminalVertices=malloc(sizeof(int*)*MAX);
        for(i=0;i<MAX;i++)
            terminalVertices[i]=calloc(MAX,sizeof(int)); //Hashtable of edges exisiting in adjList
       
        int randomEdge;
       
        for(vertices=500;vertices<=MAX;vertices+=500){ //How many edges to add to a vertex
            for(i=0;i<vertices;i++){
                adjList[i].head=NULL;
                adjList[i].tail=NULL;
                adjList[i].size=0;
            } //Initialise all the heads;
            
            
            for(i=0;i<vertices;i++){
                for(j=0;j<vertices;j++){
                    if(i==j)
                        continue;
                    Add(adjList,i,j,rand()%51); //Generate random weight
                }
            }
            initial(distance,vertices);
            initial(S,vertices);
            visitedNodes=0;
            clock_t begin=clock();
            dijkstraList(adjList,vertices,0);
            clock_t end=clock();
            printf("%lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
        }
    return 0;
}