    #include <bits/stdc++.h>
    #define ll  long long int
    #define N 15
    #define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
    #define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
    #define po pop_back
    #define pb push_back
    #define lb lower_bound
    #define fi first
    #define se second
    #define debug(x) cout << #x << " = " << x << endl
    #define ub upper_bound
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define all(x) x.begin(),x.end()
    #define PI 3.14159265
    #define cot cout.tie(0)
    using namespace std;
     /**
      * @author :: Sawlani
      *
      */

    vector <ll> v[N+1];
    bool vis[N+1];
    stack <ll> rev;
    vector <ll> t[N+1];

  void transpose()
  {
    f(i,1,N)
    {
       f(j,0,v[i].size()-1)
       {
           ll p=v[i][j];
            t[p].pb(i);
       }
    }

  }

ll cnt=0;
  void dfs(ll i)
 {
    f(j,0,v[i].size()-1)
    {
      ll p=v[i][j];
      if(!vis[p])
      {
        vis[p]=true;
        cnt++;
        dfs(p);
      }
    }
    rev.push(i);
 }
 void dfs2(ll i)
 {
    f(j,0,t[i].size()-1)
    {
      ll p=t[i][j];
      if(!vis[p])
      {
        vis[p]=true;
        cnt++;
        dfs2(p);
      }
    }

 }


     int main()
     {
         freopen("input.txt","r",stdin);
         memset(vis,false,sizeof(vis));
         ll n,m;
         cin >> n >>  m;
         f(i,1,m)
         {
            ll x,y;
            cin >> x >>  y;
            v[x].pb(y);
         }
         f(i,1,n)
         {
             if(!vis[i]){
              vis[i]=true;
             dfs(i);
             }
         }
         transpose();

         
         memset(vis,false,sizeof(vis));
         ll c=0,d=0;
         
         while(!rev.empty())
         {
             ll p=rev.top();
             cout << p <<  endl;
             rev.pop();
             if(!vis[p])
             {
              dfs2(p);
              if(cnt%2)
                c+=cnt;
              else
                d+=cnt;
              cnt=0;
             }
        }
         cout << c-d <<  endl;
       }
     
