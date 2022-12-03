#include<bits/stdc++.h>
using namespace std;


int findCycle(int v,vector<int> parent){
    
    if(parent[v]==v){
        return v;
    }
    return findCycle(parent[v],parent);
}

int main(){

    int edge_no;
    cin >> edge_no;
    vector<int> parent(edge_no,0);
    int initial=0;

    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
    
    vector<vector<int>> edge;
    
    for(int i=0;i<edge_no;i++){
        
        for(int j=0;j<edge_no;j++){
            int t;
            cin >> t;
            edge.push_back({t,i,j});
        }
    }
    sort(edge.begin(),edge.end());
    
    int cost=0,y=0;
    int flag = 0,flag2=1;
    vector<int> inDegree(edge_no,0);
    int i;
    cout<<"Path:\t";
    for( i=0;i<edge.size();i++){
        
        int x=edge[i][0],src=edge[i][1],dest=edge[i][2];
        if(x>0 && flag2==1){
            flag = 1;
        }
        if(inDegree[src]==2 || inDegree[dest]==2){
            continue;
        }
        int u=findCycle(src,parent);
        int v=findCycle(dest,parent);
        
        if(flag){
        //   cout<<"Initial :"<< char(64+u+1)<<endl;    
          initial = u;
          flag2=0;
          flag=0;
        }
        if(u==v){
            if(y==edge_no-1){
                cout<<char(64+u+1)<<" "<<char(64+initial+1)<<" ";
                cost+=x;
                break;
            }
            continue;
        }
        cost+=x;
        cout<<char(64+u+1)<<" ";

        parent[u]=v;
        inDegree[src]++;
        inDegree[dest]++;
        y++;
    }
    cout<< "\nThe cost is: " << cost << "\n";
}
