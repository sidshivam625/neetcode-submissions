class Solution {
public:
    string foreignDictionary(vector<string>& words) { 
        int n = words.size(); 
        vector<vector<int>> adj(26); // creates and empty vector array of size 26
        vector<int> indegree(26, 0);  
        string final = "";
        int totalchars = 0;

        if(n==1) { 
            return words[0];
        } 

        for(int i=0; i<n-1; i++) {
        if (words[i].size() > words[i+1].size() && words[i].substr(0, words[i+1].size()) == words[i+1].substr(0, words[i+1].size())) {
         return ""; } }  


        /* keeping track of all the elements :  */

        map<char,int> tracked; 

        for(int i=0; i<n;i++) { 
            for(int j=0; j<words[i].size();j++) { 
                if(tracked[words[i][j]]==0){ 
                    tracked[words[i][j]]=1;
                    totalchars++;
                }
            }
        }   

        















        for(int i=0; i<n-1;i++) { 
            int len = min(words[i].size(),words[i+1].size());
            for(int j=0;j<len;j++) { 
                if(words[i][j]!=words[i+1][j]) {  
                    int temp = words[i+1][j] - 'a'; 
                    bool exists = false;
                    for(int k=0; k<(adj[words[i][j]-'a'].size());k++ ) {  
                        if (adj[words[i][j]-'a'][k]==temp) { 
                            exists = true; 
                            break;
                        }
                        
                    } 

                    if(exists == false) { 
                    
                    adj[words[i][j]-'a'].push_back(temp); 
                    indegree[temp]++;  
                    
                   
                    }
                    break;
                }
            }
        } 


        queue<int> store; 
        for(int i=0; i<26;i++) { 
            char tempa = 'a'+ i;
            if(indegree[i]==0 && tracked[tempa]==1 ) { 
                store.push(i);
            }
        } 

        while(!store.empty()) { 
            int tempo = store.front();
            store.pop(); 
            char real = tempo + 'a'; 
            final.push_back(real);
            for(auto it : adj[tempo]) { 
                indegree[it]--; 
                if(indegree[it]==0) {
                    store.push(it);
                }
            }
        }

         
        


        

        

        if(final.size()!=totalchars) { 
            return "";
        } 

        return final;





        
    }
};
