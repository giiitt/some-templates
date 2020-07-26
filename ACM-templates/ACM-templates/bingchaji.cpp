#include"my_header.h"

class bingchaji {
public:
	int father[maxn] = { 0 };   //  ����i��father���ڵ� 
	//memset(father, 0, sizeof(father))

	bingchaji() {
		for (int i = 0; i < maxn; i++)
			father[i] = i;
	}

	int findRoot(int x) {   //  �����Ҹ��ڵ�
		int root = x; // ���ڵ�  
		while (root != father[root]) { // Ѱ�Ҹ��ڵ�  
			root = father[root];
		}
		while (x != root) {
			int tmp = father[x];
			father[x] = root; // ���ڵ㸳ֵ  
			x = tmp;
		}
		return root;
	}

	void Union(int x, int y) {  //  ��x���ڵļ��Ϻ�y���ڵļ������������γ�һ�����ϡ�  
		int a, b;
		a = findRoot(x);
		b = Union_findRoot(y, a);
		father[b] = a;  // y����x�ĸ��ڵ���   ��father[b] = aΪx����y�ĸ��ڵ��ϣ�  
	}

	int Union_findRoot(int x, int a) {
		int root = x; // ���ڵ�  
		while (root != father[root]) { // Ѱ�Ҹ��ڵ�  
			root = father[root];
			father[root] = a;
		}
		return root;
	}

	bool relation(int x, int y) {
		return (findRoot(x) == findRoot(y));
	}
};

//int main() {
//	bingchaji test;
//	cout << test.relation(2, 3) << endl;
//	test.Union(2, 3);
//	cout << test.relation(2, 3);
//}