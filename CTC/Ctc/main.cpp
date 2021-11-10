#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

#define MAXN 100005

stack<int> st;
vector<int> lista[MAXN];
vector<int> listaT[MAXN];
vector<int> ctc[MAXN];
int viz[MAXN] = {0};
int vizT[MAXN] = {0};
int N, M, c = 0;


void DFS(int nod)
{
    viz[nod] = 1;
    for(auto vecin:lista[nod])
        if(!viz[vecin])
        {
            viz[vecin] = 1;
            DFS(vecin);
        }

    st.push(nod);
}

void DFST(int nod, int p)
{
    vizT[nod] = c;
    for(auto vecin:listaT[nod])
        if(!vizT[vecin])
        {
            vizT[vecin] = c;
            ctc[p].push_back(vecin);
            DFST(vecin, p);
        }
}



int main()
{
    int x, y;

    fin >> N >> M;


    for(int i = 0; i < M; i++)
    {
        fin >> x >> y;
        lista[x].push_back(y);
        listaT[y].push_back(x);
    }

    for(int i = 1; i <= N; i++)
        if(!viz[i])
            DFS(i);


    while(!st.empty())
    {
        x = st.top();
        st.pop();

        if(!vizT[x])
        {
            c++;
            ctc[c].push_back(x);
            DFST(x, c);
        }
    }

    fout << c << endl;

    for(int i = 1; i <= c; i++)
        if(!ctc[i].empty()){
            for(auto comp:ctc[i])
                fout << comp << ' ';
        fout << endl;
        }

    fin.close();
    fout.close();

    return 0;
}
