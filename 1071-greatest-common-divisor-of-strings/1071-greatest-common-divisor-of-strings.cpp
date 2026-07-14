class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();
        if(s2 > s1){
            swap(str1, str2);
            swap(s1, s2);
        }
        while(!str2.empty()){
            if(str1.substr(0, s2) != str2) return "";
            while(str1.substr(0, s2) == str2){
                s1 = s1 - s2;
                str1 = str1.substr(s2, s1);
            }
            string temp = str1;
            str1 = str2;
            str2 = temp;
            swap(s1, s2);
        }
        return str1;
    }
};