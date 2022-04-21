#include<bits/stdc++.h>
using namespace std;

int main(){
    // creating board
    vector<int> board(101);
    
    // initializing board
    int i=0;
    for(auto &it : board) it = i++;
    
    // marking snakes
    int snakes; cin>>snakes;
    while(snakes--){
        int pt1,pt2; cin>>pt1>>pt2;
        board[pt2] = pt1;
    }
    
    // marking ladders
    int ladders; cin>>ladders;
    while(ladders--){
        int pt1,pt2; cin>>pt1>>pt2;
        board[pt1] = pt2;
    }
    
    // register players
    int players; cin>>players;
    i = 1;
    unordered_map<int,string> player;
    while(players--){
        string name; cin>>name;
        player[i++] = name;
    }
    
    // allocating them pieces which are at pos 0
    unordered_map<int,int> piece_pos;
    for(auto &p : player) piece_pos[p.first] = 0;
    
    // record the name of winners
    // so after winning they can't play
    unordered_set<int> winners;
    
    // starting the game
    int player_count = player.size();
    int player_number = 1;
    while(player_count > 1){
        if(winners.find(player_number) != winners.end()){
            player_number++;
            continue;
        }
        
        // finding which player has turn
        int curr_player = player_number % player_count;
        if(curr_player == 0) curr_player = player_count;
        
        // rolling the dice
        int roll_dice = rand() % 6 + 1;
        
        int curr_pos = piece_pos[curr_player];
        
        // checking if the move is valid or not
        if(curr_pos + roll_dice <= 100)         
            piece_pos[curr_player] = curr_pos + roll_dice;
        
        // finding new pos after making a move
        int new_pos = piece_pos[curr_player];
        
        // snakes and ladder both covered here
        piece_pos[curr_player] = board[new_pos];
        
        new_pos = piece_pos[curr_player];
        
        // printing the move
        cout<<player[curr_player]<<" rolled a "<<roll_dice<<" and moved from "<<curr_pos<<" to "<<new_pos<<endl;
        
        if(piece_pos[curr_player] == 100){
            cout<<player[curr_player]<<" wins the fame"<<endl;
            winners.insert(curr_player);
            player_count--;
        }
        
        // next player turn
        player_number++;
    }
}