/**
Author: Group Team 30 Tim Botelho
Title: Inventory managment System
File: inventory.h
**/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>

using namespace std;

#ifndef Inventory_H_
#define Inventory_H_

//struct object to hold the data values associated with each item
struct item{
int itemNumber;
string name;
string description;
double price;
int quanity;
};

//**********************Compare Functions for Sort Functions******************
//A compare function must be created to use the sort functions in the
// C++ Standard Library. These functions exists outside the Inventroy Class

bool compareByPrice(const item &a, const item &b); //Compare function for sorting by price
bool compareByName(string &a, string &b); //compares two names and returns a bool

//***********************Inventory Class***************************************
//Inventory class contains all the fuctions
//dealing with creating, reading, updating, and deleting items
class Inventory{
private:
  vector<item> inventoryList;  //vector to hold all the items data


public:
  Inventory();

  void sortByPrice();        							 //Sorts items by price
  void createItem(item);      						//Create an item by passing a item struct
  void createItem(string name, int itemNumber, double price, int quantity);
  void deleteItemByName(string name);	//Delete item by name
  void deleteItemByItemNumber(int itemNumber);	//Deletes item by itemNumber
  bool isEmpty();             							//Return a bool if inventory is empty
  void printInventory();      						//Prints Inventory
  void populateInventory();   					//Populate some test data
  void findByName(string name);             //Find item by name
  int  findByNameReturnPos(string name);	 //Finds item by name and returns a int(vector position) do not use if item does not exist
  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 //Function will return a value of vector size if not found

  int findByItemNumberReturnPos(int itemNumber);
  bool isItemNameExist(string name);		//Checks if name is already used
  bool isItemNumberExist(int number);	//Checks if itemNumber is used
  ~Inventory();

};

#endif
