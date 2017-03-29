/* 
 * 8_2.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-28                              
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
#include <vector>
#include <map>


struct Point {
  int row;
  int col;
};


bool isPath(std::vector<std::vector<bool>>* maze, int row, int col,
            std::vector<Point>* path, std::map<Point, int>* failedPoints) {
  if (col < 0 || row < 0 || !(*maze)[row][col])
    return false;
  
  Point p = {row, col};
  if ((*failedPoints)[p])
    return false;

  bool isAtOrigin = (row == 0) && (col == 0);

  if (isAtOrigin || isPath(maze, row, col - 1, path, failedPoints) ||
      isPath(maze, row - 1, col, path, failedPoints)) {
    path->push_back(p);
    return true;
  }

  (*failedPoints)[p] = 1;
  return false;
}


std::vector<Point>* getPath(std::vector<std::vector<bool>>* maze) {
  if (maze == nullptr || maze->size() == 0)
    return nullptr;
  std::vector<Point>* path = new std::vector<Point>();
  std::map<Point, int>* failedPoints = new std::map<Point, int>;
  if (isPath(maze, maze->size() - 1, (*maze)[0].size() - 1, path, failedPoints))
    return path;
  return nullptr;
}
