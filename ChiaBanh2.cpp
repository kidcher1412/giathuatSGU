#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#define pi acos(-1.0)
using namespace std;
 
const int maxn = 10005;
int r;
double v[maxn];
int n,f;
 
bool check(double x)
{
    int cnt = 0;
    int t = lower_bound(v,v + n,x) - v;
    for(int i = t;i < n;i ++)
    {
        cnt += (int)(v[i] / x);
    }
    if(cnt >= f+1)return true;
    else return false;
}
 
double binarySearch(double left,double right)
{
    double ans;
    double l = left,r = right;
    while(l + 1e-7 < r)
    {
        double mid = (l + r) / 2;
        if(check(mid))
        {
            ans = mid;
            l = mid;
        }
        else r = mid;
    }
    return ans;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double left = 0.0,right = 0.0;
        scanf("%d%d",&n,&f);
        for(int i = 0;i < n;i ++)
            {
                scanf("%d",&r);
                v[i] = pi * r * r * 1;
                right += v[i];
            }
            right /= (f+1);
        if(n == 1)printf("%.4lf\n",v[0] / (f + 1));
        else {
            sort(v,v + n);
            printf("%.4lf\n",binarySearch(left,right));
        }
    }
    return 0;
}