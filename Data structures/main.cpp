#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <conio.h>
#include <cmath>
#include <ctime>

using namespace std;

class GraphGenerator {

private:
    int maxWeight, minEdges, edges, verticles;
    double maxEdges;
    int **result;

public:
    GraphGenerator();
    GraphGenerator(int);
    ~GraphGenerator();
};
class Operations {

private:
    struct elementOfList {
        elementOfList *next;
        int n;
        int weight;
    };

    int verticles;
    int edges;

    int **directedGraph;
    int **undirectedGraph;
    int **matrixDirected;
    int **matrixUndirected;
    int **resultsForMatrix;
    int **resultForList;

    int edgeY;

    elementOfList **listUndirectional;
    elementOfList **neighbourList1, *tmp;
    const static double MAXINT = 2147483647;

public:
    int startVerticle, finishVerticle;

    Operations();

    void createDirectedGraph();
    void createUndirectedGraph();

    void createMatrixForDirectedGraph();
    void createMatrixForUndirectedGraph();

    void printMatrixDirected();
    void printMatrixUndirected();

    void makeUndirectedNeighbourList();
    void makeDirectedNeighbourList();

    void printUndirectedNeighbourList();
    void printDirectedNeighbourList();

    void primMatrix();
    void primList();

    void dijkstryMatrix(int);
    void dijkstryList(int);

    void kruskalMatrix(int);
    void kruskalList(int);

    void bellmanFordMatrix(int);
    void bellmanFordList(int);

    bool readFromFile();

    ~Operations();
};

// MENU dla grafu utworzonego losowo
void randomGraph() {
    GraphGenerator generator(5);
    Operations graph;
    graph.createDirectedGraph();
    graph.createUndirectedGraph();
    graph.createMatrixForDirectedGraph();
    graph.createMatrixForUndirectedGraph();
    graph.makeDirectedNeighbourList();
    graph.makeUndirectedNeighbourList();

    int wybor = 0;
    do {
        cout << endl;
        cout << "Wybierz numer:" << endl;
        cout << "1. Wyswietl graf skierowany macierzowo" << endl;
        cout << "2. Wyswietl graf nieskieroway macierzowo" << endl;
        cout << "3. Wyswietl graf skierowany listowo" << endl;
        cout << "4. Wyswietl graf nieskierowany listowo" << endl;
        cout << "5. Algorytm Prima dla reprezentacji macierzowej" << endl;
        cout << "6. Algorytm Prima dla reprezentacji listowej" << endl;
        cout << "7. Algorytm Dijkstry dla reprezentacji macierzowej" << endl;
        cout << "8. Algorytm Dijkstry dla reprezentacji listowej" << endl;
        cout << "9. Algorytm Kruskala dla reprezentacji listowej" << endl;
        cout << "10. Algorytm Kruskala dla reprezentacji macierzowej" << endl;
        cout << "11. Algorytm Bellmana Forda dla reprezentacji listowej" << endl;
        cout << "12. Algorytm Bellmana Forda dla reprezentacji macierzowej" << endl;
        cout << "13. Wyjdź" << endl << endl;
        cin >> wybor;

        switch (wybor) {
            case 1:
                graph.printMatrixDirected();
                break;
            case 2:
                graph.printMatrixUndirected();
                break;
            case 3:
                graph.printDirectedNeighbourList();
                break;
            case 4:
                graph.printUndirectedNeighbourList();
                break;
            case 5:
                graph.primMatrix();
                break;
            case 6:
                graph.primList();
                break;
            case 7:
                graph.dijkstryMatrix(graph.startVerticle);
                break;
            case 8:
                graph.dijkstryList(graph.startVerticle);
                break;
            case 9:
                graph.kruskalList(graph.startVerticle);
                break;
            case 10:
                graph.kruskalMatrix(graph.startVerticle);
                break;
            case 11:
                graph.bellmanFordList(graph.startVerticle);
                break;
            case 12:
                graph.bellmanFordMatrix(graph.startVerticle);
                break;
            default:
                cout << "Bledny numer" << endl;
                break;
        }
    } while (wybor != 13);
}
// MENU dla grafu wczytanego z pliku
void readGraph() {
    bool success;
    Operations graph;
    do {
        success = graph.readFromFile();
    } while (success != true);

    graph.createUndirectedGraph();
    graph.createMatrixForDirectedGraph();
    graph.createMatrixForUndirectedGraph();
    graph.makeDirectedNeighbourList();
    graph.makeUndirectedNeighbourList();

    int wybor = 0;
    do {
        cout << endl;
        cout << "Wybierz opcje: " << endl;
        cout << "1. Wyświetl graf skierowany macierzowo" << endl;
        cout << "2. Wyświetl graf nieskieroway macierzowo" << endl;
        cout << "3. Wyświetl graf skierowany listowo" << endl;
        cout << "4. Wyświetl graf nieskierowany listowo" << endl;
        cout << "5. Algorytm Prima dla reprezentacji macierzowej" << endl;
        cout << "6. algorytm Prima dla reprezentacji listowej" << endl;
        cout << "7. algorytm Dijkstry dla reprezentacji macierzowej" << endl;
        cout << "8. algorytm Dijkstry dla reprezentacji listowej" << endl;
        cout << "9. Algorytm Kruskala dla reprezentacji listowej" << endl;
        cout << "10. Algorytm Kruskala dla reprezentacji macierzowej" << endl;
        cout << "11. Algorytm Bellmana Forda dla reprezentacji listowej" << endl;
        cout << "12. Algorytm Bellmana Forda dla reprezentacji macierzowej" << endl;
        cout << "13. Wyjdź" << endl << endl;
        cin >> wybor;

        switch (wybor) {
            case 1:
                graph.printMatrixDirected();
                break;
            case 2:
                graph.printMatrixUndirected();
                break;
            case 3:
                graph.printDirectedNeighbourList();
                break;
            case 4:
                graph.printUndirectedNeighbourList();
                break;
            case 5:
                graph.primMatrix();
                break;
            case 6:
                graph.primList();
                break;
            case 7:
                graph.dijkstryMatrix(graph.startVerticle);
                break;
            case 8:
                graph.dijkstryList(graph.startVerticle);
                break;
            case 9:
                graph.kruskalList(graph.startVerticle);
                break;
            case 10:
                graph.kruskalMatrix(graph.startVerticle);
                break;
            case 11:
                graph.bellmanFordList(graph.startVerticle);
                break;
            case 12:
                graph.bellmanFordMatrix(graph.startVerticle);
                break;
            default:
                cout << "Błędny numer" << endl;
                break;
        }

    } while (wybor != 13);
}

