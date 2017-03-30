/* 
 * 8_5.cpp
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
#include <map>

struct Pair {
  int a;
  int b;
  bool operator < (const Pair& rhs) const {
    if (a < rhs.a)
      return true;
    if (a > rhs.a)
      return false;
    if (b < rhs.b)
      return true;
    if (b > rhs.b)
      return false;
    return false;
  }
};


int times(int a, int b, std::map<Pair, int> cash) {
  if (a == 0 || b == 0)
    return 0;
  if (cash[{a, b}] > 0)
    return cash[{a, b}];
  if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  if (a == 1)
    return b;
  cash[{a, b}] = times(a / 2, b, cash) + times((a + 1) / 2, b, cash);
  return cash[{a, b}];
}

int main () {
  int a, b;
  std::map<Pair, int> cash;
  std::cin >> a >> b; 
  std ::cout << a << "*" << b << "=" << times(a, b, cash) << std::endl;
}
