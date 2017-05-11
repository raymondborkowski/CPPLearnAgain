//
//  main.cpp
//  CPPLearnAgain
//
//  Created by Raymond Borkowski on 5/10/17.
//  Copyright © 2017 Raymond Borkowski. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <iostream> // P1
#include <cmath> // P1
#include <string> // P1

using namespace std;

string pluralize(string singular, string plural, int number);

double amountOfBatches(int amountOfPeople) {
    double batchesToMake = 1;
    
    if (amountOfPeople > 12) {
        batchesToMake = amountOfPeople/12.0;
    }
    
    return ceil(batchesToMake);
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}

void printShoppingListHeader() {
    cout << "Shopping List for \"Best Ever\" Vanilla Cupcakes\n";
    cout << "----------------------------------------------\n";
}

double groceryAmountsToBuy(double totalBatches,double servingSize,double shoppingStoreSize) {
    double bagsOfFlower = 1.0;
    double servingsPerBatches = totalBatches * servingSize;
    if (servingsPerBatches > shoppingStoreSize) {
        bagsOfFlower = ceil(servingsPerBatches/shoppingStoreSize);
    }
    return bagsOfFlower;
}

double totalCost(int howManyItems, double itemCost) {
    double totalCost = 0;
    
    return totalCost;
}

double getItemsCost(int amountOfItems, double itemCost) {
    return amountOfItems * itemCost;
}

void printShoppingListBody(int totalBatches) {
    int flour = groceryAmountsToBuy(totalBatches, 1.5, 20);
    int granSugar = groceryAmountsToBuy(totalBatches, 1, 10);
    int butter = groceryAmountsToBuy(totalBatches, 1.5, 2);
    int sourCream = groceryAmountsToBuy(totalBatches, .5, 1);
    int eggs = groceryAmountsToBuy(totalBatches, 3, 12);
    int powSugar = groceryAmountsToBuy(totalBatches, 2.5, 5.5);
    int vanilla = groceryAmountsToBuy(totalBatches, 4.5, 12);
    
    cout << "   " << flour << " " << pluralize("bag", "bags", flour) << " of flour\n";
    cout << "   " << granSugar << " " << pluralize("bag", "bags", granSugar) << " of granulated sugar\n";
    cout << "   " << butter << " " << pluralize("pound", "pounds", butter) << " of butter\n";
    cout << "   " << sourCream << " " << pluralize("container", "containers", sourCream) << " of sour cream\n";
    cout << "   " << eggs << " dozen eggs\n";
    cout << "   " << powSugar << " " << pluralize("bag", "bags", powSugar) << " of powdered sugar\n";
    cout << "   " << vanilla << " " << pluralize("bottle", "bottles", vanilla) << " of vanilla\n\n";
    
    double totalCost = getItemsCost(flour, 3.09);
    totalCost += getItemsCost(granSugar, 2.98);
    totalCost += getItemsCost(butter, 2.5);
    totalCost += getItemsCost(sourCream, 1.29);
    totalCost += getItemsCost(eggs, 2.68);
    totalCost += getItemsCost(powSugar, 1.18);
    totalCost += getItemsCost(vanilla, 4.12);
    cout << "Total expected cost of ingredients: $" << totalCost << endl;
}

int main(int argc, const char * argv[]) {
    
    int amountOfPeople;
    
    cout << "How many people do you need to serve?";
    cin >> amountOfPeople;
    int batches = amountOfBatches(amountOfPeople);
    cout << "\nYou need to make: " << batches << " " << pluralize("batch", "batches", batches) << " of cupcakes\n\n";
    printShoppingListHeader();
    printShoppingListBody(batches);
    
    cout << "\nHave a great party!"<<endl;
    
    return 0;
}
