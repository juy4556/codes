int List::DeleteMax() {
	if (!first) { return -999; }
	int max = first.data;
	else {//���鸮��Ʈ X
		ListNode* p;
		ListNode* BeforeMaxNode;
		ListNode* MaxNode;
		for (p = first; p->link == ; p = p->link) {
			if (max < p->link->data) {
				max = p->->link->data;//max�� ���� ã��
				BeforeMaxNode = p;
				MaxNode = p->link;
			}
		}
		BeforeMaxNode->link=MaxNode->link;
		for (p = first; p->link==0; p = p->link) {
			if (max == p->link->data) {
				p->link = MaxNode->link; max�� ���� �ִ� node�� ������ maxnode�� ����Ű�� node����Ű��.
				delete MaxNode;
			}
		}

	}
	return max;
}