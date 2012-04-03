/** \file
    \brief A file containing macros used by muParserX

<pre>
               __________                                 ____  ___
    _____  __ _\______   \_____ _______  ______ __________\   \/  /
   /     \|  |  \     ___/\__  \\_  __ \/  ___// __ \_  __ \     / 
  |  Y Y  \  |  /    |     / __ \|  | \/\___ \\  ___/|  | \/     \ 
  |__|_|  /____/|____|    (____  /__|  /____  >\___  >__| /___/\  \
        \/                     \/           \/     \/           \_/
                                       Copyright (C) 2012 Ingo Berg
                                       All rights reserved.

  muParserX - A C++ math parser library with array and string support
  Copyright (c) 2012, Ingo Berg
  All rights reserved.

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, 
     this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright notice, 
     this list of conditions and the following disclaimer in the documentation 
     and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
  POSSIBILITY OF SUCH DAMAGE.
</pre>
*/
#ifndef MUP_DEFINES_H
#define MUP_DEFINES_H

#include <cassert>


#if defined(_UNICODE)
  #if !defined(_T)
  #define _T(x) L##x
  #endif // not defined _T
  #define MUP_STRING_TYPE std::wstring
#else
  #ifndef _T
  /** \brief Macro needed for the "unicodification" of strings.
  */
  #define _T(x) x
  #endif
  
  /** \brief The string type used by muParserX. 
  
    This macro is needed for UNICODE support.
  */
  #define MUP_STRING_TYPE std::string
#endif

/** \brief A macro containing the version of muParserX. */
#define MUP_PARSER_VERSION _T("2.1.2 (20120224)")

/** \brief A macro for setting the parser namespace. */
#define MUP_NAMESPACE_START namespace mup {

/** \brief Closing bracket for the parser namespace macro. */
#define MUP_NAMESPACE_END }


#if defined(_DEBUG)
  #define MUP_TOK_CAST(TYPE, POINTER)  dynamic_cast<TYPE>(POINTER);

  /** \brief Debug macro to force an abortion of the programm with a certain message.
  */
  #define MUP_FAIL(MSG)    \
          bool MSG=false;  \
          assert(MSG);

  /** \brief An assertion that does not kill the program.

      This macro is neutralised in UNICODE builds. It's
      too difficult to translate.
  */
  #define MUP_ASSERT(COND)                         \
          if (!(COND))                             \
          {                                        \
            stringstream_type ss;                  \
            ss << _T("Assertion \"") _T(#COND) _T("\" failed: ") \
               << __FILE__ << _T(" line ")         \
               << __LINE__ << _T(".");             \
            throw ParserError( ss.str() );         \
          }
  #define MUP_LEAKAGE_REPORT
#else
  #define MUP_FAIL(MSG)
  #define MUP_ASSERT(COND)
  #define MUP_TOK_CAST(TYPE, POINTER)  static_cast<TYPE>(POINTER);
#endif

  /** \brief Include tests for features about to be implemented in 
             the future in the unit test.
  */
  //#define MUP_NICE_TO_HAVE
#endif


