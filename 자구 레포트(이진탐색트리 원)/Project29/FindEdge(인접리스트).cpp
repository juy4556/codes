//���� <i,j>ã��
bool FindEdge(int i, int j) {
	ChainNode* a = HeadNode[i];
	for (a; a; a = a->link) {
		if (a->key == j)//i->j���� �ִ°��̿�
			return true;
	}
	return false;//������ false�� �����ϴ°��̿�
}