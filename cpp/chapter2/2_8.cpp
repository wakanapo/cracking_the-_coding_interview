/* 
 * 2_8.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-09                              
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


Node* loop(Node* head) {
  Node* first = head;
  Node* second = head;
  bool not_head = false;
  while(1) {
    if (first == nullptr || first->next == nullptr)
      return nullptr;
    if (first == second && not_head)
      break;
    not_head = true;
    first = first->next->next;
    second = second->next;
  }
  second = head;
  while(first != second) {
    first = first->next;
    second = second->next;
  }
  return first;
}


int main() {
  Node* n1 = new Node(1);
  n1->appendToTail(2);
  n1->appendToTail(3);
  n1->appendToTail(4);
  n1->appendToTail(5);
  n1->next->next->next->next->next= n1->next;
  Node* n2 = new Node(1);
  n2->appendToTail(2);
  n2->appendToTail(3);
  n2->appendToTail(4);
  if (loop(n1) == n1->next)
    std::cout << "Loop: Pass!" << std::endl;
  else
    std::cout << "Loop: Fail!" << std::endl;
  if (loop(n2) == nullptr)
    std::cout << "Nonloop: Pass!" << std::endl;
  else
    std::cout << "Nonloop: Fail!" << std::endl;
}
