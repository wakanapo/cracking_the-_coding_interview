/* 
 * 1_5.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-03                              
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
#include <cstdlib>
#include <string>
#include <iostream>


bool checkReplacement(std::string str1, std::string str2) {
  int flag = 0;
  for (std::string::size_type i = 0; i < str1.length(); i++) {
    if (str1[i] != str2[i]) {
      flag++;
    }
    if (flag > 1) {
      return false;
    }
  }
  return true;
}


bool checkRemove(std::string l_str, std::string s_str) {
  int flag = 0;
  std::string::size_type s_idx = 0;
  for (std::string::size_type l_idx = 0; l_idx < l_str.length(); l_idx++) {
    if (flag > 1) 
      return false;
    if (l_str[l_idx] != s_str[s_idx]) {
      flag++;
      continue;
    }
    s_idx++;
    if (s_idx >= s_str.length()) 
      break;
  }
  return true;
}


bool transformStr(std::string str1, std::string str2) {
  std::string::size_type l1 = str1.length();
  std::string::size_type l2 = str2.length();
  if (std::abs(int(l1 - l2)) > 1)
    return false;
  if (l1 == l2)
    return checkReplacement(str1, str2);
  else if (l1 > l2)
    return checkRemove(str1, str2);
  else
    return checkRemove(str2, str1);
}


int main() {
  std::string str1, str2;
  getline(std::cin, str1, ',');
  getline(std::cin, str2);
  str1.erase(remove_if(str1.begin(), str1.end(), ::isspace), str1.end());
  str2.erase(remove_if(str2.begin(), str2.end(), ::isspace), str2.end());
  std::cout << str1 << str2 << std::endl;
  std::string ans = (transformStr(str1, str2)) ? "True" : "False";
  std::cout << ans << std::endl;
}
