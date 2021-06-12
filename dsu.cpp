 void initialize(ll a[],ll size[],ll n)//initializing dsu each vertex is parent of itself
{
      f(i,1,n)
       {
      a[i]=i;
      size[i]=1;
       }
}
ll root(ll a[],ll i)
{
  while(a[i]!=i)
  {
    a[i]=a[a[i]];
    i=a[i];
  }
  return i;
}
bool find(ll x,ll y,ll a[])
{
  if(root(a,x)==root(a,y))
    return true;
  else
    return false;
}
void wieghted_union(ll a[],ll size[],ll x,ll y) // union by id
{
   ll rootX=root(a,x);
   ll rootY=root(a,y);
   if(find(x,y,a))
    return ;

   if(size[rootX]<size[rootY])
   {
     size[rootY]+=size[rootX];
     a[rootX]=a[rootY];
   }
   else
   {
     size[rootX]+=size[rootY];
     a[rootY]=a[rootX];
   }
}

  int main()
 {
  ll n,m;
  cin >> n >> m;
  ll a[n+1]={0};
  ll size[n+1]={0};
    initialize(a,size,n);
  f(i,1,m)
  {
    ll x,y;
    cin >> x >> y;
    wieghted_union(a,size,x,y);
  }
  ll cnt=0;
  f(i,1,n)
  {
    if(a[i]=i)
      cnt++;
   }
   cout << cnt << endl;
   #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n\n";
    #endif
 }
