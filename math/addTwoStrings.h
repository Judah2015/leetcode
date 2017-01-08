/*
 * addTwoStrings.h
 *
 *  Created on: 2017Äê1ÔÂ8ÈÕ
 *      Author: lzd
 */

#ifndef ADDTWOSTRINGS_H_
#define ADDTWOSTRINGS_H_

#include <algorithm>

using namespace std;

class AddTwoStrings {
public:
	string f(string num1, string num2) {
		int size1 = num1.size();
		int size2 = num2.size();
		string res(max(size1, size2) + 1, '0');
		int i = size1 - 1;
		int j = size2 - 1;
		int sum = 0;
		int k = res.size() - 1;
		while (i >= 0 || j >= 0) {
			sum /= 10;
			if (i >= 0) {
				sum += (num1[i] - '0');
				i--;
			}
			if (j >= 0) {
				sum += (num2[j] - '0');
				j--;
			}
			res[k] = ((sum % 10) + '0');
			k--;
		}
		if (sum >= 10) {
			res[k] = '1';
			return res;
		}
		return res.substr(1);
	}
};

#endif /* ADDTWOSTRINGS_H_ */
