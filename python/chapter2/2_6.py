#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim: set fileencoding=utf-8 :
#
# 2_6.py
# 
# Author:   Wakana Nogami <wakana.tn16@gmail.com>
# URL:      https://wknp16.tumblr.com               
# License:  2-Clause BSD License                    
# Created:  2017-03-08                              
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

import node


def isRotation(head):
    n = head
    reverse = None
    while n!=None:
        new = node.Node(n.data)
        new.next = reverse
        reverse = new
        n = n.next
    n = head
    while n != None:
        if n.data != reverse.data:
            return False
        n = n.next
        reverse = reverse.next
    return True


if __name__ == '__main__':
    rotate = node.Node(1)
    rotate.appendToTail(2)
    rotate.appendToTail(3)
    rotate.appendToTail(2)
    rotate.appendToTail(1)
    nonrotate = node.Node(1)
    nonrotate.appendToTail(2)
    nonrotate.appendToTail(3)
    nonrotate.appendToTail(4)
    nonrotate.appendToTail(1)
    if isRotation(rotate):
        print ("Pass!")
    else:
        print ("Fail")
    if not isRotation(nonrotate):
        print ("Pass!")
    else:
        print ("Fail")
