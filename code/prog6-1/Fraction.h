/*
������
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction{
	int m_numerator=0;				// ����
	int m_denominator=1;				//��ĸ
	int gcd(int x, int y);  //���Լ��
public:
	Fraction(int a=0,int b=1);		//Ĭ�ϵĹ��캯��
	Fraction(const Fraction& rhs);		//�������캯��
	~Fraction() {}

	

	Fraction& operator=(const Fraction&);//����=�����
	Fraction operator*(const Fraction&rhs)const;	// ���������, ע�ⷵ��ֵ����Ϊ����	
	Fraction &operator*=(const Fraction&);	// �������
	bool operator<(const Fraction&)const;	// ������С�ڱȽ�
	bool operator<(double)const;
	Fraction reverse()const;			// ����
	void reduce();				//Լ��
	Fraction& operator++() {
		++m_numerator;
		return *this;
	}
	Fraction& operator--() {
		--m_numerator;
		return *this;
	}

	Fraction operator++(int) {
		Fraction a(*this);
		m_numerator++;
		return a;
	}

	double value() const{	return static_cast<double>(m_numerator) / m_denominator; }
	int numerator() const { 	return m_numerator;	}
	int denominator() const {	return m_denominator;}
	const Fraction& operator()(int a, int b) {
		m_numerator = a;
		m_denominator = b;
		return *this;
	}

	friend void makeCommon(Fraction &a, Fraction &b);
	friend ostream &operator<<(ostream & out, const Fraction& f);
	
	/*Fraction(Fraction&& rhs) {
		cout << "move" << endl;
	}*/

};
bool operator==(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
ostream &print(ostream & out, const Fraction& f);

#endif