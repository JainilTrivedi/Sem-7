#include <bits/stdc++.h>

using namespace std;

void print();

vector<vector<int>> city = {
    {0,10,8,9,7},
    {10,0,10,5,6},
    {8,10,0,8,9},
    {9,5,8,0,6},
    {7,6,9,6,0}
};

map<int,vector<int>> path;
vector<int> mini = {0,0,0,0,0};
int pathLength=0;
vector<int> visited(city.size(),0);

void findTSP(int n,int &curr){
   
     if(pathLength==city.size()-1){
        mini[curr]+=city[n][curr];

        for(auto it : path[curr])
            cout<<it+1<<" ";
            cout<<endl;
            cout<<mini[curr]<<endl;
            pathLength=0;
            return;
        }
        
    // for(int i=n;i<city.size();i++){
        
        pathLength++;
        
        /*
        if(pathLength>city[i].size()){
            pathLength=0;
            return;
        }
        
        if(i==0){
            mini[i] = city[0][2];
        }else{
            mini[i] = city[i][0];
        } */
        
        int tmin = INT_MAX;
        int call;
        
        for(int j=0; j<city[n].size(); j++){
            if( n!=j && visited[j]!=1 && city[n][j] < tmin ){
                call=j;
                tmin = city[n][j];
            }
        }
        cout<<"MIN for "<< n<< " is "<<tmin<<"\n";
        mini[curr] += city[n][call];
        visited[call] = 1;
        path[curr].push_back(call);
        findTSP(call,curr);
    // }
}

void print(){
    for(int i=0;i<city.size();i++){
        cout<<"Min dist "<< mini[i] <<"\n";
        cout<<"Path\n";
        for(auto it: path[i]){
               cout<<it+1<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    for(int i=0;i<city.size();i++){
        path[i].push_back(i);
    }
    // tsp(0,2);
    for(int i=0;i<city.size();i++){
        visited[i] = 1;
        findTSP(i,i);
        for(int i=0;i<city.size();i++){
            visited[i] = 0;
            mini[i] = 0;
        }
    }
    
    return 0;
}

/*
34 36 34 34 34
*/