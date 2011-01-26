#include<stdio.h>
#define NUM 8 /*.......*/
int a[NUM+1];
int main()
{
    int i,k,flag,not_finish=1,count=0;
    i=1; /*.............i-1..............i...*/
    a[1]=1; /*............*/
    printf("The possible configuration of 8 queens are:\n");
    while(not_finish) /*not_finish=1:......*/
    {
        while(not_finish&&i<=NUM) /*.............NUM...*/
        {
            for(flag=1,k=1;flag&&k<i;k++) /*.............*/
                if(a[k]==a[i])flag=0;
            for(k=1;flag&&k<i;k++) /*...............*/
                if((a[i]==a[k]-(k-i))||(a[i]==a[k]+(k-i))) flag=0;
            if(!flag) /*..................i...*/
            {
                if(a[i]==a[i-1]) /*.a[i]..........a[i-1]..*/
                {
                    i--; /*................*/
                    if(i>1&&a[i]==NUM)
                        a[i]=1; /*.a[i].NUM..a[i]...1*/
                    else if(i==1&&a[i]==NUM)
                        not_finish=0; /*........NUM...*/
                    else a[i]++; /*.a[i].......*/
                }
                else if(a[i]==NUM) a[i]=1;
                else a[i]++; /*.a[i].......*/
            }
            else if(++i<=NUM)
                if(a[i-1]==NUM) a[i]=1; /*.........NUM.a[i]=1*/
                else a[i]=a[i-1]+1; /*.................*/
        }
        if(not_finish)
        {
            ++count;
            printf((count-1)%3?" [%2d]: ":" \n[%2d]: ",count);
            for(k=1;k<=NUM;k++) /*....*/
                printf(" %d",a[k]);
            if(a[NUM-1]<NUM) a[NUM-1]++; /*.........*/
            else a[NUM-1]=1;
            i=NUM-1; /*............*/
        }
    }
}
