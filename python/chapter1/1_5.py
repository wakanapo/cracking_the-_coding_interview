#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim: set fileencoding=utf-8 :
#
# 1_5.py
# 
# Author:   Wakana Nogami <wakana.tn16@gmail.com>
# URL:      https://wknp16.tumblr.com               
# License:  2-Clause BSD License                    
# Created:  2017-03-03                              
#
#
# Copyright (c) 2017, Wakana Nogami
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

def checkReplacement(str1, str2):
    flag = 0
    for i in range(len(str1)):
        if str1[i] != str2[i]:
            flag += 1
        if flag > 1:
            return False
    return True


def checkRemove(l_str, s_str):
    flag = 0
    s_idx = 0
    for l_idx in range(len(l_str)):
        if flag > 1:
            return False
        if l_str[l_idx] != s_str[s_idx]:
            flag += 1
            continue
        s_idx += 1
        if s_idx >= len(s_str):
            break
    return True


def transformStr(str1, str2):
    l1 = len(str1)
    l2 = len(str2)
    if abs(l1 - l2) > 1:
        return False
    if l1 == l2:
        return checkReplacement(str1, str2)
    elif l1 > l2:
        return checkRemove(str1, str2)
    else:
        return checkRemove(str2, str1)


if __name__ == '__main__':
    s = input()
    s = s.replace(' ', '')
    s = s.split(',')
    if len(s) > 2:
        print ('ERROR!')
    if transformStr(s[0], s[1]):
        print ('True')
    else:
        print ('False')
