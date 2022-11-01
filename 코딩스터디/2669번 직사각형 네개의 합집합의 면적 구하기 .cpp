#include<iostream>
#include<vector>

using namespace std;

int main(){
    int sum = 0;
    int x1, x2, y1, y2;

    int xmax = 0;
    int xmin = 0;

    int ymax = 0;
    int ymin = 100;


    int area[101][101] = {0};

    for(int i=0; i<4; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        if(ymax < y2)
            ymax = y2;
        
        if(ymin > y1)
            ymin = y1;
    

        if(xmax < x2)
            xmax = x2;
        
        if(xmin > x1)
            xmin = x1;
    
        

        for(int k=x1; k<x2; k++){
            for(int j=y1; j<y2; j++){
                area[k][j]++;
            }
        }
    }

    for(int i=xmin; i<=xmax; i++){
        for(int j=ymin; j<=ymax; j++){
           if(area[i][j] > 0)
               sum++;
        }
    }
    
    cout << sum;
}
