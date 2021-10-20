flood fill algorithm


#include <iostream>
#include <vector>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

vector<int> input(int n)
{
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}
void solve(vvi bord, int row, int col, string psf)
{

    if (row < 0 || col < 0 || row >= bord.size() || col >= bord[0].size())
    {
        return;
    }

    if (row == bord.size() - 1 && col == bord[0].size() - 1)
    {
        cout << psf << endl;
        return;
    }

    if (!bord[row][col])
    {
        bord[row][col] = 1;

        //top
        solve(bord, row - 1, col, psf + 't');
        //bottom
        solve(bord, row + 1, col, psf + 'b');
        //right
        solve(bord, row, col + 1, psf + 'r');
        //left
        solve(bord, row, col - 1, psf + 'l');
        bord[row][col] = 0;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bord = input(n, m);
    solve(bord, 0, 0, "");
}
