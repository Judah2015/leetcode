/*
 * addBinary.h
 *
 *  Created on: 2017��1��7��
 *      Author: lzd
 */

#ifndef ADDBINARY_H_
#define ADDBINARY_H_

#include <algorithm>

using namespace std;

class AddBinary {
public:
	string f(string a, string b) {
		//nλ����mλ����������max(n, m) + 1λ
		string res(max(a.size(), b.size()) + 1, '0');
		int i = a.size() - 1, j = b.size() - 1;
		int sum = 0;
		int k = res.size() - 1;
		while (i >= 0 || j >= 0) {
			sum /= 2; //��λ
			if (i >= 0) {
				sum += (a[i] - '0');
				i--;
			}
			if (j >= 0) {
				sum += (b[j] - '0');
				j--;
			}
			res[k] = (sum % 2) + '0';
			k--;
		}
		if (sum >= 2) {
			res[k] = '1';
			return res;
		}
		return res.substr(1); //û�н�λ�����λΪ0��ȥ��
	}
};

#endif /* ADDBINARY_H_ */
