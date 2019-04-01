#include <stdio.h>
#include <algorithm>
#define max (1<<30)-1
struct data{
  int x,y,w;
}arr[200];

int idx[100], n, e;
int dst[100], visit[100];

inline bool cmp(const data a, const data b)
{
  return a.x<b.x || (a.x==b.x && a.y<b.y);
}

int main()
{
  FILE *in= fopen("input.txt","r");
  fscanf(in,"%d %d\n", &n, &e);
  for(int i=0; i<e; i++)
  {
    char t1,t2;
    int v;
    fscanf(in,"%c %c %d\n",&t1,&t2,&v);
    t1-='A';t2-='A';
    arr[i].w=v; arr[i+e].w=v;
    arr[i].x=t1;arr[i].y=t2;
    arr[i+e].x=t2;arr[i+e].y=t1;
  }
  char t1, t2;
  fscanf(in,"%c %c", &t1, &t2);
  int st= t1-'A', ed= t2-'A';
  std::sort(arr,arr+e*2,cmp);
  int i;
  idx[arr[0].x]=0;
  for(i=1; i<e*2; i++)
    if(arr[i].x!=arr[i-1].x) idx[arr[i].x]=i;
  idx[arr[i-1].x+1]=i;
  for(i=0; i<n; i++) dst[i]=max;
  dst[st]=0;
  for(int j=0; j<n; j++)
  {
    int min=max, searchv;
    for(i=0; i<n; i++)
    {
      if(!visit[i] && dst[i]<min)
      {
        min=dst[i];
        searchv=i;
      }
    }
    visit[searchv]=1;
    for(i=idx[searchv]; i<idx[searchv+1]; i++)
    {
      int nextv=arr[i].y;
      int len=arr[i].w;
      if(dst[nextv]>dst[searchv]+len)
        dst[nextv]=dst[searchv]+len;
    }
  }
  printf("%d\n", dst[ed]);
  return 0;
}
