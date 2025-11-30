/*Question#6: Use Dijkstra&s algorithm to find the shortest path from node B to node E in the graph below.*/
#include <iostream>
#include <string>
using namespace std;
class Graph{
private:
    int vertices;
    int** weightMatrix;
    int* visited, *distance, *previous;
    const int INF = 9999;
    
public:
    Graph(int v) : vertices(v){
        weightMatrix = new int*[vertices];
        for(int i = 0; i < vertices; i++) {
            weightMatrix[i] = new int[vertices];
            for(int j = 0; j < vertices; j++) {
                if(i == j)
                    weightMatrix[i][j] = 0;
                else
                    weightMatrix[i][j] = INF;
            }
        }
        visited =new int[vertices];
        distance =new int[vertices];
        previous =new int[vertices];
    }
    
    ~Graph(){
        for(int i = 0; i < vertices; i++) {
            delete[] weightMatrix[i];
        }
        delete[] weightMatrix;
        delete[] visited;
        delete[] distance;
        delete[] previous;
    }
    
    void setWeightedEdge(int u, int v, int weight) {
        weightMatrix[u][v] = weight;
        weightMatrix[v][u] = weight; 
    }
    
    int findMinDistance() {
        int minDist = INF;
        int minVertex = -1;    
        for(int i = 0; i < vertices; i++) {
            if(!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                minVertex = i;
            }
        }
        return minVertex;
    }
    
    void Dijkstra(int source, int target) {
        for(int i = 0; i < vertices; i++) {
            visited[i] = 0;
            distance[i] = INF;
            previous[i] = -1;
            if(i == source) 
                distance[i] = 0;
        }
        
        while(!visited[target]) {
            int selected_node = findMinDistance();
            if(selected_node == -1) break;
            visited[selected_node] = 1;
            
            for(int v = 0; v < vertices; v++) {
                if(!visited[v] && weightMatrix[selected_node][v] != INF) {
                    int alt = distance[selected_node] + weightMatrix[selected_node][v];
                    if(alt < distance[v]) {
                        distance[v] = alt;
                        previous[v] = selected_node;
                    }
                }
            }
        }
        printPathAndDistance(source, target);
    }
    
    void printPathAndDistance(int source, int target) {
        cout << "Shortest path from " << char('A' + source) << " to " << char('A' + target) << ": ";
        if(distance[target] == INF) {
            cout << "No path exists" << endl;
            return;
        }
        cout << "Distance = " << distance[target] << ", Path = ";
        printPath(target);
        cout << endl;
    }
    
    void printPath(int vertex) {
        if(previous[vertex] == -1) {
            cout << char('A' + vertex);
            return;
        }
        printPath(previous[vertex]);
        cout << " -> " << char('A' + vertex);
    }
};

int main() {
    Graph graph(6);
    graph.setWeightedEdge(0, 1, 4);  
    graph.setWeightedEdge(0, 2, 8);  
    graph.setWeightedEdge(1, 2, 9);  
    graph.setWeightedEdge(1, 3, 8);  
    graph.setWeightedEdge(2, 4, 6);  
    graph.setWeightedEdge(3, 4, 14); 
    graph.setWeightedEdge(3, 5, 3);  
    graph.setWeightedEdge(4, 5, 9);   
    graph.Dijkstra(1, 4);
}
