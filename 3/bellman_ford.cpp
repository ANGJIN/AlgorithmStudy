#include <stdio.h>
#include <algorithm>
#define max (1<<30)-1

struct data{
  int x, y, w;
}arr[200];

int n, e, i, j, dst[100];

int main()
{
  FILE *in= fopen("input.txt","r");
  fscanf(in,"%d %d\n", &n, &e);
  for(i=0; i<e; i++)
  {
    int v;
    char t1,t2;
    fscanf(in,"%c %c %d\n", &t1, &t2, &v);
    arr[i].x=t1-'A';
    arr[i].y=t2-'A';
    arr[i].w=v;
  }
  char t1, t2;
  fscanf(in,"%c %c", &t1, &t2);
  int st,ed;
  st=t1-'A';
  ed=t2-'A';
  for(i=0; i<n; i++)
  {
    if(i==st) dst[i]=0;
    else dst[i]=max;
  }
  for(i=1; i<=n-1; i++)
  {
    for(j=0;j<e; j++)
    {
      if(dst[arr[j].y]>dst[arr[j].x]+arr[j].w)
        dst[arr[j].y]=dst[arr[j].x]+arr[j].w;
    }
  }
  printf("%d\n",dst[ed]);
  return 0;
}
