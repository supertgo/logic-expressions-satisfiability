#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

struct Node {
  std::string value;
  Node *left;
  Node *right;
  int result;

  Node(std::string &val) : value(val), left(nullptr), right(nullptr), result(-1) {}
};


class BinaryTree {
public:
  BinaryTree(std::string &input, std::string &exp);
  ~BinaryTree();
  void printTree();
  std::string evaluateTree(int start);
  std::string getExpression() const;

private:
  Node *root;
  std::string expression;
  Node *buildTree(std::string &input, size_t index);
  void destroyTree(Node *node);
  void printTree(Node* node, int depth);
  void evaluateTree(Node* node, std::string &genericStr, int index);
  void evaluateNode(Node *node);
};

#endif // BINARYTREE_H
