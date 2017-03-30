/* 
 * 8_8.cpp
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
#include <string>
#include <vector>

struct Bracket {
  std::string bra;
  bool sym;
};


std::vector<Bracket>* BracketsOrder(int n) {
  std::vector<Bracket>* brackets = new std::vector<Bracket>;
  if (n == 1) {
    brackets->push_back({"()", true});
    return brackets;
  }
  for (auto b : *BracketsOrder(n - 1)) {
    for (int i = 0; i < 3; ++i) {
     std::string new_s = b.bra;
     if (i == 0) {
       new_s.insert(0, "(");
       new_s.insert(new_s.length(), ")");
     }
     else if (i == 1) 
       new_s.insert(0, "()");
     else if (i == 2) 
       new_s.insert(new_s.length(), "()");
     if (i == 1 && b.sym) {
       brackets->push_back({new_s, true});
       break;
     }
     brackets->push_back({new_s, false});
    }
  }
  return brackets;
}


int main() {
  int n;
  std::cin >> n;
  for (auto b : *BracketsOrder(n))
    std::cout << b.bra << std::endl;
}
