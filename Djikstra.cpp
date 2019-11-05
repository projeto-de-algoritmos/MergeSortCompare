#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forn1(i, n) for (ll i = 1; i <= n; i++)
#define EPS 1e-9
#define pb push_back
#define sortx(x) sort(x.begin(), x.end())

using ll = long long;
using ii = pair<ll, ll>;

const ll MAX{1010}, oo{1000000000000000010LL};
ll dist[MAX];
vector<ii> adj[MAX];
bitset<MAX> processed;

void dijkstra(int s, int N)
{    
    //inicializa as distancias como infinito
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    //distancia da saida ate ela mesma é 0
    dist[s] = 0;

    //reseta os vertices processados pois podem ser varios testes
    processed.reset();

    //mantem fila de prioridade de nós nao explorados
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (not pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        auto d = p.first, u = p.second;

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto &q : adj[u])
        {
            auto v = q.first, w = q.second;

            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int n_casos, ans=0;
    // cout << "\nDigite o numero de casos\n";
    cin >> n_casos;

    for (int i = 0; i < n_casos; ++i)
    {
        //n de ratos eh o n de celulas: 1 rato em cada celula logo a resposta do problema eh sempre no min 1
        int cells, saida, tempo;
        ans=0;
        // cout << "\nDigite o numero de celulas do labirinto\n";
        cin >> cells;
        // cout << "\nDigite a celula de saida\n";
        cin >> saida;
        // cout << "\nDigite o tempo maximo para os ratos sairem do labirinto\n";
        cin >> tempo;

        for (int i = 0; i < MAX; ++i)
            adj[i].clear();

        int conexoes;
        // cout << "\nDigite o numero de conexoes entre as celulas do labirinto\n";
        cin >> conexoes;

        while (conexoes--)
        {
            int u, v, time;
            // cout << "\nDigite a celula de inicio e com qual outra celula ela se conecta\n";
            cin >> u >> v;
            // cout << "\nDigite o tempo para travessia\n";
            cin >> time;
            /*A aresta é invertida pois ao inves de calcular djiksta de cada aresta para saida
            calculamos apenas djikstra da saida para todos*/
            adj[v].push_back(ii(u, time));
        }
        dijkstra(saida, cells);
        // for(int i=1; i<=cells; i++){

        //     for(int j=0; j<adj[i].size(); j++){
        //         cout << "aresta " << i << " até " << adj[i][j].first << " custa t=" << adj[i][j].second << endl;
        //     }

        // }
            for(int i=1; i<=cells; i++){
                // cout << "aresta " << 2 << " até " << i << " custa " << dist[i] << endl;
                if(dist[i]<=tempo){
                    ans+=1;
                }
            }

        if(i)
            cout << '\n';

        // cout << "O numero de ratos que conseguiu sair do labirinto é: " << ans << '\n';
    }

    return 0;
}