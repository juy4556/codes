//Binary Search Tree
#include <iostream>
using namespace std;
class BST;
class BstNode {
	friend class BST;
private:
	BstNode* LeftChild;
	BstNode* RightChild;
	int key;
};
class BST {
private:
	BstNode* root;
public:
	BST(){ root = 0; }
	void inorder() { inorder(root); }//Driver
	void inorder(BstNode* CurrentNode);//Workhorse
	BstNode* IterSearch(const int x);
	bool Insert(const int x);
	void Delete(const int x);
};
void BST::inorder(BstNode* CurrentNode) {
	if (CurrentNode) {
		inorder(CurrentNode->LeftChild);
		cout << CurrentNode->key<<' ';
		inorder(CurrentNode->RightChild);
	}
}

BstNode* BST::IterSearch(const int x)
// ���� Ž�� Ʈ������ Ű x�� ���Ҹ� Ž�� 
{
	for (BstNode* t = root; t; )
	{
		if (x == t->key) return t;
		if (x < t->key) t = t->LeftChild;
		else t = t->RightChild;
	}
	return 0;     // ���� ��� null�� ��ȯ
}
bool BST::Insert(const int x) {
	BstNode* p = root;	BstNode* q = 0;//q�� p�� �θ�
	while (p) {
		q = p;
		if (x == p->key)return false;//x�� ����
		else if (x < p->key)p = p->LeftChild;//������ ����
		else p = p->RightChild;//ũ�� ������
	}
	p = new BstNode;
	p->LeftChild = p->RightChild = 0; p->key = x;
	if (!root)root = p;//Ʈ���� �ƹ� ��嵵 ������ ��
	else if (x < q->key)q->LeftChild = p;//���� Ʈ���� �� ��带 ����
	else q->RightChild = p;
	return true;
}
void BST::Delete(const int x) {
	BstNode* a=IterSearch(x);
	if (!a)printf("Ʈ���� %d�ش��ϴ� �� ����\n", x);
	else {//Ʈ���� �μ��� �ش��ϴ� �� ���� ��(�ߺ��� ���� ��)
		BstNode* p = root; BstNode* q = root;//q�� p�� �θ�
		while (x != p->key) {//x���� p�� key���� ������ �� break
			q = p;
			if (x < p->key) p = p->LeftChild;
			else if (x > p->key) p = p->RightChild;
		}
		if (p->LeftChild == 0 && p->RightChild == 0) {//��������� ��
			if (q->key < p->key)q->RightChild = 0;
			else if (q->key > p->key)q->LeftChild = 0;
		}
		else if (p->LeftChild != 0 && p->RightChild != 0) {//�� ���� �ڽ��� ���� ����� ��
			//���ʼ���Ʈ������ ���� ū ���� ��ü
			BstNode* i; BstNode* j=0;//j�� i�� �θ�
			if (p->LeftChild->RightChild) {
				for (i = p->LeftChild; i; i = i->RightChild) {//i�� null�� �� break, j�� i �θ�
					j = i;
				}
				p->key = j->key;//�����Ϸ��� p����� ���� j->key�ش��ϴ� ������ ��ü
			}
			else {//���ʼ���Ʈ������ ���������� ���� ��尡 ������ �ٷ� �����ڽ��� �ø�
				p->key = p->LeftChild->key;
				p->LeftChild = p->LeftChild->LeftChild;
			}
		}
		else {//�ϳ��� �ڽ��� ���� ����� ��
			if (p->key == q->key)root=p->RightChild;//p�� ���ʼ���Ʈ���� ���� ��
			else if (p->key < q->key) {//p�� q�� ���ʼ���Ʈ���� ���
				if (p->LeftChild)	q->LeftChild = p->LeftChild;
				else if (p->RightChild) q->LeftChild = p->RightChild;
			}
			else {//p�� q�� �����ʼ���Ʈ���� ���
				if (p->LeftChild)	q->RightChild = p->LeftChild;
				else if (p->RightChild) q->RightChild = p->RightChild;
			}
		}
	}
}
int main() {
	BST bst;
	int n;
	int a, b;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &n);
		bst.Insert(n);
	}
	bst.inorder();
	putchar('\n');
	scanf_s("%d", &a);
	if (bst.IterSearch(a))printf("����\n");
	else printf("����\n");
	scanf_s("%d", &b);
	if (bst.IterSearch(b))printf("����\n");
	else printf("����\n");
	scanf_s("%d", &n); bst.Delete(n);
	scanf_s("%d", &n); bst.Delete(n);
	bst.inorder();
	putchar('\n');
	for (int j = 0; j < 5; j++) {
		scanf_s("%d", &n);
		bst.Insert(n);
	}
	scanf_s("%d", &a);
	if (bst.IterSearch(a))printf("����\n");
	else printf("����\n");
	scanf_s("%d", &b);
	if (bst.IterSearch(b))printf("����\n");
	else printf("����\n");
	scanf_s("%d", &n); bst.Delete(n);
	scanf_s("%d", &n); bst.Delete(n);
	bst.inorder();
	putchar('\n');
	return 0;
}


