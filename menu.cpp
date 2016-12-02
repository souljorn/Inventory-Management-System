#include <iostream>
#include "Inventory.h"
#include "menu.h"


using namespace std;

menu::menu(){
	temp = Inventory();
}

void menu::initializeInventory(){
	//Inventory temp = Inventory();
	temp.populateInventory();
	temp.printInventory();
	temp.updateItemNumber(1,111);
	temp.printInventory();
	temp.updatePriceByName("Drill", 500.10);

	temp.printInventory();
	temp.updateQuantityByItemNumber(111,99);
	temp.deleteItemByName("Hammer");
	temp.printInventory();
}

void menu::addItem(){

	string name;
	int itemNumber;
	double price;
	int quantity;
	cout << "Please enter the name of the item:" << endl;
	cin >> name;
	cout << "Please enter the item number:" << endl;
	cin >> itemNumber;
	cout << "Pleae enter the price of the item:" << endl;
	cin >> price;
	cout << "Please enter the quantity of the item" << endl;
	cin >> quantity;
	temp.createItem(name, itemNumber, price, quantity);
}


void menu::managerMenu(){
	int input;
	initializeInventory();
	cout << "Please select an option from the menu: " << endl;
	cout << "1. Add an item to stock" << endl;
	cout << "2. Remove an item from stock" << endl;
	cout << "3. Increaes quantity of an item in stock" << endl;
	cout << "4. Decrease quantity of an item in stock" << endl;
	cin >> input;
	switch(input){
		case 1:
		addItem();
		break;
		case 2:
		// do
		break;
		case 3:
		// do
		break;
		case 4:
		//do
		break;
	}
}
// Main menu
