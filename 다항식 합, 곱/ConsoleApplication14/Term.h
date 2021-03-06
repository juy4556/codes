#pragma once
class Polynomial;
class Term {
	friend Polynomial;
private:
	float coef;//계수
	int exp;//지수
};