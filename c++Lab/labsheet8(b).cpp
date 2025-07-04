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
    void addEdge(int src, int dest)
    {
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;
    }
    void DFSUtil(int vertex, bool visited[])
    {
        visited[vertex] = true;
        for (int neighbor = 0; neighbor < numVertices; neighbor++)
        {
            if (adjacencyMatrix[vertex][neighbor] == 1 && !visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }
    bool isConnected()
    {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }
        DFSUtil(0, visited);
        for (int i = 0; i < numVertices; i++)
        {
            if (!visited[i])
            {
                delete[] visited;
                return false;
            }
        }
        delete[] visited;
        return true;
    }
};
int main()
{

    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    bool connected = graph.isConnected();
    if (connected)
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;
    return 0;
}