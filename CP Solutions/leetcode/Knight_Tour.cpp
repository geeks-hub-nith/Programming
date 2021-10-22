//Link:  https://leetcode.com/problems/knight-probability-in-chessboard/
//Author:  Kushgara
//Github : https://github.com/Kushagra1974

#include <iostream>
#include <vector>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

#define loop(i, a, n) for (int i = a; i < n; i++)

void print2d(vector<vector<int>> bord)
{
    cout << endl;
    for (int i = 0; i < bord.size(); i++)
    {
        for (int j = 0; j < bord[0].size(); j++)
        {
            cout << bord[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vvi &bord, int row, int col, int count)
{
    if (row < 0 || col < 0 || row >= bord.size() || col >= bord.size())
    {
        return;
    }
    if (count == bord.size() * bord.size())
    {
        bord[row][col] = count;
        print2d(bord);
        bord[row][col] = 0;
        cout << row << col << endl;
        return;
    }

    if (!bord[row][col])
    {
        bord[row][col] = count + 1;

        solve(bord, row - 2, col + 1, count + 1);
        solve(bord, row - 1, col + 2, count + 1);
        solve(bord, row + 1, col + 2, count + 1);
        solve(bord, row + 2, col + 1, count + 1);
        solve(bord, row + 2, col - 1, count + 1);
        solve(bord, row + 1, col - 2, count + 1);
        solve(bord, row - 1, col - 2, count + 1);
        solve(bord, row - 2, col - 1, count + 1);

        bord[row][col] = 0;
    }
}

int main()
{
    int n, row, col;
    cin >> n >> row >> col;
    vvi bord(n, vi(n, 0));
    solve(bord, row, col, 0);
}