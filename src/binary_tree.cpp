#include "binary_tree.h"
#include "boolean_expressions.h"
#include <iostream>

#define LONG unsigned int

BinaryTree::BinaryTree(std::string &input, std::string &exp)
    : root(nullptr), expression(exp) {
  root = buildTree(input, 0);
}

BinaryTree::~BinaryTree() { destroyTree(root); }

Node *BinaryTree::buildTree(std::string &input, size_t index) {
  Node *node = new Node(input);

  for (LONG i = index; i < input.length(); i++) {
    if (input[i] == 'e' || input[i] == 'a') {
      std::string left_values = input;
      left_values[i] = '0';
      node->left = buildTree(left_values, i + 1);

      std::string right_values = input;
      right_values[i] = '1';
      node->right = buildTree(right_values, i + 1);

      break;
    }
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
