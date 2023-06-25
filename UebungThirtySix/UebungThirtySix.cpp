#include <iostream>
using namespace std;

class MapElement {
public:
    int key;
    string value;
    MapElement* next;
    MapElement() : key(0), next(nullptr) {}
    MapElement(int k, const string& s) : key(k), value(s), next(nullptr) {}
    // ... ggf. weitere Elemente
};

class Map {
private:
    MapElement* head;
    void free_list() {
        MapElement* temp = head;
        MapElement* temp2 = temp;
        while (temp != nullptr) {
            temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        
            delete temp;
            
    }
public:
    Map() : head(nullptr) {}
    ~Map() { free_list(); }
    int insert(int k, const string& s) {
        MapElement* temp = head;
        
        while (temp != nullptr) {
            if (temp->key == k) {
                temp->value = s;
                return 1;
            }
            temp = temp->next;
        }
        
        temp = head;
        while (temp != nullptr) {
            if (temp->key > k) {
                MapElement* oldHeadNode = new MapElement(temp->key, temp->value);
                oldHeadNode->next = temp->next;
                head = new MapElement(k, s);
                head->next = oldHeadNode;
                return 1;
            }
        temp = temp->next;
        }

        if (temp == nullptr) {
            head = new MapElement(k, s);
            return 1;
        }

        return 0;
    }

};

int main() {
    Map* one = new Map();
    one->insert(1, "Hallo1");
    one->insert(2, "Hallo2");
    one->insert(3, "Hallo3");
    one->insert(4, "Hallo4");
    one->insert(5, "Hallo5");
    one->insert(0, "Hallo0");
    cout << (one->insert(0, "Hallo0") == 1) << "\n";
    cout << (one->insert(1, "Hallo0") == 1);
    cout << sizeof(one);
    delete one;
    cout << sizeof(one);
    return 1;
}