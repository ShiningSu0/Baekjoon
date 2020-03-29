#include<iostream>
#include<string>
using namespace std;
int dp[100010][3] = { { 0 } };
int main()
{
    int n;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    cin >> n;
    for (int i = 2; i <= n + 1; i++)
    {

        cout << "i : " << i << endl;
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        cout << "1 :"<<dp[i][0]<<endl;

        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        cout << "2  : " << dp[i][0]<<endl;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
        cout << "3 :" <<dp[i][0]<<endl;

    }
    cout << "!!! "<<dp[n + 1][0];
    return 0;
}