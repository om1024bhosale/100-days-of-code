/*
link ->https://www.geeksforgeeks.org/problems/power-set4302/1

*/

class Solution{
	public:
	
	    void permutations(string s, vector<string>&ans, int i, string temp)
	    {
	        if(i==s.size()){
	            if(temp.size()>0)
	            {
	                ans.push_back(temp);
	            }
	            return;
	        }
	        
	        permutations(s,ans,i+1,temp);
	        char ch = s[i];
	        temp.push_back(ch);
	        permutations(s,ans,i+1,temp);
	        
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string temp="";
		    permutations(s,ans,0,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
