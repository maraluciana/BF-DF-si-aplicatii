#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


ifstream fin("sortaret.in");
ofstream fout("sortaret.out");


#define MAXN 100005

stack<int> st;
vector<int> lista[MAXN];
int viz[MAXN] = {0};
int N, M;



void DFS(int nod)
{
    viz[nod] = 1;
    for(auto vecin:lista[nod])
        if(!viz[vecin])
            DFS(vecin);

    st.push(nod);
}



int main()
{
    fin >> N >> M;

    int x,y;

    for(int i = 0; i < M; i++)
    {
        fin >> x >> y;
        lista[x].push_back(y);
    }

    for(int i = 1; i <= N; i++)
        if(!viz[i])
            DFS(i);

    while(!st.empty())
    {
        fout << st.top() << ' ';
        st.pop();
    }


    fin.close();
    fout.close();

    return 0;
}
