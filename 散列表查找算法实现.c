//HsahTable是散列表结构，结构中elem为一个动态数组
#define SUCCESS 1
#define fault 0
#define HashSize 12
#define NULIIKEY -32768
typedef struct {
	int* elem;//数据元素存储基址，动态分配数组
	int count;//数据元素个数
}HashTable;
int m = 0;//散列表表长，全局变量

//初始化散列表
int InitHashTable(HashTable* h) {
	int i;
	m = HashSize;
	h->count = m;
	h->elem = (int*)malloc(m * sizeof(int));
	for ( i = 0; i < m; i++)
		h->elem[i] = NULIIKEY;
	return SUCCESS;
}

//散列函数
int Hash(int key) {
	return key % m;//除留余数法
}

//插入关键字
void InsertHash(HashTable* h, int key) {
	int addr = Hash(key);//散列地址
	while (h->elem[addr]!= NULIIKEY)//如果不是空，则冲突
		addr = (addr + 1) % m;//开放地址法的线性探测
	h->elem[addr] = key;//有空位插入关键字
}

//查找
int SearchHash(HashTable* h,int key, int* addr) {
	*addr = Hash(key);
	while (h->elem[*addr]!=key)
	{
		*addr = (*addr + 1) % m;
		if (h->elem[*addr] ==NULIIKEY || *addr == Hash(key))
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}