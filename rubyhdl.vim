" Vim syntax file
" Language:	Ruby HDL
" Maintainer:	tim, from a file for Pascal by Mario Eusebio <bio@dq.fct.unl.pt>
" Last Change:	2000 Nov 02




" Remove any old syntax stuff hanging around
syn clear

syn case match

syn keyword rubyhdlStatement		INCLUDE SELECT $wire $rel
syn keyword rubyhdlStatement		LET IN END
syn keyword rubyhdlConditional		IF ELSE THEN
syn keyword rubyhdlRepeat		FOR

syn keyword rubyhdlTodo contained	TODO

" String
syn region  rubyhdlString	start=+"+  end=+"+
"syn region  rubyhdlVHDL		start=+{+  end=+}+

"syn match  rubyhdlIdentifier		"\<[a-zA-Z_][a-zA-Z0-9_]*\>"

syn match  rubyhdlDelimiter		"[<>]"

"syn match  rubyhdlMatrixDelimiter	"[][]"


"syn match  rubyhdlNumber		"-\=\<\d\+\.\d\+[dD]-\=\d\+\>"
"syn match  rubyhdlNumber		"-\=\<\d\+\.\d\+[eE]-\=\d\+\>"
syn match  rubyhdlNumber		"-\=\<\d\+\.\d\+\>"
syn match  rubyhdlNumber		"-\=\<\d\+\>"
syn match  rubyhdlByte		"\$[0-9a-fA-F]\+\>"

" If you don't like tabs
"syn match rubyhdlShowTab "\t"
"syn match rubyhdlShowTabc "\t"

syn region rubyhdlComment	start="#"  end="\n" contains=rubyhdlTodo

"syn keyword rubyhdlOperator	OF MAP IS ATTRIBUTES
"syn keyword rubyhdlOperator	True False
syn keyword rubyhdlOperator	minus add mult div mod inc dec gtn geq
syn keyword rubyhdlOperator	ltn leq eq max min abs muxr gcd fac log
syn keyword rubyhdlOperator	not and or xor nand nor xnor
syn keyword rubyhdlOperator	append
syn keyword rubyhdlOperator	D DI AD sdpr pdsr
syn keyword rubyhdlOperator	bit2int int2bit bit2uint uint2bit
syn keyword rubyhdlOperator	bit2sint sint2bit
syn keyword rubyhdlOperator	bit2real real2bit
syn keyword rubyhdlOperator	bit2sreal sreal2bit

"syn keyword rubyhdlType	GENERIC VECTOR WIRE
syn keyword rubyhdlType	VAR

"syn keyword rubyhdlFunction	procedure function

syn sync lines=250

if !exists("did_rubyhdl_syntax_inits")
  let did_rubyhdl_syntax_inits = 1
  " The default methods for highlighting.  Can be overridden later
  hi link rubyhdlStatement		Statement
  hi link rubyhdlLabel			Label
  hi link rubyhdlConditional		Conditional
  hi link rubyhdlRepeat			Repeat
  hi link rubyhdlTodo			Todo
  hi link rubyhdlString			String
  hi link rubyhdlNumber			Number
  hi link rubyhdlByte			Number
  hi link rubyhdlOperator		Operator
  hi link rubyhdlType			Type
  hi link rubyhdlComment			Comment
  hi link rubyhdlStatement		Statement

"optional highlighting
  "hi link rubyhdlDelimiter		Identifier

  "hi link rubyhdlShowTab			Error
  "hi link rubyhdlShowTabc		Error

  "hi link rubyhdlIdentifier		Identifier
endif

let b:current_syntax = "rubyhdl"

" vim: ts=8
