#include <iostream>
#include <vector>

using namespace std;

int minimumValueNode(const vector<int>& values, const vector<bool>& visited) {
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
	vector<vector<int>> graph = { {0,10,0,0,15,5},
								{10,0,10,30,0,0},
								{0,10,0,12,5,0},
								{0,30,12,0,0,20},
								{15,0,5,0,0,0},
								{5,0,0,20,0,0} };

	const int NO_CITIES = 6;
	int START_CITY = 0;

	vector<int> parent(NO_CITIES);
	vector<bool> visited(NO_CITIES, false);
	vector<int> values(NO_CITIES, INT32_MAX);

	values[START_CITY] = 0;
	parent[START_CITY] = -1;

	for (int i = 0; i < NO_CITIES - 1; i++) {
		int idx = minimumValueNode(values, visited);
		visited[idx] = true;

		for (int j = 0; j < NO_CITIES; j++) {
			if (graph[idx][j] != 0 && visited[j] == false && graph[idx][j] + values[idx] < values[j]) {
				values[j] = graph[idx][j] + values[idx];
				parent[j] = idx;
			}
		}
	}

	for (int j = 0; j < NO_CITIES; j++) {
		if (j != START_CITY) {
			cout << "Distance of City " << j << " = " << values[j] << "\n";
			
			cout << "Path=" << j ;
			
			int current = j;
			while (current != START_CITY) {
				current = parent[current];
				cout << "<-" << current;
			}
			cout << "\n\n";
		}
	}
}