/*
 * sumOfTwoIntegers.h
 *
 *  Created on: 2017��1��7��
 *      Author: lzd
 */

#ifndef SUMOFTWOINTEGERS_H_
#define SUMOFTWOINTEGERS_H_

class SumOfTwoIntegers {
public:
	int f(int a, int b) {
		/*int sum = a;
		while (b != 0) {
			sum = a ^ b; //������������ӣ������ǽ�λ
			b = (a & b) << 1; //������������ӵĽ�λ��
			a = sum;
		}
		return sum;*/
		//����һ�д���ö�
		return b == 0 ? a : f(a ^ b, (a & b) << 1);
	}
};

#endif /* SUMOFTWOINTEGERS_H_ */
