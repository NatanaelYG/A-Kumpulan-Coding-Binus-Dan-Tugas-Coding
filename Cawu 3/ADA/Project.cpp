#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100001

typedef struct Node {
    int id;
    struct Node* next;
} Node;

Node* adj[MAX_N];
int dp[MAX_N][2];  // dp[i][0]: MIS size not including i, dp[i][1]: MIS size including i

void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = 1;

    for (Node* v = adj[u]; v != NULL; v = v->next) {
        if (v->id != parent) {
            dfs(v->id, u);
            dp[u][0] += (dp[v->id][0] > dp[v->id][1] ? dp[v->id][0] : dp[v->id][1]);
            dp[u][1] += dp[v->id][0];
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 2) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(1, 0);  // Start DFS from node 1

    int mis_size = (dp[1][0] > dp[1][1] ? dp[1][0] : dp[1][1]);
    long long result = (long long)mis_size * (N - 1);

    printf("%lld\n", result);

    return 0;
}
