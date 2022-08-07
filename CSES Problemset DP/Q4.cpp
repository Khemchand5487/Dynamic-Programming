/*
Title: Coin Combinations II
Link: https://cses.fi/problemset/task/1636/
Complexity: Time - O(n*x); Space - O(n*x) 
where, 
        n: number of coins
        x: target sum
*/

/** Solution By khemchand5487 **/

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define debug(x) cout << #x <<" "; _print(x); cout << endl;

typedef long long ll;

//for debugging
template <class T>
void _print(T t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}" << endl;}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T, class V> void _print(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]" << endl;}
//END

//reading input 
template<typename... T>
void input(T&... args) {(((cin>>args), ...));}

//writing output
template<typename... T>
void output(T... args) {(((cout<<args<<" "), ...));  cout<<endl;}

//input an array
template<typename T>
void inputArray(vector<T>& arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) cin>>arr[i];
}

// for finding mod with 10^9 + 7
int mod(int a)
{
    int m = 1000000007;
    return (a % m + m) % m;
}

////////solution goes here////////
void solve()
{
    int n, x;
    cin>>n>>x;
    int dp[n][x+1];
    vector<int> c(n);
    inputArray(c);
    
    for(int i=0;i<n;i++) dp[i][0] = 1;
    
    for(int i=0;i<n;i++) {
        for(int j=1;j<=x;j++) {
            dp[i][j] = mod(((i==0)? 0:dp[i-1][j]) + ((j-c[i]<0)? 0:dp[i][j-c[i]]));
        }
    }
    
    cout<<dp[n-1][x];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

/** Solution By khemchand5487 **/