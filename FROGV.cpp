#include<algorithm>
#include<stdio.h>
using namespace std;
long Bin_search(long arr[],long num,long lim)
{
    long beg=0,mid,end=lim;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(arr[mid]==num)
        {
            break;
        }
        else if(arr[mid]>num)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    return mid;
}
int main()
{
    long N,K,P;
    long coord[100001],temp[100001];
    scanf("%ld%ld%ld",&N,&K,&P);
    for(long i = 0 ; i < N ; i++)
    {
        scanf("%ld",&coord[i]);
        temp[i]=coord[i];
    }
    sort(temp,temp+N);
    while(P--)
    {
        long A,B;
        bool flag=true;
        scanf("%ld%ld",&A,&B);
        long var;
        if(B<A)
        {
            var=A;
            A=B;
            B=var;
        }
        A--;
        B--;
        long start=Bin_search(temp,coord[A],N-1);
        long end=Bin_search(temp,coord[B],N-1);
        for(long i = start+1; i<=end; i++)
        {
            if(temp[i]-temp[i-1]>K)
            {
                flag=false;
                break;
            }
        }
        if(flag||start==end)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
