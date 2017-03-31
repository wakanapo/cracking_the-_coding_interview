/* 
 * 8_9.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-31                              
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


struct Color {
  int r;
  int g;
  int b;
  bool operator == (const Color &rhs) const {
    if (r == rhs.r && g == rhs.g && b == rhs.b)
      return true;
    return false;
  }
};


class Paint {
private:
  std::vector<std::vector<Color>> screen;
public:
  Paint(int x, int y);
  void FloodFil(int x, int y, Color c);
};


Paint::Paint(int x, int y) {
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) {
      screen[i][j] = {255, 255, 255};
    }
  }
}


void Paint::FloodFil(int x, int y, Color c) {
  if (screen[x][y] == screen[x-1][y])
    FloodFil(x-1, y, c);
  if (screen[x][y] == screen[x+1][y])
    FloodFil(x+1, y, c);
  if (screen[x][y] == screen[x][y-1])
    FloodFil(x, y-1, c);
  if (screen[x][y] == screen[x][y+1])
    FloodFil(x, y+1, c);
  screen[x][y] = c;
}

