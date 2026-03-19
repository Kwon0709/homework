#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"My_Fraction.h"

int find_gcd(int a, int b) {
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
}
my_fraction create(int numerator, int denominator) {
	return(numerator<<16)|denominator;
}

	my_fraction add(my_fraction i, my_fraction j) {
		int a = i >> 16;
		int b = i & 0xFFFF;


		int c1 = j >> 16;
		int c2 = j & 0xFFFF;

		if (b == c2) {
			int n = a + c1;
			int d = b;
			return (n << 16) | d;
		}
		else if(b != c2) {
			int n = a * c2 + b * c1;
			int d = b * c2;
			return(n << 16) | d;
		}
	}

	my_fraction minus(my_fraction i, my_fraction j) {
		int a = i >> 16;
		int b = i & 0xFFFF;

		int c1 = j >> 16;
		int c2 = j & 0xFFFF;

		if (b == c2) {
			int n = a - c1;
			int d = b;
			return (n << 16) | d;
		}
		else if (b != c2) {
			int n = a * c2 - b * c1;
			int d = b * c2;
			return(n << 16) | d;
		}
	}
	my_fraction mult(my_fraction i, my_fraction j) {
		int a = i >> 16;
		int b = i & 0xFFFF;

		int c1 = j >> 16;
		int c2 = j & 0xFFFF;

		int n = a * c1;
		int d = b * c2;

		return (n << 16) | d;
	}
	my_fraction divid(my_fraction i, my_fraction j) {
		int a = i >> 16;
		int b = i & 0xFFFF;

		int c1 = j >> 16;
		int c2 = j & 0xFFFF;

		int n = a * c2;
		int d = b * c1;

		return (n << 16) | d;
}

	
	void print(my_fraction f) {
		int n = f >> 16;
		int d = f & 0xFFFF;

		printf("%d/%d", n, d);
	}

	my_fraction reduce(my_fraction f) {
		int n = f >> 16;
		int d = f & 0xFFFF;

		int gcd = find_gcd(n, d);
		n = n / gcd;
		d = d / gcd;

		return create(n, d);
	}
