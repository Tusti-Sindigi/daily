#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char,int> m;

        for(char c: text)
            m[c]++;

        m['l']/=2;
        m['o']/=2;

        string check="balloon";

        if(m.find(check[0])==m.end())
            return 0;

        int min=m[check[0]];

        for(int i=1;i<check.size();i++)
        {
                if(m[check[i]]<min)
                    min=m[check[i]];
        }
        return min;
    }
};