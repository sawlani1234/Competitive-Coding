  #include <bits/stdc++.h>
   #define ll  long long int
  #define N 100000
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
  //using namespace __gnu_pbds;

  /**
    * @author :: Sawlani
    *
    */

  ll tree[4*N+60]={0};
  ll lazy[4*N+60]={0};

  void update(ll node,ll start,ll end,ll l,ll r,ll val)
  {
       
       if(lazy[node])
       {
          tree[node]+=(end-start+1)*lazy[node];
          if(start!=end)
          {
             tree[2*node]+=lazy[node];
             tree[2*node+1]+=lazy[node];
          }
          lazy[node]=0;
       }

       if(l>end||r<start||start>end)
        return ;
      else if(l<=start&&r>=end)
      {
            ll k=(r-l+1)*val;
             tree[node]+=k;
               
           if(lazy[node])
           {
               tree[node]+=(r-l+1)*lazy[node];
               if(satrt!=end)
               {
                lazy[2*node]+=(lazy[node]+val);
                lazy[2*node+1]+=(lazy[node]+val);
               }
               lazy[node]=0;
           }

           else
            {
                if(start!=end)
                {  
                  lazy[2*node]+=val;
                  lazy[2*node+1]+=val;
                }
            }
      }
      else
      {
         ll mid=(start+end)>>1;
          update(2*node,start,mid,l,r,val);
          update(2*node+1,mid+1,end,l,r,val);
          tree[node]=tree[2*node]+tree[2*node+1];
      }
  }

  ll query(ll node,ll start,ll end,ll l,ll r)
  {
       if(l>end||r<start||sart>end)
        return 0;
        
        if(lazy[node])
        {
           tree[node]+=(end-start+1)*lazy[node];
           if(start!=end)
           {
              lazy[2*node]+=lazy[node];
              lazy[2*node+1]+=lazy[node];
           }
           lazy[node]=0;
        }

        if(l<=start&&r>=end)
        {
          return tree[node];
       }

      else
      {
          ll mid=(start+end)>>1;
          return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
      }
  }

  int main()
  {

      freopen("input.txt","r",stdin);
      ll t;
      cin >> t;

      f(i,1,t)
      {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
         ll n,c;
         cin >>  n >> c;
         f(j,1,c)
         {
             ll a;
          cin >>  a;


            if(a==0)
           {
              ll p,q,v;
              cin >>  p >> q >>  v;
              update(1,1,n,p,q,v);
              }
         else
         {
             ll p,q;
             cin >>  p >>  q;

             cout << query(1,1,n,p,q) << endl;

         }
      }
    }
  }
