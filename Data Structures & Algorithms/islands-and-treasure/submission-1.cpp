class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {   
                int n = grid.size(); 
                int m = grid[0].size();  

               



                queue<pair<int,int>> store; 
                for(int i=0;i<n;i++) { 
                    for(int j=0; j<m;j++) { 
                        if(grid[i][j]==0) { 
                            store.push({i,j}); 
                            

                        }
                    } 


                } 


        vector<int> low = {-1,0,1,0}; 
        vector<int> high = {0,1,0,-1};

        while(!store.empty()) { 
            pair<int,int> temp = store.front(); 
            int a=  temp.first; 
            int b = temp.second; 

            store.pop(); 
            for(int k=0; k<4;k++) { 
                int i = low[k];
                int j = high[k];
                    if(a+i >=0 && a+i <n && b+j>=0 && b+j<m && grid[a+i][b+j]==INT_MAX) { 
                         
                            grid[a+i][b+j]=1+grid[a][b]; 
                            store.push({a+i,b+j});
                            
                        
                    }
                
            }
        } 

          
        
    }
};
