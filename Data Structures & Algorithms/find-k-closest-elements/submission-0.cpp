class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {   /*
        int n = arr.size();
        map<int,int> check; 

        for(int i=0; i<n;i++) { 
            check.insert({abs(x-arr[i]),i});
        } 

        vector<int> ans; 
        int count = 0;
        for(auto x : check ) { 
            int j = x.second;
            ans.push_back(arr[j]); 
            count++; 
            if(count == k) { 
                break;
            }
        } 

        sort(ans.begin(),ans.end()); 
        return ans;  

        this bruteforce doest work as there map doesnt store duplicate elements we need to take a two pointer approach .  

        */  
    int n = arr.size();
    int i=0; 
    int j=i+k-1;  

    int sum = 0; 
    int temp;

    for(int l=0; l<k; l++) { 
        sum = sum + abs(x-arr[l]); 
        
    } 
    int start = 0; 
    int end = k-1;


    while (j<n-1) {  

        temp = sum - abs(x-arr[i]);
        temp = temp + abs(x - arr[j+1]); 
        if (temp<sum) { 
            start = i+1; 
            end = j+1; 
            sum = temp;
            
            
        }
        i++; 
        j++;
        

        
          
       
        
    }  

    vector<int> ans;

    for(int i=start; i <= end;i++) { 
        ans.push_back(arr[i]);

    } 

    return ans;



 
        
    } 

};