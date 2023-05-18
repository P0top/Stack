#include <iostream>
using namespace std;

struct comp {
	int Data;
	comp* next;
};

void set_comp(comp** top, int D) {
	comp* q;
	q = new comp();
	q->Data = D;
	if (top == NULL) {
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

void del_comp(comp** top, int N) {
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL) {
		if (q->Data == N) {
			if (q == *top) {
				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}
void get_last_comp(comp* top) {
	comp* q = top;
	cout << q->Data;
}

void print(comp* top) {	
	comp* q = top;
	while (q) {
		printf_s("%i", q->Data);
		q = q->next;
	}
}

int main()
{
	comp* top = NULL;
	set_comp(&top, 1);
	set_comp(&top, 2);
	set_comp(&top, 3);
	set_comp(&top, 4);
	set_comp(&top, 5);

	print(top);
	del_comp(&top, 4);
	cout << endl;
	print(top);
	cout << endl;
	get_last_comp(top);
	cout << endl;
	system("pause");
}