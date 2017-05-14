#ifndef _Cursor_H
#define _Cursor_H

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace();//CursorSpace结构体数组初始化  
static Position CursorAlloc();//作用类似于malloc函数  
static void CursorFree(Position);//作用类似于free函数  
int IsEmpty(const List);//测试一个链表是否为空  
int IsLast(const Position);//测试是否是链表的末尾  
Position Find(ElementType, const List);//寻找给定元素的位置  
void Delete(ElementType, List);//删除给定元素  
Position FindPrevious(ElementType, const List);//寻找给定元素的前一个元素的位置  
void Insert(ElementType, List, Position);//插入给定元素  
void DeleteList(List);//删除线性表内所有数据  
void TraverseList(List);  //遍历单链表并输出

#endif