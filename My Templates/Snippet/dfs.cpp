void dfs(int vertex) {
	//Take action on vertex after entering the vertex
	cout << vertex << endl;
	vis[vertex] = true;
	for(int child: graph[vertex]) {
		//Take action on child before entering the child node
		cout << "Par: " << vertex << ", Child: " << child << endl; 
		if(vis[child]) continue;
		dfs(child);
		// Take action on child before exiting  the child node
	}
	// Take action on vertex after exiting the vertex 
}
//O(V+E)
