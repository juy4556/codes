template <class T>
class Chain;
template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T>* link;
};
template <class T>
class Chain {
private:
	ChainNode <T>* first;
	ChainNode <T>* last;
public:
	Chain() { first = 0; last = 0; }
	void Insert(ChainNode* x, int a);
	void Delete(ChainNode* x, ChainNode* y);//y�� x�� ���
	void InsertBack(const T& e);
	void Concatenate(Chain& b);
	void InsertFront(const T& e);
};
void Chain<T>::Insert(ChainNode* x,int a) {
	if (!first) { first = new ChainNode(a, 0); last = new ChainNode(a, 0); }
	else x->link = new ChainNode(a, x->link);//x�� ����Ű�� ���� �� ����, �� ���� x�� ����Ű�� ��� ����Ŵ

}
void Chain<T>::Delete(ChainNode* x,ChainNode *y) {//x ����(y�� x����Ű�� ���)
	if (x == first)first = first->link;
	else y->link = x->link;
	delete x;
}
void Chain<T>::InsertBack(const T& e) {
	if (first) {
		last->link = new ChainNode(e);
		last = last->link;
	}
	else first = last = new ChainNode(e);
}
void Chain<T>::Concatenate(Chain& b) {//last�������
	if (!first) { first = b.first; return; }
	if (b.first) {
		ChainNode* p;
		for (p = first; p->link; p = p->link);
		p->link = b.first;
	}
}
void Chain<T>::InsertFront(const T& e) {

}