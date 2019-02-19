#include<iostream>
using namespace std;

template<int ObjectSize,int NumObjects = 20>
class MemPool
{
public:
	MemPool()
	{
		freeNodeHeader = NULL;
		memBlockHeader = NULL;
	}
	~MemPool()
	{
		MemBlock* ptr;
		while(memBlockHeader)
		{
			ptr = memBlockHeader->pNext;
			delete memBlockHeader;
			memBlockHeader = ptr;
		}
	}
	
	void* malloc();
	void free(void*);
private:
	//空闲链表
	struct FreeNode
	{
		FreeNode* pNext;
		char data[ObjectSize];
	};
	//内存结构体
	struct MemBlock
	{
		MemBlock* pNext;
		FreeNode data[NumObjects];
	};
	FreeNode* freeNodeHeader;
	MemBlock* memBlockHeader;
};

template<int ObjectSize,int NumObjects>
void* MemPool<ObjectSize,NumObjects>::malloc()
{	
	//无空闲链表
	if(freeNodeHeader == NULL)
	{
		MemBlock* newBlock = new MemBlock;
		newBlock->pNext = NULL;
		
		freeNodeHeader = &newBlock->data[0];
		for(int i=1;i<NumObjects;i++)
		{
			newBlock->data[i-1].pNext = &newBlock->data[i];
		}
		newBlock->data[NumObjects-1].pNext = NULL;
		
		//首次申请内存块
		if(memBlockHeader == NULL)
		{
			memBlockHeader = newBlock;
		}
		else
		{
			//将新内存加入到链表中
			newBlock->pNext = memBlockHeader;
			memBlockHeader = newBlock;
		}
	}
	//返回空闲链表的第一个节点
	void* freeNode = freeNodeHeader;
	freeNodeHeader = freeNodeHeader->pNext;
	return freeNode;
}

//释放已经分配的节点
template<int ObjectSize,int NumObjects >
void MemPool<ObjectSize,NumObjects>::free(void* p)
{
	FreeNode* pNode = (FreeNode*)p;
	pNode->pNext = freeNodeHeader;
	freeNodeHeader = pNode;
}

class ActualClass
{
private:
	static int count;
	int NO;
public:
	ActualClass()
	{
		NO = count;
		count++;
	}
	void Print()
	{
		cout<<this<<":";
		cout<<"the"<<NO<<"the object"<<endl;
	}
	
	void* operator new(size_t size);
	void operator delete(void* p);
};

//定义内存池对象
MemPool<sizeof(ActualClass),2>mp;

void* ActualClass::operator new(size_t size)
{
	return mp.malloc();
}

void ActualClass::operator delete(void *p)
{
	mp.free(p);
}

int ActualClass::count = 0;

int main()
{
	ActualClass* p1 = new ActualClass;
	p1->Print();
	
	ActualClass* p2 = new ActualClass;
	p2->Print();
	
	delete p1;
	delete p2;
}
