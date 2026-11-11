class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costboth, int need1, int need2) {
        ll c1 = (ll)((ll)cost1*need1 +(ll)cost2*need2);
        int mi = min(need1,need2);
        int ma = max(need1,need2);
        ll c2  =(ll) ((ll)costboth*mi+(ll)(need1-mi)*min(cost1,costboth)+(ll)(need2-mi)*min(cost2,costboth));
        return min(c1,c2);
    }
};