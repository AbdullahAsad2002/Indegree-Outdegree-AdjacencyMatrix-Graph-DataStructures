#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class graph
{
private:
    int **matrix;
    int *inDegree;
    int *outDegree;
    int v;
public:
    graph()
    {
        matrix = new int *[4];
        inDegree = new int[4];
        outDegree = new int[4];
        v = 4;
        for (int i = 0; i < 4; i++)
        {
            matrix[i] = new int[4];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                matrix[i][j] = 0;
            }
            inDegree[i] = 0;
            outDegree[i] = 0;
        }
    }
    graph(int vertices)
    {
        matrix = new int *[vertices];
        inDegree = new int[vertices];
        outDegree = new int[vertices];
        v = vertices;
        for (int i = 0; i < vertices; i++)
        {
            matrix[i] = new int[vertices];
        }
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                matrix[i][j] = 0;
            }
            inDegree[i] = 0;
            outDegree[i] = 0;
        }
    }
    void insertInmatrix(int v1, int v2, int e)
    {
        matrix[v1][v2] = e;
    }
    void Calculate_In_Out_deg()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (matrix[i][j] != 0)
                {
                    outDegree[i] = outDegree[i] + 1;
                    inDegree[j] = inDegree[j] + 1;
                }
            }
        }
    }
    void printMatrix()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void print_In_Out_deg()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "outdegree of " << i << " = " << outDegree[i] << " , ";
            cout << "indegree of " << i << " = " << inDegree[i] << endl;
        }
    }
    ~graph()
    {
        for (int i = 0; i < v; i++)
        {
            delete (matrix[i]);
        }
        delete matrix;
        delete inDegree;
        delete outDegree;
        cout << "destructor Called .." << endl;
    }
};
int main()
{
    int vertices;
    int edges;
    ifstream in;
    in.open("graph.txt");
    string str;
    getline(in,str);
    stringstream ve(str);
    string n;
    getline(ve,n,',');
    vertices = stoi(n);
    cout<<"Total vertices are : "<<vertices<<endl;
    getline(ve,n);
    edges = stoi(n);
    cout<<"Total edges are : "<<edges<<endl;
    graph g1(vertices);
    int v1, v2, weight;
    for (int i = 0; i < edges; i++)
    {
        getline(in, str);
        stringstream ss(str);
        string num;
        getline(ss, num, ',');
        v1 = stoi(num);
        cout << v1 << " ";
        getline(ss, num, ',');
        v2 = stoi(num);
        cout << v2 << " ";
        getline(ss, num, ',');
        weight = stoi(num);
        cout << weight << " ";
        cout << endl;
        g1.insertInmatrix(v1, v2, weight);
    }
    cout << "The Adjacency Matrix is :" << endl;
    g1.printMatrix();
    g1.Calculate_In_Out_deg();
    g1.print_In_Out_deg();
    return 0;
}