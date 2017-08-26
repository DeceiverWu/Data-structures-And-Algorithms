#ifndef _SplayTree_H
#define _SplayTree_H

typedef int ElementType;

struct SplayNode;
typedef struct SplayNode *Position;
typedef struct SplayNode *SplayTree;

SplayTree CreateSplayTree();
SplayTree MakeEmpty(SplayTree t);
Position Find(ElementType x, SplayTree t);
Position FindMin(SplayTree t);
Position FindMax(SplayTree t);
SplayTree Insert(ElementType x, SplayTree t);
SplayTree Delete(ElementType x, SplayTree t);
ElementType Retrieve(Position p);

#endif