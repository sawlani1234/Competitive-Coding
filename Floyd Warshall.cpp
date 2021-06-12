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
                            const ll inf=1e7;
                            ll t;
                            cin >> t;
                            while(--t>=0)
                            {
                                 ll v;
                                 cin >> v;
                                 
                                 ll dis[v+1][v+1];
                                 
                                 f(i,1,v)
                                 {
                                      
                                     f(j,1,v)
                                     {
                                         cin >> dis[i][j];
                                         
                                     }
                                 }
                                 
                                 for(int k=1;k<=v;k++)
                                 {
                                     for(int i=1;i<=v;i++)
                                     {
                                         for(int j=1;j<=v;j++)
                                         {
                                             if(i==j)
                                             continue;
                                             if(dis[i][k]+dis[k][j]<dis[i][j])
                                             dis[i][j]=dis[i][k]+dis[k][j];
                                         }
                                     }
                                }
                                
                                f(i,1,v)
                                {
                                    f(j,1,v)
                                    {
                                        if(dis[i][j]==inf)
                                        cout << "INF ";
                                        else
                                        cout << dis[i][j] << " " ;
                                    }
                                    cout << endl;
                                }
                            }
                                 
                           }
                        
                     