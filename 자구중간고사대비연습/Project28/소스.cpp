int Circqueue::delete_max() {
	if (front == rear)return -999;
	int max = q[front];
	int* temp;
	int index;
	for (int i = (front+1)%capacity; i ==rear; front++) {
		if (max < q[i]) {
			max = q[i];
			index = i;
		}
	}
	for (int i = front; i < index; i++) {
		temp[i] = q[i];
	}
	for (int j = index+1; j <= rear; j++) {
		temp[j-1] = q[j];
	}
	delete[]q;
	q = temp;
}