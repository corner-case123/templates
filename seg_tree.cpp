#include<bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second 
#define ld long double
#define pb(x) push_back(x)
#define loop(n) for(ll i=0;i<n;i++)
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
#define ln '\n'
using namespace std;
// cout << setprecision(x) << fixed << value
// long double can store very large value greater than long long 
 
vll a ;
vll tree ;
 
ll build(ll node,ll l,ll r){
    if (l==r) return tree[node]  = a[l] ;
    return tree[node] = build(2*node,l,(l+r)/2) + build(2*node+1,(l+r)/2+1,r) ;
}
 
ll query(ll node,ll l, ll r,ll low,ll high){
    if (high<l or low > r) return 0 ;
    if (low<=l and r<=high) return tree[node] ;
    return query(2*node,l,(l+r)/2,low,high) + query(2*node+1,(l+r)/2+1,r,low,high) ;
}
ll update(ll node,ll l,ll r,ll pos,ll value){
    if (l==r and l==pos) {
        a[pos] = value ; 
        return tree[node]=value; 
    }
    if (pos<l or pos>r) return tree[node] ;
    return tree[node] = update(2*node,l,(l+r)/2,pos,value) + update(2*node+1,(l+r)/2+1,r,pos,value) ;
}
 
void solve(){
    ll n ,q  ; cin >> n >> q ;
    a.resize(n) ;
    loop(n) cin >> a[i] ;
    ll sz = pow(2ll,(ll)ceil((double)log2(n))) ; // making the tree power of two
    while(sz!=n){
        a.push_back(0) ; n++ ;
    }
    tree.resize(2*n) ;
    build(1,0,n-1) ;
    while(q--){
        ll t , a , b ; cin >> t >> a >> b ;
        if (t==2){
            a-- ; b-- ;
            cout << query(1,0,n-1,a,b) << ln ;
        }
        else {
            a-- ;
            update(1,0,n-1,a,b) ;
        }
    }
    return ;
}
 
int main(){
    ll t =1 ;
    //cin >> t  ;
    while(t--) solve() ;
    return 0 ;
}
