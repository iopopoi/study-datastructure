#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long x, n, a;
int p1, p2;
vector<long long> v;
vector<pair<long, pair<int, int> > > ans;

int main(){
    while(scanf("%lld", &x) != EOF){
        x *= 10000000;
        scanf("%lld", &n);
        v.clear();
        ans.clear();

        while(n--){
            scanf("%lld", &a);
            v.push_back(a);
        }

        sort(v.begin(), v.end());
        
        p1 = p2 = 0;
        while(p2<v.size()){
            cout << v[p1] << " : " << v[p2] << "\n";
            a = v[p1] + v[p2];
            if(a == x){
                ans.push_back({v[p1]-v[p2],{p1, p2}});
                p2++;
            }
            else if(a < x){
                if(p1<p2-1)p1++;
                else p2++;
            }
            else{
                break;
            }
        }

        sort(ans.begin(), ans.end());

        if(ans.size()>0){
            printf("yes %lld %lld\n", v[ans[0].second.first], v[ans[0].second.second]);
        }
        else{
            printf("danger\n");
        }
    }
}