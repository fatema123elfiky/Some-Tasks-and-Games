#include <iostream>
#include <vector>
using namespace std;

bool valid(int row,int column,int R,int C){

    if(row<0||row>=R||column<0||column>=C)
        return false;
    else
        return true;
}

class Universe{
private:
    vector<int>directions{-1,1,0,0,-1,1,-1,1};
    vector<int>directions2{0,0,-1,1,-1,1,1,-1};
    vector<vector<char>>grid;
    void Run(int row,int column,int R,int C ){
        int alive=0,dead=0;
        for (int i = 0; i < 8; ++i) {
            if(valid(row+directions[i],column+directions2[i],R,C)){
              if(grid[row][column]=='*')
                  alive++;
              else{
                  dead++;
              }

            }

        }
        if(grid[row][column]=='*'&&alive<2){
            grid[row][column]='.';
        }else if((alive==2||alive==3)&&grid[row][column]=='*')
            grid[row][column]='*';
        else if(alive>3&&grid[row][column]=='*'){
            grid[row][column]='.';
        }else if(grid[row][column]=='.'&&alive==3)
            grid[row][column]='*';

    }
public:
    //.-->dead , *-->alive

    Universe(int row,int column):grid(vector<vector<char>>(row,vector<char>(column) )){
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                grid[i][j]='.';
            }
        }
    };

    void intialize(vector<vector<char>> & grid){
        this->grid=grid;
    }

    void reset(){
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
               grid[i][j]='.';
            }
        }
    }

    long long count_neighbors(){
        long long count=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '*'){
                    count++;
                }
            }
        }
        return count;
    }

    void display(){
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                cout<<grid[i][j]<<" ";
            }
            cout<<'\n';
        }

    }

    void run(int runs){
        for (int i = 0; i < runs; ++i) {

            for (int j = 0; j < grid.size(); ++j) {
                for (int k = 0; k < grid[i].size() ; ++k) {

                   Run(j,k,grid.size(),grid[i].size());

                }
            }


        }

    }

   void  next_generation(){
        run(1);
    }

};



int main() {

Universe u(20,50);
vector<vector<char>>v(20,vector<char>(50,'.'));
v[11][20]=v[10][20]=v[13][22]='*';
u.intialize(v);
u.display();
cout<<"alive : \n"<<u.count_neighbors()<<"\n\n\n";
cout<<"generation : "<<'\n';
    u.next_generation();
    u.display();
    cout<<"\n\n\n";
    u.run(3);
    u.display();




}
