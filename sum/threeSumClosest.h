/*
 * threeSumClosest.h
 *
 *  Created on: 2017��1��6��
 *      Author: lzd
 */

#ifndef SUM_THREESUMCLOSEST_H_
#define SUM_THREESUMCLOSEST_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class ThreeSumClosest {
public:
	int threeSumClosest(vector<int> &nums, int target) {
	        vector<int> v(nums.begin(), nums.end());
	        int n = v.size();
	        //ע���������
	        if (n <= 3) {
	        	return accumulate(v.begin(), v.end(), 0); //��0����ʾ��0����
	        }
	        sort(v.begin(), v.end());
	        int ans = v[0] + v[1] + v[2];
	        int sum;
	        for (int i = 0; i < n - 2; i++) { //ע��i < n - 2
	            int j = i + 1;
	            int k = n - 1;
	            while (j < k) {
	                sum = v[i] + v[j] + v[k];
	                //�ؼ���ȡ����ֵС��
	                if (abs(target - ans) > abs(target - sum)) {
	                    ans = sum;
	                    if (ans == target) {
	                        return ans;
	                    }
	                }
	                (sum < target) ? j++ : k--;
	            }
	        }
	        return ans;
	    }
};

#endif /* SUM_THREESUMCLOSEST_H_ */
