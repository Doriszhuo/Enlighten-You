#include "graphicsdisplay.h"
#include "cell.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int n):
  gridSize{n}, length{500/n}, xw{*new Xwindow()} {
    for(int row = 0; row < n; ++row) {
      std::vector<bool> oneRow;
      for (int col = 0; col < n; ++col) {
        oneRow.push_back(false);
        xw.fillRectangle(col*length, row*length, length, length, Xwindow::Black);
      }
      theDisplay.push_back(oneRow);
  }
}


void GraphicsDisplay::notify(Cell &c) {
  int row = c.getRow();
  int col = c.getCol();
  int x = length * row;
  int y = length * col;
  if (theDisplay[row][col]) {
    theDisplay[row][col] = false;
    xw.fillRectangle(y, x, length, length, Xwindow::Black);
  } else {
    theDisplay[row][col] = true;
    xw.fillRectangle(y, x, length, length, Xwindow::White);
  }
}


GraphicsDisplay::~GraphicsDisplay() {
  for(int i = 0 ; i < gridSize; ++i) {
    theDisplay[i].clear();
  }
  theDisplay.clear();
  delete &xw;
}


SubscriptionType GraphicsDisplay::subType() {
  return SubscriptionType::Graphics;
}
