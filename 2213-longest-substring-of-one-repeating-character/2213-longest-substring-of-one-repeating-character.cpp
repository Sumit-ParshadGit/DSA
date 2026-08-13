// class Solution {
// public:
//     vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
//         vector<int>length;
        
//         for(int ind = 0;ind<qi.size();ind++){
//             int ma = 1;
//             s[qi[ind]] = qc[ind];
//             int n = s.size();
//             int ans = 1;
//             for(int j = 1;j<n;j++){
//                 if(s[j]==s[j-1]){
//                     ans++;
//                 }else{
//                     ans = 1;
//                 }ma = max(ans,ma);
//             }
//             length.push_back(ma);
//         }return length;
//     }
// };

class Solution {
public:
    struct Node{
        int pre = 0;
        int suff = 0;
        int maxl = 0;
        char lc = 0;
        char rc = 0;
    };
    int n;
    vector<Node>segtree;
    Node merge(const Node&l,const Node&r,int ln,int rn){
        Node res;
        res.lc = l.lc;
        res.rc = r.rc;
        res.pre = l.pre;
        if(l.pre==ln&&l.rc==r.lc){
            res.pre = l.pre+r.pre;
        }
        res.suff=r.suff;
        if(r.suff==rn&&l.rc==r.lc){
            res.suff = r.suff+l.suff;
        }
        res.maxl = max(l.maxl,r.maxl);
        if(l.rc==r.lc){
            res.maxl = max(res.maxl,l.suff+r.pre);
        }return res;
    }
    void buildst(int i,int l,int r,string&s){
        if(l==r){
            segtree[i]={1,1,1,s[l],s[l]};
            return ;
        }
        int mid = l+(r-l)/2;
        buildst(2*i+1,l,mid,s);
        buildst(2*i+2,mid+1,r,s);
        segtree[i] = merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r-mid);
    }
    void update(int i,int l,int r,int pos,char ch){
        if(l==r){
            segtree[i]={1,1,1,ch,ch};
            return ;
        }
        int mid = l+(r-l)/2;
        if(pos <= mid){
            update(2*i+1,l,mid,pos,ch);
        }else{
            update(2*i+2,mid+1,r,pos,ch);
        }
        segtree[i] = merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r-mid);
    }
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        n = s.size();
        segtree.assign(4*n,Node());
        buildst(0,0,n-1,s);
        int k = qc.size();
        vector<int>res(k);
        for(int i = 0;i<k;i++){
            int pos = qi[i];
            char ch = qc[i];
            update(0,0,n-1,pos,ch);
            res[i] = segtree[0].maxl;
        }return res;
    }
};