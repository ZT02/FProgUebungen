#include <iostream>
using namespace std;

class Knoten {
public:
    int value;
    Knoten* left;
    Knoten* right;
    Knoten(int v = 0) : value(v), left(nullptr), right(nullptr) {}
};

//X.value < K.value für alle Knoten X des linken Teilbaums von K und

//X.value > K.value für alle Knoten X des rechten Teilbaums von K
class Baum {
private:
    Knoten* root;
    int n;
    using NodeFunction = int (Baum::*)(typename Knoten*);
    void iterate(Knoten* node, NodeFunction visit);
    int insert(Knoten** parent, int value);

    

public:
    Baum() : root(new Knoten(0)), n(0) {}
    int insert(int value) { return insert(&root, value); }
    int sum(Knoten* node);
    void sumtotal();

};
int Baum::insert(Knoten** parent, int value) {
    if (!*parent) {
        *parent = new Knoten(value);
        return 1;
    }
    if (value < (*parent)->value)
        return (insert(&(*parent)->left, value));
    else if (value > (*parent)->value)
        return (insert(&(*parent)->right, value));

    return 0;
}

void Baum::iterate(Knoten* node, NodeFunction visit) {
    if (!node)
        return;

    iterate(node->left, visit);
    (this->*visit)(node);
    iterate(node->right, visit);
}

int Baum::sum(Knoten* node) {
   
    n += node->value;
    cout << "nodeValue: " << node->value <<endl;
    return n;
}

void Baum::sumtotal() {
    n = 0;
    iterate(root, &Baum::sum);
    
    cout << "Gesamtsumme: " << n << endl;
}
int main()
{
    Baum b;
    for (int i = 0; i < 10; i++)
        b.insert(i * 2 + 1);
    b.sumtotal();
    return 0;
}