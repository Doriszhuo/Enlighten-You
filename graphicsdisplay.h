#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"
class Cell;

class GraphicsDisplay : public Observer {
  Xwindow &xw;
  std::vector<std::vector<bool>> theDisplay;
  const int gridSize;
  int length;
 public:
  GraphicsDisplay(int n);
  ~GraphicsDisplay();

  void notify(Cell &c) override;
  SubscriptionType subType() override;

};


#endif
