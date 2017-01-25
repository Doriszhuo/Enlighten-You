#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n):
gridSize{n} {
  for(int i = 0; i < n; ++i) {
    std::vector<char> oneRow;
    for(int i = 0; i< n; ++i) {
      oneRow.push_back('_');
    }
    theDisplay.push_back(oneRow);
  }
}

void TextDisplay::notify(Cell &c) {
  int row = c.getRow();
  int col = c.getCol();
  if (theDisplay[row][col] == 'X') {
    theDisplay[row][col] = '_';
  } else {
    theDisplay[row][col] = 'X';
  }
}

TextDisplay::~TextDisplay() {
  for(int i = 0; i < gridSize; ++i) {
    theDisplay[i].clear();
  }
  theDisplay.clear();
}


SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for(int row = 0; row < td.gridSize; ++row) {
    for (int col = 0; col < td.gridSize; ++col) {
        out << (td.theDisplay)[row][col];
    }
    out << endl;
  }
  return out;
}
