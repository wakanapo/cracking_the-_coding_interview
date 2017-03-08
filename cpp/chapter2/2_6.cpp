/* 
 * 2_6.cpp
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


bool isRotation(Node* head) {
  Node* n = head;
  Node* reverse = nullptr;
  while (n != nullptr) {
    Node* new_n = new Node(n->data);
    new_n->next = reverse;
    reverse = new_n;
    n = n->next;
  }
  n =head;
  while (n != nullptr) {
    if (n->data != reverse->data)
      return false;
    n = n->next;
    reverse = reverse->next;
  }
  return true;
}


int main() {
  Node* rotate = new Node(1);
  rotate->appendToTail(2);
  rotate->appendToTail(3);
  rotate->appendToTail(2);
  rotate->appendToTail(1);
  Node* nonrotate = new Node(1);
  nonrotate->appendToTail(2);
  nonrotate->appendToTail(3);
  nonrotate->appendToTail(1);
  if (isRotation(rotate))
    std::cout << "Pass!" << std::endl;
  if (!isRotation(nonrotate))
    std::cout << "Pass!" << std::endl;
}
