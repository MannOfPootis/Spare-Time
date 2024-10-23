#include <iostream>
#include "string"
#include "vector"
#include <cstdlib>
using namespace std;
struct chord{
    int comp[2];
};
class Crossword{
    vector<chord> placements;
    vector<char> letter;
};
Crossword makeConsSqare(string words[],vector<vector<int>>* cons){
    vector<vector<int>>picked;
    //aply geometric rules to make connections
    //get random coonnection
    //if(fkin geometricaly possible)-> write down that you have it
    //delete connection,
    //repeat until out of connections
}
bool geometricalyPossible(Crossword* crossword,string words[],vector<int> candidate){//concept of coordinates should still aply for 2d euclidian crosswords

}
vector<vector<int>> getParts(string words[]){
    vector<vector<int>> cons;//all mi homies hat n! time complexity
    for(int i =0;i<words->length();i++){
        for (int j = 0; j < words[i].length(); j++) {//goes thru all the words and finds all the indexes of  the letters that are paired
            for(int x =i+1;x<words->length();x++){//its a surprise tool thatll help us later
                for(int y =0;y<words[x].length();y++){
                    if(words[i][j]==words[x][y]){
                        vector<int> pair= {i,j,x,y};
                       // cout<<pair[0]<<","<<pair[1]<<"=="<<pair[2]<<","<<pair[3]<<"\n";
                        cons.push_back(pair);//dont mind this indentation helll is swear its the only way
                    }
                }
            }
        }
    }
    return cons;
}

int main() {
//    int seed=123;

    std::string words[] = {"aaa","aaa","aaa"};
    vector<vector<int>> pair=getParts(words);//finds connections of characters
    for(int i=0;i<pair.size();i++){
        cout<<words[pair[i][0]][pair[i][1]]<<" == "<<words[pair[i][2]][pair[i][3]]<<"\n";
        //cout<<pair[i][0]<<","<<pair[i][1]<<"=="<<pair[i][2]<<","<<pair[i][3]<<"\n";
    }
   // cout<<words[pair[0][0]][pair[0][1]]<<words[pair[0][2]][pair[0][3]];
    std::cout << "Hello, World!" << std::endl;
    //find connnections (check)
    //pick connections according to gemometric rules
    //print(meh)
    return 0;
}
