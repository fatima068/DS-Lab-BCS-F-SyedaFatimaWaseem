/*Question#5: For the following graph implement the following:
 Create an Adjacency List and Adjacency Matrix. Display the list and matrix.
 Traverse the graph using BFS and DFS.
 Display the output for both the traversals.*/
#include <iostream>
#include <string>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;
    int* visited;
    
public:
    Graph(int v) : vertices(v) {
        adjMatrix = new int*[vertices];
        for(int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for(int j = 0; j < vertices; j++)
                adjMatrix[i][j] = 0;
        }
        
        visited = new int[vertices];
        for(int i = 0; i < vertices; i++) 
            visited[i] = 0;
    }
    
    ~Graph() {
        for(int i = 0; i < vertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
        delete[] visited;
    }
    
    void setEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }
    
    void displayAdjMatrix() {
        for(int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        for(int i = 0; i < vertices; i++) {
            cout << i << " ";
            for(int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void displayAdjList() {
        for(int i = 0; i < vertices; i++) {
            cout << i << ",";
            bool first = true;
            for(int j = 0; j < vertices; j++) {
                if(adjMatrix[i][j] == 1) {
                    if(!first) cout << ",";
                    cout << j;
                    first = false;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void BFS(int startVertex) {
        for(int i = 0; i < vertices; i++) 
            visited[i] = 0;
        int* queue = new int[vertices];
        int front = 0, rear = 0;
        
        visited[startVertex] = 1;
        queue[rear++] = startVertex;
        
        while(front < rear) {
            int current = queue[front++];
            cout << current << " ";
            for(int i = 0; i < vertices; i++) {
                if(adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
        delete[] queue;
    }
    
    void DFShelper(int vertex) {
        visited[vertex] = 1;
        cout << vertex << " ";
        for(int i = 0; i < vertices; i++) {
            if(adjMatrix[vertex][i] == 1 && !visited[i]) 
                DFShelper(i);
        }
    }
    
    void DFS(int startVertex) {
        for(int i = 0; i < vertices; i++) 
            visited[i] = 0;
        DFShelper(startVertex);
    }
};

int main() {
    Graph graph(5);
    graph.setEdge(0, 1);
    graph.setEdge(0, 2);
    graph.setEdge(1, 3);
    graph.setEdge(1, 4);
    graph.setEdge(2, 3);
    graph.setEdge(3, 4);
    graph.displayAdjList();
    graph.displayAdjMatrix();
    graph.BFS(0);
    graph.DFS(0);
