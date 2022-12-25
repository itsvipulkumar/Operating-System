#include<stdio.h>
int main()
{
     int a,b,page_fault=0,pos;
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
     int n=sizeof(pages)/sizeof(pages[0]);

     int nf=3;
     int frame[nf];
     for(int i=0;i<nf;i++)
     frame[i]=-1;

     int temp[nf];

     for(int i=0;i<n;i++)
     {
        a=0;
        b=0;
        for(int j=0;j<nf;j++)
        {
          if(frame[j]==pages[i])
          {
            a=1;
            b=1;
            break;
          }
        }
        if(a==0)
        {
            for(int j=0;j<nf;j++)
            {
                if(frame[j]==-1)
                {
                    frame[j]=pages[i];
                    b=1;
                    page_fault++;
                    break;
                }
            }
        }
        if(b==0)
        {
            for(int j=0;j<nf;j++)
            {
                temp[j]=0;
            }
            for(int k=i-1,l=1;l<=nf-1;l++,k++)
            {
                for(int j=0;j<nf;j++)
                {
                    if(frame[j]==pages[k])
                    {
                        temp[j]=1;
                    }
                }
            }
            for(int j=0;j<nf;j++)
            {
                if(temp[j]==0)
                pos=j;
            }
            frame[pos]=pages[i];
            page_fault++;
        }
     }
     printf("Total page fault : %d",page_fault);
    return 0;
}