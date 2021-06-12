vector <ll> v[N+1];
bool vis[N+1];
void dfs(ll i)
{
    for(auto j:v[i])
    {
        if(!vis[j])
        {
          vis[j]=true;
          dfs(j);
        }
    }
   
}
   int main()
  {
      //freopen("input.txt","r",stdin);
     ll n,m;
     cin >>  n  >> m;
  
     f(i,1,m)
     {
       ll x,y;
       cin >> x >> y;

       v[x].pb(y);
       v[y].pb(x);
     }

     vis[1]=true;
     dfs(1);
    
}





