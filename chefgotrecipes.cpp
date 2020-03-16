#include<bits/stdc++.h>
using namespace std;


int init(int *a,int n)
{
    int odd_count=0;
    for(int i=0;i<n;i++)
    {
        bitset<40> b(a[i]);
        int count=b.count();
        if(count%2==1)
            odd_count++;
    }
    return odd_count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {   
        int n,q;
        cin>>n>>q;
        int a[n];
        int p[q];
        int count_p[q]={0};
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<q;i++)
            cin>>p[i];
        int odd_count_a=init(a,n);
        int even_count_a=n-odd_count_a;
        for(int i=0;i<q;i++)
        {
            bitset<40> b(p[i]);
            count_p[i]=b.count();
        }
        int total_odd=0;
        int total_even=0;
        for(int j=0;j<q;j++)
        {  
            if(count_p[j]%2==1)
            {
                total_odd=even_count_a;
                total_even=n-total_odd;
            }
            else
            {
                total_odd=odd_count_a;
                total_even=n-total_odd;
            }
            printf("%d %d\n",total_even,total_odd);
        }
        
    }
    return 0;
}
/*

1
6 1
4 2 15 9 8 8
3
*/