#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int lights(long long int n) {
     int i; long long int k=1;
       for(i=1;i<=n;i++)
       {
          k=(k<<1)%100000;
       }
   k-=1;
    return k;
}
int main()
{
     int t;
    cin >> t;
     for (int t_itr = 0; t_itr < t; t_itr++) {
        long long int n;
        cin >> n;


        long long int result = lights(n);

        cout << result << endl;
    }
}
