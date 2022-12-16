#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    int ca;
    cin >> ca;

    vector<string> dab;
        

    for(int i=0; i<ca; i++){
        
        map<int, string> m;
        vector<int> v;
        
        int uni;
        cin >> uni;

        for(int i=0; i<uni; i++){
            int soju;
            string name;
            cin >> name >> soju;
            v.push_back(soju);
            m.insert({soju, name});
        }

        sort(v.begin(), v.end());
        dab.push_back(m[v[v.size()-1]]);
    }

    for(int i=0; i<dab.size(); i++)
        cout << dab[i] << endl;

    
}