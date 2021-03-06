int BST::Delete_Right() {
	BstNode* p = root->RightChild;
	if (root == 0 || p == 0)return -999;
	int ret = p->key;
	if (p->LeftChild == 0 && p->RightChild == 0) {//�ڽ� ���� ��
		root->RightChild = 0;
	}
	else if (p->LeftChild != 0 && p->RightChild != 0) {
		BstNode* i = *j = p->LeftChild;
		if (i->RightChild) {//�����ڽĿ� �������ڽ��� ���� ��
			for (i = p->LeftChild; i->RightChild; i = i->RightChild) { j = i; }
			p->key = i->key;
			if (i->LeftChild) { j->RightChild = i->LeftChild; delete i; }
		}
		else {//�����ڽĿ� �������ڽ� ���� ��
			root->RightChild = p->LeftChild;
			p->LeftChild->RightChild = p->RightChild;
		}
	}
	else {//�ڽ� �ϳ��� ���� ��
		if (p->LeftChild)root->RightChild = p->LeftChild;
		else root->RightChild = p->RightChild;
	}
	delete p, q;
	return ret;
}