#include "observer.h"
#include "cell.h"
using namespace std;

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
  isOn = true;
  notifyAllObservers();
  notifyGraphics();
}

void Cell::toggle() {
  if (isOn) {
    isOn = false;
  } else {
    isOn = true;
  }
  notifyAllObservers();
  notifySwitchObservers();
  notifyGraphics();
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::attach(Observer *o) {
  observers.push_back(o);
}

void Cell::notify(Cell &c) {
  if(isOn) {
    isOn = false;
  } else {
    isOn = true;
  }
  notifyAllObservers();
  notifyGraphics();
}

SubscriptionType Cell::subType() {
  return SubscriptionType::SwitchOnly;
}

void Cell::notifyAllObservers() {
  int size = observers.size();
  for(int i = 0; i < size; ++i) {
    if (observers[i]->subType() == SubscriptionType::All) {
      observers[i]->notify(*this);
    }
  }
}

void Cell::notifySwitchObservers() {
  int size = observers.size();
  for(int i = 0; i < size; ++i) {
    if (observers[i]->subType() == SubscriptionType::SwitchOnly) {
      observers[i]->notify(*this);
    }
  }
}

void Cell::notifyGraphics() {
  int size = observers.size();
  for(int i = 0; i < size; ++i) {
    if (observers[i]->subType() == SubscriptionType::Graphics) {
      observers[i]->notify(*this);
    }
  }
}
