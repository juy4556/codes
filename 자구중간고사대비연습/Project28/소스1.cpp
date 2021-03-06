bool List::DeleteIndexNode(int index) {
	if (!first)return false;
	ChainNode* p;
	int count = 1;
	ChainNode* before;
	for (p = first; p->link; p = p->link) {
		count++;
		if (count == index) {
			before = p;
			before->link = p->link->link;
			return true;
		}
	}
	return false;
}