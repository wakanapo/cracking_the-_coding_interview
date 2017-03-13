/* 
 * 4_6.cpp
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


#include "tree.h"

#include <iostream>


Node* NextNode(Node* n) {
  if (n->right != nullptr) {
    n = n->right;
    while (n->left != nullptr)
      n = n->left;
    return n;
  }
  while (n->parent->left != n) {
    n = n->parent;
    if (n->parent == nullptr)
      return nullptr;
  }
  return n->parent;
}


int main() {
  Node* tree = new Node(4);
  tree->left = new Node(2);
  tree->left->parent = tree;
  tree->right = new Node(6);
  tree->right->parent = tree;
  tree->left->left = new Node(1);
  tree->left->left->parent = tree->left;
  tree->left->right = new Node(3);
  tree->left->right->parent = tree->left;
  tree->right->left = new Node(5);
  tree->right->left->parent = tree->right;
  Node* n = tree->left->left;
  while (n != nullptr) {
    std::cout << n->value << std::endl;
    n = NextNode(n);
  }
}
