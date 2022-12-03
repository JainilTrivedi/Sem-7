#include <bits/stdc++.h>

using namespace std;

void clear(vector<int> &v1,vector<int> &v2){
    for(int i=0;i<v1.size();i++)
        v1[i] = 0;
    for(int i=0;i<v2.size();i++)
        v2[i] = 0;
}

int main() {
    
    srand(time(0));
    vector<int> weights = {5,3,7,2};
    vector<int> values = {12,5,10,7};
    vector<int> selected = {0,0,0,0};
    vector<int> c1,c2,c3,c4;
    
    vector<string> chromosomes;
    chromosomes.push_back("0110");
    chromosomes.push_back("0101");
    chromosomes.push_back("1101");
    chromosomes.push_back("1111");
    
    vector<int> fitness(values.size(),0);
    vector<int> totalWeights(weights.size(),0);
    
    for(int i=0;i<3;i++){
        
        cout<<"--------------Iteration "<<i<<"--------------\n";
    
        // CALCULATING FITNESS
        for(int i=0;i<chromosomes.size();i++){
            for(int j=0;j<chromosomes[i].size();j++){
                if(chromosomes[i][j] == '1'){
                    fitness[i] += values[j];
                    totalWeights[i] += weights[j];
                }
            }
        }
       
            
        cout<<"Initial Fitness\n";
        for(auto it: fitness)
            cout<<it<<" ";
        cout<<"\n";
        cout<<"totalWeights\n";
        for(auto it: totalWeights)
            cout<<it<<" ";
        
        
        // CHECK IF ANY CHROMOSOME WEIGHS MORE THAN MAXWEIGHT
        int maxWeight = 12;
        int weightExceededIndex=0;
        int sumOfValues = 0;
        for(int i=0;i<totalWeights.size();i++){
            if(totalWeights[i]<= maxWeight)
                sumOfValues += fitness[i];
            else
                weightExceededIndex=i;
        }
        cout<<"\nTotal Fitness "<<sumOfValues<<"\n";
        
        int tmp = rand()%4;
        if(tmp == weightExceededIndex){
            tmp = (tmp+1)%4;
        }
        chromosomes[weightExceededIndex] = chromosomes[tmp];
        
       //CROSSOVER
        int index1=0,index2=0;
        index1 = rand()%4;
        index2 = rand()%4;
        if(index1==index2){
            index2 = (index2+1) %4;
        }
        cout<<"indexes "<<index1<<" "<<index2<<endl;
        
        int randomPoint = rand()%4;
        cout<<"random point "<<randomPoint<<" \n";
        for(int i=randomPoint;i<chromosomes.size();i++){
            int t = chromosomes[index1][i];
            chromosomes[index1][i] = chromosomes[index2][i];
            chromosomes[index2][i] = t;
        }
        cout<< "after changing " << index1 <<" and " << index2 << " about "<<randomPoint<<"\n";
        for(auto it : chromosomes[index1])
            cout<< it<<" ";
        cout<<endl;
        for(auto it : chromosomes[index2])
            cout<< it<<" ";
        
        // MUTATION
        int mut1 = rand()%4;
        int mut2 = rand()%4;
        cout<<"\n"<<mut1 << " " <<mut2<<"\n";
        cout<<"After mutation "<<index1 << "and " <<index2 <<"\n";
        
        if(chromosomes[index1][mut1]=='1')
            chromosomes[index1][mut1] = '0';
        else
            chromosomes[index1][mut1] = '1';
            
        if(chromosomes[index2][mut2]=='1')
            chromosomes[index2][mut2] = '0';
        else
            chromosomes[index2][mut2] = '1';
            
        for(auto it : chromosomes[index1])
            cout<< it<<" ";
        cout<<endl;
        for(auto it : chromosomes[index2])
            cout<< it<<" ";
        
        
        clear(fitness,totalWeights);
        for(int i=0;i<chromosomes.size();i++){
            for(int j=0;j<chromosomes[i].size();j++){
                if(chromosomes[i][j] == '1'){
                    fitness[i] += values[j];
                    totalWeights[i] += weights[j];
                }
            }
        }
       
        cout<<"\nNew Fitness\n";
        for(auto it: fitness)
            cout<<it<<" ";
        cout<<"\n";
        cout<<"\nTotal Weights\n";
        for(auto it: totalWeights)
            cout<<it<<" ";
        
        // CHECK IF ANY CHROMOSOME WEIGHS MORE THAN MAXWEIGHT
        sumOfValues = 0;
        for(int i=0;i<totalWeights.size();i++){
            if(totalWeights[i]<= maxWeight)
                sumOfValues += fitness[i];
            else
                weightExceededIndex=i;
        }
        cout<<"\nTotal Fitness "<<sumOfValues<<"\n";
        
    }
    return 0;
}