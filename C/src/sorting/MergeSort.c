#include<stdio.h>
#define max 10
struct ele
{
 int info;
}ar[max],temp;

int noe,i,j,k,size,end,small,posn,flag;

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

void mrg_srt()
{

 int cnt = 0;
 size = 1;
 do
 {
 size *=2;
 printf("\n");
 for(i=0;i<noe;i+=size)
  {
  end = i+size >= noe ? noe:i+size;
  for(j=i;j<end;j++)
  {
   flag = 0;
   small = ar[j].info;
   for(k=j+1;k<end;k++)
    {
    if(small > ar[k].info)
    {
     small = ar[k].info; posn =k ;  flag = 1;
    }
    }
    if(flag==1)
     {
     temp = ar[j];
     ar[j] = ar[posn];
     ar[posn] = temp;
     }
   }
  }
  printf("\n After Pass %d the array is :",++cnt);
  for(i=0;i<noe;i++)
   printf(" %d",ar[i].info);
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
