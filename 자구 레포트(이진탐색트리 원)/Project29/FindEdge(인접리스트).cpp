//간선 <i,j>찾기
bool FindEdge(int i, int j) {
	ChainNode* a = HeadNode[i];
	for (a; a; a = a->link) {
		if (a->key == j)//i->j간선 있는것이여
			return true;
	}
	return false;//없으면 false를 리턴하는것이여
}