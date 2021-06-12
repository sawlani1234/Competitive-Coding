ll n;
ll a[N+1]={0};
ll BIT[N+3]={0};
void update(ll x,ll val)
{
     for(;x<=n;x+=x&-x)
        BIT[x]+=val;
}
ll query(ll x)
{
    ll sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT[x];
    return sum;
}

int main()
{
    ibs;cti;
     cin >>  n;
    f(i,1,n)
    {
        cin >> a[i];
        if(a[i]%2==0)
        update(i,1);
    }
    ll q;
    cin >> q;
    while(--q>=0)
    {
        ll p,x,y;
        cin >> p  >>  x >>  y;
        if(p==0)
        {
            if(a[x]%2==0&&y%2==0)
             update(x,0);
            else if(a[x]%2==0&&y%2!=0)
             update(x,-1);
            else if(a[x]%2!=0&&y%2==0)
              update(x,1);
            else if(a[x]%2!=0&&y%2!=0)
              update(x,0);
             a[x]=y; 
         }
        else if(p==1)
        {
               cout <<  query(y)-query(x-1) << endl;
        }
        else
        {
               cout <<   (y-x+1)-(query(y)-query(x-1)) << endl;
        }
    }
}
