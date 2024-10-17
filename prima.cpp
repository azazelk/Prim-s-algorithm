#include <iostream>
#include <vector>
#include <algorithm>

#define INF 9999
using namespace std;

void prim(vector<vector<int>>& graph, const size_t& size){
    int sum = 0;
    vector<int> visited;
    vector<int> unvisited;
    cout << "\nАлгоритм Прима выполняется...\nОстовное дерево:\n";
    for (int i = 1; i < size; i++){
        unvisited.push_back(i);
    }
    visited.push_back(0);
    int minimum = INF;
    int a = 0;
    cout << "V" << a+1 << " ";
    for (int i = 0; i < size; i++){
        if (graph[0][i] != 0 && graph[0][i] < minimum){
            minimum = graph[0][i];
            a = i;
        }
    }
    sum += minimum;
    minimum = INF;
    visited.push_back(a);
    unvisited.erase(find(unvisited.begin(), unvisited.end(), a));
    cout << "V" << a+1 << "\n";
    int b = 0;
    while (!unvisited.empty()){
        for (int i : visited){
            for (int j = 0; j < size; j++){
                if ((graph[i][j] != 0 && find(visited.begin(), visited.end(), j) == visited.end()) && graph[i][j] < minimum){
                    minimum = graph[i][j];
                    a = j;
                    b = i;
                }
            }
        }
        visited.push_back(a);
        unvisited.erase(find(unvisited.begin(), unvisited.end(), a));
        sum += minimum;
        minimum = INF;
        cout << "V" << b+1 << " " << "V" << a+1 << "\n";
    }
    cout << "Конечная сумма остовного дерева: " << sum << "\n";
}

int main(){
  const size_t size = 7;
  vector<vector<int>> graph{
         {0, 4, 12, 0, 0, 16, 5},
         {4, 0, 2, 0, 0, 0, 1},
         {12, 2, 0, 10, 4, 1, 2},
         {0, 0, 10, 0, 9, 7, 5},
         {0, 0, 4, 9, 0, 10, 3},
         {16, 0, 1, 7, 10, 0, 12},
         {5, 1, 2, 5, 3, 12, 0}};
  cout << "Матрица смежности графа:\n";
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
  prim(graph, size);
}