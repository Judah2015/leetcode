/*
 * addTwoNumbers.h
 *
 *  Created on: 2017��1��6��
 *      Author: lzd
 */

#ifndef ADDTWONUMBERS_H_
#define ADDTWONUMBERS_H_

#include <cstddef>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class addTwoNumbers {
public:
	//�����Լ���
	/*ListNode *f(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *res = new ListNode(0);
		ListNode *p3 = res;
		bool carry = false;
		bool isFirstLoop = true;
		while (p1 != NULL && p2 != NULL) {
			if (!isFirstLoop) {
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
			}
			else {
				isFirstLoop = false;
			}
			int sum = p1->val + p2->val;
			if (carry) sum++;
			p3->val = (sum >= 10) ? (sum - 10) : sum;
			carry = (sum >= 10) ? true : false;
			p1 = p1->next;
			p2 = p2->next;
 		}
		if (p1 == NULL && p2 == NULL) { //���Ҫ��һ���ж�
			if (carry) {
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
				p3->val = 1;
				carry = false;
			}
		}
		else if (p1 != NULL) {
			while (p1 != NULL) { //���������
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
				p3->val = p1->val;
				if (carry) {
					p3->val++;
					if (p3->val == 10) {
						p3->val = 0; //��������1 + 99�͵ó�0->10��
						carry = true;
					}
					else {
						carry = false;
					}
				}
				p1 = p1 ->next;
			}
		}
		else {
			while (p2 != NULL) {
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
				p3->val = p2->val;
				if (carry) {
					p3->val++;
					if (p3->val == 10) {
						p3->val = 0;
						carry = true;
					}
					else {
						carry = false;
					}
				}
				p2 = p2->next;
			}
		}
		if (carry) { //��������1 + 99��
			ListNode *p4 = new ListNode(0);
			p3->next = p4;
			p3 = p4;
			p3->val = 1;
		}
		return res;
	}*/

	//������볬��
	ListNode *f(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *res = new ListNode(0);
		ListNode *p3 = res;
		int sum = 0;
		while (p1 != NULL || p2 != NULL) { //�����á���
			sum /= 10; //��λ
			if (p1 != NULL) { //����һ��λ����ͬ�ľͲ��÷ֿ�������
				sum += p1->val;
				p1 = p1->next;
			}
			if (p2 != NULL) {
				sum += p2->val;
				p2 = p2->next;
			}
			p3->next = new ListNode(sum % 10); //�����½�ָ��
			p3 = p3->next;
		}
		if (sum >= 10) {
			p3->next = new ListNode(1);
		}
		return res->next; //������ʡ�˲�������
	}
};

#endif /* ADDTWONUMBERS_H_ */
