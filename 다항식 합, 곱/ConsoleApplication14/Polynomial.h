#pragma once
class Polynomial {
private:
	int terms;//0이 아닌 항의 수
	int capacity=4;//termArray 크기
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
		Polynomial temp;//함수를 호출한 객체의 한 항을 다른 객체(다항식)에 곱한 후 저장하기 위해
		while (bPos < b.terms) {
			float t = termArray[aPos].coef * b.termArray[bPos].coef;//계수 곱
			temp.NewTerm(t, (termArray[aPos].exp + b.termArray[bPos].exp));//새로운 항(계수를 곱한 값과 지수를 더한 값) 추가
			bPos++;
		}
		bPos = 0;//객체 b의 첫번째 항부터 다시 곱하기 위해 0으로 초기화
		aPos++;//함수 호출한 객체의 다음 항을 객체 b에 곱하기 위해
		temp=c.Add(temp);//while문을 한 번 돌 때마다 Add호출
	}
	return c;//다항식의 곱을 마친 Polynomial객체 반환
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
