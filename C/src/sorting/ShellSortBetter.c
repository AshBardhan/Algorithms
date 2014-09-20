#include<stdio.h>
#define max 10
struct ele
{
 int info;
}ar[max],temp;

int noe,i,j,k,size,small,posn,flag;

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

void shl_srt()
{

 int cnt = 0;
 size = noe/2;
 do
 {
 printf("\n (Size = %d)",size);
 for(i=size;i<noe;i++)
 {
  temp = ar[i];
  j = i;
  while(ar[j-size].info>temp.info && j>=0)
  {
   ar[j] = ar[j-size];
   j -= size;
  }
  ar[j] = temp;
 }
  printf("\n After Pass %d the array is :",++cnt);
  for(i=0;i<noe;i++)
   printf(" %d",ar[i].info);
  size /= 2;
 }while(size>=1);
 printf("\n\n\n The '%d' elements of array in sorted order :",noe);
 for(i=0;i<noe;i++)
  printf(" %d",ar[i].info);
}

int main()
{
 inp_dat();
 shl_srt();
 return 0;
}