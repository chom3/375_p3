#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

/* For reference
0 = NYC
1 = Allentown
2 = Scranton
3 = Binghamton
4 = Albany
5 = Montreal
6 = Syracuse
7 = Kingston
8 = Rochester
9 = Buffalo
10 = Toronto
*/

//find the shortest path since we have the shortest distance answer
void Path (int u, int v, vector<vector<int>> p)
    {
        int k;
        k = p[u][v];
        if (k == -1) return;
        Path(u,k, p);
        // a little inefficient but oh well
        if (k == 0)
        {
            cout << "Visits: NYC" << endl;
        }
        else if (k == 1){
            cout << "Visits: Allentown" << endl; 
        }
        else if (k == 2){
            cout << "Visits: Scranton" << endl; 
        }
        else if (k == 3){
            cout << "Visits: Binghamton" << endl; 
        }
        else if (k == 4){
            cout << "Visits: Albany" << endl; 
        }
        else if (k == 5){
            cout << "Visits: Montreal" << endl; 
        }
        else if (k == 6){
            cout << "Visits: Syracuse" << endl; 
        }
        else if (k == 7){
            cout << "Visits: Kingston" << endl; 
        }
        else if (k == 8){
            cout << "Visits: Rochester" << endl; 
        }
        else if (k == 9){
            cout << "Visits: Buffalo" << endl; 
        }
        else if (k == 10){
            cout << "Visits: Toronto" << endl; 
        }
        Path(k,v, p);
    }
int main(){ 
    int v = 11;
    //make a vector for floyds algorithm
    //another vector to store the points to find shortest path
    vector<vector<int> > a(v);
    vector<vector<int> > p(v);
        for ( int i = 0 ; i < v ; i++ ){
            a[i].resize(v);
            p[i].resize(v);
        }

    //store 0 in floyds
    //store -1 in next
    for(int i=0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j] = 0;
            p[i][j] = -1;
        }
    }
    

    //print out to check
    // for(int i = 0; i < v; i++)
    // {
    //     for(int j = 0; j < v; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    // initialize distances
    a[0][1]= 70;
    a[0][2]= 100;
    a[0][3] = 180;
    a[0][4] = 140;
    a[1][2] = 65;
    a[2][3] = 60;
    a[3][6] = 70;
    a[4][6] = 100;
    a[4][5] = 130;
    a[5][7] = 160;
    a[6][7] = 65;
    a[6][8] = 70;
    a[7][10] = 180;
    a[8][9] = 60;
    a[9][10] = 100;
    
    //print out to chek
    // for(int i = 0; i < v; i++)
    // {
    //     for(int j = 0; j < v; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
//     //  floyd's algorithm
//     for each vertex v
//     dist[v][v] ← 0
// for each edge (u,v)
//     dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
// for each vertex k
//     for each vertex i
//         for each vertex j
//             if dist[i][k] + dist[k][j] < dist[i][j] then
//                 dist[i][j] ← dist[i][k] + dist[k][j]

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if ((a[i][k] * a[k][j] != 0 && (i != j)))
                {
                    if ((a[i][k] + a[k][j] < a[i][j]) || a[i][j] == 0)
                    {
                        a[i][j] = a[i][k] + a[k][j];
                        p[i][j] = k;
                    }
                }
            }
        }
    }
    //print out the entire matrix
    // for(int i = 0; i < v; i++)
    // {
    //     for(int j = 0; j < v; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //      cout << endl;
    // }
    // print out shortest path from NYC to Toronto
    cout << "Shortest path: " << a[0][10] << " miles" << endl;
    cout << "Starting: New York City" << endl;
    Path(0, 10, p);
    cout << "End in: Toronto" << endl;
    // cout << "Hardcoded... The answer should be: " << endl;
    // cout << "NYC -> Scranton -> Binghamton -> Syracuse -> Rochester -> Buffalo -> Toronto = 460" << endl;
}