/*
 * addBinary.h
 *
 *  Created on: 2017年1月7日
 *      Author: lzd
 */

#ifndef ADDBINARY_H_
#define ADDBINARY_H_

#include <algorithm>

using namespace std;

class AddBinary {
public:
	string f(string a, string b) {
		//n位数加m位数，结果最高max(n, m) + 1位
		string res(max(a.size(), b.size()) + 1, '0');
		int i = a.size() - 1, j = b.size() - 1;
		int sum = 0;
		int k = res.size() - 1;
		while (i >= 0 || j >= 0) {
			sum /= 2; //进位
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
		return res.substr(1); //没有进位，最高位为0，去掉
	}
};

#endif /* ADDBINARY_H_ */
