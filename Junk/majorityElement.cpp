// Moore’s Voting Algorithm
// ChandyShot... 

// Majority Element:  A majority element in an array A[] of size n is an element that appears
//                    more than n/2 times (and hence there is at most one such element).

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 100010
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;
#define clr(x) memset(x, 0, sizeof (x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for(int (i)=(j); (i)<(k); (i)+=(l))
#define ff(i, j, k, l) for(int (i)=(j); (i)<=(k); (i)+=(l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
using namespace std;

ll pw(ll x, ll y){
    ll res = 1;
    if(y == 0)
        return 1;
    while(y){
        if(y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

vector <int> v;

istream& operator >> (istream &in, vector <int> &v){
    for(int i=0; i<v.size(); i++) in>>v[i];
    return in;
}

bool isMajority(vector <int> &v, int &elm){
    int cnt = 0;
    for(int a : v)
        if(elm == a)
            cnt++;
    if(cnt > v.size() / 2)
        return true;
    return false;
}

bool findMajorityElement(vector <int> &v, int &maj){
    if(v.size() == 0)
        return false;
    if(v.size() == 1){
        maj = v[0];
        return true;
    }
    int cnt = -1;
    int elm = -1;

    for(int a : v){
        if(cnt == -1){
            elm = a;
            cnt = 1;
            continue;
        }

        if(elm == a) cnt++;
        else cnt--;

        if(cnt == 0){
            cnt = 1;
            elm = a;
        }
    }
    
    if(isMajority(v, elm)){
        maj = elm;
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    v.resize(n);
    cin>>v;
    int maj = -1;
    if(findMajorityElement(v, maj))
        cout<<maj<<endl;
    else
        cout<<"Don't contain Majority Element"<<endl;
    return 0;
}
