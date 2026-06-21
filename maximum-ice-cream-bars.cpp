#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(), costs.end());

        int i=0, max=0;

        while(i<costs.size() && coins>=costs[i])
        {
            max++;
            coins-=costs[i];
            i++;
        }
        return max;
    }
};