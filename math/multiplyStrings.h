/*
 * multiplyStrings.h
 *
 *  Created on: 2017��1��7��
 *      Author: lzd
 */

#ifndef MULTIPLYSTRINGS_H_
#define MULTIPLYSTRINGS_H_

#include <string>

using namespace std;

class MultiplyStrings {
public:
	string f(string num1, string num2){
		string res(num1.size() + num2.size(), '0'); //num1.size() + num2.size()��'0'
		//nλ��������mλ����λ��������n+m
		for (int i = num1.size() - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; j--) {
				int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry; //��iλ���Ե�jλ�����ڽ���ĵ�i+j+1λ
				res[i + j + 1] = tmp % 10 + '0'; //��λ��ת�ַ�
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
