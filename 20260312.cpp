#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class DSU {
public:
    vector<int> p, r;

    DSU(int n){
        p.resize(n);
        r.resize(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }

    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;

        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int x){
        DSU dsu(n);
        int used=0;

        vector<vector<int>> freeEdges;
        vector<vector<int>> upgradeEdges;

        // must edges
        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must){
                if(s < x) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
            else{
                if(s>=x) freeEdges.push_back(e);
                else if(s*2>=x) upgradeEdges.push_back(e);
            }
        }

        // free edges first
        for(auto &e: freeEdges){
            if(dsu.unite(e[0],e[1])){
                used++;
                if(used==n-1) return true;
            }
        }

        // then upgraded edges
        for(auto &e: upgradeEdges){
            if(k==0) break;
            if(dsu.unite(e[0],e[1])){
                used++;
                k--;
                if(used==n-1) return true;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int left=0, right=200000, ans=-1;

        while(left<=right){
            int mid=(left+right)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0,1,2,1}, {1,2,3,0}};
    cout << s.maxStability(3, edges, 1) << endl;
    edges = {{0,1,4,0}, {1,2,3,0}, {0,2,1,0}};
    cout << s.maxStability(3, edges, 2) << endl;
    edges = {{0,1,1,1}, {1,2,1,1}, {2,0,1,1}};
    cout << s.maxStability(3, edges, 0) << endl;

    return 0;
}