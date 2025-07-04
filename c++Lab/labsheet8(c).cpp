#include <iostream>
using namespace std;

class Graph
{
private:
    int numVertices;
    int **adjacencyMatrix;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjacencyMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjacencyMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }
    void addEdge(int src, int dest, int weight)
    {
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }
    int findMinDistance(int *dist, bool *visited)
    {
        int minDist = -1;
        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v] && (minDist == -1 || dist[v] < dist[minDist]))
            {
                minDist = v;
            }
        }
        return minDist;
    }
    void printShortestPath(int *dist)
    {
        cout << "Vertex\tDistance from Source\n";
        for (int v = 0; v < numVertices; v++)
        {
            cout << v << "\t" << dist[v] << "\n";
        }
    }
    void dijkstraShortestPath(int src)
    {
        int *dist = new int[numVertices];
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            dist[i] = -1;
            visited[i] = false;
        }
        dist[src] = 0;
        for (int count = 0; count < numVertices - 1; count++)
        {
            int u = findMinDistance(dist, visited);
            visited[u] = true;
            for (int v = 0; v < numVertices; v++)
            {
                if (!visited[v] && adjacencyMatrix[u][v] && (dist[v] == -1 || dist[u] + adjacencyMatrix[u][v] < dist[v]))
                {
                    dist[v] = dist[u] + adjacencyMatrix[u][v];
                }
            }
        }
        printShortestPath(dist);
        delete[] dist;
        delete[] visited;
    }
};
int main()
{

    Graph graph(9);
    graph.addEdge(0, 1, 9);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 9, 8);
    graph.addEdge(1, 2, 11);
    graph.addEdge(9, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 9);
    graph.addEdge(3, 2, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(9, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(2, 7, 1);
    graph.addEdge(6, 8, 9);
    graph.addEdge(9, 2, 7);

    cout << "Performing Dijkstra's algorithm...\n";
    graph.dijkstraShortestPath(0);
    return 0;
}