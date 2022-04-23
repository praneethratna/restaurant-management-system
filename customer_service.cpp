#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include "constants.cpp"
using namespace std;

void add_dishes_to_cart(int i){
    string dish;
    int q;
    cout << "Enter the dish name to be added to the cart" << endl;
    cin >> dish;
    cout << "Enter the quantity of the dish to be added to the cart" << endl;
    cin >> q;
    if(q > 0){
    customers[i].orders.push_back(pair<string,int>(dish,q));
    customers[i].bill_amount+=finddish(dish).price*q;
    }
    else{
        cout << "Invalid quantity entered!" << endl;
    }
}
void viewbill(int i){
    cout << "Bill for customer " << customers[i].name << endl;
    cout << "====================="<<endl;
    cout << std::left << std::setw(20) << "Dish name" << internal
    << setw(20) << "Price" <<setw(20) << "Quantity"<< endl;
    for(int j=0;j<customers[i].orders.size();j++){
        cout << std::left << std::setw(20) << customers[i].orders[j].first << internal << setw(20)
        << finddish(customers[i].orders[j].first).price << internal << setw(20) << customers[i].orders[j].second << endl;
    }

    cout << "Total bill amount: " << customers[i].bill_amount << endl;
}
void placeorder(int i){
    cout << "Your order has been successfully placed!" << endl;
    if(customers[i].no_of_visits>1){
        cout << "You have been given a " << 2*customers[i].no_of_visits << "% discount on your bill!" << endl;
        customers[i].bill_amount-=(2*customers[i].no_of_visits*customers[i].bill_amount)/10;
        viewbill(i);
    }
    else{
        viewbill(i);
    }
    for(int j=0;j<customers[i].orders.size();j++){
        decrease_quantity(customers[i].orders[j].first,customers[i].orders[j].second);
    }
    customers[i].bill_amount = 0;
    customers[i].orders.clear();
}
void votedishes(){
cout << "Enter the name of the dish for which you want to give rating: " << endl;
string dish;
cin >> dish;
vote(dish);
}

void editcart(int i){
    cout << "Enter the dish name to be edited: " << endl;
    string dish;
    cin >> dish;
    int j = searchcart(i, dish);
    if(j == -1){
        cout << "Dish not found in the Cart!" << endl;
    }
    else{
    cout << "Enter the new quantity of the dish: " << endl;
    int q;
    cin >> q;
        if(q > 0){
            customers[i].bill_amount-=finddish(dish).price*customers[i].orders[j].second;
            customers[i].orders[j].second = q;
            customers[i].bill_amount+=finddish(dish).price*q;
            cout << "Dish quantity updated successfully!" << endl;
        }
        else if(q < 0){
            cout << "Invalid quantity entered!" << endl;
        }
        else{
            customers[i].bill_amount-=finddish(dish).price*customers[i].orders[j].second;
            customers[i].orders.erase(customers[i].orders.begin()+j);
            cout << "Dish successfully removed from cart!" << endl;
        }
    }
    }



void customerservices(int i){
    int num;
    bool exit = false;
    while(!exit){
    cout << "Choose any one of the options below:" << endl;
    cout << "1. View available dishes and quantity" << endl;
    cout << "2. Search for a particular dish using its name"<<endl;
    cout << "3. Select dishes into cart" << endl;
    cout << "4. Edit cart" << endl;
    cout << "5. View dishes in cart and total amount to be paid" << endl;
    cout << "6. Place order" << endl;
    cout << "7. Vote for dishes"<<endl;
    cout << "8. Logout" << endl;
    cin >> num;
    switch(num){
        case 1:
            viewdishes();
            break;
        case 2:
            searchdish();
            break;
        case 3:
            add_dishes_to_cart(i);
            break;
        case 4:
            editcart(i);
            break;
        case 5:
            viewbill(i);
            break;
        case 6:
            placeorder(i);
            break;
        case 7:
            votedishes();
            break;
        case 8:
            exit = true;
            break;
        default:
            cout << "Invalid option entered!" << endl;
    }
    }
}

