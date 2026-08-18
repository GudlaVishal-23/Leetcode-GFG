class Solution {
public:
    int largestInteger(vector<int>& n, int k) {

    int freq[51]={0};  
    int maxx=-1;  
    for(auto& i:n)
    {
        freq[i]++;
    }
int nn=n.size();
    for(int j=0;j<nn;j++)
    {
    if(k==nn||freq[n[j]]==1 && (k==1||!j||j==nn-1))
    {
       maxx=max(maxx,n[j]);
    }}
    
    
    return maxx;
        
    }
};