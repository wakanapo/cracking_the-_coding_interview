/* 
 * 2_7.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-08                              
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


#include "node.h"
#include <cstdio>
#include <iostream>
#include <stack>


std::stack<Node*>* addressStack(Node* head) {
  Node* n = head;
  std::stack<Node*>* addr = new std::stack<Node*>;
  while (n != nullptr) {
    addr->push(n);
    n = n->next;
  }
  return addr;
}


Node* commonNode(Node* n1, Node* n2) {
  std::stack<Node*>* addr_n1 = addressStack(n1);
  std::stack<Node*>* addr_n2 = addressStack(n2);
  Node* common = nullptr;
  while (!addr_n1->empty() && !addr_n2->empty()) {
    if (addr_n1->top() != addr_n2->top())
      break;
    common = addr_n1->top();
    addr_n1->pop();
    addr_n2->pop();
  }
  return common;
}


int main() {
  Node* n1 = new Node(1);
  n1->appendToTail(2);
  n1->appendToTail(3);
  n1->appendToTail(4);
  Node* n2 = new Node(5);
  n2->appendToTail(6);
  n2->next->next = n1->next;
  Node* common = commonNode(n1, n2);
  while (common != nullptr) {
    std::cout << common->data << std::endl;
    common = common->next;
  }
}
