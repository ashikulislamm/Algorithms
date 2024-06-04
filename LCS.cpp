#include<bits/stdc++.h>

using namespace std;

//abc
//acb
string x;
string y;
int c[1000][1000];
int b[1000][1000];

void Print_LCS( string x, int i, int j)
{
    if(i == 0 || j == 0)
    {
        //cout<<endl;
        return;
    }
        
    if(b[i][j] == 1)
    {
        Print_LCS(x, i - 1, j - 1);
        cout << x[i - 1];
    }
    else if(b[i][j] == 2)
    {
        Print_LCS( x, i - 1, j);
    }
    else
    {
        Print_LCS(x, i, j - 1);
    }
}
void PrintAlllcs(int i, int j, int m)
{
    if(i==0 || j==0)
    {
        cout<<endl;
        return;
    }
    if(c[i][j]==c[i][j-1] && c[i][j]==m)
    {
        PrintAlllcs(i, j-1,m);
    }
    if(c[i][j]==c[i-1][j] && c[i][j]==m)
    {
         PrintAlllcs(i-1, j,m);
    }
    else{
        
        PrintAlllcs(i-1, j-1,m);
        cout<<x[i-1];
    }
}


void LCS_Length(string x, string y)
{
    int m = x.size();
    int n = y.size();

    // vector<vector<int> > c(m + 1, vector<int> (n + 1));
    // vector<vector<int> > b(m + 1, vector<int> (n + 1, 0));

    for(int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for(int j = 1; j <= n; j++)
    {
        c[0][j] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if(c[i - 1][j] >= c[i][j -1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }

    cout << "LCS: ";
    Print_LCS(x, m, n);
    cout << endl;
    cout << "Length of LCS: " << c[m][n]<<endl;

    cout<<"LCS Matrix"<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    

    cout << "Enter 1st string: ";
    cin >> x;

    cout << "Enter 2nd string: ";
    cin >> y;

    LCS_Length(x, y);

    int p = c[x.length()][ y.length()];

    PrintAlllcs(x.length(), y.length(),p);
}