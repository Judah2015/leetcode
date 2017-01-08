/*
 * sumOfTwoIntegers.h
 *
 *  Created on: 2017年1月7日
 *      Author: lzd
 */

#ifndef SUMOFTWOINTEGERS_H_
#define SUMOFTWOINTEGERS_H_

class SumOfTwoIntegers {
public:
	int f(int a, int b) {
		/*int sum = a;
		while (b != 0) {
			sum = a ^ b; //俩二进制数相加，不考虑进位
			b = (a & b) << 1; //俩二进制数相加的进位；
			a = sum;
		}
		return sum;*/
		//反而一行代码好懂
		return b == 0 ? a : f(a ^ b, (a & b) << 1);
	}
};

#endif /* SUMOFTWOINTEGERS_H_ */
