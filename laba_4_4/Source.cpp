#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class HashTable
{
    int capacity;
    list<int>* table;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    int hashFunction(int key)
    {
        return (capacity * (key * ((sqrt(5) - 1) / 2) - floor(key * ((sqrt(5) - 1) / 2))));
    }
    void displayHash();
    int searchHash(int key);
};
HashTable::HashTable(int c)
{
    capacity = c;
    table = new list<int>[c];
}
void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}


void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
int HashTable::searchHash(int key) {
    int k = 0;
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++)
    {
        k++;
        if (*i == key)
            break;
    }
    if (i == table[index].end())
        return 0;
    return k;
}
int main()
{
    srand(time(NULL));
    int n = 10;
    ofstream f1("A.txt");
    int x;
    for (int i = 0; i < n; i++) {
        x = rand()%1000;
        f1 << x<<'\n';
    }
    HashTable h2(n);
    f1.close();
    ifstream f2("A.txt");
    for (int i = 0; i < n; i++) {
        f2 >> x;
        h2.insertItem(x, x);
    }
    h2.displayHash();

    cout << endl << h2.searchHash(x);
}