//this is the visualizer 

#include <bits/stdc++.h>
#include "Percolation.h"

using namespace  std;

//grid visualiser . - open site , # - blocked

void printGrid (Percolation &p ,int N){
    cout<<"Grid State: - "<<endl;
    for(int i=0;i<N ;i++){
        for(int j =0;j<N ;j++){
            if(p.isOpen(i,j)){
                cout <<". ";
            }
            else {
                cout << "# ";
            }
        }
        cout <<endl;

    } 
    cout <<"Percolates : "<<(p.percolates()? "YES" : "NO")<<endl;
    cout <<"-----------------"<<endl;
}


int main (){
    int N =5;
    cout <<"Initializing "<<N <<"x"<<"grid..."<<endl;
    Percolation perc(N);//init a grid of size N 

    printGrid(perc ,N);
    if(perc.percolates()){
        cerr<<"ERROR, SYSTEM PERCOLATES IMMEDIATELY!"<<endl;
        return 1;
    }

    //Test 2 : Create a zig-zag path from top to bottom

    //Path : 0,1 -> 1,1 -> 1,2 -> 2,2 -> 3,2 -> 4,2
    vector<pair<int,int> > path = {
        {0, 1}, // Top row connection
        {1, 1}, 
        {1, 2}, // Sideways move
        {2, 2}, 
        {3, 2}, 
        {4, 2}  // Bottom row connection
    };

    for (auto site : path){
        cout <<"Opening site ("<<site.first<< ","<<site.second << ") ..."<<endl;
        perc.open(site.first,site.second);
        printGrid(perc,N);
    }

    //final check 

    if (perc.percolates()){
        cout <<"SUCCESS: the system percolates "<<endl ;
    }else {
        cerr << "FAILURE: System should percolate but returned false." << std::endl;
    }

    return 0;


}
