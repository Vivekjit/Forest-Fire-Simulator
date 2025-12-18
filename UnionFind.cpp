#include "UnionFind.h"
#include <numeric>
 
using namespace std ;

UnionFind::UnionFind(int N ){//the constuctor , to make the grid 
    count = N;
    parent.resize(N);
    size.resize(N,1);//Start size of each componenet as 1

    //Inditaialise parent [i]= i
    for(int i =0;i<N ;i++){
        parent[i]=i;//parental link for teh root
    }
}

//Find with the path compression 

int UnionFind::find(int p){
    //validate p is within bounds (optional )

    //if p<0 or p> parent.size (), throw out of range 

    while (p != parent [p]){
        //PATH COMPRESSION : Make p point to its grandaparent 
        //  this halves tge path lengts 
        parent[p]=parent[parent[p]];
        p=parent[p];//
    }
    return p;
}

//Weighted Union

void UnionFind ::unionSets(int p,int q){
    int rootP =find(p);
    int rootQ =find(q);

    if(rootP == rootQ) return; //already connected

    //WEIGHTING :link smaller tree to the larger tree to keep thetree heightlow , path comp

    if (size[rootP]<size[rootQ]){
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    }
    else {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
    count --;

}

bool UnionFind::connected(int p ,int  q){
    return find(p)== find (q);
}