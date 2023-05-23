#include <iostream>
#include <vector>

using namespace std;

int minimumValueNode(const vector<int>& values,const vector<bool>& visited) {
	int min = INT32_MAX;
	int minIndex = -1;
	for (int i = 0; i < values.size(); i++) {
		if (visited[i] == false && values[i] < min) {
			min = values[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int main() {
	vector<vector<int>> graph = { {0,3,0,0,0,1},
								{3,0,2,1,10,0},
								{0,2,0,3,0,5},
								{0,1,3,0,5,0},
								{0,10,0,5,0,4},
								{1,0,5,0,4,0} };

	const int NO_NODES = 6;
	const int START_NODE = 0;
	
	vector<int> parent(NO_NODES);
	vector<bool> visited(NO_NODES, false);
	vector<int> values(NO_NODES, INT32_MAX);
	
	values[START_NODE] = 0;
	parent[START_NODE] = -1;

	for (int i = 0; i < NO_NODES - 1; i++) {
		int idx = minimumValueNode(values, visited);
		visited[idx] = true;

		for (int j = 0; j < NO_NODES; j++) {
			if (graph[idx][j] != 0 && visited[j] == false && graph[idx][j] < values[j]) {
				values[j] = graph[idx][j];
				parent[j] = idx;
			}
		}
	}

	cout << "Edge\t:     Weight\n";
	for (int j = 0; j < NO_NODES; j++) {
		if(j != START_NODE)
			cout << j << " - " << parent[j] << "\t:\t" << values[j] << "\n";
	}
}