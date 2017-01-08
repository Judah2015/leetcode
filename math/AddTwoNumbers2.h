/*
 * AddTwoNumbers2.h
 *
 *  Created on: 2017Äê1ÔÂ8ÈÕ
 *      Author: lzd
 */

#ifndef ADDTWONUMBERS2_H_
#define ADDTWONUMBERS2_H_

#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class AddTwoNumbers2 {
public:
	ListNode *f(ListNode *l1, ListNode *l2) {
		/*ListNode *p1 = l1;
		int size1;
		while (p1 != NULL) {
			size1++;
			p1 = p1->next;
		}
		p1 = l1;
		ListNode *p2 = l2;
		int size2;
		while (p2 != NULL) {
			size2++;
			p2 = p2->next;
		}
		p2 = l2;
		int bigger = (size1 > size2) ? size1 : size2 ;
		int smaller = (size1 > size2) ? size2 : size1 ;
		ListNode *sum = new ListNode(0);
		ListNode *ps = sum;
		ListNode *carry = new ListNode(0);
		ListNode *pc = carry;
		while (bigger != smaller) {

		}
		while (p1 != NULL || p2 != NULL) {
			int sum = 0;
			if (p1 != NULL) {
				sum += p1->val;
				p1 = p1->next;
			}
			if (p2 != NULL) {
				sum += p2->val;
				p2 = p2->next;
			}
			ps->next = new ListNode(sum / 10);

		}*/
		ListNode *p1 = l1, *p2 = l2;
		vector<int> v1, v2;
		while (p1 != NULL) {
			v1.push_back(p1->val);
			p1 = p1->next;
		}
		while (p2 != NULL) {
			v2.push_back(p2->val);
			p2 = p2->next;
		}
		int i = v1.size() - 1;
		int j = v2.size() - 1;
		vector<int> res;
		int sum = 0;
		while (i >= 0 || j >= 0) {
			sum /= 10;
			if (i >= 0) {
				sum += v1[i];
				i--;
			}
			if (j >= 0) {
				sum += v2[j];
				j--;
			}
			res.push_back(sum % 10);
		}
		if (sum >= 10) {
			res.push_back(1);
		}
		ListNode *result = new ListNode(0);
		ListNode *pr = result;
		int k = res.size() - 1;
		while (k >= 0) {
			pr->next = new ListNode(res[k]);
			pr = pr->next;
			k--;
		}
		return result->next;
 	}
};

#endif /* ADDTWONUMBERS2_H_ */
