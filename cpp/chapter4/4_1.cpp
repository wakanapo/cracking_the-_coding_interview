/* 
 * 4_1.cpp
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


#include "directed.h"
#include <iostream>
#include <map>
#include <queue>
#include <string>


void success(std::string str) {
  std::cout << str << " : Success!" << std::endl;
}


template<typename T>
bool isPath(Node<T>* from, Node<T>* to) {
  Node<T>* next;
  std::map<Node<T>*, int> visited;
  std::queue<Node<T>*> visit;
  visit.push(from);
  while (!visit.empty()) {
    next = visit.front();
    for (auto node : next->neighbors) {
      if (node == to)
        return true;
      if (visited[node] == 0) {
        visit.push(node);
        visited[node] = 1;
      }
    }
    visit.pop();
  }
  return false;
}


int main() {
  DirectedGraph<int>* IntGraph = new DirectedGraph<int>;
  Node<int>* node1 = new Node<int>(1);
  Node<int>* node2 = new Node<int>(1);
  Node<int>* node3 = new Node<int>(1);
  Node<int>* node4 = new Node<int>(1);
  Node<int>* node5 = new Node<int>(1);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  node2->neighbors.push_back(node4);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node5);
  IntGraph->nodes.push_back(node1);
  IntGraph->nodes.push_back(node2);
  IntGraph->nodes.push_back(node3);
  IntGraph->nodes.push_back(node4);
  IntGraph->nodes.push_back(node5);
  if (isPath(node1, node5))
    success("1->5");
  if (!isPath(node5, node1))
    success("5->1");
  if (!isPath(node2, node3))
    success("2->3");
}
