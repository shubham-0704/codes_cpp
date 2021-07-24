# Graph
* refer note for some theory

## 1. BFS

```cpp
void BFS(vector<int> adj[], int V, int s)// s== source generally 0 
{ 
	bool visited[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
} 
// directed 
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    bool vis[V]={0};
	    vector<int>ans;
	    queue<int>q;
	    q.push(0);
	    while(q.size()>0){
	        if(vis[q.front()]!=1){
	        ans.push_back(q.front());
	        vis[q.front()]=1;
                for(auto i:adj[q.front()]){
                   if(!vis[i]) q.push(i);
                }   
	        }
	        
	        q.pop();
	    }
	    return ans;
	}
```
## Bfs for diconnnected graph also count of conneted graph
```cpp
void BFS(vector<int> adj[], int s, bool visited[]) 
{ 	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

void BFSDin(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            BFS(adj,i,visited);
    }
}

// counting number of connetd grpahs
void BFS(vector<int> adj[], int s, bool visited[]) 
{ 	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

int BFSDin(vector<int> adj[], int V){
    bool visited[V]; int count=0;
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {BFS(adj,i,visited);count++;}
    }

    return count;
}
```

## 2.DFS
```cpp
//conneted grpah
	void dfs(vector<int> adj[],int i,bool vis[],vector<int>&ans){
	    ans.push_back(i);
	    vis[i]=1;
	    for(auto e:adj[i]){
	        if(!vis[e])dfs(adj,e,vis,ans);
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
        vector<int>ans;
        bool vis[V+1]={0};
        
         dfs(adj,0,vis,ans);
     
	    return ans;
	}

// for diconnected grpah
	void dfs(vector<int> adj[],int i,bool vis[],vector<int>&ans){
	    ans.push_back(i);
	    vis[i]=1;
	    for(auto e:adj[i]){
	        if(!vis[e])dfs(adj,e,vis,ans);
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	
        vector<int>ans;
        bool vis[V+1]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i])dfs(adj,i,vis,ans);
        }
	    return ans;
	}
// same code as above but it counts
void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

int DFS(vector<int> adj[], int V){
    int count=0;
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {DFSRec(adj,i,visited);count++;}
    }
    return count;
}
```

## 3.cycle detection using DFS
```cpp
// undirected graph
// parent is use to avoid a corner case eg  0 -- 1
bool DFSRec(vector<int> adj[], int s,bool visited[], int parent) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false){
            if(DFSRec(adj,u,visited,s)==true)
                {return true;}}
        else if(u!=parent)
            {return true;}
    }
    return false;
}

bool DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i=0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,-1)==true)
                return true;
    }
    return false;
}

// using BFS
    bool bfs(int curr,vector<int>adj[], vector<bool>&vis){
        int par=-1;
        queue<pair<int,int>>q;q.push({curr,-1});
        vis[curr]=1;
        
        while(q.size()){
            pair<int,int> t=q.front();
            q.pop();
            
            for(auto i :adj[t.first]){
                if(vis[i] && i!=t.second)return 1;
                else if(vis[i]==0){
                    q.push({i,t.first});vis[i]=1;
                }
            }
        }
        
        return 0;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>vis(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	           if( bfs(i,adj,vis))return 1;
	        }
	    }
	    return 0;
	}
```
```cpp
// directed graph
0 --> 1 <--2  corner case

bool DFSRec(vector<int> adj[], int s,bool visited[], bool recSt[]) 
{ 	
    visited[s]=true;
    recSt[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false && DFSRec(adj,u,visited,recSt)==true)
                {return true;}
        else if(recSt[u]==true)
            {return true;}
    }
    recSt[s]=false;
    return false;
}
bool DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i=0;i<V; i++) 
		visited[i] = false;
	bool recSt[V]; 
	for(int i=0;i<V; i++) 
		recSt[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,recSt)==true)
                return true;
    }
    return false;
}
```

## cycle detection using topological sorting
```cpp
void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

    int count=0;  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
        count++;
    } 
    if (count != V) { 
        cout << "There exists a cycle in the graph\n"; 
    }
    else{
        cout << "There exists no cycle in the graph\n";
    }
}
```

