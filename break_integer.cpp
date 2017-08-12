/*
Given a positive integer n, break it into the sum of at least two positive

integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/

/*this question can be solved using both recursion and tabulation dp,i have solved this question using recursion,

                        consider a state,   f(x,y),x is integer to be broken,
                                and y is the number of smaller integrs it is broken into.

                               ex:           f(3,0)
                                        /-1    |-2    \-3
                                    f(2,1) f(1,1)    f(0,1)
                                    /  \     ..          ..
                                f(1,2) f(0,2)

        ...for(int i=1;i<=x;i++){
            ans=max(ans,i*f(x-i,min(2,y+1)));
        }...in this part of code, we are getting max result by
                    either breaking number x  into 1+(x-1)or 2+(x-2) or so on..

                    also,value of y is <=2,i.e.,if x is breaking into less than 2 integers then
                        we can't consider that as an answer.
*/



#include <bits/stdc++.h>
using namespace std;
int dp[100][3],n;
int f(int x,int y){
        if(x==0)
        {
            if(y==2)
                return 1;
            else
                return 0;
        }
        if(dp[x][y]!=-1)
            return dp[x][y];
        int ans=0;
        for(int i=1;i<=x;i++){
            ans=max(ans,i*f(x-i,min(2,y+1)));
        }
        return dp[x][y]=ans;

    }
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<f(n,0);
}
