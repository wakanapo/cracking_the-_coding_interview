/* 
 * 8_11.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-04-03                              
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
#include <vector>

int makeChange(int amount, std::vector<int>* denoms,
               int index, std::vector<std::vector<int>>* map) {
  if ((*map)[amount][index] > 0)
    return (*map)[amount][index];
  if (index >= (int)denoms->size() - 1)
    return 1;
  int denomAmount = (*denoms)[index];
  int ways = 0;
  for (int i = 0; i * denomAmount <= amount; ++i) {
    int amountRemaining = amount - i * denomAmount;
    ways += makeChange(amountRemaining, denoms, index + 1, map);
  }
  (*map)[amount][index] = ways;
  return ways;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> denoms = {25, 10, 5, 1};
  std::vector<std::vector<int>> map(n+1, std::vector<int>(denoms.size(), 0));
  std::cout << "Combination: " << makeChange(n, &denoms, 0, &map) << std::endl;
}

