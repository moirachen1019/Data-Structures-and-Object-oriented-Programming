#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
    // your implementation
    if(len==0){
        root=new Node;
        root->val=x;
    }
    else{
        Node *cur = root;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        Node *n=new Node;
        n->val=x;
        cur->next=n;
    }
    len++;
}

void LinkedList::insert(int pos, int x) {
    // your implementation
    if (pos > len) {
        cout << "insert fail" << endl;
    }
    else {
        Node* cur = root;
        if (pos > 0) {
            for (int i = 0; i < pos - 1; i++) {
                cur = cur->next;
            }
            Node* ans = cur->next;
            Node* n = new Node;
            n->val = x;
            cur->next = n;
            cur = cur->next;
            cur->next = ans;
        }
        else {
            Node* n = new Node;
            n->val = x;
            n->next = cur;
            root = n;
        }
    }
}

int LinkedList::find(int x){
    // your implementation
    Node *cur = root;
    int i=0;
    while(cur->next != nullptr){
        if(cur->val==x){
            return i;
        }
        cur = cur->next;
        i++;
    }
    if(cur->val==x){
        return i;
    }else{
        return -1;
    }
}

void LinkedList::remove(int pos) {
    // your implementation
    if (pos > len) {
        cout << "remove fail" << endl;
    }
    else {
        Node* cur = root;
        for (int i = 0; i < (pos - 1); i++) {
            cur = cur->next;
        }
        Node* ans = new Node;
        ans = cur;
        ans = ans->next;
        ans = ans->next;
        cur->next = ans;

    }
}

void LinkedList::print(){
    if(root == nullptr)
        return;

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    LinkedList mylist;

    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}