int main() {
    int wybor = 0;

    do {
        cout << "Wygeneruj graf: " << endl;
        cout << "1. Losowo" << endl;
        cout << "2. Z pliku" << endl;
        cout << "3. Wyjdź" << endl << endl;
        cin >> wybor;

        switch (wybor) {
            case 1:
                // Wygenerowanie grafu losowo
                randomGraph();
                break;
            case 2:
                // Wczytaniu grafu z pliku
                readGraph();
                break;
            case 3:
                // Wyjście z programu
                break;
            default:
                cout << "bledny wybor" << endl;
                break;
        }
    } while (wybor != 3);

    system("PAUSE");
}

// Tworzenie grafu skierowanego z pliku
void Operations::createDirectedGraph() {
    fstream file("plik.txt", std::ios::in);
    if (file.is_open()) {
        file >> edges;
        file >> verticles;
        file >> startVerticle;
        file >> finishVerticle;
        directedGraph = new int *[edges];
        if (file.fail())
            cout << "Błąd" << endl;
        else {
            int source, destination, localWeight;
            for (int i = 0; i < edges; i++) {
                file >> source;
                file >> destination;
                file >> localWeight;

                if (file.fail()) {
                    cout << "Błąd" << endl;
                    break;
                }
                else {
                    directedGraph[i] = new int[3];
                    directedGraph[i][0] = source;
                    directedGraph[i][1] = destination;
                    directedGraph[i][2] = localWeight;
                }
            }
        }

        file.close();
    }
    else
        cout <<"Błąd" << endl;
}
// Tablica bez powtorzonych wierzcholkow potrzebna dla operacji na grafie nieskierowanym
void Operations::createUndirectedGraph() {
    bool *duplicate;
    duplicate = new bool[edges];
    for (int i = 0; i < edges; i++)
        duplicate[i] = false;
    undirectedGraph = new int *[edges];
    for (int i = 0; i < edges; i++)
        undirectedGraph[i] = NULL;

    for (int i = 0; i < edges; i++) {
        for (int j = 0; j < i; j++) {
            if ((directedGraph[i][0] == directedGraph[j][0] && directedGraph[i][1] == directedGraph[j][1]) || (directedGraph[i][1] == directedGraph[j][0] && directedGraph[i][0] == directedGraph[j][1])) {
                duplicate[i] = false;
                break;
            }
            duplicate[i] = true;
        }
    }

    duplicate[0] = true;
    edgeY = 0;
    for (int i = 0; i < edges; i++) {
        if (duplicate[i] == true) {
            undirectedGraph[edgeY] = new int[3];
            undirectedGraph[edgeY][0] = directedGraph[i][0];
            undirectedGraph[edgeY][1] = directedGraph[i][1];
            undirectedGraph[edgeY][2] = directedGraph[i][2];
            edgeY++;
        }
    }

    delete[] duplicate;
}
// Tworzenie macierzy dla grafu skierowanego
void Operations::createMatrixForDirectedGraph() {
    matrixDirected = new int *[verticles];
    for (int i = 0; i < verticles; i++) {
        matrixDirected[i] = new int[verticles];
    }
    for (int i = 0; i < verticles; i++) {
        for (int j = 0; j < verticles; j++) {
            matrixDirected[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++) {
        matrixDirected[directedGraph[i][0]][directedGraph[i][1]] = directedGraph[i][2];
    }
}
// Tworzenie macierzy dla grafu nieskierowanego
void Operations::createMatrixForUndirectedGraph() {
    matrixUndirected = new int *[verticles];
    for (int i = 0; i < verticles; i++) {
        matrixUndirected[i] = new int[verticles];
    }
    for (int i = 0; i < verticles; i++) {
        for (int j = 0; j < verticles; j++) {
            matrixUndirected[i][j] = 0;
        }
    }

    for (int i = 0; i < edgeY; i++) {
        matrixUndirected[undirectedGraph[i][0]][undirectedGraph[i][1]] = undirectedGraph[i][2];
        matrixUndirected[undirectedGraph[i][1]][undirectedGraph[i][0]] = undirectedGraph[i][2];
    }
}
// Wyświetlenie macierzy incydencji dla grafu nieskierowanego
void Operations::printMatrixUndirected() {
    for (int i = 0; i < verticles; i++) {
        for (int j = 0; j < verticles; j++) {
            cout << matrixUndirected[i][j] << " ";
        }
        cout << endl;
    }
}
// Wyświetlenie macierzy incydencji dla grafu skierowanego
void Operations::printMatrixDirected() {
    for (int i = 0; i < verticles; i++) {
        for (int j = 0; j < verticles; j++) {
            cout << matrixDirected[i][j] << " ";
        }
        cout << endl;
    }
}
// Tworzenie listy sąsiedztwa dla grafu nieskierowanego
void Operations::makeUndirectedNeighbourList() {
    listUndirectional = new elementOfList *[verticles];
    for (int i = 0; i < verticles; i++)
        listUndirectional[i] = NULL;

    for (int i = 0; i < edgeY; i++) {
        tmp = new elementOfList;
        tmp->n = undirectedGraph[i][1];
        tmp->weight = undirectedGraph[i][2];
        tmp->next = listUndirectional[undirectedGraph[i][0]];
        listUndirectional[undirectedGraph[i][0]] = tmp;

        tmp = new elementOfList;
        tmp->n = undirectedGraph[i][0];
        tmp->weight = undirectedGraph[i][2];
        tmp->next = listUndirectional[undirectedGraph[i][1]];
        listUndirectional[undirectedGraph[i][1]] = tmp;
    }
}
// Wyświetlenie listy sąsiedztwa dla grafu nieskierowanego
void Operations::printUndirectedNeighbourList() {
    cout << "[nr_wierzcholka] = " << setw(3) << "nr_wierzcholka(waga_krawdzi)" << endl;
    for (int i = 0; i < verticles; i++) {
        cout << "[" << i << "] =";
        tmp = listUndirectional[i];
        while (tmp) {
            cout << setw(3) << tmp->n << "(" << tmp->weight << ")";
            tmp = tmp->next;
        }
        cout << endl;
    }
}
// Utworzenie listy sąsiedztwa dla grafu skierowanego
void Operations::makeDirectedNeighbourList(){
    neighbourList1 = new elementOfList *[verticles];
    for (int i = 0; i < verticles; i++)
        neighbourList1[i] = NULL;

    for (int i = 0; i < edges; i++) {

        tmp = new elementOfList;    // Tworzymy nowy element
        tmp->n = directedGraph[i][1];          // Numerujemy go
        tmp->weight = directedGraph[i][2];
        tmp->next = neighbourList1[directedGraph[i][0]];    // Dodajemy go na pocz�tek listy
        neighbourList1[directedGraph[i][0]] = tmp;
    }
}
// Wyświetlenie listy sąsiedztwa dla grafu skierowanego
void Operations::printDirectedNeighbourList() {
    cout << "[nr_wierzcholka] = " << setw(3) << "nr_wierzcholka(waga_krawdzi)" << endl;
    for (int i = 0; i < verticles; i++) {
        cout << "[" << i << "] = ";
        tmp = neighbourList1[i];
        while (tmp) {
            cout << setw(3) << tmp->n << "(" << tmp->weight << ")";
            tmp = tmp->next;
        }
        cout << endl;
    }
}
// Algorytm Prima wykonany na macierzy incydencji
void Operations::primMatrix() {

    resultsForMatrix = new int*[verticles - 1];
    // Startujemy z pierwszego wierzchołka zamiast z losowego
    int currentVerticle = undirectedGraph[0][0];
    vector <int> verticlesForTree;
    verticlesForTree.push_back(currentVerticle);
    int help;
    bool *visitedVerticles;
    visitedVerticles = new bool[verticles];
    for (int i = 0; i < verticles; i++)
        visitedVerticles[i] = false;

    int idx, idy, nweight;
    idy = currentVerticle;
    idx = currentVerticle;

    visitedVerticles[currentVerticle] = true;

    for (int i = 0; i < verticles; i++) {
        currentVerticle = verticlesForTree[0];
        nweight = 11;
        for (int j = 0; j < verticlesForTree.size(); j++) {
            currentVerticle = verticlesForTree[j];
            for (int k = 0; k < verticles; k++) {

                if (matrixUndirected[currentVerticle][k] != 0 && matrixUndirected[currentVerticle][k] < nweight && visitedVerticles[k] == false) {
                    idx = k;
                    idy = currentVerticle;
                    nweight = matrixUndirected[currentVerticle][k];
                }
            }
        }

        resultsForMatrix[i] = new int[3];
        resultsForMatrix[i][0] = idy;
        resultsForMatrix[i][1] = idx;
        resultsForMatrix[i][2] = nweight;

        visitedVerticles[idx] = true;
        verticlesForTree.push_back(idx);
    }
    int MST = 0;
    for (int i = 0; i < verticles - 1; i++) {
        cout << "(" << resultsForMatrix[i][0] << "," << resultsForMatrix[i][1] << ")   " << resultsForMatrix[i][2] << endl;
        MST += resultsForMatrix[i][2];
    }
    cout << "Minimalne drzewo rozpinające: " << MST << endl;
}
// Algorytm Prima wykonany na liscie sąsiedztwa
void Operations::primList() {
    resultForList = new int*[verticles - 1];

    int currentVerticle = directedGraph[0][0];
    vector <int> verticlesForTree;
    verticlesForTree.push_back(currentVerticle);
    int help;
    bool *visitedVerticles;
    visitedVerticles = new bool[verticles];
    for (int i = 0; i < verticles; i++) {
        visitedVerticles[i] = false;
    }
    int fromHere, there, nweight;
    fromHere = currentVerticle;
    there = currentVerticle;
    visitedVerticles[currentVerticle] = true;

    for (int i = 0; i < verticles; i++) {
        currentVerticle = verticlesForTree[0];
        nweight = 11;
        for (int j = 0; j < verticlesForTree.size(); j++) {

            currentVerticle = verticlesForTree[j];
            tmp = listUndirectional[currentVerticle];
            while (tmp) {
                if (tmp->weight != 0 && tmp->weight < nweight && visitedVerticles[tmp->n] == false) {
                    fromHere = currentVerticle;
                    there = tmp->n;
                    nweight = tmp->weight;

                }
                tmp = tmp->next;
            }
        }
        resultForList[i] = new int[3];
        resultForList[i][0] = fromHere;
        resultForList[i][1] = there;
        resultForList[i][2] = nweight;

        visitedVerticles[there] = true;
        verticlesForTree.push_back(there);
    }

    int MST = 0;
    for (int i = 0; i < verticles - 1; i++) {
        cout << "(" << resultForList[i][0] << "," << resultForList[i][1] << ")   " << resultForList[i][2] << endl;
        MST += resultForList[i][2];
    }
    cout << "Minimalne drzewo rozpinające: " << MST << endl;
}
// Algorytm Dijkstry wykonany na liscie sąsiedztwa
void Operations::dijkstryList(int start) {

    int *cost, *path, *Stack, stackPointer;
    int i, j, u;	//do petli
    bool *visited;

    cost = new int[verticles];
    path = new int[verticles];
    visited = new bool[verticles];
    Stack = new int[verticles];
    stackPointer = 0;

    for (int i = 0; i < verticles; i++) {
        cost[i] = MAXINT;
        path[i] = -1;
        visited[i] = false;
    }

    cout << endl;
    cost[start] = 0;

    for (int i = 0; i<verticles; i++) {
        for (j = 0; visited[j]; j++);
        for (u = j++; j<verticles; j++)
            if (!visited[j] && (cost[j]<cost[u]))
                u = j;

        visited[u] = true;

        for (tmp = neighbourList1[u]; tmp; tmp = tmp->next)
            if (!visited[tmp->n] && (cost[tmp->n] > cost[u] + tmp->weight)) {
                cost[tmp->n] = cost[u] + tmp->weight;
                path[tmp->n] = u;
            }
    }

    cout << "Wierzchołek startowy: " << startVerticle << endl;
    cout << "Wierzcholek_koncowy    Waga    Sciezka" << endl;
    for (i = 0; i < verticles; i++) {
        cout << i << ": ";
        for (j = i; j > -1; j = path[j]) Stack[stackPointer++] = j;
        cout << "   | " << cost[i] << " |   ";
        while (stackPointer) cout << Stack[--stackPointer] << " ";
        cout << endl;
    }

    delete[] cost;
    delete[] path;
    delete[] Stack;
    delete[] visited;
}
// Algorytm Dijkstry wykonany na macierzy sąsiedztwa
void Operations::dijkstryMatrix(int start) {

    int *cost, *path, *Stack, stackPointer;
    int i, j, u; // do petli
    bool *visited;

    cost = new int[verticles];
    path = new int[verticles];
    visited = new bool[verticles];
    Stack = new int[verticles];
    stackPointer = 0;

    for (int i = 0; i<verticles; i++) {
        cost[i] = MAXINT;
        path[i] = -1;
        visited[i] = false;
    }

    cout << endl;
    cost[start] = 0;

    for (int i = 0; i<verticles; i++) {
        for (j = 0; visited[j]; j++);
        for (u = j++; j<verticles; j++)
            if (!visited[j] && (cost[j]<cost[u])) u = j;

        visited[u] = true;

        for (int g = 0; g < verticles; g++) {
            if (matrixDirected[u][g] != 0) {
                if (!visited[g] && (cost[g] > cost[u] + matrixDirected[u][g])) {
                    cost[g] = cost[u] + matrixDirected[u][g];
                    path[g] = u;
                }
            }
        }
    }

    cout << "Wierzcholek startowy " << startVerticle << endl;
    cout << "Wierzcholek_koncowy    Waga    Sciezka" << endl;
    for (i = 0; i < verticles; i++) {
        cout << i << ": ";
        for (j = i; j > -1; j = path[j]) Stack[stackPointer++] = j;
        cout << "   | " << cost[i] << " |   ";
        while (stackPointer) cout << Stack[--stackPointer] << " ";
        cout << endl;
    }

    delete[] cost;
    delete[] path;
    delete[] Stack;
    delete[] visited;
}
// Algorytm kruskala na liscie
void Operations::kruskalList(int) {
    resultForList = new int*[verticles - 1];

    int currentVerticle = directedGraph[0][0];
    vector <int> verticlesForTree;
    verticlesForTree.push_back(currentVerticle);
    int help;
    bool *visitedVerticles;
    visitedVerticles = new bool[verticles];
    for (int i = 0; i < verticles; i++) {
        visitedVerticles[i] = false;
    }
    int fromHere, there, nweight;
    fromHere = currentVerticle;
    there = currentVerticle;
    visitedVerticles[currentVerticle] = true;

    for (int i = 0; i < verticles; i++) {
        currentVerticle = verticlesForTree[0];
        nweight = 11;
        for (int j = 0; j < verticlesForTree.size(); j++) {

            currentVerticle = verticlesForTree[j];
            tmp = listUndirectional[currentVerticle];
            while (tmp) {
                if (tmp->weight != 0 && tmp->weight < nweight && visitedVerticles[tmp->n] == false) {
                    fromHere = currentVerticle;
                    there = tmp->n;
                    nweight = tmp->weight;

                }
                tmp = tmp->next;
            }
        }
        resultForList[i] = new int[3];
        resultForList[i][0] = fromHere;
        resultForList[i][1] = there;
        resultForList[i][2] = nweight;

        visitedVerticles[there] = true;
        verticlesForTree.push_back(there);
    }

    int MST = 0;
    for (int i = 0; i < verticles - 1; i++) {
        cout << "(" << resultForList[i][0] << "," << resultForList[i][1] << ")   " << resultForList[i][2] << endl;
        MST += resultForList[i][2];
    }
    cout << "Minimalne drzewo rozpinające: " << MST << endl;
}
// Algorytm Bellmana Forda wykonany na macierzy sąsiedztwa
void Operations::bellmanFordMatrix(int start) {

    int *cost, *path, *Stack, stackPointer;
    int i, j, u; // do petli
    bool *visited;

    cost = new int[verticles];
    path = new int[verticles];
    visited = new bool[verticles];
    Stack = new int[verticles];
    stackPointer = 0;

    for (int i = 0; i<verticles; i++) {
        cost[i] = MAXINT;
        path[i] = -1;
        visited[i] = false;
    }

    cout << endl;
    cost[start] = 0;

    for (int i = 0; i<verticles; i++) {
        for (j = 0; visited[j]; j++);
        for (u = j++; j<verticles; j++)
            if (!visited[j] && (cost[j]<cost[u])) u = j;

        visited[u] = true;

        for (int g = 0; g < verticles; g++) {
            if (matrixDirected[u][g] != 0) {
                if (!visited[g] && (cost[g] > cost[u] + matrixDirected[u][g])) {
                    cost[g] = cost[u] + matrixDirected[u][g];
                    path[g] = u;
                }
            }
        }
    }

    cout << "Wierzcholek startowy " << startVerticle << endl;
    cout << "Wierzcholek_koncowy    Waga    Sciezka" << endl;
    for (i = 0; i < verticles; i++) {
        cout << i << ": ";
        for (j = i; j > -1; j = path[j]) Stack[stackPointer++] = j;
        cout << "   | " << cost[i] << " |   ";
        while (stackPointer) cout << Stack[--stackPointer] << " ";
        cout << endl;
    }

    delete[] cost;
    delete[] path;
    delete[] Stack;
    delete[] visited;
}
// Algorytm Bellmana Forda wykonany na liscie sąsiedztwa
void Operations::bellmanFordList(int start) {

    int *cost, *path, *Stack, stackPointer;
    int i, j, u;	//do petli
    bool *visited;

    cost = new int[verticles];
    path = new int[verticles];
    visited = new bool[verticles];
    Stack = new int[verticles];
    stackPointer = 0;

    for (int i = 0; i < verticles; i++) {
        cost[i] = MAXINT;
        path[i] = -1;
        visited[i] = false;
    }

    cout << endl;
    cost[start] = 0;

    for (int i = 0; i<verticles; i++) {
        for (j = 0; visited[j]; j++);
        for (u = j++; j<verticles; j++)
            if (!visited[j] && (cost[j]<cost[u]))
                u = j;

        visited[u] = true;

        for (tmp = neighbourList1[u]; tmp; tmp = tmp->next)
            if (!visited[tmp->n] && (cost[tmp->n] > cost[u] + tmp->weight)) {
                cost[tmp->n] = cost[u] + tmp->weight;
                path[tmp->n] = u;
            }
    }

    cout << "Wierzchołek startowy: " << startVerticle << endl;
    cout << "Wierzcholek_koncowy    Waga    Sciezka" << endl;
    for (i = 0; i < verticles; i++) {
        cout << i << ": ";
        for (j = i; j > -1; j = path[j]) Stack[stackPointer++] = j;
        cout << "   | " << cost[i] << " |   ";
        while (stackPointer) cout << Stack[--stackPointer] << " ";
        cout << endl;
    }

    delete[] cost;
    delete[] path;
    delete[] Stack;
    delete[] visited;
}
// Algorytm Kruskala wykonany na macierzy incydencji
void Operations::kruskalMatrix(int) {

    resultsForMatrix = new int*[verticles - 1];
    // Startujemy z pierwszego wierzchołka zamiast z losowego
    int currentVerticle = undirectedGraph[0][0];
    vector <int> verticlesForTree;
    verticlesForTree.push_back(currentVerticle);
    int help;
    bool *visitedVerticles;
    visitedVerticles = new bool[verticles];
    for (int i = 0; i < verticles; i++)
        visitedVerticles[i] = false;

    int idx, idy, nweight;
    idy = currentVerticle;
    idx = currentVerticle;

    visitedVerticles[currentVerticle] = true;

    for (int i = 0; i < verticles; i++) {
        currentVerticle = verticlesForTree[0];
        nweight = 11;
        for (int j = 0; j < verticlesForTree.size(); j++) {
            currentVerticle = verticlesForTree[j];
            for (int k = 0; k < verticles; k++) {

                if (matrixUndirected[currentVerticle][k] != 0 && matrixUndirected[currentVerticle][k] < nweight && visitedVerticles[k] == false) {
                    idx = k;
                    idy = currentVerticle;
                    nweight = matrixUndirected[currentVerticle][k];
                }
            }
        }

        resultsForMatrix[i] = new int[3];
        resultsForMatrix[i][0] = idy;
        resultsForMatrix[i][1] = idx;
        resultsForMatrix[i][2] = nweight;

        visitedVerticles[idx] = true;
        verticlesForTree.push_back(idx);
    }
    int MST = 0;
    for (int i = 0; i < verticles - 1; i++) {
        cout << "(" << resultsForMatrix[i][0] << "," << resultsForMatrix[i][1] << ")   " << resultsForMatrix[i][2] << endl;
        MST += resultsForMatrix[i][2];
    }
    cout << "Minimalne drzewo rozpinające: " << MST << endl;
}
// Wczytanie wartości zmiennych z pliku do tablicy i utworzenie grafu
bool Operations::readFromFile() {
    bool success = false;
    fstream file;

    file.open("plik.txt");

    // Wczytanie wartości: liczba krawedzi, liczba wierzcholkow, poczatkowy wierzcholek, koncowy wierzcholek
    if (file.is_open()) {
        file >> edges;
        file >> verticles;
        file >> startVerticle;
        file >> finishVerticle;

        directedGraph = new int *[edges];

        if (file.fail())
            cout << "Błąd" << endl;
        else {
            int source, destination, weight;
            for (int i = 0; i < edges; i++) {
                file >> source;
                file >> destination;
                file >> weight;

                if (file.fail()) {
                    cout << "Błąd" << endl;
                    break;
                }
                else {
                    // Wczytanie wartości do tablicy wskaźników
                    directedGraph[i] = new int[3];
                    directedGraph[i][0] = source;
                    directedGraph[i][1] = destination;
                    directedGraph[i][2] = weight;
                }
            }
        }

        file.close();
        success = true;
    }
    else {
        cout << "Błąd" << endl;
        success = false;
    }

    return success;
}

// Konstruktor
Operations::Operations() {

}
// Destruktor klasy
Operations::~Operations() {

    for (int i = 0; i < edges; i++) {
        delete[] directedGraph[i];
        delete[] undirectedGraph[i];
    }
    directedGraph = NULL;
    undirectedGraph = NULL;

    for (int i = 0; i < verticles; i++) {
        delete[] matrixDirected[i];
        delete[] matrixUndirected[i];
    }

    matrixDirected = NULL;
    matrixUndirected = NULL;}
// Konstruktor klasy
GraphGenerator::GraphGenerator() {
}
// Generator grafu
GraphGenerator::GraphGenerator(int x) {
    int verticles2 = 0;
    float density = 0;

    do {
        cout << "Podaj liczbe wierzchołków: ";
        cin >> verticles2;
    } while (verticles2 < 2);

    this->verticles = verticles2;
    maxWeight = 9;
    minEdges = verticles - 1;	//minimalna ilosc krawedzi dla grafu spojnego
    maxEdges = ((verticles - 1)*verticles) / 2;
    // ceil - Zaokrągla w góre
    int minDensity = ceil((minEdges / maxEdges) * 100);

    do {
        cout << "Podaj gestosc (minimum " << minDensity << "%) " << endl;
        cin >> density;
    } while (density < minDensity || density >= 100);


    edges = ceil(maxEdges*(density / 100));	    //pożądana liczba krawedzi
    int weight;
    result = new int *[2 * edges];

    //kreowanie drzewa
    vector <int> tab;   //vektor pamietajacy czy wierzcholek byl juz odwiedzony
    for (int i = 0; i < verticles; i++)	tab.push_back(i);

    srand(time(NULL));
    int next, previous;
    previous = rand() % verticles;
    tab[previous] = -1;
    for (int i = 1; i < minEdges + 1; i++) {
        while (true){
            next = rand() % verticles;
            if (tab[next] >= 0)
                break;
        }

        result[i - 1] = new int[3];
        result[i - 1][0] = previous;
        result[i - 1][1] = next;
        weight = (rand() % maxWeight) + 1;
        result[i - 1][2] = weight;
        tab[next] = -1;
        previous = next;
    }
    bool czyJest = false;
    for (int i = minEdges; i < edges; i++) {		// dodanie losowych krawedzi do drzewa
        while (true) {
            czyJest = false;
            previous = rand() % verticles;
            next = rand() % verticles;
            for (int j = 0; j < i; j++) {
                if ((result[j][0] == previous && result[j][1] == next) || (result[j][0] == next && result[j][1] == previous) || (next == previous)) {
                    czyJest = true;
                    break;
                }
            }
            if (czyJest == false) {
                result[i] = new int[3];
                result[i][0] = previous;
                result[i][1] = next;
                weight = rand() % maxWeight + 1;
                result[i][2] = weight;
                break;
            }
        }

    }

    int help;
    for (int i = edges; i < edges * 2; i++) {

        while (true) {
            czyJest = false;
            previous = rand() % verticles;
            next = rand() % verticles;
            for (int j = 0; j < i; j++) {

                if ((result[j][0] == previous && result[j][1] == next) || (next == previous)) {
                    czyJest = true;
                    break;
                }

            }
            if (czyJest == false) {
                result[i] = new int[3];
                result[i][0] = previous;
                result[i][1] = next;
                weight = rand() % maxWeight + 1;
                result[i][2] = weight;
                break;
            }
        }

    }

    fstream plik("plik.txt", ios::out);	    //wpisuje do pliku
    if (plik.good()) {
        plik << 2 * edges << " " << verticles << " " << result[0][0] << " " << result[verticles - 1][0] << "\n";
        for (int i = 0; i < 2 * edges; i++)	plik << result[i][0] << " " << result[i][1] << " " << result[i][2] << "\n";
        plik.close();
    }
}
// Destruktor
GraphGenerator::~GraphGenerator() {
    for (int i = 0; i < 2 * edges; i++)
        delete result[i];
    result = NULL;
}