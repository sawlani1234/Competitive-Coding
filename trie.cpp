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

//Template for TRIE DATA STRUCTURE

struct trieNode
{
	struct trieNode *children[26];
	bool isEndofWord; // stores end of word for a string
};
struct trieNode* getNode(void)
{
	struct trieNode *node = new trieNode();
	node->isEndofWord=false;
	f(i,0,25)
	{
       node->children[i]= NULL;
	}
	return node;
};
void insert(struct trieNode *root,String key)
{
   struct trieNode *temp=root;
   f(i,0,key.length()-1)
   {
   	  ll index=key[i]-'a';
   	  if(temp->children[index]==NULL)
   	  {
   	  	temp->children[index]=getNode();
   	  }
   	  temp=temp->children[index];
    }
   temp->isEndofWord=true;
}
bool search(struct trieNode *root,String key)
{ 
  struct trieNode *temp=root;

  f(i,0,key.length()-1)
  {
     ll index=key[i]-'a';
     if(!temp->children[index])
     {
     	return false;
      }
      temp=temp->children[index];
  }
   
    return temp!=NULL&&temp->isEndofWord;
}
int main()
{
   ll n;
   cin >> n;
   struct trieNode* root= getNode();
   f(i,1,n)
   {
      string s;
      cin >> s;
      insert(root,s);
  }
  ll q;
  cin >> q;
  f(i,1,q)
  {
  	string j;
  	cin >> j;
  	if(search(root,j))
  		cout << "Trie kr liye bhsdk" << endl;
  	else
  		cout << "Nhi kr paye madarchod" << endl;
  }
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n\n";
    #endif
}


 

