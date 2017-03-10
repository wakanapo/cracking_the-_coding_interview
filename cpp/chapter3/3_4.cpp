/* 
 * 3_4.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-10                              
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


#include "3_4.h"


template <typename T>
void MyQueue<T>::add(T item) {
  if (origin.empty() && !reverse.empty()) {
    while (!reverse.empty()) {
      origin.push(reverse.top());
      reverse.pop();
    }
  }
  origin.push(item);
}

template <typename T>
void MyQueue<T>::remove() {
  if (reverse.empty() && !origin.empty()) {
    while (!origin.empty()) {
      reverse.push(origin.top());
      origin.pop();
    }
  }
  reverse.pop();
}

template <typename T>
T MyQueue<T>::peek() {
  if (reverse.empty() && !origin.empty()) {
    while (!origin.empty()) {
      reverse.push(origin.top());
      origin.pop();
    }
  }
  return reverse.top();
}

template <typename T>
bool MyQueue<T>::isEmpty() {
  if (origin.empty() && reverse.empty())
    return true;
  else
    return false;
}

template class MyQueue<int>;
template class MyQueue<double>;
