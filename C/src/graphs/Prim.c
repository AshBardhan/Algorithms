#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 9
#define INFINITY 1000

struct edge
{
  char u;
  char v;
  int wuv;
  int ind;
  int tind;
}ed[max*max],tmp;


int ind[max];
int size;
int i,j,noe;

void inp_dat()
{
 int cho;
 size = 0;
 printf("\n Enter the number of nodes : ");
 scanf("%d",&noe);
 fflush(stdin);

 for(i=0;i<noe-1;i++)
 {
  for(j=i+1;j<noe;j++)
  {
   printf("\n Enter weightage for edge '%c%c' : ",97+i,97+j);
   scanf("%d",&cho);
   fflush(stdin);
   if(cho != 0)
   {
    ed[size].wuv = cho;   ed[size].u = 97+i;
    ed[size].v = 97+j;    ed[size].ind = 0;
    ed[size].tind = 0;    ++size;
   }
  }
}
}

void sort_dat()
{
 for(i=0;i<size;i++)
 {
  for(j=0;j<size-i-1;j++)
  {
   if(ed[j].wuv > ed[j+1].wuv)
   {
    tmp = ed[j];
    ed[j] = ed[j+1];
    ed[j+1] = tmp;
   }
  }
 }
}

void disp_dat()
{
 for(i=0;i<size;i++)
  printf("\n Edge '%c%c' weight : %d ",ed[i].u,ed[i].v,ed[i].wuv);
}

void prim()
{
 char stack[max];
 int ss;
 int ret;
 char tmp;
 char dest;
 char src;

 char set[max];
 int sts;
 int min;
 int pos;
 char end;

 printf("\n Enter the starting point : ");
 scanf("%c",&src);
 set[0] = src;
 sts = 1;

 do
 {
  min = INFINITY;
  for(i=0;i<sts;i++)
  {
   for(j=0;j<size;j++)
   {
    if(set[i] == ed[j].u && ed[j].ind == 0)// && ed[j].tind == 0)
    {
     if(min > ed[j].wuv)
     {
      stack[0] = ed[j].u;      dest = ed[j].v;
      ss = 1;        ret = 0;
      int k;
      for(k=0;k<size;k++)
          ed[k].tind = 0;
      do
      {
       --ss;
       tmp = stack[ss];
       int l;
       for(l=0;l<size;l++)
       {
  if(ed[l].ind == 1 && ed[l].tind == 0 && l!= j)
  {
   if(tmp == ed[l].u)
   {
    ed[l].tind = 1;
    if(dest == ed[l].v)
    {
     ret = 1;     break;
    }
    else
    {
    stack[ss] = ed[l].v;   ++ss;
    }
   }
   if(tmp == ed[l].v)
   {
    if(dest == ed[l].u)
    {
    ret = 1;    break;
    }
    else
    {
    stack[ss] = ed[l].u;    ++ss;
    }
   }
  }
 if(ret == 1)
  break;
       }
      }while(ss !=0 && ret == 0);

      if(ret == 0)
      {
       min = ed[j].wuv;       end = ed[j].v;
       pos = j;
      }
    }
    }

    if(set[i] == ed[j].v && ed[j].ind == 0)// && ed[j].tind == 0)
    {
     if(min > ed[j].wuv)
     {
      stack[0] = ed[j].v;      dest = ed[j].u;
      ss = 1;        ret = 0;
      int k;
      for(k=0;k<size;k++)
     ed[k].tind = 0;
      do
      {
       --ss;
       tmp = stack[ss];
       int l;
       for(l=0;l<size;l++)
       {
    if(ed[l].ind == 1 && ed[l].tind == 0 && l!= j)
    {
   if(tmp == ed[l].u)
   {
    ed[l].tind = 1;
    if(dest == ed[l].v)
    {
     ret = 1;     break;
    }
    else
    {
    stack[ss] = ed[l].v;    ++ss;
    }
   }
   if(tmp == ed[l].v)
   {
    if(dest == ed[l].u)
    {
    ret = 1;    break;
    }
    else
    {
    stack[ss] = ed[l].u;    ++ss;
    }
   }
  }

 if(ret == 1)
  break;
       }
      }while(ss !=0 && ret == 0);



      if(ret == 0)
      {
       min = ed[j].wuv;       end = ed[j].u;
       pos = j;
      }
    }
   }
 }
 }
  set[sts] = end;
  ed[pos].ind = 1;
  ++sts;

 }while(sts != noe);

 printf("\n\n The Minimum Spanning Tree \n\n");
 int k;
 for(k=0;k<size;k++)
 {
  if(ed[k].ind == 1)
   printf("\n Edge '%c%c' weight : %d ",ed[k].u,ed[k].v,ed[k].wuv);
 }
 getch();
}

int main()
{
 inp_dat();
 printf("\n.. Before Prim ..\n");
 disp_dat();
 printf("\n.. After Prim  ..\n");
 prim();
 return 0;
}
