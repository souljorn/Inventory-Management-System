#include "Inventory.h"
#include "Inventory.cpp"


using namespace std;

int main(int argc, char const *argv[]) {
  /* code */

  Inventory current = Inventory();
  current.populateInventory();
  current.printInventory();
  current.sortByPrice();
  current.printInventory();
  current.findByName("Drill");
  cout << current.findByNameReturnPos("Drill Bit") << endl;
  cout << current.findByNameReturnPos("Drill Bi") << endl;
  current.deleteItemByName("Drill Bit");
  current.printInventory();
  current.deleteItemByItemNumber(9);
  current.printInventory();
  current.deleteItemByItemNumber(1);
  current.deleteItemByItemNumber(22);
  current.deleteItemByItemNumber(12);
  current.deleteItemByItemNumber(12);
  current.createItem("Screwdriver", 1234, 8.99, 23);
  current.printInventory();
  return 0;
}
