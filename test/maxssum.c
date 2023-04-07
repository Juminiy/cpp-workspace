#include<stdio.h>
int n,j,sum,maxx;int main(){scanf("%d%d",&n,&maxx);sum=maxx;while(--n){scanf("%d",&j);sum=sum>0?sum:0;sum+=j;maxx=maxx>sum?maxx:sum;}return (printf("%d",maxx))&0;}