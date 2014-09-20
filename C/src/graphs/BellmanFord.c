#include<stdio.h>
#define max 10
#define INFINITY 1000

char node[max];
int ind[max];

int d[max];
char p[max];
int w[max][max];
char edge[2*max*max][2];

int e_size;
int n_size;
int i,j;

void in_dat()
{
 printf("\n Enter the number of nodes : ");
 scanf("%d",&n_size);
 fflush(stdin);

 for(i=0;i<n_size;i++)
  node[i] = 97+i;

 e_size = 0;

 for(i=0;i<n_size;i++)
 {
  w[i][i] = 0;

  for(j=i+1;j<n_size;j++)
  {
   printf("\n Enter the weight of edge '%c' to '%c': ",97+i,97+j);
   scanf("%d",&w[i][j]);

   if(w[i][j] != 0)
   {
    edge[e_size][0] = 97+i;
    edge[e_size][1] = 97+j;
    e_size++;
   }

   printf("\n Enter the weight of edge '%c' to '%c': ",97+j,97+i);
   scanf("%d",&w[j][i]);
   if(w[j][i] != 0)
   {
    edge[e_size][0] = 97+j;
    edge[e_size][1] = 97+i;
    e_size++;
   }
  }
 }
}

void dis_dat()
{
 printf("\n The Path adjacent matrix \n");
 for(i=0;i<n_size;i++)
  printf("\t%c",97+i);


 for(i=0;i<n_size;i++)
 {
  printf("\n%c",97+i);
  for(j=0;j<n_size;j++)
   printf("\t%d",w[i][j]);
 }
}

void bellford()
{
 char s;
 do
 {
 printf("\n Enter the starting point : ");
 scanf("%c",&s);
 }while(s<97||s>=97+n_size);

 for(i=0;i<n_size;i++)
 {
  d[i] = INFINITY;
  p[i] = ' ';        // NULL here
 }

 int si = s-97;
 d[si] = 0;

 int in=0,min,dd,tp;

 while(in < n_size-1)
 {
  for(i=0;i<e_size;i++)
  {
   if(d[edge[i][1]-97] > d[edge[i][0]-97] + w[edge[i][0]-97][edge[i][1]-97])
   {
     d[edge[i][1]-97] = d[edge[i][0]-97] + w[edge[i][0]-97][edge[i][1]-97];
     p[edge[i][1]-97] = edge[i][0];
   }
  }
  ++in;
 }

 printf("\n ..... The Results ..... \n");
 printf("\n \td\tp");

 for(i=0;i<n_size;i++)
  printf("\n%c\t%d\t%c",node[i],d[i],p[i]);

}

int main()
{
 in_dat();
 dis_dat();
 bellford();
 return 0;
}
