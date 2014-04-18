#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define N 20010
#define M 1000010
#define INF 0x7FFFFFFF
#define F(x)((x)/3+((x)%3==1?0:tb))
#define G(x)((x)<tb?(x)*3+1:((x)-tb)*3+2) 

using namespace std;
int wa[N],wb[N],wv[N],WS[M];
int sa[N*3] ;
int rank1[N],height[N]; 
int r[N*3]; 


int c0(int *r,int a,int b) {
    return r[a]==r[b] && r[a+1]==r[b+1] && r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b) {
    if(k==2)
        return r[a]<r[b] || ( r[a]==r[b] && c12(1,r,a+1,b+1) );
    else
        return r[a]<r[b] || ( r[a]==r[b] && wv[a+1]<wv[b+1] );
}
void sort(int *r,int *a,int *b,int n,int m) {
    int i;
    for(i=0; i<n; i++)
        wv[i]=r[a[i]];
    for(i=0; i<m; i++)
        WS[i]=0;
    for(i=0; i<n; i++)
        WS[wv[i]]++;
    for(i=1; i<m; i++)
        WS[i]+=WS[i-1];
    for(i=n-1; i>=0; i--)
        b[--WS[wv[i]]]=a[i];
    return;
}

void dc3(int *r,int *sa,int n,int m) {
    int i , j , *rn = r+n , *san = sa+n , ta = 0 ,tb = (n+1)/3 , tbc = 0 , p;
    r[n] = r[n+1] = 0;
    for(i=0; i<n; i++) {
        if(i%3!=0)
            wa[tbc++]=i; 
    }
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc)
        dc3(rn,san,tbc,p);
    else {
        for(i=0; i<tbc; i++)
            san[rn[i]]=i;
    }
    for(i=0; i<tbc; i++) {
        if(san[i]<tb)
            wb[ta++]=san[i]*3;
    }
    if(n%3==1) 
        wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0; i<tbc; i++)
        wv[wb[i] = G(san[i])]=i;

    for(i=0,j=0,p=0; i<ta&&j<tbc; p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(; i<ta; p++)
        sa[p]=wa[i++];
    for(; j<tbc; p++)
        sa[p]=wb[j++];
    return;
}

void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1; i<=n; i++)
        rank1[sa[i]]=i;
    for(i=0; i<n; height[rank1[i++]]=k)
        for(k?k--:0,j=sa[rank1[i]-1]; r[i+k]==r[j+k]; k++);
}

bool judge(int mid,int n,int k) {
    int cnt = 1;
    for(int i=1; i<=n; i++) {
        if(height[i] >= mid) {
            cnt ++;
        } else cnt = 1;
        if(cnt >= k) return true;
    }
    return false;
}

int main() {
	freopen("data_DAP_Q41.in", "r", stdin);
    int NN,K; cin >> NN >> K;
    
    for(int i=0; i < NN; i++) { scanf("%d", &r[i]); r[i] ++; }
    
    r[NN] = 0; 
    
    dc3(r, sa, NN+1, 1000010);
    calheight(r, sa, NN);
    
    int l=1, r=NN, mid; 
    int ans = 0;
    
    while(l <= r) {
        mid = (l + r) >> 1;
    
        if(judge(mid, NN, K)) {
            ans = mid;
            l = mid + 1;
        } 
        else 
            r = mid - 1;
    }

    cout << ans << endl;
    return 0;
}