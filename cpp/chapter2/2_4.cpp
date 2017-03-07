/* 
 * 2_4.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-07                              
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
#include <random>


void divideHighLow(Node *head, int k) {
  Node *border = nullptr;
  Node *n = head;
  while (n->next != nullptr) {
    if (n->data < k && n->next->data >= k)
      border = n;
    if (n->data >= k && n->next->data < k) {
      Node *tmp = border->next;
      border->next = n->next;
      n->next = n->next->next;
      border->next->next = tmp;
      border = border->next;
      continue;
    }
    n = n->next;
  }
}


int main() {
  Node* head = new Node(1);
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<> rand10(0, 9);
  for (int i = 0; i < 10; i++)
    head->appendToTail(rand10(mt));
  std::cout << "before" << std::endl;
  Node* n = head;
  while (n != nullptr) {
    std::cout << n->data << std::endl;
    n = n->next;
  }
  std::cout << "after" << std::endl;
  divideHighLow(head, 5);
  n = head;
  while (n != nullptr) {
    std::cout << n->data << std::endl;
    n = n->next;
  }
}
