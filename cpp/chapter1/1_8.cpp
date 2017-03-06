/* 
 * 1_8.cpp
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


bool zeroMatrix(std::vector<std::vector<int>>* matrix) {
  std::size_t row = (*matrix).size();
  if (row == 0)
    return false;
  std::size_t colmun = (*matrix)[0].size();
  if (colmun == 0)
    return false;
  std::vector<int> zero_col;
  for (int i = 0; i < int(row); i++) {
    for (int j = 0; j < int(colmun); j++) {
      if((*matrix)[i][j] == 0) {
        (*matrix)[i].assign(colmun, 0);
        zero_col.push_back(j);
        break;
      }
    }
  }
  for (int i = 0; i < int(row); i++) {
    for (auto j : zero_col) {
      (*matrix)[i][j] = 0;
    }
  }
  return true;
}


int main() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
  if (zeroMatrix(&matrix)) {
    std::cout << matrix[0][0] << matrix[0][1] << matrix[0][2] << std::endl;
    std::cout << matrix[1][0] << matrix[1][1] << matrix[1][2] << std::endl;
    std::cout << matrix[2][0] << matrix[2][1] << matrix[2][2] << std::endl;
  }
}
