#include<stdio.h>
#include<conio.h>
#define max 10
#define INFINITY 1000

int w[max+1][max+1];
int n_size;

int d[max+1][max+1][max+1];
int pi[max+1][max+1][max+1];

void in_dat()
{
 printf("\n Enter the number of nodes : ");
 scanf("%d",&n_size);

 int i,j;

 for(i=1;i<=n_size;i++)
 {
  w[i][i] = 0;
  d[0][i][i] = 0;
  pi[0][i][i] = 0;

  for(j=i+1;j<=n_size;j++)
  {
   printf("\n Enter the weight of edge '%d' to '%d': ",i,j);
   scanf("%d",&w[i][j]);
   if(w[i][j] == 0)
    w[i][j] = INFINITY;

   d[0][i][j] = w[i][j];
   pi[0][i][j] = w[i][j] == INFINITY ? 0:i;

   printf("\n Enter the weight of edge '%d' to '%d': ",j,i);
   scanf("%d",&w[j][i]);
   if(w[j][i] == 0)
    w[j][i] = INFINITY;

   d[0][j][i] = w[j][i];
   pi[0][j][i] = w[j][i] == INFINITY ? 0:j;
  }
 }
}

void flyd_wrsl()
{
 int i,j,k,m;

 printf("\n\n\t D(0)/Pi(0)");

 for(i=1;i<=n_size;i++)
 {
  printf("\n");
  for(j=1;j<=n_size;j++)
  {
   if(d[0][i][j] == INFINITY)
    printf("\t*");



   else
    printf("\t%d",d[0][i][j]);
   printf("/%d",pi[0][i][j]);
  }
 }

 getch();

 for(k=1;k<=n_size;k++)
 {
  printf("\n\n\t D(%d)/Pi(%d)",k,k);
  for(i=1;i<=n_size;i++)
  {
   printf("\n");

   for(j=1;j<=n_size;j++)
   {
    if(d[k-1][i][j] > d[k-1][i][k] + d[k-1][k][j])
    {
     pi[k][i][j] = pi[k-1][k][j];
     if(d[k-1][i][k] != INFINITY && d[k-1][k][j] != INFINITY)
      d[k][i][j] = d[k-1][i][k] + d[k-1][k][j];
     else
      d[k][i][j] = d[k-1][i][j];
    }

    else
    {
     pi[k][i][j] = pi[k-1][i][j];
     d[k][i][j] = d[k-1][i][j];
    }

    if(d[k][i][j] == INFINITY)
     printf("\t*");
    else
     printf("\t%d",d[k][i][j]);
    printf("/%d",pi[k][i][j]);
   }
  }
  getch();

 }
}

int main()
{
 in_dat();
 flyd_wrsl();
 getch();
 return 0;
}
