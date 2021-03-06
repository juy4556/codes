int Bst::DeleteMin() {
	int min = 0;
	if (root == 0) return 999;
	else {//트리 존재
		min = root->key;
		if (root->LeftChild) {//왼쪽자식 있으면
			BstNode* p = * q = 0;//q는 p 부모
			for (p = root->LeftChild; p->LeftChild; p = p->LeftChild) {
				q = p;
			}
			min = p->key;
			if (p->RightChild) { q->LeftChild = p->RightChild; delete p; }
			return min;
		}
		else {//왼쪽자식 없으면 root의 key가 최솟값
			BstNode* temp = root;
			root = root->RightChild;
			delete temp;
			return min;
		}
	}
}

int Bst::DeleteMin() {
	if (root == 0) return 999;
	else {
		BstNode* p = 0, * q = 0;
		for (p = root; p->LeftChild; p = p->LeftChild)q = p;
		if (p == root) {//LeftChild X
			int min = root->key;
			root = root->RightChild;
			delete p;
			return min;
		}
		else {
			q->LeftChild = p->RightChild;
			delete p;
		}
	}
}