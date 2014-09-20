#include<stdio.h>
#define max 10

struct ele
{
 int info;
}ar[max],A[max],B[max],C[max];

int noe,i,j,k,size,mgsize,end,small,posn,flag,na,nb,nc;

void inp_dat()
{
 do
 {
 printf("\n\n Enter the no. of elements : ");
 scanf("%d",&noe);
 }while(noe<=0 || noe>=max);
 printf("\n\n Enter the '%d' elements of array in unsorted order : ",noe);
 for(i=0;i<noe;i++)
  scanf("%d",&ar[i].info);
 printf("\n\n The '%d' elements of array in unsorted order :",noe);
 for(i=0;i<noe;i++)
  printf(" %d",ar[i].info);
}

void merge()
{
 int a,b;
 for(a=0,b=0;a<na && b<nb;)
 {
  if(A[a].info <= B[b].info)
   C[nc++] = A[a++];
  else
   C[nc++] = B[b++];
 }
 while(a<na)
  C[nc++] = A[a++];
 while(b<nb)
  C[nc++] = B[b++];
}

void mrg_srt()
{
 int cnt = 0;
 size = 1;
 do
 {
 mgsize = size*2;
 for(i=0;i<noe;i+=mgsize)
  {
  end = i+mgsize >= noe ? noe:i+mgsize;
  na = nb = nc = 0;
  for(j=i;j<i+size;j++)
   A[na++] = ar[j];
  for(;j<end;j++)
   B[nb++] = ar[j];
  merge();
  for(j=0,k=i;j<nc;j++)
   ar[k++] = C[j];
  }
  printf("\n After Pass %d the array is :",++cnt);
  for(i=0;i<noe;i++)
   printf(" %d",ar[i].info);
  size = mgsize;
 }while(size<noe);
 printf("\n\n\n The '%d' elements of array in sorted order :",noe);
 for(i=0;i<noe;i++)
  printf(" %d",ar[i].info);

}

int main()
{
 inp_dat();
 mrg_srt();
 return 0;
}
