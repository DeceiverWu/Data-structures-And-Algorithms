#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "Cursor_H.h"

const size_t SpaceSize = 20;

struct Node  
{  
    ElementType Element;  
    Position Next;  
};  
  
struct Node CursorSpace[SpaceSize]; 

//CursorSpace结构体数组初始化 
void InitializeCursorSpace()  
{  
    int i;  
    for (i = 0; i < SpaceSize - 1; i++){  
                CursorSpace[i].Next = i + 1;  
    }  
    CursorSpace[0].Element=0;  
    CursorSpace[SpaceSize - 1].Next = 0;  
}

//作用类似于malloc函数
static Position CursorAlloc(void){
	Position P;

	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}

//作用类似于free函数 
static void CursorFree(Position P){
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

//测试一个链表是否为空 , 0 == NULL ,模拟使用指针的链表
int IsEmpty(const List L){
	return CursorSpace[L].Next == 0;
}

//测试是否是链表的末尾
int IsLast(const Position P){
	return CursorSpace[P].Next == 0;
}

//寻找给定元素的位置
Position Find(ElementType X, const List L){
	Position P;

	P = CursorSpace[L].Next;
	while(P && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

//寻找给定元素的前一个元素的位置 
Position FindPrevious(ElementType X, const List L){
	Position P;

	P = L;
	while(CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

//删除给定元素
void Delete(ElementType X, List L){
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if(!IsLast(P, L)){
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}

//插入给定元素 
void Insert(ElementType X, List L, Position P){
	Position TmpCell;

	TmpCell = CursorAlloc();

	if(TmpCell == 0)
		cout << "Out of space !!!" << endl;

	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;

}

//删除线性表内所有数据
void DeleteList(List L){
	Position P, TmpCell;

	P = CursorSpace[L].Next;
	CursorSpace[L].Next = 0;

	while(P){
		TmpCell = CursorSpace[P].Next;
		CursorFree(TmpCell);
		P = TmpCell;
	}

} 

//遍历单链表并输出
void TraverseList(List L){
	Position P;
	P = CursorSpace[L].Next;

	if(IsEmpty(L))
		cout << "List is Empty!!!" << end;
	else{
		while(P){
			cout << CursorSpace[P].Element << endl;
			P = CursorSpace[P].Next;
		}
	}
}

int main(void){
	int i, m;
	int data,data_find,data_delete;   
    Position P,LHead;  
    InitializeCursorSpace();  //初始化结构体数组的Next域  
      
    LHead = CursorAlloc();  //作用类似于用malloc申请一个内存空间，然后把申请到的内存空间的“首地址”赋给一个变量  
    cout << "The piosition of LHead is" << LHead << endl;

    CursorSpace[LHead].Next = 0;
    CursorSpace[LHead].Element = 0;
    P = LHead;  //LHead相当于链表中的头结点  
  
    //初始化链表  
    cout << "Please input the number of data:" << endl; 
    cin >> m;
    cout << "The original input is as follows:" << endl;

    for(i = 0 ; i < m ; i++)    
    {
    	cin >> data;  
        Insert(data, LHead, P);    
        P = CursorSpace[P].Next;    //插入数据的过程中，游标相应的也必须同步往后移动  
    }

   TraverseList(LHead);    
  
   //寻找链表中某个数据的位置  
   cout << "Please input the data you wanna find:" << endl;
   cin >> data_find;
   P = Find(data_find, LHead);    
   cout << "The position of data is:" << P << endl;  
  
   //删除链表中某个数据，然后遍历输出  
   cout << "Please input the data you wanna delete:" << endl;  
   cin >> data_delete;
   Delete(data_delete, LHead);    
   TraverseList(LHead);    
      
   //清空链表，遍历后输出（实际上此时链表已空，并无数据输出）   
   DeleteList(LHead);
   cout << "After clearing,now the list is:" << endl;  
   TraverseList(LHead);  

   return 0;
}


