#pragma once
class box {
private:
	double x, y, z;
	double volume;
public:
	void setbox(double a, double b, double c);//x=a; y=b; z=c;
	void calcvolume();//���� ���
	double vol();//���� ��ȯ
};
