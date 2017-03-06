/* 
 * 1_7.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-06                              
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


#include <cstdio>
#include <iostream>
#include <vector>


bool rotate(std::vector<std::vector<int>>* matrix) {
  std::size_t n = matrix->size();
  if (n == 0 || n != (*matrix)[0].size())
    return false;
  for (std::size_t layer = 0; layer < n / 2; layer++) {
    int first = int(layer);
    int last = int(n - 1 - layer);
    for(int i = first; i < last; i++) {
      int offset = i - first;
      int top = (*matrix)[first][i];
      (*matrix)[first][i] = (*matrix)[last - offset][i];
      (*matrix)[last - offset][first] = (*matrix)[last][last - offset];
      (*matrix)[last][last - offset] = (*matrix)[i][last];
      (*matrix)[i][last] = top;      
    }
  }
  return true;
}


int main() {
  std::vector<std::vector<int>> matrix =
    {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  if (rotate(&matrix))
    std::cout << matrix[0][0] << matrix[0][1] << matrix[0][2] << std::endl;
    std::cout << matrix[1][0] << matrix[1][1] << matrix[1][2] << std::endl;
    std::cout << matrix[2][0] << matrix[2][1] << matrix[2][2] << std::endl;
}
