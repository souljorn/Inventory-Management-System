

/*
**************Overview of Inventory Class********************
-Inventory class holds item structs which hold the data of items held in the
inventory.
-The structs named "item" will have data values such as "price",
 "item number", "quanity", and whatever else the specification states.
-The item objects/structs will be held in a vector named inventoryList during
runtime and will then update the CSV file through a file class.
*/

//Consctructor
Inventory::Inventory(){

}
//Destructor
Inventory::~Inventory(){

}
//Create item
void Inventory::createItem(item input){
  inventoryList.push_back(input);
}

//Find item by name uses the stl algorithm find
void Inventory::findByName(string name){
  //create iterator
  int vecPos;
  vector<item>::iterator position;
  //Set the position iterator equal to the found item
  //Searches the inventory vector to find the string passed in name
  position = find(inventoryList.begin(), inventoryList.end(),name);
  if(position != inventoryList.end())
  {
    vecPos = distance(inventoryList.begin(), position);
    cout << "Found at index " << vecPos << endl;

  }
  else
  cout << "Not Found" << endl;
}


//Print Items in inventoryList
void Inventory::printInventory(){
  cout << "*********Item List**************" << endl;

  for(int i = 0; i < inventoryList.size(); i++){
    cout <<"| Item Number: " << inventoryList[i].itemNumber;
    cout <<" | Name: " << inventoryList[i].name;
    cout << " | Price: " << inventoryList[i].price;
    cout <<" | Quantity: " << inventoryList[i].quanity << endl;
  }
}

//isEmpty
bool Inventory::isEmpty(){
  if(inventoryList.size() == 0)
  {
    return true;
  }
  else{
    return false;
  }
}

//Populate inventoryList with some example data
void Inventory::populateInventory(){
  item temp;

  temp.itemNumber = 1;
  temp.name = "Hammer";
  temp.price = 5.12;
  temp.quanity = 12;

  createItem(temp);

  temp.itemNumber = 22;
  temp.name = "Hand Saw";
  temp.price = 12.23;
  temp.quanity = 5;
  createItem(temp);

  temp.itemNumber = 9;
  temp.name = "Drill";
  temp.price = 36.23;
  temp.quanity = 3;
  createItem(temp);

  temp.itemNumber = 12;
  temp.name = "Pliers";
  temp.price = 15.19;
  temp.quanity = 10;
  createItem(temp);

  temp.itemNumber = 192;
  temp.name = "Drill Bit";
  temp.price = 1.13;
  temp.quanity = 5;
  createItem(temp);

}


void Inventory::sortByPrice(){
  sort(inventoryList.begin(), inventoryList.end(), compareByPrice);
}

/***********************Compare Functions**********************/
bool compareByPrice(const item &a, const item &b)
{
    return a.price < b.price;
}

//Comapre two strings
bool compareByName(string &a, string &b)
{
 return (a.compare(b) == 1) ? true : false;
}

//Operator overloading used for using find function, in the stl library
bool operator==(const item& itemName, const string& name)
{
  return itemName.name == name;
}
