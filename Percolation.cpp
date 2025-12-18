#include"Percolation.h"
using namespace std;

Percolation ::Percolation(int n ):N(n),uf(n*n+2){
    // We initialize UnionFind with N*N sites + 2 virtual sites

    //Resize grid to N*N and init all to false (blocked)
    grid.resize(n*n,false );
    topVirtualNode=n*n;
    bottomVirtualNode=n*n+1;


}

//Changing 2d to 1d
int Percolation::getIndex(int row,int col){
    return row*N+col; 
}

//Helper to Open a site and connect it to open Nbrs
void Percolation::open(int row ,int col){
    int idx =getIndex(row,col);

    if(grid[idx]) return ;//already opened 

    grid[idx]=true;

    //3. Connect to the virtual nodes if on edge

    if (row==0){
        uf.unionSets(idx,topVirtualNode);
    }

    if(row==N-1){
        uf.unionSets(idx,bottomVirtualNode);
    }

    //4.connect the nbrs up down left right 
    // We must check bounds AND if the neighbor is open
    
    // UP
    if (row > 0 && isOpen(row - 1, col)) {
        uf.unionSets(idx, getIndex(row - 1, col));
    }
    // DOWN
    if (row < N - 1 && isOpen(row + 1, col)) {
        uf.unionSets(idx, getIndex(row + 1, col));
    }
    // LEFT
    if (col > 0 && isOpen(row, col - 1)) {
        uf.unionSets(idx, getIndex(row, col - 1));
    }
    // RIGHT
    if (col < N - 1 && isOpen(row, col + 1)) {
        uf.unionSets(idx, getIndex(row, col + 1));
    }

}

bool Percolation::isOpen(int row , int col ){
    return grid[getIndex(row,col)];//true or false
}

bool Percolation::percolates(){
    return uf.connected(topVirtualNode,bottomVirtualNode);//O(1) check
}
bool Percolation::isFull (int row , int col ){
    int idx =getIndex (row,col );
    //It must be open AND connected to the source 
    return isOpen (row,col) && uf.connected(idx,topVirtualNode);//returns if both are open
    
}