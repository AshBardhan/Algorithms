#include<stdio.h>
#define max 50
struct ele
{
 int info;
}ar[max],stup[max],stlw[max],tmp;


int noe,i,beg,last,top,loc,left,right;


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


void quick(int &beg,int &last,int &loc)
{
 left = beg;
 right = last;
 loc = beg;
 while(loc != right || loc !=left)
 {
  while(ar[loc].info <= ar[right].info && right != loc)
    right -= 1;
  if(ar[loc].info > ar[right].info)
  {
   tmp = ar[loc];
   ar[loc] = ar[right];
   ar[right] = tmp;
   loc = right;
  }
  while(ar[loc].info >= ar[left].info && left != loc)
    left += 1;
  if(ar[loc].info < ar[left].info)
  {
   tmp = ar[loc];
   ar[loc] = ar[left];
   ar[left] = tmp;
   loc = left;
  }
 }
}


void qk_srt()
{
top = 0;
stlw[top].info = 0;   stup[top].info = noe-1;
while(top != -1)
{
 beg = stlw[top].info;
 last = stup[top].info;
 top = top-1;
 quick(beg,last,loc);
 if(beg < loc-1)
 {
 top = top+1;
 stlw[top].info = beg;   stup[top].info = loc-1;
 }
 if(loc+1 < last)
 {
 top = top+1;
 stlw[top].info = loc+1;   stup[top].info = last;
 }
}
 printf("\n\n The '%d' elements of array in sorted order :",noe);
 for(i=0;i<noe;i++)
  printf(" %d",ar[i].info);
}


int main()
{
inp_dat();
qk_srt();
return 0;
}