## topological sort (DFS)
```cpp
void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{ 	
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    st.push(u);
}


void topologicalSort(vector<int> adj[], int V) 
{ 
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
	stack<int> st;
    
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
   
}
```
## topological sort (Kahn's BFS Based Algortihm)
```cpp
void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        cout<<u<<" "; 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
    } 
}

```

## shortest distnace and no of paths of lenght shortest distnace
```cpp
//another way tak int_max in in distnace array and bfs trnaverse
// dist [n] = {INT_MAX ......}
//  for(auto i:adj[curr]){
//      if(dis[curr]+1<dist[i]){
//          dist[i]=dist[curr]+1;q.push(i);
//      }
//  }

// for weighted used above and insted of 1 used weight

// different way
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

int bfs(int src,int des,vector<int>adj [],int n){
    vector<int>vis(n,-1);
    vector<int>path(n,-1);
    queue<int>q;q.push(src);
    vis[src]=0; // shortest distance
    path[src]=1; // no. of paths of shortest distnace length
    while(q.size()){
        int curr= q.front();q.pop();

        for(auto i : adj[curr]){
            if(vis[i]<0){  // this vis may not be neccesary if checked for vis[i]>vis[curr]+1;
                q.push(i);
                vis[i]=vis[curr]+1;
                path[i]=path[curr];
            }
            else if(vis[i]==vis[curr]+1){
                path[i]+=path[curr];
            }
        }
    }

    return path[des];
}

int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);

  int n;n=9;
  vector<int> adj[n];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    add_edge(adj, 5, 8);
    add_edge(adj, 6, 8);

    int t=10;
    while(t--){
        int s;int des;cin>>s>>des;
        cout<<bfs(s,des,adj,n)<<endl;
    }
return 0;
}
```

## shortest distnace in case of directed graph with weight

```cpp

//first make top sort stack using dfs even 
//(bfs topshort is also can be used)
st -->stack which stores top sort;
make dist [] ={INT_MAX};
dist[src]=0;
while(st.size()){
    it curr=st.top();
    st.pop();

    if(dis[curr]!=INT_MAX){
        for(auto i:adj[curr]){
            if(dis[curr]+i.second<dist[i.first]){
                dist[i.first]=dis[curr]+i.second;
            }
        }
    }
}
// hence dist will have shorte path for each node from source node
```

## Dijkstra's Algorithm | Shortest Path in Undirected Graphs with weight
```cpp
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
```

# Minimum spannig tree

## prim's algo

```cpp
array key []={INT_MAX...}
array mst[n] ={false}
array par[] = {-1 ...}
key[0]=0;
index =search min in key which is not in mst
mst[index]=1;

for(auto i: adj[index]){
    if(i.first != mst && i.weight< key[i]){
        key[i.first]=i.weight;
        par[i.first]=index;
    }
}
```
```cpp
// O(n^2)  solution
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	int parent[N];  
    int key[N];  
    bool mstSet[N]; 
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    {    
        int mini = INT_MAX, u; 
        for (int v = 0; v < N; v++) 
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v;             
        mstSet[u] = true;     
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
// O(n logn) 

    int key[N]; 
    int parent[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
```

## Disjoint set (Union and path compression)
```cpp
// find parent and will doing path compreesion
int findpar(vector<int>& par,vector<int>&rank,int i){
    if(i==par[i])return i;
    // path compression
    else par[i]= findpar(par,rank,par[i]);
}
// making union
void uni(vector<int>& par,vector<int>&rank,int a,int b ){
     a=findpar(par,rank,a);
     b=findpar(par,rank,b);

     if(rank[a]==rank[b]){
         par[b]=a;
         rank[a]++;
     }else if(rank[a]<rank[b]){
         par[a]=b;
     }else{
         par[b]=a;
     }
}

int main() {
  int n;cin>>n;
  vector<int>par(n);
  vector<int>rank(n,0);
  for(int i=0;i<n;i++)par[i]=i;  

  // if two points are in same component
   findpar(a)==findpar(b);

}
```
## Kruskal's Algorithm
```cpp
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}

```

## bridges in graph
```cpp
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}
```