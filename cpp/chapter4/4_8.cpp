/* 
 * 4_8.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-14                              
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
#include <map>
#include <string>


Node* CommonAncestor(Node* a, Node* b) {
  std::map<Node*, int> a_ancestor;
  std::map<Node*, int> b_ancestor;
  while (1) {
    a_ancestor[a->parent] = 1;
    b_ancestor[b->parent] = 1;
    if (a_ancestor[b->parent] == 1)
      return b->parent;
    if (b_ancestor[a->parent] == 1)
      return a->parent;
    if (a->parent != nullptr)
      a = a->parent;
    if (b->parent != nullptr)
      b = b->parent;
  }
}


void p(std::string str) {
  std::cout << str + ": success!" << std::endl;
}


int main(){
  Node* tree = new Node(1);
  Node* n = tree;
  for (int i = 0; i < 3; i++) {
    n->left = new Node(n->value + i + 1);
    n->left->parent = n;
    n->right = new Node(n->value + i + 2);
    n->right->parent = n;
    if (i % 2 == 0)
      n = n->left;
    else
      n = n->parent->right;
  }
  if (CommonAncestor(tree->left->left, tree->left->right) == tree->left)
    p("left");
  if (CommonAncestor(tree->left->left, tree->right->left) == tree)
    p("tree");
  if (CommonAncestor(tree->right, tree->right->right) == tree)
    p("right");
}
