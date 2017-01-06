/*
 * fourSum.h
 *
 *  Created on: 2017年1月6日
 *      Author: lzd
 */

#ifndef SUM_FOURSUM_H_
#define SUM_FOURSUM_H_

#include <vector>
#include <algorithm>

using namespace std;

class FourSum {
public:
	//思路和3Sum一样，可以推广到nSum
    vector<vector<int>> f(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) {
            return res;
        }
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 3; i++) {
            int target_3 = target - v[i];
            for (int j = i + 1; j < n - 2; j++) {
                int target_2 = target_3 - v[j];
                int front = j + 1;
                int rear = n - 1;
                while (front < rear) {
                    int sum = v[front] + v[rear];
                    if (sum < target_2) {
                        front++;
                    }
                    else if (sum > target_2) {
                        rear--;
                    }
                    else {
                        vector<int> subRes(4, 0);
                        subRes[0] = v[i];
                        subRes[1] = v[j];
                        subRes[2] = v[front];
                        subRes[3] = v[rear];
                        res.push_back(subRes);

                        while (front < rear && v[front] == subRes[2]) front++;
                        while (front < rear && v[rear] == subRes[3]) rear--;
                    }
                }
                while (j + 1 < n - 2 && v[j + 1] == v[j]) j++;
            }
            while (i + 1 < n - 3 && v[i + 1] == v[i]) i++;
        }
        return res;
    }
};

#endif /* SUM_FOURSUM_H_ */
