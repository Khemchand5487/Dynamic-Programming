/*
Title: Book Shop
Link: https://cses.fi/problemset/task/1158/
Complexity: Time - O(n*x); Space - O(n*x) 
where, 
        n: number of books
        x: total price
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
    int n , x;
    cin>>n>>x;
    vector<int> h(n+1), s(n+1);
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>s[i];
    
    int dp[n+1][x+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=x;j++) {
            if(j==0 || i==0) dp[i][j] = 0;
            else dp[i][j] = max(i==1? 0:dp[i-1][j], ((j<h[i]) ? 0: dp[i-1][j-h[i]]+s[i]));
        }
    }
    
    cout<<dp[n][x];
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