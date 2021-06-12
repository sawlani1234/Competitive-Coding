#include <bits/stdc++.h>
#define ll long long int
#define N 100
#define f(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << endl
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define all(x) x.begin(), x.end()
#define PI 3.141592653
#define cot cout.tie(0)
#define endl "\n"
using namespace std;
/**
        * @author :: Sawlani
        *
        */
// example array {12, 11, 13, 5, 6, 7}
ll a[N+1]; //representing tree in array


void heapify(ll i,ll n)
{
    if(i>(n/2)) return ;

    
    ll maxi = max({a[i],a[2*i]});
     
      if((2*i+1)<=n)
      maxi=max(maxi,a[2*i+1]);

      if(maxi==a[2*i])  {
          swap(a[i],a[2*i]);
          heapify(2*i,n);
      }
      else if(((2*i+1)<=n) && maxi==a[2*i+1])
      {
          swap(a[2*i+1],a[i]);
          heapify(2*i+1,n);
      }
 
}
int main()
{
     ll n;

     freopen("input.txt","r",stdin);
       cin >>  n;
     
     f(i,1,N) a[i]=INT_MIN;
     
     f(i,1,n)
     {
         cin >> a[i];
     }       

      //Start making heap in O(N) recursively 

      rf(i,n/2,1)
      {
          heapify(i,n);
      }

      // Heap elements in array form
      f(i,1,n)  cout << a[i] << " ";
      cout << endl;

      //Heap Sort of elements 
     cout << "Sorted order " << endl;
    f(i,1,n)
    {
        cout << a[1] << endl;
        swap(a[1],a[n-i+1]);
        heapify(1,n-i);
    }
         
}