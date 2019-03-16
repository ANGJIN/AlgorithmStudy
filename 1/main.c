#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(A,B) tmp=A; A=B; B=tmp
#define decidek(n) (n)/2%2==0 ? (n)/2+1 : (n)/2

int arr[11], i, j, h, n=11, tmp;

void makerandarr(){for(i=0;i<n;i++) arr[i]=rand()%10;}
void printarr(){
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");}

void bubblesort()
{
    printf("Bubble Sort : ");
    for(i=0; i<n-1; i++) //0~8
    {
        for(j=0; j<n-i-1; j++) //0~(8-i)
        {
            if(arr[j]>arr[j+1]){
                SWAP(arr[j],arr[j+1]);}
        }
    }
}

void selectionsort()
{
    printf("Selection Sort : ");
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j]){
                SWAP(arr[i],arr[j]);}
        }
    }
}
void insertionsort()
{
    printf("Insertion Sort : ");
    for(i=1; i<n; i++)
    {
        tmp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>tmp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }
}
void shellsort()
{
    printf("Shell Sort : ");
    int k;
    k=n;
    do //k가 1이될때 까지
    {
        k=decidek(k);
        for(i=0; i<k; i++) //부분 리스트 개수만큼
        {
            for(j=i+k; j<n; j+=k) //각 부분 리스트 삽입정렬
            {
                tmp=arr[j];
                h=j-k;
                while(h>=0 && arr[h]>tmp)
                {
                    arr[h+k]=arr[h];
                    h-=k;
                }
                arr[h+k]=tmp;
            }
        }
    }while(k>1);
}
int arr2[11];
void mergesort(int s, int e)
{
    if(s==e)
    {
        return;
    }
    mergesort(s,(s+e)/2);
    mergesort((s+e)/2+1,e);
    int x=s, y=(s+e)/2+1, z=s;
    while(x<=(s+e)/2 && y<=e)
    {
        if(arr[x]<arr[y])   arr2[z++]=arr[x++];
        else    arr2[z++]=arr[y++];
    }
    while(x<=(s+e)/2)   arr2[z++]=arr[x++];
    while(y<=e) arr2[z++]=arr[y++];
    for(i=s; i<=e; i++) arr[i]=arr2[i];
}

void quicksort(int s, int e)
{
    int pivot=s, x=s+1, y=e;
    while(x<=y)
    {
        while(arr[x]<arr[pivot])    x++;
        while(arr[y]>arr[pivot])    y--;
        if(x<=y){

                SWAP(arr[x],arr[y]);
                x++;
                y--;
        }
    }
    SWAP(arr[pivot],arr[y]);
    pivot=y;
    if(s<pivot) quicksort(s,pivot-1);
    if(e>pivot) quicksort(pivot+1,e);
}

void downheap(int node)
{
    int p;
    while((node*2<=n && arr[node]>arr[node*2]) || (node*2+1<=n && arr[node]>arr[node*2+1]))
    {
        if(node*2+1<=n)
            p = arr[node*2]<arr[node*2+1] ? node*2 : node*2+1;
        else
            p = node*2;
        SWAP(arr[node],arr[p]);
        node=p;
    }
}

void makeheap(int node)
{
    if(node*2 > n) return;  //node that has no child
    makeheap(node*2);
    if(node*2+1<=n) makeheap(node*2+1);
    downheap(node);
}

void printheap()
{
    printf("%d ", arr[1]);
    arr[1]='\0';
    SWAP(arr[1],arr[n]);
    n--;
    downheap(1);
}
int main()
{
    srand(time(NULL));  //rand 함수 시드값을 넣어줌

    makerandarr();
    printarr();
    bubblesort();
    printarr();
    makerandarr();
    printarr();
    selectionsort();
    printarr();
    makerandarr();
    printarr();
    insertionsort();
    printarr();
    makerandarr();
    printarr();
    shellsort();
    printarr();
    makerandarr();
    printarr();
    mergesort(0,n-1);
    printf("Merge Sort : ");
    printarr();
    makerandarr();
    printarr();
    printf("Quick Sort : ");
    quicksort(0,n-1);
    printarr();
    makerandarr();
    printarr();
    n=10;
    makeheap(1);
    printf("Heap Sort : ");
    for(i=0; i<10; i++)  printheap();

    return 0;
}
