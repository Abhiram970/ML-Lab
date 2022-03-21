#include <map>
#include <iostream>
using namespace std;
#include <vector>

vector<pair<int,int>> zerosum(vector <int> arr)
{
    int sum = 0;
    int n = arr.size();
    vector <pair<int,int>> ans;
    map<int, vector <int>>map1;

    for (int i = 0; i < n ; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            ans.push_back(make_pair(0,i));
        }

        else if(map1.find(sum) != map1.end())
        {
            vector <int> v = map1[sum];

            for (auto it = v.begin() ; it != v.end() ; it++)
            {
                ans.push_back(make_pair(*it + 1,i));
            }
        }

        map1[sum].push_back(i);
    }
    return ans;

}


int main()
{
    vector <pair <int,int> > d;
    int n;
    int x;
    vector <int> arr;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    
    d = zerosum(arr);
    int n2 = d.size();

    if (n2 > 0)
    {
        for (auto it = d.begin(); it != d.end(); it++)
        {
            cout << (it->first) + 1 << " " << (it->second) + 1 << endl;
        }
    }

    else if (n2 == 0)
    {
        cout << -1;
    }
    
    return 0;
}