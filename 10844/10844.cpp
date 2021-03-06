//
//  10844.cpp
//  example
//
//  Created by hwangyunho on 2017. 8. 25..
//  Copyright © 2017년 hwangyunho. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[101][10];
long long mod = 1000000000, ans=0;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=9;i++)
        dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==0)
                dp[i][0]=dp[i-1][1];
            else if(j==9)
                dp[i][9]=dp[i-1][8];
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            dp[i][j]%=mod;
        }
    }
    for(int i=0;i<=9;i++)
        ans+=dp[n][i];
    ans%=mod;
    cout<<ans<<"\n";
    return 0;
}
