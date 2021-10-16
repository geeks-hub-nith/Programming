/*
    Author : prashant_th18
    Link: https://www.geeksforgeeks.org/bubble-sort/
*/
// Bubble Sort
#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int> &v)
{
    int size = (int)v.size();
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 0; j < size - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                v[j] = v[j] + v[j + 1];
                v[j + 1] = v[j] - v[j + 1];
                v[j] = v[j] - v[j + 1];
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    BubbleSort(v);
    for(auto val : v)
    {
        cout << val << " ";
    }
    return 0;
}