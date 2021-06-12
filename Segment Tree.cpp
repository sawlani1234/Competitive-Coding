
ll a[N + 1];

vector<ll> tree(4 * N + 1);

void build(ll node, ll start, ll end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(ll node,ll start,ll end,ll idx,ll val)
{

  if(start>end || idx < start || idx>end)
    return ;
  if(start == end && start == idx)
  {
       tree[node] = val;
       a[idx] = val;
       return ;
  }

   ll mid = (start+end)>>1;

    update(2*node,start,mid,idx,val);
    update(2*node+1,mid+1,end,idx,val);

    tree[node] = min(tree[2*node],tree[2*node+1]);

}
ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (r < start || l > end || start > end)
        return INT_MAX;

    if (l <= start && r >= end)
        return tree[node];

    ll mid = (start + end) >> 1;

    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}