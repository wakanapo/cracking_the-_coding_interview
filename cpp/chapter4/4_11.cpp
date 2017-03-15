/* 
 * 4_11.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-15                              
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


#include "4_11.h"

#include <random>
#include <string>


template <typename T>
TreeNode<T>::TreeNode(T item) {
  data = item;
  left = nullptr;
  right = nullptr;
}


template <typename T>
RandomTree<T>::RandomTree() {
  root = nullptr;
}

template <typename T>
void RandomTree<T>::Add(T item) {
  TreeNode<T>* n = new TreeNode<T>(item);
  if (node_v.size() <= 0)
    root = n;
  else {
    for (auto node : node_v) {
      if (node->left == nullptr) {
        node->left = n;
        n->parent = node;
        break;
      }
      if (node->right == nullptr) {
        node->right = n;
        n->parent = node;
        break;
      }
    }
  }
  node_v.push_back(n);
}

template <typename T>
TreeNode<T>* RandomTree<T>::Find(T item) {
  for (auto node : node_v) {
    if (node->data == item)
      return node;
  }
  return nullptr;
}

template <typename T>
void RandomTree<T>::Remove(T item) {
  TreeNode<T>* node = Find(item);
  if (node == nullptr)
    return;
  if (node->parent == nullptr)
    root = nullptr;
  if (node->parent->left == node)
    node->parent->left = nullptr;
  else if (node->parent->right == node)
    node->parent->right = nullptr;
  auto itr = std::find(node_v.begin(), node_v.end(), node);
  if (itr != node_v.end())
    node_v.erase(itr);
  delete(node);
}

template <typename T>
TreeNode<T>* RandomTree<T>::GetRandomNode() {
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<> rand(0, node_v.size());
  return node_v[rand(mt)];
}


template class RandomTree<int>;
template class RandomTree<std::string>;
