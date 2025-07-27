#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    while(true){
        int r,c;
        cin>>r>>c;
        if(r==0&&c==0)break;
        vector<string>map(r);
        for(int i=0;i<r;i++){
                cin>>map[i];
        }
        int dy[8]={-1,-1,0,1,1,1,0,-1};
        int dx[8]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(map[i][j]=='*'){
                    cout<<map[i][j];
                    continue;
                }
                int cnt=0;
                for(int k=0;k<8;k++){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(ny<0||nx<0||ny>=r||nx>=c)continue;
                    if(map[ny][nx]=='*')cnt++;
                }
                map[i][j]=cnt+'0';
                cout<<map[i][j];
            }
            cout<<"\n";
        }
        
    }
    
    return 0;
}