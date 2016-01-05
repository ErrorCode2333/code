#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define _MAX  100
int N;

vector<int> s[_MAX][_MAX];


void f (int m)
{
    cout << m << " ";
}

vector<int> merge(int m, vector<int> v)
{
    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        *it = (*it) + m;
        it++;
    }

    return v;
}

vector<int> step(int arr [], int k, int i)
{
    if (i == 1)
    {
        vector<int> v;
        for (int j = 1; j <= k; j++)
        {
            v.push_back(arr[j]);
        }

        return v;
    }

    if (k == i)
    {
        vector<int> v;
        int _sum = 0;
        for (int j = 1; j <= k; j++)
            _sum += arr[j];

        v.push_back(_sum);

        return v;
    }


    vector<int> v2 = merge(arr[k], s[k - 1][i - 1]);
    vector<int> v3;

    v3.insert(v3.end(), s[k - 1][i].begin(), s[k - 1][i].end());
    v3.insert(v3.end(), v2.begin(), v2.end());

    return v3;
}

int main() 
{
    cin >> N;
    int arr[2 * N + 1];
    for (int i = 1; i <= 2 * N; i++)
        cin >> arr[i];


    for (int k = 1; k <= N * 2; k++)
        for (int i = 1; i <= k; i++)
        {
            s[k][i] = step(arr, k, i);
        }

    for_each(s[2 * N][N].begin(), s[2 * N][N].end(), f);

    system("pause");
    return 0;
}
