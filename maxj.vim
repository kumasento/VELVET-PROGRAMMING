" Vim syntax file
" Language:	MaxJ, Maxeler hardware designs using their extended Java
" Maintainer:	Tim Todman
" URL:		---
" Last Change:	2014

" Uses java.vim, and adds a few special things for JavaCC Parser files.
" Those files usually have the extension  *.jj
" based on javacc.vim

" For version 5.x: Clear all syntax items
" For version 6.x: Quit when a syntax file was already loaded
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

" like javacc.vim, base on java.vim
" source the java.vim file
if version < 600
  source <sfile>:p:h/java.vim
else
  runtime! syntax/java.vim
endif
unlet b:current_syntax

" special objects
syn keyword maxjPackages constant io count control stream state mem
" extra keywords
syn keyword maxjPackages IF THEN ELSE SWITCH CASE OTHERWISE
syn keyword maxjType     DFEVar DFEType CounterChain Counter Count
syn keyword maxjOperator cast eq neq
"syn match maxjSpecToken IF THEN SWITCH CASE OTHERWISE
" the dot is necessary as otherwise it will be matched as a keyword.
"syn match maxjSpecToken ".LOOKAHEAD("ms=s+1,me=e-1
"syn match maxjToken "<[^> \t]*>"
"syn keyword maxjActionToken TOKEN SKIP MORE SPECIAL_TOKEN
"syn keyword maxjError DEBUG IGNORE_IN_BNF

" Define the default highlighting.
" For version 5.7 and earlier: only when not done already
" For version 5.8 and later: only when an item doesn't have highlighting yet
if version >= 508 || !exists("did_css_syn_inits")
  if version < 508
    let did_css_syn_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif
  HiLink maxjSpecToken Statement
  HiLink maxjType Type
  HiLink maxjPackages javaScopeDecl
  HiLink maxjOperator javaOperator
  HiLink maxjError Error
  delcommand HiLink
endif

let b:current_syntax = "maxj"

" vim: ts=8
