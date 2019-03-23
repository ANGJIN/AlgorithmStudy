#include <stdio.h>
#include <string.h>
//adjacent array  , visited  , number of nodes, number of lines
int adjarray[30][30], v[30], n, e;

//start depth first search in parameter(int node)
void dfs(int node)
{
  printf("%d", node); //print current ndoe
  v[node]=1; //check visit
  for(int i=0; i<=n; i++)
  {
    if(i!=node && adjarray[node][i]==1 && !v[i]) //not node itself, connected, not visited
      dfs(i); //start searching from this node
  }
}

//queue is used for breadth first search
int queue[30];
//start breadth first search in parameter(int start)
void bfs(int start)
{
  int top=0; //containing queue's next filling index
  v[start]=1; //check visit
  queue[top++]=start; //push starting node into queue
  int cur_searching, node;
  cur_searching=0; //bfs start from [0] index of queue
  while( (node=queue[cur_searching++]) ) //stop searching if node is 0(no node remains to search) 
  {
    for(int i=0; i<=n; i++)
    {
      if(i!=node && adjarray[node][i]==1 && !v[i]) //not node itself, connected, not visited
      {
        v[i]=1; //check visit
        queue[top++]=i; //push queue
      }
    }
  }
  //print result data of queue
  for(int i=0; i<n; i++)  printf("%d", queue[i]);
  putchar('\n');
}
int main()
{
  FILE*in=fopen("input.txt","r");
  fscanf(in,"%d %d", &n, &e);
  for(int i=0; i<e; i++)  //get input, make adjacent array
  {
    int a, b;
    fscanf(in,"%d %d", &a, &b);
    adjarray[a][b]=adjarray[b][a]=1;
  }
  int start;
  fscanf(in,"%d", &start); //get starting number of node

  dfs(start);
  putchar('\n');
  memset(v,0,sizeof(v));  //reset visit data
  bfs(start);
  return 0;
}
