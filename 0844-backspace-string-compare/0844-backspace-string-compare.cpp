//T.C -> O(n + m)
// S.C -> O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0;
        int skipT = 0;

        while(i >= 0 || j >= 0){

            while(i >= 0){
                if(s[i] == '#'){
                    skipS++;
                    i--;
                }
                else if(skipS){
                    skipS--;
                    i--;
                }
                else{
                    break;
                }
            }

            while(j >= 0){
                if(t[j] == '#'){
                    skipT++;
                    j--;
                }
                else if(skipT){
                    skipT--;
                    j--;
                }
                else{
                    break;
                }
            }

            if(i >= 0 && j >= 0){
                if(s[i] != t[j])
                    return false;
            }
            else if(i >= 0 || j >= 0){
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};