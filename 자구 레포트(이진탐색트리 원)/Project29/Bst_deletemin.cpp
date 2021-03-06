int Bst::DeleteMin() {
	int min = 0;
	if (root == 0) return 999;
	else {//Ʈ�� ����
		min = root->key;
		if (root->LeftChild) {//�����ڽ� ������
			BstNode* p = * q = 0;//q�� p �θ�
			for (p = root->LeftChild; p->LeftChild; p = p->LeftChild) {
				q = p;
			}
			min = p->key;
			if (p->RightChild) { q->LeftChild = p->RightChild; delete p; }
			return min;
		}
		else {//�����ڽ� ������ root�� key�� �ּڰ�
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