const ll M=998244353;
const ll N=1e6+10;

ll fact[N];
ll fact_inverse[N];

ll binExp(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*1LL*a)%M;
        }
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

void factorial(){
    fact[0]=1;
    fact_inverse[0]=1;
    for(ll i=1;i<N;++i){
        fact[i]=(fact[i-1]*1LL*i)%M;
        fact_inverse[i]=binExp(fact[i],M-2);
    }
}

ll ncr(ll n,ll r){
    if(r>n){
        return 0;
    }
    return (fact[n]*((fact_inverse[r]*fact_inverse[n-r])%M))%M;
}