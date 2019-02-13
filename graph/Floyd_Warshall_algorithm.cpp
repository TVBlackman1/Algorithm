/*
 *  Floyd-Warshall algorithm
 *  work with array
 *  NO -> the absence of edges in a graph
 *
 *
 */


#include <iostream>
#include <limits>

using namespace std;


#define _min(a, b) a > b ? b : a
#define inf numeric_limits<float>::infinity()
#define NO inf


int main()
{
    int n = 6; // size matrix

    float matrix[n][n] = {
            {0, 6, 8, NO, NO, NO},
            {5, 0, 5, NO, NO, NO},
            {1, 7, 0, NO, NO, NO},
            {NO, NO, NO, 0, 6, NO},
            {NO, NO, NO, NO, 0, 3},
            {NO, NO, NO, 2, NO, 0}
    };
    //fill matrix

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = _min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    // work this array

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // output

    system("pause");
}