//we use monte carlo simulation 
#include<bits/stdc++.h>
#include "Percolation.h"

using namespace std;
//Config

const int N=50;
const int TRIALS =1000; //Trials per probabitlity step, or epochs !

int main(){
    //randomiser
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis (0.0,1.0);//uniform 

    //create output file csv format

    ofstream file("percolation.csv");
    file<<"p,probability_of_percolation\n";
    cout <<"Starting the monte carlo simulation..."<<endl;

    for (double p=0.0;p<=1.0;p+=0.02){
        int successCount=0;
        for (int t=0;t<TRIALS ;t++){
            Percolation perc(N);

            //Randomly open sites based in P 
            for (int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(dis(gen)<p){
                        perc.open(i,j);//random opener over the grid
                    }
                }
            }

            if(perc.percolates()){
                successCount++;//no of successfull percolations observations 
            }
        }
        double fraction =(double)successCount/TRIALS;
        file <<p<<","<<fraction<<"\n";//outputting in the file 

        cout <<"p="<<p<<" -> "<<fraction*100<< "%"<<endl;

    }

    file.close ();
    cout <<"Done ! data saved to percolation_data.csv"<<endl;
    return 0;

    
}