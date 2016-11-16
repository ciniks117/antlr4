﻿/*
 * [The "BSD license"]
 *  Copyright (c) 2016 Mike Lischke
 *  Copyright (c) 2013 Terence Parr
 *  Copyright (c) 2013 Dan McLaughlin
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "antlr4-common.h"

namespace antlr4 {
namespace tree {

  /** This interface describes the minimal core of methods triggered
   *  by {@link ParseTreeWalker}. E.g.,
   *
   *  	ParseTreeWalker walker = new ParseTreeWalker();
   *		walker.walk(myParseTreeListener, myParseTree); <-- triggers events in your listener
   *
   *  If you want to trigger events in multiple listeners during a single
   *  tree walk, you can use the ParseTreeDispatcher object available at
   *
   * 		https://github.com/antlr/antlr4/issues/841
   */
  class ANTLR4CPP_PUBLIC ParseTreeListener {
  public:
    virtual ~ParseTreeListener() {};
    
    virtual void visitTerminal(TerminalNode *node) = 0;
    virtual void visitErrorNode(ErrorNode *node) = 0;
    virtual void enterEveryRule(ParserRuleContext *ctx) = 0;
    virtual void exitEveryRule(ParserRuleContext *ctx) = 0;

    bool operator == (const ParseTreeListener &other) {
      return this == &other;
    }
  };

} // namespace tree
} // namespace antlr4