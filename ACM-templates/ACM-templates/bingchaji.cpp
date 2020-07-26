#include"my_header.h"

class bingchaji {
public:
	int father[maxn] = { 0 };   //  储存i的father父节点 
	//memset(father, 0, sizeof(father))

	bingchaji() {
		for (int i = 0; i < maxn; i++)
			father[i] = i;
	}

	int findRoot(int x) {   //  迭代找根节点
		int root = x; // 根节点  
		while (root != father[root]) { // 寻找根节点  
			root = father[root];
		}
		while (x != root) {
			int tmp = father[x];
			father[x] = root; // 根节点赋值  
			x = tmp;
		}
		return root;
	}

	void Union(int x, int y) {  //  将x所在的集合和y所在的集合整合起来形成一个集合。  
		int a, b;
		a = findRoot(x);
		b = Union_findRoot(y, a);
		father[b] = a;  // y连在x的根节点上   或father[b] = a为x连在y的根节点上；  
	}

	int Union_findRoot(int x, int a) {
		int root = x; // 根节点  
		while (root != father[root]) { // 寻找根节点  
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