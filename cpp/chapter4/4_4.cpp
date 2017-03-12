/* 
 * 4_4.cpp
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
#include <cstdlib>


int CheckDepth(Node* n) {
  if (n == nullptr)
    return 0;
  if (CheckDepth(n->left) > CheckDepth(n->right))
    return CheckDepth(n->left) + 1;
  else
    return CheckDepth(n->right) + 1;
}


bool isBalanced(Node* tree) {
  if (std::abs(CheckDepth(tree->left) - CheckDepth(tree->right)) > 1)
    return false;
  else
    return true;
}


int main() {
  Node* tree = new Node(3);
  tree->left = new Node(2);
  tree->right = new Node(2);
  tree->left->left = new Node(1);
  tree->left->right = new Node(1);
  if (isBalanced(tree))
    std::cout << "Balance: Pass!" << std::endl;
  tree->left->left->left = new Node(0);
  if (!isBalanced(tree))
    std::cout << "NoBalance: Pass!" << std::endl;
}
