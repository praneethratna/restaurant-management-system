#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include "constants.cpp"
using namespace std;

void add_dishes_menu()
{
    string dishname;
    int price,qty;
    cout<<"Enter dish name: "<<endl;
    cin.ignore(256, '\n');
    getline(cin, dishname, '\n');
    cout<<"Enter price of the dish: "<<endl;
    cin>>price;
    cout<<"Enter quantity of the dish: "<<endl;
    cin>>qty;
    dishes.push_back(Dish(dishname,price,qty,1));


}
void modify_dish()
{
  cout<<"Enter dish name which needs to be modified: ";
  string s;
  int price ,ind,qty;
  cin>>s;
  bool fd=0;
  for(int i=0;i<dishes.size();i++)
  {
      if(lower(s)==lower(dishes[i].name))
      {
          fd=1;
          ind=i;
          break;
      }
  }
  if(fd)
  {
      cout<<"Do you wish to modify price if YES enter 1 all other numbers indicate NO"<<endl;
      int i;
      cin>>i;
      if(i==1)
      {
         cout<<"Enter new price: "<<endl;
         int pr;
         cin>>pr;
         dishes[ind].price=pr;
      }
     cout<<"Do you wish to modify quantity if YES enter 1 all other numbers indicate NO"<<endl;
     cin>>i;
     if(i==1)
     {
         cout<<"Enter new quantity: "<<endl;
         int qty;
         cin>>qty;
         dishes[ind].quantity=qty;
     }

  }
}

void delete_dish()
{
  cout<<"Enter dish name which needs to be deleted: ";
  string s;
  int ind;
  cin>>s;
  bool fd=0;
    for(int i=0;i<dishes.size();i++)
    {
        if(lower(s)==lower(dishes[i].name))
        {
            fd=1;
            ind=i;
            break;
        }
    }
    if(fd)
    {
        dishes.erase(dishes.begin()+ind);
        cout << "Dish deleted successfully" << endl;
    }
}

void adminservices(){
    int num;
    bool exit = false;
    while(!exit){
    cout << "Choose any one of the options below:" << endl;
    cout << "1. View available dishes and quantity" << endl;
    cout << "2. Add new dishes into menu" << endl;
    cout << "3. Modify a particular dish" << endl;
    cout << "4. Delete a particular dish" << endl;
    cout << "5. Search for a particular dish using its name" << endl;
    cout << "6. Logout" << endl;
    cin >> num;
    switch(num){
        case 1:
            viewdishes();
            break;
        case 2:
            add_dishes_menu();
            break;
        case 3:
            modify_dish();
            break;
        case 4:
            delete_dish();
            break;
        case 5:
            searchdish();
            break;
        case 6:
            exit = true;
            break;
        default:
            cout << "Invalid option!" << endl;
    }
    }
}