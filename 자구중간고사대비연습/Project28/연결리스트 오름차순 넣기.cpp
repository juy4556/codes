void InsertItem(int item) {//single linked
    if (!first) { first = new Node(item, 0); }//�ϰ͵� ���� ��
    else {
        if (item < first.data)first=new Node(item,first);
        else {
            Node* p;
            for (p = first; p->link; p = p->link) {
                if (item >= p->data && item <= p->link->data) {
                    p->link = new Node(item, p->link);
                    return;
                }
                Node* last = p;
            }
            last->link = new Node(item, 0);
        }
    }
}