#include <bits/stdc++.h>
using namespace std;
#define      M    1000000007
#define      hM   9999999900000001
// #define      int long long int
#define      vi vector<int>
#define      vvi vector<vi>
#define      vpi vector<pair<int,int>>
#define      pii pair<int,int>
#define      pb push_back
#define      inf 1e18
#define      ff first
#define      ss  second
#define      line  "\n"
#define      deb(x) cout<<#x<<" "<<x<<endl;
#define      all(x) x.begin(),x.end()
#define      printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
const int N = 1e5 + 10;

//int BIT[N];
//void add(int x, int val) {while (x < N)BIT[x] += val, x += x & -x;}
//int sum(int x) {return x ? BIT[x] + sum(x - (x & -x)) : 0;}


void runcases(int T)
{

  int n, x;
  cin >> n >> x;
  vvi v(n, vi(2));
  for (int i = 0; i < n; i++) {
    cin >> v[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i][1];
  }
  // for (int i = 0; i < n; i++)
  // {
  //   cout << v[i][0] << " " << v[i][1] << endl;
  // }
  int dp[2][x + 1];
  int ans = 0;
  memset(dp, 0, sizeof(dp));
  int f = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      dp[f][j] = dp[1 - f][j];
      if (j >= v[i - 1][0])
        dp[f][j] = max(dp[f][j], v[i - 1][1] + dp[1 - f][j - v[i - 1][0]]);

      ans = max(ans, dp[f][j]);
    }
    f = 1 - f;
  }
  cout << ans << endl;



  //cout << "Case #" << T << ": ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  // freopen("inputf.txt", "r", stdin);
  // freopen("outputf.txt", "w", stdout);
#endif
  int T = 1;
  //cin >> T;
  for (int t = 1; t <= T; t++) {
    runcases(t);
  }

  return 0;
}

