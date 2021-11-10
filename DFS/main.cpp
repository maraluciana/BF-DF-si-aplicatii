#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 100004

int N, M, c = 1;
vector<int> lista[MAXN];
int viz[MAXN] = {0};
stack<int> st;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

void DFS(int nod)
{
    viz[nod] = c;
    for(auto vecin:lista[nod])
        if(!viz[vecin])
        {
            viz[vecin] = c;
            DFS(vecin);
        }
}

int main()
{
    int X, Y;

    fin >> N >> M ;

    for(int i = 0; i < M; i++)
    {
        fin >> X >> Y;
        lista[X].push_back(Y);
        lista[Y].push_back(X);
    }

    DFS(X);

    for(int i = 1; i <= N; i++)
        if(!viz[i])
        {
            c++;
            DFS(i);
        }

    fout << c;

    return 0;
}
