#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    double prob, range_from, range_to;
}node;

double encoding(unordered_map<char,node> arr, string s)
{
    double low = 0.0,high = 1.0, dif = 1.0;
    cout << "Symbol\tLow_v\tHigh_v\tdiff\n";
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        high = low + dif * arr[c].range_to;
        low = low + dif * arr[c].range_from;
        dif = high - low;
        cout<<c<<"\t"<<low<<"\t"<<high<<"\t"<<dif<<endl;
    }
    cout<<low<<endl;
    return low;
}

string decoding(unordered_map<char,node> arr, double code, int len )
{
    char ch;
    string text= "";
    int j=0;
    unordered_map<char, node>:: iterator it;
    cout<<"Code\tOutput\tRangeFrom\tRangeTo\n";
    while(j<len){
        cout<<code<<"\t";
        for(it= arr.begin(); it!=arr.end(); it++){
            char i= (*it).first;
            if(arr[i].range_from<= code && code< arr[i].range_to){
                ch= i;
                code= (code-arr[i].range_from)/(arr[i].range_to- arr[i].range_from);
                break;
            }
        }
        cout<<ch<<"\t"<<arr[ch].range_from<<"\t\t"<<arr[ch].range_to<<endl;
        text+= ch;
        j++;
    }
    return text;
}


int main()
{
    int n;
    cout<<"Enter no. of characters\n";
    cin>>n;
     /* 
        n=9
        Y 0.1
        E 0.2
        R 0.1
        G 0.1
        N 0.1
        M 0.1
        A 0.1
        F 0.1
        C 0.1
    */
    unordered_map<char, node> arr;
    
    vector<char> ar;
    double range_from= 0;
    cout<<"Enter probabilities:\n";
    for(int i=0; i<n; i++){
        char ch;
        cin>>ch;
        ar.push_back(ch);
        cin>>arr[ch].prob;
        arr[ch].range_from= range_from;
        arr[ch].range_to= range_from+ arr[ch].prob;
        range_from= arr[ch].range_to;
    }
    cout<<"Symbol\tProb\tRangeFrom\tRangeTo\n";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<"\t";
        char ch=ar[i];
        cout<<arr[ch].prob<<"\t"<<arr[ch].range_from<<"\t\t"<<arr[ch].range_to<<endl;
    }
    string s;
    cout<<"Enter text: ";
    cin>>s;
    double code=encoding(arr,s);
    cout<<"Code Generated is: "<<code<<endl;
    string d=decoding(arr,code,s.size());
    cout<<"Decoded Text: "<<d<<endl;
    
}
