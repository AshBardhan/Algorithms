#include<stdio.h>
#include<math.h>
#define max 10

struct ele
{
 int info;
}ar[max],qu[10][max],temp;

int noe,i,j,k,size,end,small,posn,flag;
int front[max],rear[max];

void inp_dat()
{
 do
 {
 printf("\n\n Enter the no. of elements : ");
 scanf("%d",&noe);
 }while(noe<=0 || noe>=max);
 printf("\n\n Enter the '%d' elements of array in unsorted order : ",noe);
 for(i=0;i<noe;i++)
 {
 scanf("%d",&ar[i].info);
 front[i] = rear[i] = 0;
 }
 printf("\n\n The '%d' elements of array in unsorted order :",noe);
 for(i=0;i<noe;i++)
  printf(" %d",ar[i].info);
}

void rdx_srt()
{
  int dig = 1,rem,exp,cnt=0,l,m;
 do
 {
  flag =0; m = 0;
  for(i=0;i<10;i++)
   rear[i] = 0;
  for(i=0;i<noe;i++)
  {
   exp = pow(10,dig-1);
   rem = (ar[i].info/exp) % 10;
   qu[rem][rear[rem]] = ar[i];
   rear[rem]++;
  }
  for(j=0;j<10;j++)
  {
   for(k=0;k<rear[j];k++)
    ar[m++] = qu[j][k];
  }
  printf("\n After Pass %d the array is :",++cnt);
  for(l=0;l<noe-1;l++)
  {
  printf(" %d",ar[l].info);
   if(ar[l].info > ar[l+1].info)
    flag=1;
  }
  printf(" %d",ar[l].info);
  dig+=1;
 }while(flag==1);

 printf("\n\n\n The '%d' elements of array in sorted order :",noe);
 for(i=0;i<noe;i++)
  printf(" %d",ar[i].info);
}

int main()
{
 inp_dat();
 rdx_srt();
 return 0;
}
