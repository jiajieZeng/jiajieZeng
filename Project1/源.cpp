#include<iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
	struct node* tail;
};

struct node* head, * p, * q, * t;
int n, m, k;

node* createList(int n) {
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	q = head;
	for (int i = 2; i <= n; i++) {
		p = (struct node*)malloc(sizeof(struct node));
		p->data = i;
		if (i == n) {
			p->next = head;
		}
		else {
			p->next = NULL;
		}
		q->next = p;
		q = p;
	}
	return head;
}

void travalList(node* head) {
	t = head;
	while (t->next != head) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << t->data << " ";
	return;
}

void solution(node* head, int m, int k) {
	t = q;
	while (t != t->next) {
		for (int i = k; i < m; i++) {
			t = t->next;
		}
		t->next = t->next->next;
	}
	cout << t->data << endl;
}

int main() {
	cin >> n >> m >> k;
	createList(n);
	travalList(head);
	cout << endl;
	solution(head, m, k);
	return 0;
}