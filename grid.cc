#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid():
  theGrid{0}, gridSize{0}, won{false}, td{0}, gd{0} {}

Grid::~Grid() {
  clearGrid();
}

void Grid::clearGrid() {
  theGrid.clear();
  delete td;
  delete gd;
}

bool Grid::isWon() const {
  for(auto row : theGrid) {
    for(auto col : row) {
      if(col.getState()) return won;
    }
  }
  return !won; 
}

void Grid::init(int n) {
  clearGrid();
  gridSize = n;
  won = false;
  td = new TextDisplay(n);
  gd = new GraphicsDisplay(n);

  // create the vector
  for(int row = 0; row < gridSize; ++row) 
  {
    // create the inside vector
    std::vector<Cell> rowCell;
    for(int col = 0; col < gridSize; ++col) {
      Cell aCell;
      aCell.setCoords(row, col);
      rowCell.push_back(aCell);
    }
    theGrid.push_back(rowCell);
  }

  // attach cell to their neighbours
  for(int row = 0; row < gridSize; ++row) {
    for(int col = 0; col < gridSize; ++col) {
      // the left cell
      if (col - 1 >= 0) {
        theGrid[row][col].attach(&theGrid[row][col-1]);
      }
      // the right cell
      if (col + 1 < gridSize) {
        theGrid[row][col].attach(&theGrid[row][col+1]);
      }
      // the up cell
      if (row - 1 >= 0) {
        theGrid[row][col].attach(&theGrid[row-1][col]);
      }
      // the down cell
      if (row + 1 < gridSize) {
        theGrid[row][col].attach(&theGrid[row+1][col]);
      }

      //attach the all textdisplay
      theGrid[row][col].attach(td);
      theGrid[row][col].attach(gd);
    }
  }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
  TextDisplay &t = *(g.td);
  out<< t;

  return out;
}
