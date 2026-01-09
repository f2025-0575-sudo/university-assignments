#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct FoodItem {
    int id;
    string name;
    int price;
};

struct Table {
    int id;
    int busy;
    time_t startTime;
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
            o << i << " 0 0\n";
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
        fin >> tables[i].id >> tables[i].busy >> tables[i].startTime;
    fin.close();
}

void saveTables() {
    ofstream fout("tables.txt");
    for (int i = 0; i < 10; i++)
        fout << tables[i].id << " " << tables[i].busy << " " << tables[i].startTime << endl;
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
         << right << setw(10) << "Price\n";
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

        cout << "1 Add another item\n2 Back\n";
        cin >> again;
    }
}

bool showBill(int tableId) {
    ifstream fin("orders.txt");
    int t, id, qty;
    int total = 0;
    bool found = false;

    cout << "\nBILL FOR TABLE " << tableId << endl;
    cout << left << setw(25) << "Item"
         << right << setw(5) << "Qty"
         << setw(10) << "Price"
         << setw(10) << "Total\n";

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
        cout << "No orders for this table\n";
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
        cout << "No orders to pay\n";
        return;
    }

    remove("orders.txt");
    rename("temp.txt", "orders.txt");

    loadTables();
    tables[tableId - 1].busy = 0;
    tables[tableId - 1].startTime = 0;
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
        tables[tableId - 1].startTime = time(0);
        saveTables();
    }

    int ch;
    while (true) {
        cout << "\n1 View Menu\n2 Order Food\n3 View Bill\n4 Pay Bill\n5 Back\n";
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

    cout << "\nACTIVE ORDERS\n";
    cout << left << setw(10) << "Table"
         << setw(25) << "Item"
         << setw(5) << "Qty\n";

    while (fin >> t >> id >> qty) {
        FoodItem item = getItem(id);
        cout << left << setw(10) << t
             << setw(25) << item.name
             << setw(5) << qty << endl;
        found = true;
    }
    fin.close();

    if (!found)
        cout << "No active orders\n";
}

void owner() {
    loadTables();
    int freeT = 0, busyT = 0;

    for (int i = 0; i < 10; i++)
        tables[i].busy ? busyT++ : freeT++;

    cout << "\nTotal Tables: 10\n";
    cout << "Free Tables: " << freeT << endl;
    cout << "Busy Tables: " << busyT << endl;

    for (int i = 0; i < 10; i++)
        if (tables[i].busy)
            cout << "Table " << tables[i].id
                 << " occupied for "
                 << difftime(time(0), tables[i].startTime) / 60
                 << " minutes\n";
}

int main() {
    initFiles();

    cout << "WELCOME TO RESTAURANT SYSTEM\n";

    int role;
    while (true) {
        cout << "\n1 Customer\n2 Waiter\n3 Owner\n4 Exit\n";
        cin >> role;

        if (role == 1) customer();
        else if (role == 2) waiter();
        else if (role == 3) owner();
        else if (role == 4) break;
    }
    return 0;
}
