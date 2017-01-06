/*
 * threeSumSmaller.h
 *
 *  Created on: 2017��1��6��
 *      Author: lzd
 */

#ifndef SUM_THREESUMSMALLER_H_
#define SUM_THREESUMSMALLER_H_

#include <vector>
#include <algorithm>

using namespace std;

class ThreeSumSmaller {
public:
	int f(vector<int> &nums, int target) {
		int n = nums.size();
		if (n < 3) {
			return 0;
		}
		vector<int> v(nums.begin(), nums.end());
		sort(v.begin(), v.end());
		int res = 0;
		int sum;
		for (int i = 0; i < n; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				sum = v[i] + v[j] + v[k];
				if (sum >= target) {
					k--;
				}
				else {
					//�ؼ�����Ȼv[j] + v[k]С��Ŀ�꣬��ôv[j]+v[k - 1]��v[j] + v[k - 2]��...��v[j] + v[j + 1]
					//ҲС��Ŀ�꣬����k - j��
					res += (k - j);
					j++;
				}
			}
		}
		return res;
	}
};

#endif /* SUM_THREESUMSMALLER_H_ */
