int bst_DeleteMax() {
	int max = 0;
	if (root == 0)return 999;
	else {
		max = root->key;
		BstNode* p =0, *q = 0;
		for (p = root; p->RightChild; p = p->RightChild) {
			q = p;
		}
		if (p == root) {//root�������ڽ� X
			root = root->RightChild;
			delete p;
			return max;
		}
		else {//root�������ڽ� O
			max = p->key;
			if (p->LeftChild)q->RightChild = p->LeftChild;
			delete p;
			return max;
		}
	}
}