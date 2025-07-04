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
    void BFS(int startVertex)
    {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }
        int *queue = new int[numVertices];
        int front = -1;
        int rear = -1;
        visited[startVertex] = true;
        queue[++rear] = startVertex;
        cout << "BFS Traversal: ";
        while (front != rear)
        {
            int currentVertex = queue[++front];
            cout << currentVertex << " ";
            for (int neighbor = 0; neighbor < numVertices; neighbor++)
            {
                if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue[++rear] = neighbor;
                }
            }
        }
        delete[] visited;
        delete[] queue;
    }
    void DFSUtil(int vertex, bool visited[])
    {
        visited[vertex] = true;
        cout << vertex << " ";
        for (int neighbor = 0; neighbor < numVertices; neighbor++)
        {
            if (adjacencyMatrix[vertex][neighbor] == 1 && !visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }
    void DFS(int startVertex)
    {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }
        cout << "DFS Traversal: ";
        DFSUtil(startVertex, visited);
        delete[] visited;
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

    cout << "Performing BFS traversal..." << endl;
    graph.BFS(0);
    std::cout << endl;

    cout << "Performing DFS traversal..." << endl;
    graph.DFS(0);
    cout << endl;
    return 0;
}