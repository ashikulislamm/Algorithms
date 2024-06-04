#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mat[10][10];

queue<int> order;

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << mat[i][j] << "\t";
        cout << endl;
    }
}

void tsp(int n, int src)
{
    int reduced_cost = 0, mn;

    //Initial cost reduce to calcutale the bound
    for (int i = 0; i < n; i++)
    {
        mn = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 9999)
                mn = min(mn, mat[i][j]);
        }

        for (int k = 0; k < n; k++)
            mat[i][k] -= mn;

        reduced_cost += mn;
    }

    for (int i = 0; i < n; i++)
    {
        mn = INT_MAX;
        for (int j = 0; j < n; j++)
            mn = min(mn, mat[j][i]);

        for (int k = 0; k < n; k++)
            mat[k][i] -= mn;

        reduced_cost += mn;
    }

    int t = n - 1, mnnode = -1, mncost = 9999;
    //Loop to calculate path from source
    while (t--)            
    {
        int tmat[10][10], mnmat[10][10];

        //Create copy of the main matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmat[i][j] = mat[i][j];
            }
        }

        // Calculate the cost to visit all adjacent nodes from current source node
        for (int i = 0; i < n; i++)
        {
            //Check if it is possible to visit the node
            if (mat[src][i] != 9999)
            {

                int ttmat[10][10];

                //Create a copy of the current state of the matrix
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        ttmat[j][k] = tmat[j][k];
                        if (j == src)
                            ttmat[j][k] = 9999;

                        if (k == i)
                            ttmat[j][k] = 9999;
                    }
                }

                ttmat[i][src] = 9999;

                int rc = 0;

                //Cost reduce for the current matrix
                //Row reduce
                for (int j = 0; j < n; j++)
                {
                    mn = 9999;
                    for (int k = 0; k < n; k++)
                        mn = min(mn, ttmat[j][k]);

                    if (mn != 9999)
                    {
                        for (int l = 0; l < n; l++)
                            ttmat[j][l] -= mn;

                        rc += mn;
                    }
                }

                //Column reduce
                for (int j = 0; j < n; j++)
                {
                    mn = 9999;
                    for (int k = 0; k < n; k++)
                        mn = min(mn, ttmat[k][j]);

                    if (mn != 9999)
                    {
                        for (int l = 0; l < n; l++)
                            ttmat[l][j] -= mn;

                        rc += mn;
                    }
                }

                rc = rc + mat[src][i] + reduced_cost;

                //Store the node is cost is minimum to visit
                if (rc < mncost)
                {
                    mncost = rc;
                    mnnode = i;
                    for (int j = 0; j < n; j++)
                    {
                        for (int k = 0; k < n; k++)
                            mnmat[j][k] = ttmat[j][k];
                    }
                }
            }
        }

        //Update the main matrix
        src = mnnode;
        order.push(src + 1);
        reduced_cost = mncost;
        mncost = 9999;
        mnnode = -1;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                mat[j][k] = mnmat[j][k];
        }

        cout << endl;
        print(n);
    }

    cout << reduced_cost + mat[src][0];
}

int main()
{
    int n, e;
    cin >> n >> e;

    cout << n << e << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = 9999;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cout<<"Enter Values : "<<endl;
        cin >> u >> v >> w;

        u--;
        v--;

        mat[u][v] = w;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << mat[i][j] << " ";
        cout << endl;
    }

    int src = 1;
    src--;

    order.push(1);
    tsp(n, src);
    order.push(1);

    cout << endl;
    while (!order.empty())
    {
        cout << order.front() << " ";
        order.pop();
    }

    return 0;
}