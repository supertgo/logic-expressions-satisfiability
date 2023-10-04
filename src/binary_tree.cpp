#include "binary_tree.h"
#include "boolean_expressions.h"
#include <iostream>

#define LONG unsigned long long int

BinaryTree::BinaryTree(std::string &input, std::string &exp)
    : root(nullptr), expression("") {
  expression = exp;
  root = buildTree(input, 0);
}

BinaryTree::~BinaryTree() { destroyTree(root); }

Node *BinaryTree::buildTree(std::string &input, size_t index) {
  Node *node = new Node(input);

  while (index < input.length() && input[index] != 'e' && input[index] != 'a') {
    index++;
  }

  if (input[index] == 'a' || input[index] == 'e') {
    node->left = new Node(input);
    node->left->value[index] = '0';

    node->right = new Node(input);
    node->right->value[index] = '1';

    node->left = buildTree(node->left->value, index + 1);
    node->right = buildTree(node->right->value, index + 1);
  }

  return node;
}

std::string BinaryTree::evaluateTree(int start = 0) {
  evaluateTree(root, expression, start);

  if (root->result == 0) {
    return "0";
  }
  return "1 " + root->value;
}

void BinaryTree::evaluateTree(Node *root, std::string &expression, int index) {
  if (!root) {
    return;
  }

  evaluateTree(root->left, expression, index + 1);
  evaluateTree(root->right, expression, index + 1);

  if (root->left == nullptr && root->right == nullptr) {
    evaluateNode(root);
    return;
  }

  const LONG str_size = root->value.length();
  int left_result = root->left->result;
  int right_result = root->right->result;
  LONG pos_insert = find_next_quantificator_pos_after_index(root->value, index);

  const int RESULT_0 = 0;
  const int RESULT_1 = 1;

  if (left_result == RESULT_1 && right_result == left_result) {
    for (LONG i = 0; i < str_size; i++) {
      if (root->right->value[i] != root->left->value[i]) {
        root->value[i] = 'a';
      } else {
        root->value[i] = root->right->value[i];
      }
    }
    root->result = RESULT_1;
  } else if (left_result || right_result) {
    if (root->value[pos_insert] == 'a') {
      root->result = RESULT_0;
      return;
    }
    std::string value = right_result ? root->right->value : root->left->value;
    root->value = value;
    root->result = RESULT_1;
  } else {
    root->result = RESULT_0;
    root->value[index] = '0';
  }
}

void BinaryTree::evaluateNode(Node *node) {
  node->result = evaluate(expression.c_str(), node->value.c_str());
}

void BinaryTree::destroyTree(Node *node) {
  if (!node) {
    return;
  }

  destroyTree(node->left);
  destroyTree(node->right);
  delete node;
}
