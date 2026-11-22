// class Solution {
// public:
//     bool checkString(string s) {
//         int i = 0;
//         while(i<s.size()&&s[i]=='a'){
//             i++;
//         }
//         while(i<s.size()){
//             if(s[i]=='a')return 0;
//             i++;
//         }return 1;
//     }
// };
class Solution {
public:
    bool checkString(string s) {
        int f = 1;
        for(int x:s){
            if(x=='b')f = 0;
            if(f==0&&x=='a')return 0;
        }
        return 1;
    }
};