#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;
int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

  while (true) {
    cin >> cmd;

    // give a new grid
    if (cmd == "new") {
      int n;
      cin >> n;
      g.init(n);
      moves = 0;
    }

    // initialize a new grid
    else if (cmd == "init") {
      int r = 0, c = 0;
      cin >> r >> c;
      while(true) {
        if (r == -1 && c == -1) {
          cout << g;
          break;
        }
        g.turnOn(r,c);
        cin >> r >> c;
      }
    }

    // start a new game
    else if (cmd == "game") {
      cin >> moves;
      cout << moves << " moves left" << endl;
      
      // check if given move is 0, the grid has already win
      if (moves == 0) {
        if (g.isWon()) {
          cout << "Won" << endl;
        } else {
          cout << "Lost" << endl;
        }
        return 0;
      }
    }

    // switch the cells
    else if (cmd == "switch") {
        int r = 0, c = 0;
        // input, change, switch
        cin >> r >> c;
        g.toggle(r,c);
        cout << g;
        --moves;
        cout << moves << " moves left" << endl;

        // check if grid is Won
        if (g.isWon()) {
          cout << "Won" << endl;
          return 0;
        }

        // cehck if grid is not Won, there is still moves remaining
        if (moves == 0) {
          cout << "Lost" << endl;
          return 0;
        } 
    }
  }
}
