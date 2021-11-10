#include <iostream>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

int main()
{
    //N - nr noduri ; M - nr muchii; S - start
    int N, M, S, nod, x, y;

    fin >> N >> M >> S;

    int dist[N + 1];

    for(int i = 1; i <= N; i++)
        dist[i] = -1;



    queue<int> st;
    vector<int> lista[N + 1];


    for(int i = 0; i < M; i++)
    {
        fin >> x >> y;
        lista[x].push_back(y);

    }


    st.push(S);
    dist[S] = 0;

    while(!st.empty())
    {
        nod = st.front();
        st.pop();

        for(auto vecin:lista[nod])
        {
            if(dist[vecin] == -1)
            {
                st.push(vecin);
                dist[vecin] = dist[nod] + 1;
            }
        }
    }

    for(int i = 1; i <= N; i++)
        fout << dist[i] << ' ';

    fin.close();
    fout.close();

    return 0;
}
