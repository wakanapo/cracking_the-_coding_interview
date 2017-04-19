/* 
 * 10_3.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-04-19                              
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



int Find(int n, std::vector<int>& nums) {
  if (nums.size() <= 0)
    return -1;  // When n is not found, Find() return -1. 
  int first = nums[0];
  int m_idx = nums.size() / 2;
  int mid = nums[m_idx];
  int offset = 0;
  if (mid == n)
    return m_idx;
  std::vector<int> next;
  if (n == first)
    return 0;
  if (mid == first)
    return -1;
  if (((mid > n) & (first > mid || n > first)) || (first > mid && n > first))
    next = std::vector<int>(nums.begin(), nums.begin() + m_idx);
  else {
    if (m_idx < (int)nums.size()) {
      next = std::vector<int>(nums.begin() + m_idx + 1, nums.end());
      offset = m_idx + 1;
    }
    else
      return -1;
  }
  int next_ans = Find(n, next);
  if (next_ans == -1)
    return -1;
  return Find(n, next) + offset;
}


int main() {
  std::vector<int> nums = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
  int n;
  std::cin >> n;
  std::cout << Find(n, nums) << std::endl;
}
