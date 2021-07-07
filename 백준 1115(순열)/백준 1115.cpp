#include <iostream>
#include <vector>
using namespace std;

class Node{
    private:
    int key;
    Node* link;
    public:
    Node(int n, Node* next){
        key=n; link=next;
    }
};
class LinkedList{
    friend class Node;
    private:
    Node *first;
    public:
    LinkedList(){first=0;}

};

int main(){
    int n;
    vector<int> v(1,0);
    scanf_s("%d",&n);
    int buf;
    for(int i=0;i<n;i++){
        scanf_s("%d",&buf);
        v.push_back(buf);
    }
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    return 0;
}