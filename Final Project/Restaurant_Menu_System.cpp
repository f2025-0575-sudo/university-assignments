#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct FoodItem {
    int id;
    string name;
    int price;
};

struct Table {
    int id;
    int busy;
};

FoodItem menu[5] = {
    {1, "Fried Rice", 500},
    {2, "Chow Mein", 600},
    {3, "Sweet & Sour Chicken", 750},
    {4, "Kung Pao Chicken", 850},
    {5, "Hot & Sour Soup", 400}
};

Table tables[10];

void initFiles() {
    ifstream f1("tables.txt");
    if (!f1) {
        ofstream o("tables.txt");
        for (int i = 1; i <= 10; i++)
            o << i << " 0" << endl;
        o.close();
    } else f1.close();

    ifstream f2("orders.txt");
    if (!f2) {
        ofstream o("orders.txt");
        o.close();
    } else f2.close();

    ifstream f3("sales.txt");
    if (!f3) {
        ofstream o("sales.txt");
        o.close();
    } else f3.close();
}

void loadTables() {
    ifstream fin("tables.txt");
    for (int i = 0; i < 10; i++)
        fin >> tables[i].id >> tables[i].busy;
    fin.close();
}

void saveTables() {
    ofstream fout("tables.txt");
    for (int i = 0; i < 10; i++)
        fout << tables[i].id << " " << tables[i].busy << endl;
    fout.close();
}

FoodItem getItem(int id) {
    for (int i = 0; i < 5; i++)
        if (menu[i].id == id)
            return menu[i];
    return menu[0];
}

void showMenu() {
    cout << left << setw(5) << "No"
         << setw(30) << "Item"
         << right << setw(10) << "Price" << endl;

    for (int i = 0; i < 5; i++)
        cout << left << setw(5) << menu[i].id
             << setw(30) << menu[i].name
             << right << setw(10) << menu[i].price << endl;
}

void orderFood(int tableId) {
    int again = 1;
    while (again == 1) {
        int id, qty;
        showMenu();
        cout << "Select item number: ";
        cin >> id;
        cout << "Quantity: ";
        cin >> qty;

        ofstream fout("orders.txt", ios::app);
        fout << tableId << " " << id << " " << qty << endl;
        fout.close();

        cout << "1 Add another item" << endl;
        cout << "2 Back" << endl;
        cin >> again;
    }
}

bool showBill(int tableId) {
    ifstream fin("orders.txt");
    int t, id, qty;
    int total = 0;
    bool found = false;

    cout << endl;
    cout << "BILL FOR TABLE " << tableId << endl;

    cout << left << setw(25) << "Item"
         << right << setw(5) << "Qty"
         << setw(10) << "Price"
         << setw(10) << "Total" << endl;

    while (fin >> t >> id >> qty) {
        if (t == tableId) {
            FoodItem item = getItem(id);
            int sum = item.price * qty;
            total += sum;
            found = true;

            cout << left << setw(25) << item.name
                 << right << setw(5) << qty
                 << setw(10) << item.price
                 << setw(10) << sum << endl;
        }
    }
    fin.close();

    if (!found) {
        cout << "No orders for this table" << endl;
        return false;
    }

    cout << "Grand Total: Rs " << total << endl;
    return true;
}

void payBill(int tableId) {
    ifstream fin("orders.txt");
    ofstream temp("temp.txt");

    int t, id, qty;
    int total = 0;
    bool found = false;

    while (fin >> t >> id >> qty) {
        if (t == tableId) {
            FoodItem item = getItem(id);
            total += item.price * qty;
            found = true;
        } else {
            temp << t << " " << id << " " << qty << endl;
        }
    }

    fin.close();
    temp.close();

    if (!found) {
        remove("temp.txt");
        cout << "No orders to pay" << endl;
        return;
    }

    remove("orders.txt");
    rename("temp.txt", "orders.txt");

    loadTables();
    tables[tableId - 1].busy = 0;
    saveTables();

    ofstream sales("sales.txt", ios::app);
    sales << "Table " << tableId << " Paid " << total << endl;
    sales.close();

    cout << "Payment successful. Total Rs " << total << endl;
}

void customer() {
    int tableId;
    loadTables();

    cout << "Enter table number (1-10): ";
    cin >> tableId;

    if (!tables[tableId - 1].busy) {
        tables[tableId - 1].busy = 1;
        saveTables();
    }

    int ch;
    while (true) {
        cout << endl;
        cout << "1 View Menu" << endl;
        cout << "2 Order Food" << endl;
        cout << "3 View Bill" << endl;
        cout << "4 Pay Bill" << endl;
        cout << "5 Back" << endl;
        cin >> ch;

        if (ch == 1) showMenu();
        else if (ch == 2) orderFood(tableId);
        else if (ch == 3) showBill(tableId);
        else if (ch == 4) { payBill(tableId); break; }
        else if (ch == 5) break;
    }
}

void waiter() {
    ifstream fin("orders.txt");
    int t, id, qty;
    bool found = false;

    cout << endl;
    cout << "ACTIVE ORDERS" << endl;

    cout << left << setw(10) << "Table"
         << setw(25) << "Item"
         << setw(5) << "Qty" << endl;

    while (fin >> t >> id >> qty) {
        FoodItem item = getItem(id);
        cout << left << setw(10) << t
             << setw(25) << item.name
             << setw(5) << qty << endl;
        found = true;
    }
    fin.close();

    if (!found)
        cout << "No active orders" << endl;
}

void owner() {
    loadTables();
    int freeT = 0, busyT = 0;

    for (int i = 0; i < 10; i++)
        tables[i].busy ? busyT++ : freeT++;

    cout << endl;
    cout << "Total Tables: 10" << endl;
    cout << "Free Tables: " << freeT << endl;
    cout << "Busy Tables: " << busyT << endl;
}

int main() {
    initFiles();

    cout << "WELCOME TO RESTAURANT SYSTEM" << endl;

    int role;
    while (true) {
        cout << endl;
        cout << "1 Customer" << endl;
        cout << "2 Waiter" << endl;
        cout << "3 Owner" << endl;
        cout << "4 Exit" << endl;
        cin >> role;

        if (role == 1) customer();
        else if (role == 2) waiter();
        else if (role == 3) owner();
        else if (role == 4) break;
    }
    return 0;
}
