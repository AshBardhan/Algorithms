#include<stdio.h>
#define max 50

struct elem
{
 int info;
}ar[max],tr[max],item;

int noe,i,ptr,par,ind,left,right;

void inp_dat()
{
 do
 {
 printf("\n\n Enter the no. of elements : ");
 scanf("%d",&noe);
 }while(noe<=0 || noe>=max);
 printf("\n\n Enter the '%d' elements of array in unsorted order : ",noe);
 for(i=1;i<=noe;i++)
  scanf("%d",&ar[i].info);
 printf("\n\n The '%d' elements of array in unsorted order :",noe);
 for(i=1;i<=noe;i++)
  printf(" %d",ar[i].info);
}

void ins_heap(int n)
{
 tr[n] = ar[n];
 if(n != 1)
 {
 ptr = n;
 par = ptr/2;
 while(ptr>1 && tr[par].info < tr[ptr].info)
 {
  item = tr[par];
  tr[par] = tr[ptr];
  tr[ptr] = item;
  ptr = par;
  par = ptr/2;
 }
 }
}

void del_heap(int n)
{
 item = tr[1];
 tr[1] = tr[n];
 tr[n] = item;
 par = 1; left = 2; right = 3;
 ind = 0;
 while(par < n && ind == 0)
 {
  if(tr[left].info > tr[par].info && tr[left].info > tr[right].info && left<n)
  {
  item = tr[left];
  tr[left] = tr[par];
  tr[par] = item;
  par = left;
  }
  else if(tr[right].info > tr[par].info && tr[left].info < tr[right].info  && right<n)
  {
  item = tr[right];
  tr[right] = tr[par];
  tr[par] = item;
  par = right;
  }
  else
   ind = 1;
  left = 2*par;
  right = 2*par+1;
 }
 ar[n] = tr[n];
}

void hp_srt()
{
 for(i=1;i<=noe;i++)
  ins_heap(i);
 i = noe;
 while(i>=1)
 {
 del_heap(i);
 i--;
 }
 printf("\n\n The '%d' elements of array in sorted order :",noe);
 for(i=1;i<=noe;i++)
  printf(" %d",ar[i].info);
}

int main()
{
clrscr();
inp_dat();
hp_srt();
return 0;
}
