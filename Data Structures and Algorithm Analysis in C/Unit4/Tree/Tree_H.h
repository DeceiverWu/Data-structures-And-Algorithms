#ifndef _Tree_H
#define _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *Tree;
typedef int ElementType;

Tree MakeEmpty(Tree tree);
Position Find(ElementType x, Tree tree);
Position FindMin(Tree tree);
Position FindMinNotRec(Tree tree);
Position FindMax(Tree tree);
Position FindMaxNotRec(Tree tree);
Tree Insert(ElementType x, Tree tree);
Tree Delete(ElementType x, Tree tree);
ElementType Retrieve(Position p);

#endif