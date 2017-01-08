/*
 * multiplyStrings.h
 *
 *  Created on: 2017年1月7日
 *      Author: lzd
 */

#ifndef MULTIPLYSTRINGS_H_
#define MULTIPLYSTRINGS_H_

#include <string>

using namespace std;

class MultiplyStrings {
public:
	string f(string num1, string num2){
		string res(num1.size() + num2.size(), '0'); //num1.size() + num2.size()个'0'
		//n位整数乘以m位整数位数不超过n+m
		for (int i = num1.size() - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; j--) {
				int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry; //第i位乘以第j位作用于结果的第i+j+1位
				res[i + j + 1] = tmp % 10 + '0'; //个位数转字符
				carry = tmp / 10;
			}
			res[i] = carry + '0';
		}
		size_t pos = res.find_first_not_of("0");
		if (pos != string::npos) {
			return res.substr(pos);
		}
		return "0";
	}
};

#endif /* MULTIPLYSTRINGS_H_ */
