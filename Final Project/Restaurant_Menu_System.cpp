#include <iostream>
#include <iomanip>
using namespace std;

struct FoodItem {
    string name;
    int price;
};

struct Order {
    string name;
    int price;
    int qty;
};

Order orders[100];
int orderCount = 0;

FoodItem appetizers[11] = {
    {"Crispy Finger Fish", 2795},
    {"Dynamite Chicken", 3125},
    {"Spicy Honey Chicken Wings", 2525},
    {"Sesame Honey Chilli Chicken", 3025},
    {"Dynamite Prawns", 4295},
    {"Stuffed Chilli Prawns", 3895},
    {"Prawn Tempura", 4295},
    {"Golden Silk Prawns", 4295},
    {"Chinese Spring Rolls", 2145},
    {"Steamed Chicken Dumplings", 2195},
    {"Fried Wonton", 2795}
};

FoodItem friesSmall[3] = {
    {"Plain Fries", 925},
    {"Masala Fries", 995},
    {"Cheese Fries", 1025}
};

FoodItem friesLarge[3] = {
    {"Plain Fries", 1095},
    {"Masala Fries", 1175},
    {"Cheese Fries", 1245}
};

FoodItem thai[14] = {
    {"Crispy Chicken Salad", 2195},
    {"Tom Yum Soup (Chicken)", 1575},
    {"Tom Yum Soup (Prawn)", 1725},
    {"Thai Green Curry Chicken", 3795},
    {"Thai Green Curry Prawns", 4595},
    {"Thai Red Curry Prawns", 4595},
    {"Thai Red Curry Chicken", 3795},
    {"Thai Chicken Cashew Nuts", 3395},
    {"Fried Fish Tamarind Sauce", 4095},
    {"Jasmine Rice (Half)", 1395},
    {"Jasmine Rice (Full)", 2175},
    {"Thai Noodles Prawns", 3475},
    {"Thai Noodles Chicken", 3245},
    {"Thai Noodles Vegetables", 2975}
};

FoodItem japanese[20] = {
    {"Nigiri Salmon", 2175},
    {"Nigiri Prawn", 2175},
    {"Nigiri Crab", 2175},
    {"Nigiri Tuna", 2175},
    {"Sashimi Salmon", 3195},
    {"Sashimi Tuna", 3195},
    {"Sashimi Prawn", 3195},
    {"Sashimi Crab", 3195},
    {"Sashimi Mixed", 3195},
    {"Spicy Salmon Roll", 4445},
    {"Spicy Tuna Roll", 4445},
    {"Rainbow Roll", 4445},
    {"Salmon Peach Roll", 3825},
    {"Tuna Flaming Roll", 4445},
    {"Salmon Flaming Roll", 4445},
    {"Crispy Salmon Roll", 3825},
    {"Spicy Tempura Roll", 3825},
    {"Spicy Red Snapper Roll", 3825},
    {"California Roll", 3825},
    {"Vegetable Roll", 2395}
};

FoodItem desserts[7] = {
    {"New York Cheesecake Slice", 1195},
    {"Caramel Custard", 895},
    {"Bread and Butter Pudding", 1625},
    {"Molten Lava Cake", 1625},
    {"Sizzling Brownie with Ice Cream", 1575},
    {"Chocolate Fudge Cake Slice", 895},
    {"Warm Chocolate Fudge Cake with Ice Cream", 1345}
};

FoodItem beverages[11] = {
    {"Soft Drinks", 325},
    {"Frosted Mint Lemonade", 325},
    {"Blue Lagoon", 1145},
    {"Pina Colada", 1195},
    {"Sparkling Water Small", 945},
    {"Mineral Water Large", 365},
    {"Mineral Water Small", 195},
    {"Tea", 415},
    {"Green Tea", 315},
    {"Coffee", 1075},
    {"Cold Coffee", 1345}
};

void addOrder(string name, int price) {
    int qty;
    cout << "Enter quantity: ";
    cin >> qty;
    orders[orderCount++] = {name, price, qty};
    cout << "Added to order.\n";
}

void printMenuWithOrder(FoodItem items[], int size) {
    cout << left << setw(5) << "No"
         << setw(35) << "Item"
         << right << setw(10) << "Price" << endl;

    for (int i = 0; i < size; i++)
        cout << left << setw(5) << i + 1
             << setw(35) << items[i].name
             << right << setw(10) << items[i].price << endl;

    int choice;
    cout << "Select item number (0 to cancel): ";
    cin >> choice;

    if (choice > 0 && choice <= size)
        addOrder(items[choice - 1].name, items[choice - 1].price);
}

void showFriesMenu() {
    cout << left << setw(5) << "No"
         << setw(30) << "Item"
         << right << setw(10) << "Small"
         << setw(10) << "Large" << endl;

    for (int i = 0; i < 3; i++)
        cout << left << setw(5) << i + 1
             << setw(30) << friesSmall[i].name
             << right << setw(10) << friesSmall[i].price
             << setw(10) << friesLarge[i].price << endl;

    int ch, size;
    cout << "Item number (0 cancel): ";
    cin >> ch;
    if (ch == 0) return;

    cout << "1. Small  2. Large: ";
    cin >> size;

    if (size == 1)
        addOrder(friesSmall[ch - 1].name + " (Small)", friesSmall[ch - 1].price);
    else if (size == 2)
        addOrder(friesLarge[ch - 1].name + " (Large)", friesLarge[ch - 1].price);
}

void showBill() {
    int total = 0;
    cout << "\n----- BILL -----\n";
    cout << left << setw(35) << "Item"
         << right << setw(8) << "Qty"
         << setw(10) << "Price"
         << setw(10) << "Total\n";

    for (int i = 0; i < orderCount; i++) {
        int t = orders[i].price * orders[i].qty;
        total += t;
        cout << left << setw(35) << orders[i].name
             << right << setw(8) << orders[i].qty
             << setw(10) << orders[i].price
             << setw(10) << t << endl;
    }
    cout << "-----------------------------\n";
    cout << "Grand Total: Rs " << total << endl;
}

void foodMenu() {
    int ch;
    while (true) {
        cout << "\n1. Appetizers\n2. Fries\n3. Thai\n4. Japanese\n5. Desserts\n6. Beverages\n7. Back\n";
        cin >> ch;

        if (ch == 1) printMenuWithOrder(appetizers, 11);
        else if (ch == 2) showFriesMenu();
        else if (ch == 3) printMenuWithOrder(thai, 14);
        else if (ch == 4) printMenuWithOrder(japanese, 20);
        else if (ch == 5) printMenuWithOrder(desserts, 7);
        else if (ch == 6) printMenuWithOrder(beverages, 11);
        else if (ch == 7) break;
    }
}

int main() {
    int ch;
    while (true) {
        cout << "\n1. Order Food\n2. View Bill\n3. Exit\n";
        cin >> ch;

        if (ch == 1) foodMenu();
        else if (ch == 2) showBill();
        else if (ch == 3) break;
    }
    return 0;
}
