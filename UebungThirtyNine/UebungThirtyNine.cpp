#include <iostream>
using namespace std;
class Knoten {
public:
    int value;
    Knoten* left;
    Knoten* right;
    Knoten(int v = 0) : value(v), left(nullptr), right(nullptr) {}
};
class Baum {
private:
    Knoten* root;
    int n;
    using NodeFunction = int (Baum::*)(typename Knoten*);
    void iterate(Knoten* node, NodeFunction visit) {    
        if (!node)
            return;

        iterate(node->left, visit);
        (this->*visit)(node);
        iterate(node->right, visit);
    }



    int insert(Knoten** parent, int value) {
        if (!*parent)
        {
            *parent = new Knoten(value);
            return 1;
        }

        if (value > (*parent)->value)
            return (insert(&(*parent)->right, value));

        if (value < (*parent)->value)
            return (insert(&(*parent)->left, value));

        return 0;
    }
public:
    Baum() : root(new Knoten(0)), n(0) {}
        int insert(int value) { return insert(&root, value); }
    
    
    int sum(Knoten* node) {
        
        n += node->value;
        cout << node->value << endl;
        return n;
    }


    void sumtotal() {
        
        n = 0;
        iterate(root, &Baum::sum);

        cout << "Summe: " << n << endl;
    
    }
};

int main()
{
    Baum b;
    for (int i = 0; i < 10; i++)
        b.insert(i * 2 + 1);
    b.sumtotal();
    return 0;
}