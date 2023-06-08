string reverseString(string &s){
	vector <string> ans;
        for (int i = 0; i < s.length(); i++){
            string temp;
            if (s[i] != ' '){
                while(s[i] != ' ' && i < s.length()){
                    temp.push_back(s[i]);
                    i++;
                }
                ans.push_back(temp);
            }
        }
        reverse(ans.begin(), ans.end());
        string res;
        for (int i = 0; i < ans.size(); i++){
            if (i == ans.size() - 1){
                res += ans[i];
                break;
            }
            res += ans[i] + ' ';
        }
        return res;
	// Write your code here.	
}