/* 
 * 8_6.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-30                              
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
#include <iostream>
#include <stack>
#include <vector>

class Tower {
private:
  std::stack<int>* disks;
  int index;
public:
  Tower(int i) {
    disks = new std::stack<int>;
    index = i;
  }
  
  int getIndex() {
    return index;
  }

  void add(int d) {
    if (!disks->empty() && disks->top() <= d)
      std::cout << "Error placing disk" << d << std::endl;
    else
      disks->push(d);
  }

  void moveTopTo(Tower t) {
    t.add(disks->top());
    disks->pop();    
  }

  void moveDisks(int n, Tower dest, Tower buff) {
    if (n > 0) {
      moveDisks(n - 1, buff, dest);
      moveTopTo(dest);
      buff.moveDisks(n - 1, dest, *this);
    }
  }
};


int main() {
  int n;
  std::cin >> n;
  std::vector<Tower*> towers;
  for (int i = 0; i < n; ++i) {
    towers[i] = new Tower(i);
  }

  for (int i = n - 1; i >= 0; --i) {
    towers[0]->add(i);
  }
  towers[0]->moveDisks(n, *towers[2], *towers[1]);
}
