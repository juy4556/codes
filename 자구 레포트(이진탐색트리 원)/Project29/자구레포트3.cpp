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
// 이진 탐색 트리에서 키 x의 원소를 탐색 
{
	for (BstNode* t = root; t; )
	{
		if (x == t->key) return t;
		if (x < t->key) t = t->LeftChild;
		else t = t->RightChild;
	}
	return 0;     // 없을 경우 null을 반환
}
bool BST::Insert(const int x) {
	BstNode* p = root;	BstNode* q = 0;//q는 p의 부모
	while (p) {
		q = p;
		if (x == p->key)return false;//x값 존재
		else if (x < p->key)p = p->LeftChild;//작으면 왼쪽
		else p = p->RightChild;//크면 오른쪽
	}
	p = new BstNode;
	p->LeftChild = p->RightChild = 0; p->key = x;
	if (!root)root = p;//트리에 아무 노드도 없었을 때
	else if (x < q->key)q->LeftChild = p;//기존 트리에 새 노드를 연결
	else q->RightChild = p;
	return true;
}
void BST::Delete(const int x) {
	BstNode* a=IterSearch(x);
	if (!a)printf("트리에 %d해당하는 값 없음\n", x);
	else {//트리에 인수에 해당하는 값 없을 때(중복값 없을 때)
		BstNode* p = root; BstNode* q = root;//q는 p의 부모
		while (x != p->key) {//x값이 p의 key값과 같아질 때 break
			q = p;
			if (x < p->key) p = p->LeftChild;
			else if (x > p->key) p = p->RightChild;
		}
		if (p->LeftChild == 0 && p->RightChild == 0) {//리프노드일 때
			if (q->key < p->key)q->RightChild = 0;
			else if (q->key > p->key)q->LeftChild = 0;
		}
		else if (p->LeftChild != 0 && p->RightChild != 0) {//두 개의 자식을 갖는 노드일 때
			//왼쪽서브트리에서 가장 큰 노드로 대체
			BstNode* i; BstNode* j=0;//j는 i의 부모
			if (p->LeftChild->RightChild) {
				for (i = p->LeftChild; i; i = i->RightChild) {//i가 null일 때 break, j는 i 부모
					j = i;
				}
				p->key = j->key;//삭제하려는 p노드의 값을 j->key해당하는 값으로 대체
			}
			else {//왼쪽서브트리에서 오른쪽으로 뻗는 노드가 없으면 바로 왼쪽자식을 올림
				p->key = p->LeftChild->key;
				p->LeftChild = p->LeftChild->LeftChild;
			}
		}
		else {//하나의 자식을 갖는 노드일 때
			if (p->key == q->key)root=p->RightChild;//p의 왼쪽서브트리가 없을 때
			else if (p->key < q->key) {//p가 q의 왼쪽서브트리인 경우
				if (p->LeftChild)	q->LeftChild = p->LeftChild;
				else if (p->RightChild) q->LeftChild = p->RightChild;
			}
			else {//p가 q의 오른쪽서브트리인 경우
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
	if (bst.IterSearch(a))printf("성공\n");
	else printf("실패\n");
	scanf_s("%d", &b);
	if (bst.IterSearch(b))printf("성공\n");
	else printf("실패\n");
	scanf_s("%d", &n); bst.Delete(n);
	scanf_s("%d", &n); bst.Delete(n);
	bst.inorder();
	putchar('\n');
	for (int j = 0; j < 5; j++) {
		scanf_s("%d", &n);
		bst.Insert(n);
	}
	scanf_s("%d", &a);
	if (bst.IterSearch(a))printf("성공\n");
	else printf("실패\n");
	scanf_s("%d", &b);
	if (bst.IterSearch(b))printf("성공\n");
	else printf("실패\n");
	scanf_s("%d", &n); bst.Delete(n);
	scanf_s("%d", &n); bst.Delete(n);
	bst.inorder();
	putchar('\n');
	return 0;
}


