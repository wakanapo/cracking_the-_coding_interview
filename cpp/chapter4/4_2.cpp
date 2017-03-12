/* 
 * 4_2.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-12                              
 *
 *
 * Copyright (c) 2017, Wakana Nogami
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <vector>
#include <iostream>


class Node {
public:
  Node(int);
  int value;
  Node* left;
  Node* right;
};

Node::Node(int date) {
  value = date;
  left = nullptr;
  right = nullptr;
}


Node* SmallTree(std::vector<int> v) {
  int size = v.size(); 
  int middle = size / 2; 
  Node* node = new Node(v[middle]);
  if (middle > 0) {
    node->left = SmallTree(std::vector<int>(v.begin(), v.begin() + middle));
    if (middle + 1 < size)
      node->right = SmallTree(
        std::vector<int>(v.begin() + middle + 1, v.end()));
  }
  return node;
}


int main() {
  std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> v2 = {1, 2, 3, 4, 5, 6};
  Node* tree1 = SmallTree(v1);
  Node* tree2 = SmallTree(v2);
  std::cout << tree1->value << std::endl;                                      // 4
  std::cout << tree1->left->value << " " << tree1->right->value << std::endl;  // 2 6 
  std::cout << tree1->left->left->value << " "                                 // 1 3 5 7
            << tree1->left->right->value << " "
            << tree1->right->left->value << " "
            << tree1->right->right->value << std::endl;
  std::cout << tree2->value << std::endl;                                      // 4
  std::cout << tree2->left->value << " " << tree2->right->value << std::endl;  // 2 6
  std::cout << tree2->left->left->value << " "                                 // 1 3 5
            << tree2->left->right->value << " "
            << tree2->right->left->value  << std::endl;
}
