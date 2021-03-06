int List::DeleteMax() {
	if (!first) { return -999; }
	int max = first.data;
	else {//공백리스트 X
		ListNode* p;
		ListNode* BeforeMaxNode;
		ListNode* MaxNode;
		for (p = first; p->link == ; p = p->link) {
			if (max < p->link->data) {
				max = p->->link->data;//max값 먼저 찾고
				BeforeMaxNode = p;
				MaxNode = p->link;
			}
		}
		BeforeMaxNode->link=MaxNode->link;
		for (p = first; p->link==0; p = p->link) {
			if (max == p->link->data) {
				p->link = MaxNode->link; max값 갖고 있는 node의 전꺼가 maxnode가 가리키는 node가리키게.
				delete MaxNode;
			}
		}

	}
	return max;
}