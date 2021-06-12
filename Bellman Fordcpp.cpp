                      #include <bits/stdc++.h>
                      #define ll long long  int
                      #define N 300000
                      #define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
                      #define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
                      #define po pop_back
                      #define pb push_back
                      #define pp pair<ll,ll>
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
                        *
                        **/
                        int main()
                        {
                          freopen("input.txt","r",stdin);
                            ll t;
                            cin >> t;

                           const ll inf=1e9+7;

                            while(t-->=0)
                             {
                                 bool flag=true;

                                ll e,v;
                                cin >> v >>  e;

                                 map <pair<ll,ll>,ll> mp;
                                 ll dis[v];
                                memset(dis,0,sizeof(dis));

                                f(i,1,e)
                                {
                                    ll x,y,w;
                                    cin >> x >> y >> w;

                                     mp[{x,y}]=w;

                                }

                                dis[0]=0;
                                f(i,1,v-1)
                                dis[i]=inf;

                               for(auto i: mp){cout <<  i.fi.fi << " " << i.fi.se << " " << i.se << endl; }

                                for(int i=1;i<=v-1;i++)
                                {
                                    for(auto it=mp.begin();it!=mp.end();it++)
                                    {
                                        ll x=it->first->first;
                                        ll y=it->first->second;
                                        ll w=it->second;

                                         if(dis[x]+w<dis[y])
                                         dis[y]=dis[x]+w;
                                    }
                                }
                                bool flag=true;
                                for(auto it=mp.begin();it!=mp.end();it++)
                                    {
                                        ll x=it->first->first;
                                        ll y=it->first->second;
                                        ll w=it->second;

                                         if(dis[x]+w<dis[y])
                                         {
                                             flag=false;
                                              break;
                                         }
                                   }

                                   if(flag)
                                   cout << 1 << endl;
                                   else
                                   cout << 0 << endl;
                             }
                        }
