#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int greatest=*max_element(costs.begin(), costs.end());
        vector<int> freq(greatest+1, 0);

        for(int c: costs)
            freq[c]++;

        for(int i=1;i<freq.size();i++)
            freq[i]+=freq[i-1];

        vector<int> sorted(costs.size(), 0);

        for(int i=costs.size()-1;i>=0;i--)
        {
            sorted[freq[costs[i]]-1]=costs[i];
            freq[costs[i]]--;
        }    

        int i=0, max=0;

        while(i<sorted.size() && coins>=sorted[i])
        {
            max++;
            coins-=sorted[i];
            i++;
        }
        return max;
    }
};