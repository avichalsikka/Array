#include <bits/stdc++.h>
#include <string>
      #define ll int
      #define N 100000
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
      vector <ll> bits;

      void cnv(ll n)
      {
            while(n!=0)
            {
                if(n%2)
                    bits.pb(1);
                else
                    bits.pb(0);
                n/=2;

            }
           reverse(all(bits));

      }
      ll k;
      ll dp[41][2][2];
      ll rec(ll idx,ll tight,ll b)
      {
          ll ans=0;
          //cout <<  idx << " " << tight <<  " " << b << endl;
          if(dp[idx][tight][b]!=-1)
            return dp[idx][tight][b];
          if(idx==bits.size())
            return 1;

          if(idx==0)
          {
                 if(idx==k)
              ans+=rec(idx+1,1,1);
              else{
              ans+=rec(idx+1,1,1);

              ans+=rec(idx+1,tight,0);

             }
          }
          else
          {
           if(tight==1)
          {
              if(idx==k)
              {
                   if(bits[idx]==0)
                    return 0;
                   else
                   {
                       ans+=rec(idx+1,tight,1);

                   }
              }
              if(idx!=k&&bits[idx]==1)
              {
                  ans+=rec(idx+1,tight,1);
                  ans+=rec(idx+1,0,0);
              }
              else if(idx!=k&&bits[idx]==0)
              {
                  ans+=rec(idx+1,1,0);
              }
          }
          else
          {
              if(idx==k)
              {
                  ans+=rec(idx+1,tight,1);
              }
               else
            {
              ans+=rec(idx+1,0,0);
              ans+=rec(idx+1,0,1);
             }

           }
          }
          return dp[idx][tight][b]=ans;
      }
      int main()
      {
          ll t;
          cin >> t;
          f(i,1,t)
          {
              memset(dp,-1,sizeof(dp));
              ll n,b;
              cin >> n >> b;
                bits.clear();

                cnv(n);
                 //cout << bits.size() << endl;
                if(b>=bits.size()){
                     cout << 0 << endl;
                    }
                else{

                    k=bits.size()-b-1;
                            cout << rec(0,0,0) << endl;

          }



      }
      }
