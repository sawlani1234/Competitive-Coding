#include <bits/stdc++.h>
#define ll  long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Sawlani
  *
  */
vector <pair <ll,ll>  > v[N+1];
bool vis[N+1]={false};
ll distanc[N+1];
  int main()
  {
      ll n,m;
      cin >> n >> m;
      f(i,1,m)
      {
      	 ll x,y,w;
      	 cin >> x >> y >> w;
        v[x].pb({y,w});
        v[y].pb({x,w});
      }
      priority_queue < pair <ll,ll > >  pq; // push pair of {distanc,vertex} ;
     f(i,0,N)
     distanc[i]=INT_MAX;
       distanc[1]=0;
      pq.push({0,1});  //Step 1 :Push
      while(!pq.empty())
      {
      	 ll d=pq.top().first;
      	 ll vertex=pq.top().second;
      	 pq.pop();//Step 2  :Pop
      	 if(vis[vertex]) // Step 3:Check
      	 	continue;
      	 vis[vertex]=true;
      	 f(i,0,v[vertex].size()-1)
      	 {
      	 	ll child=(v[vertex][i].first);
      	 	ll w=v[vertex][i].second;
      	 	 if(distanc[vertex]+w<distanc[child])
      	 	 {
                 distanc[child]=distanc[vertex]+w;
                 pq.push({-distanc[child],child});  //Step 4:Push
      	 	 }
      	 }

      }
      f(i,2,n)
      {
          cout << distanc[i] <<  " " ;

      }
      #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n\n";
    #endif
  }
