/* 
 * 10_5.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-04-24                              
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

int findIndex_rec(std::string target, std::vector<std::string>& strs,
                  int first, int last) {
  if (first > last)
    return -1;
  
  int mid = (first + last) / 2;
  if (strs[mid] == "") {
    int left = mid - 1;
    int right = mid + 1;
    while(1) {
      if (left < first && right > last)
        return -1;
      if (right <= last && strs[right] != "") {
        mid = right;
        break;
      }
      if (left >= first && strs[left] != "") {
        mid = left;
        break;
      }
      left--;
      right++;
    }
  }
  if (strs[mid] == target)
    return mid;
  if (strs[mid] < target)
    return findIndex_rec(target, strs, mid + 1, last);
  if (strs[mid] > target)
    return findIndex_rec(target, strs, first, mid - 1);
  return -1;
}


int findIndex(std::string target, std::vector<std::string>* strs) {
  if (strs == nullptr || target == "")
    return -1;
  return findIndex_rec(target, *strs, 0, strs->size() - 1);
}


int main() {
  std::vector<std::string> strs =
    {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
  std::string target;
  std::cin >> target;
  std::cout << findIndex(target, &strs) << std::endl;
}
