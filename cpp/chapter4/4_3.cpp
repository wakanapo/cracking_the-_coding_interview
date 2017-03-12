/* 
 * 4_3.cpp
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
#include <vector>

class List {
public:
  List();
  Node* node;
  List* next;
  void append(Node*);
};

List::List() {
  node = nullptr;
  next = nullptr;
}

void List::append(Node* n) {
  if (this->node == nullptr)
    this->node = n;
  else {
    List* list = this;
    while (list->next != nullptr)
      list = list->next;
    list->next = new List();
    list->next->node = n;
  }
}


std::vector<List*>* MakeList(Node* tree) {
  std::vector<List*>* lists = new std::vector<List*>;
  List* list = new List();
  list->append(tree);
  lists->push_back(list);
  while (1) {
    List* new_list = new List();
    while (list != nullptr) {
      Node* now = list->node;
      if (now->left != nullptr) 
        new_list->append(now->left);
      if (now->right != nullptr)
        new_list->append(now->right);
      list = list->next;
    }
    if (new_list->node == nullptr)
      break;
    list = new_list;
    lists->push_back(list);
  }
  return lists;
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
  Node* tree = SmallTree(v1);
  std::vector<List*>* lists = MakeList(tree);
  for (auto list : *lists) {
    List* now = list;
    while (now != nullptr) {
      std::cout << now->node->value << " ";
      now = now->next;
    }
    std::cout << std::endl;
  }
}
