//uses union find to model the system 
//check if the system percolates..flows from top to bottom
//NAIVE APPROACH : iterates through the entire bottom ro wto see if any cell connects to any cell in the top row
//THE FIX : Create two extra invisble nodes 
//Virtual top : Index N^2.All Opensites in the top row connect to thois 
//Virtual bottom : Index N^2+1, all open sites in bottom row connect to this 

#include "UnionFind.h"

#include <vector>

using namespace std ;

class Percolation {
    private :
        int N ;//Grid Dimension unchangable within
        vector<bool> grid;//Tracks which sites are open or blocked
        UnionFind uf;//object of UF type, engine handling the connectivity
        int topVirtualNode ;
        int bottomVirtualNode ;
        
        //Helper to convert into 1D
        int getIndex(int row , int col );
            
        

    public :

        Percolation(int n ); //constructor to create the N X N grid 

        void open (int row , int col);//open the site if its not open already

        //checker is open 

        bool isOpen(int row , int col);

        //Does the system percolate ?

        bool isFull (int row , int col);//checks if site is connected to the top , filled with water
        

        bool percolates ();
};



