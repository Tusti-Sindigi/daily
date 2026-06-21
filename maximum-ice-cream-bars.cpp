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

        int leftover=coins, max=0;

        for(int c=1;c<=greatest;c++)
        {
            if(freq[c]>0)
            {
                int bars=min(freq[c], leftover/c);
                max+=bars;
                leftover-=c*bars;

                if(bars==0)
                break;
            }
        }
        return max;
    }
};