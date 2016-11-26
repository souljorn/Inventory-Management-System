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

  return 0;
}
