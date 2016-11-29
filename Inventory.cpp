#include "Inventory.h"

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
Inventory::Inventory() : inventoryList() {

}
//Destructor
Inventory::~Inventory(){

}

//Create item
void Inventory::createItem(item input){

	//Check if item name already exists
	if(!isItemNameExist(input.name) || !isItemNumberExist(input.itemNumber)){
		inventoryList.push_back(input);
	}
	else
		cout << "Item Already Exists" << endl;
}

void Inventory::createItem(string name,int itemNumber, double price, int quantity){
	item temp;

	temp.name = name;
	temp.itemNumber = itemNumber;
	temp.price = price;
	temp.quanity = quantity;
	//Check if item name already exists
	if(!isItemNameExist(temp.name) || !isItemNumberExist(temp.itemNumber)){
		inventoryList.push_back(temp);
	}
	else
		cout << "Item Already Exists" << endl;
}

void Inventory::deleteItemByName(string name){
	int temp;

	//If Item exists then delete item using vector erase
	if(isItemNameExist(name))
	{
		temp = findByNameReturnPos(name);
		cout << inventoryList[temp].name << " was deleted" << endl;
		inventoryList.erase(inventoryList.begin( ) + temp);
	}
	else{
		cout << "Item does not exist" << endl;
	}
}

void Inventory::deleteItemByItemNumber(int itemNumber){
	int temp;

	//If Item exists then delete
	if(isEmpty()){
		cout << "Inventory is Empty" << endl;
	}
	else if(isItemNumberExist(itemNumber))
	{
		temp = findByItemNumberReturnPos(itemNumber);
		cout << inventoryList[temp].name << " was deleted" << endl;
		inventoryList.erase(inventoryList.begin( ) + temp);
	}
	else{
		cout << "Item does not exist" << endl;
	}
}

void Inventory::findByName(string name){			//Find item by name uses the stl algorithm find

	//create an int to hold vector position and an iterator
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

int Inventory::findByNameReturnPos(string name){			//Find item by name uses the stl algorithm find
	//Only use if item is known to exist

	//create iterator
	int vecPos;
	vector<item>::iterator position;
	//Set the position iterator equal to the found item
	//Searches the inventory vector to find the string passed in name
	position = find(inventoryList.begin(), inventoryList.end(),name);
	//Find the position of item
	vecPos = distance(inventoryList.begin(), position);
	return vecPos;
}

int Inventory::findByItemNumberReturnPos(int itemNumber){			//Find item by name uses the stl algorithm find
	//Only use if item is known to exist

	//create iterator
	int vecPos;
	vector<item>::iterator position;
	//Set the position iterator equal to the found item
	//Searches the inventory vector to find the string passed in name
	position = find(inventoryList.begin(), inventoryList.end(),itemNumber);
	//Find the position of item
	vecPos = distance(inventoryList.begin(), position);
	return vecPos;
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

//isEmpty checks if inventoryList is empty
bool Inventory::isEmpty(){
	if(inventoryList.size() == 0)
	{
		return true;
	}
	else{
		return false;
	}
}

bool Inventory::isItemNameExist(string name){
	vector<item>::iterator position;
	//Set the position iterator equal to the found item
	//Searches the inventory vector to find the string passed in name
	position = find(inventoryList.begin(), inventoryList.end(),name);
	if(position != inventoryList.end())
	{
		return true;
	}

	else
		return false;
}

bool Inventory::isItemNumberExist(int number){
	//create an iterator
	vector<item>::iterator position;

	//set postion of iterator using find stl algorithm
	position = find(inventoryList.begin(), inventoryList.end(), number);

	if(position != inventoryList.end())
	{
		return true;
	}

	else
		return false;

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

	//Error checking duplicate name
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

//Sort functions need a compare function written and passed so the library knows how to compare the items
bool compareByPrice(const item &a, const item &b)
{
	return a.price < b.price;
}

//Comapre two strings
bool compareByName(string &a, string &b)
{
	return (a.compare(b) == 1) ? true : false;
}

//**********************Overloaded Operator ***********************
//Operator overloading used for using find function, in the stl library
bool operator==(const item& itemName, const string& name)
				{
	return itemName.name == name;
				}

//Operator overloading of item number comparison for find function in stl library
bool operator==(const item& itemName, const int& itemNumber)
				{
	return itemName.itemNumber == itemNumber;
				}
