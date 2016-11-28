#include "Inventory.h"


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
  return 0;
}
