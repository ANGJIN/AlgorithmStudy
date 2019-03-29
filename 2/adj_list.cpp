#include <stdio.h>
#include <algorithm>

struct data
{
  int x,y;
}arr[201];
//compare function(struct sorting)
inline bool cmp(const data a, const data b)
{
  return a.x< b.x || (a.x==b.x && a.y< b.y);
}
int n, e;
int idx[28];//start index of n vertex data in arr
int visit[27];
//Depth First Search
void dfs(int vertex)
{
  visit[vertex]=1; //check visit
  printf("%d",vertex); //print current vertex
  for(int i=idx[vertex]; i<idx[vertex+1]; i++)
  {
    int nextv=arr[i].y;
    if(!visit[nextv])
      dfs(nextv);
  }
}
int queue[27]; //queue used for BFS
void bfs(int start)
{
  int top=0; //pointing index of next push
  int searchidx, searchv;
  queue[top++]=start; //push first vertex
  visit[start]=1; //check visit
  searchidx=0;
  while(searchidx<top)
  {
    searchv=queue[searchidx];
    for(int i=idx[searchv]; i<idx[searchv+1]; i++) //visit all connected vertex in current searching vertex
    {
      int nextv=arr[i].y;
      if(!visit[nextv])
      {
        visit[nextv]=1;
        queue[top++]=nextv;
      }
    }
    searchidx++;
  }
  for(int i=0; i<top; i++)
    printf("%d", queue[i]);
  putchar('\n');
}
int main()
{
  //get input, make adjacent list
  FILE* in=fopen("input.txt","r");
  fscanf(in,"%d %d", &n, &e);
  int t1,t2;
  int i;
  for(i=0; i<e; i++)
  {
    fscanf(in,"%d %d", &t1, &t2);
    arr[i].x=t1,arr[i].y=t2;
    arr[i+e].x=t2,arr[i+e].y=t1;
  }
  std::sort(arr,arr+(e*2),cmp);
  idx[arr[0].x]=0;
  for(i=1; i<e*2; i++)
  {
    if(arr[i].x!=arr[i-1].x)
      idx[arr[i].x]=i;
  }
  idx[arr[i-1].x+1]=i;
  int st;
  fscanf(in,"%d", &st);
  //do DFS
  dfs(st);
  putchar('\n');
  for(i=0;i<=n; i++) visit[i]=0;
  //do BFS
  bfs(st);
  return 0;
}
