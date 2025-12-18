//---step1---build a generic Disjoint Set union class
//manages the N x N grid and translates 2D coord to 1d indicees 
//Implementing Virtual top and Bottom for graph theory imple..by path compression
//a simeple main.cpp to verify the logic

//just need to imple the Weighted Quick Union with Path compression algo

//map row,col to row*N + col, like the grid in Nand2tetris ,coverting to linear and decreasing the Dimension

#include <vector>
using namespace std;

class UnionFind{
    private :
        vector<int> parent ;//parent[i]=parent of node i 
        vector<int> size ;//size[i]=no fo nodes in the subtree rooted at i 
        int count ;//no of components 
    public:
        //Constructor to initialize N sites with 0 to N-1
        UnionFind(int N );

        //Returns the canonical root of element p (with Path Compression!)
        int find(int p);

        // Connects p and q (Weighted union: link smaller tree to larger tree), basic union algo
        void unionSets(int p, int q);

        // Returns true if p and q are in the same set
        bool connected(int p, int q);
};

