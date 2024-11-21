#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
  int current_pos;
  bool play_next_round;
};

int main(){
  int players_number, squares_number;
  while(cin >> players_number >> squares_number && players_number != 0 && squares_number != 0){
    vector<int> traps_position;
    for(int i = 0; i < 3; i++){
      int temp;
      cin >> temp;
      traps_position.push_back(temp);
    }

    Player default_player;
    default_player.current_pos = 0;
    default_player.play_next_round = true;
    vector<Player> players(players_number, default_player);

    int dices_number, next_player = 0;
    cin >> dices_number;
    while(dices_number--){
      int d1, d2;
      cin >> d1 >> d2;
      int result = d1 + d2;

      Player* current = &players.at(next_player);
      while(!current->play_next_round){
        next_player++;
        if(next_player >= players_number) next_player = 0;
        current->play_next_round = true;
        current = &players.at(next_player);
      }

      current->current_pos+=result;
      bool is_in_trap = count(traps_position.begin(), traps_position.end(), current->current_pos) > 0? true : false;
      if(is_in_trap){
        current->play_next_round=false;
      }

      if(current->current_pos > squares_number){
        cout << next_player+1 << endl;
        break;
      }
      next_player++;
      if(next_player >= players_number) next_player = 0;
    }
  }
}

/*

CASO 1
3 10
2 4 8
11
1 1
1 1 
1 1
1 1
1 1
1 1
2 2
2 2
2 2
1 1
1 2

2

CASO 2
2 10
2 4 8
8
1 1
1 1
1 1 
1 1
2 2
2 2
1 1
2 2

2

CASO 3
2 10
2 4 8
4
1 1
3 4
1 2
6 5

1

CASO 4
3 7
4 5 7
7
1 2
2 2
2 1
1 1
1 2
1 1
1 1

3

CASO 5
5 20
2 4 7
8
2 4
1 1
2 2
4 5
6 1
1 4
3 6
6 6

1

CASO 6
2 40
2 9 5
10
1 1
1 1
6 6
6 6
4 4
4 4
1 1
5 5
1 1
6 6

2

*/