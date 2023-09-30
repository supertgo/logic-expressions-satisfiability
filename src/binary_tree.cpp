#include "binary_tree.h"
#include "boolean_expressions.h"
#include <iostream>
#include <queue>

BinaryTree::BinaryTree(std::string &input, std::string &exp)
    : root(nullptr), expression("") {
  expression = exp;
  root = buildTree(input, 0);
}

BinaryTree::~BinaryTree() { destroyTree(root); }

std::string BinaryTree::getExpression() const { return expression; }

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

void BinaryTree::printTree() {
  if (!root) {
    std::cout << "Tree is empty." << std::endl;
    return;
  }

  std::queue<Node *> nodesQueue;
  nodesQueue.push(root);

  while (!nodesQueue.empty()) {
    int levelSize = nodesQueue.size();

    for (int i = 0; i < levelSize; i++) {
      Node *node = nodesQueue.front();
      nodesQueue.pop();

      std::cout << node->value << " ";

      if (node->left) {
        nodesQueue.push(node->left);
      }
      if (node->right) {
        nodesQueue.push(node->right);
      }
    }

    std::cout << std::endl;
  }
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

  if (root->left == 0 && root->right == 0) {
    evaluateNode(root);
  } else {
    int left_result = root->left->result;
    int right_result = root->right->result;
    // std::cout << left_result << " lft result" << std::endl;
    // std::cout << right_result << " rght result" << std::endl;

    if (left_result == 2 && right_result == 2) {
      unsigned long long int str_size = root->value.length();
      // std::cout << root->value << " parent" << std::endl;
      // std::cout << root->left->value << " left" << std::endl;
      // std::cout << root->right->value << " right" << std::endl;
      root->result = 2;
      for (unsigned long long int i = 0; i < str_size; i++) {
        if (root->right->value[i] != root->left->value[i]) {
          // std:: cout << "i: " << i << std::endl;
          // std::cout << root->left->value[i] << " left" << std::endl;
          // std::cout << root->right->value[i] << " right" << std::endl;
          // std::cout << root->right->value << " parent" << std::endl;
          root->value[i] = 'a';
          // std::cout << root->right->value << " after parent" << std::endl;
        } else {
          root->value[i] = root->right->value[i];
        }
      }
    } else if (left_result != -1 && right_result != -1) {
      if (left_result == 1 && right_result == left_result) {
        unsigned long long int pos_insert =
            find_next_quantificator_pos_after_index(root->value, index);

        // std::cout << root->value[pos_insert] << " quantificador "<<
        // std::endl;
        //  std::cout << root->value << " before" << std::endl;
        root->value[pos_insert] = 'a';
        root->result = 2;
        // std::cout << root->value << " deu bom nos dois" << std::endl;
      } else if (left_result || right_result) {
        std::string value;

        unsigned long long int pos_insert =
            find_next_quantificator_pos_after_index(root->value, index);

        // std::cout << root->value[pos_insert] << " quantificador "<<
        // std::endl;

        if (root->value[pos_insert] == 'a') {
          root->result = 0;
        }

        if (right_result) {
          value = root->right->value;
        } else {
          value = root->left->value;
        }
        // std::cout << value << " aqui que foi" << std::endl;
        // std::cout << pos_insert << " pos_insert" << std::endl;
        root->value[pos_insert] = value[pos_insert];
      } else {
        root->result = 0;
        root->value[index] = '0';
      }
    }
  }
}

void BinaryTree::evaluateNode(Node *node) {
  // calls only for leaf nodes
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
