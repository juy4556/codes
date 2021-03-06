#pragma once
class Polynomial {
private:
	int terms;//0�� �ƴ� ���� ��
	int capacity=4;//termArray ũ��
	Term* termArray;
public:
	Polynomial() { terms = 0; termArray = new Term[capacity]; }
	Polynomial Add(Polynomial b);
	Polynomial Multiply(Polynomial b);
	void NewTerm(const float theCoeff, const int theExp);
	void Print();
	Polynomial SingleAdd(float a, int b);
};
void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	if (terms == capacity) {
		capacity *= 2;
		Term* temp = new Term[capacity];
		for (int i = 0; i < terms; i++)
			temp[i] = termArray[i];
		delete[]termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}
Polynomial Polynomial::Add(Polynomial b) {
	Polynomial c;
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms)) {
		if (termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
}
Polynomial Polynomial::Multiply(Polynomial b) {
	Polynomial c;
	int aPos = 0, bPos = 0;
	while (aPos < terms) {
		Polynomial temp;//�Լ��� ȣ���� ��ü�� �� ���� �ٸ� ��ü(���׽�)�� ���� �� �����ϱ� ����
		while (bPos < b.terms) {
			float t = termArray[aPos].coef * b.termArray[bPos].coef;//��� ��
			temp.NewTerm(t, (termArray[aPos].exp + b.termArray[bPos].exp));//���ο� ��(����� ���� ���� ������ ���� ��) �߰�
			bPos++;
		}
		bPos = 0;//��ü b�� ù��° �׺��� �ٽ� ���ϱ� ���� 0���� �ʱ�ȭ
		aPos++;//�Լ� ȣ���� ��ü�� ���� ���� ��ü b�� ���ϱ� ����
		temp=c.Add(temp);//while���� �� �� �� ������ Addȣ��
	}
	return c;//���׽��� ���� ��ģ Polynomial��ü ��ȯ
}
void Polynomial::Print() {
	for (int i = 0; i < terms; i++) {
		printf("%lfx^%d ", termArray[i].coef, termArray[i].exp);
		if (i + 1 != terms&&termArray[i+1].coef>0)
			putchar('+');
	}
	putchar('\n');
}
Polynomial Polynomial::SingleAdd(float a, int b) {
	for (int i = 0; i <= terms; i++) {
		if (b == termArray[i].exp) {
			termArray[i].coef += a;
			return *this;
		}
	}
	NewTerm(a, b);
	return *this;
}
