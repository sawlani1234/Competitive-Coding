    
bool prime[N+1]={false};
ll spf[N+1];
  ll sum[N+1]={0};
  void mulmod(ll A,ll B,ll MOD) {
    ll RES = 0;
    while (B > 0) {
        if (B % 2) {
            RES = (RES + A) % MOD;
        }
        A = (A * 2) % MOD;
        B = B / 2;
    }
    return RES;
}
   void spf_sieve()
 {
    for(ll i=2;i<=N;i++)
    {
      spf[i]=i;
    }
     
    for(ll i=2;i*i<=N;i++)
    {
        if(spf[i]==i)
        {
         for(ll j=i*i;j<=N;j+=i)
         {
            if(spf[j]==j)
            {
               spf[j]=i;
            }
         }
     }
   }
   sum[1]=1;
   ll cnt=0;
   f(i,2,N)
   {
       ll k=i;
        cnt=0;
       while(k!=1)
       {
          k/=spf[k];
          cnt++;
       }
       sum[i]=sum[i-1]+cnt;
   }
 }
void sieve()
{
	prime[1]=false;
	 for(int i=2;i*i<=N;i++)
	 {
	 	if(prime[i]) 
	 	{
	    	for(int j=i*i;j<=N;j+=i)
	 	   {
	 		prime[j]=false;
	 	  }
	    }
     }
}

ll factorial[N+1];
void prefact()
{
	factorial[0]=1;
	f(i,1,N)
     factorial[i]=(i*factorial[i-1])%M;
}
ll gcd(ll a,ll b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}
ll ncr[1001][1001]={0};
void NCR()
{
    ncr[0][0]=1;
    f(i,1,1000)
    {
        f(j,0,i)
        {
            if(j==0)
                ncr[i][j]=1;
            else
                ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%M;
        }
    }
 
}
 
ll modularExponentiation(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
ll modInverse(ll A)// when M is PRIME
{
    return modularExponentiation(A,M-2);
}
 
 ll factors(ll p)
 {
 	ll ans=1;
 	 f(i,2,sqrt(p))
     {
     	ll cnt=0;
        while(p%i==0)
     	{
     		cnt++;
     		p=p/i;
     	}
 
     	ans=ans*(cnt+1);
     }
      return ans;
  }