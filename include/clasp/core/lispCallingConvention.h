/*
    File: lispCallingConvention.h
*/

/*
Copyright (c) 2014, Christian E. Schafmeister
 
CLASP is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.
 
See directory 'clasp/licenses' for full details.
 
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
/* -^- */
#ifdef LCC_MACROS

#define LCC_UNUSED NULL
#define LCC_FIXED_ARGS LCC_ARGS_IN_REGISTERS
#define LCC_FROM_SMART_PTR(x) (x.raw_())
#define LCC_TYPE T_O *
#define LCC_FROM_ACTIVATION_FRAME_SMART_PTR(x) (x.raw_())
#define LCC_TO_SMART_PTR(x) (gctools::smart_ptr<core::T_O>((gc::Tagged)x))

#define LCC_UNUSED_rest2() NULL
#define LCC_UNUSED_rest1() NULL, NULL
#define LCC_UNUSED_rest0() NULL, NULL, NULL

// Pass a defined number of arguments to operator()
#define LCC_PASS_ARGS0_ELLIPSIS(funcRaw) funcRaw, NULL, 0, NULL, NULL, NULL
#define LCC_PASS_ARGS1_ELLIPSIS(funcRaw,a0) funcRaw, NULL, 1, a0, NULL, NULL
#define LCC_PASS_ARGS2_ELLIPSIS(funcRaw,a0, a1) funcRaw, NULL, 2, a0, a1, NULL
#define LCC_PASS_ARGS3_ELLIPSIS(funcRaw,a0, a1, a2) funcRaw, NULL, 3, a0, a1, a2

#define LCC_PASS_MAIN() NULL,NULL, 0, NULL, NULL, NULL

// Don't need lcc_arglist because no arguments are passed
#define LCC_PASS_ARGS0_VA_LIST(funcRaw) funcRaw, lcc_arglist, 0, NULL, NULL, NULL
#define LCC_PASS_ARGS1_VA_LIST(funcRaw,a0) funcRaw, lcc_arglist, 1, a0, NULL, NULL

#define LCC_PASS_ARGS0_ARGLIST(funcRaw) funcRaw, lcc_arglist, 0, NULL, NULL, NULL
#define LCC_PASS_ARGS1_ARGLIST(funcRaw,a0) funcRaw, lcc_arglist, 1, a0, NULL, NULL
#define LCC_PASS_ARGS2_ARGLIST(funcRaw,a0, a1) funcRaw, lcc_arglist, 2, a0, a1, NULL
#define LCC_PASS_ARGS3_ARGLIST(funcRaw,a0, a1, a2) funcRaw, lcc_arglist, 3, a0, a1, a2
#define LCC_PASS_ARGS3_ARGLIST_GENERAL(funcRaw,arglist, nargs, a0, a1, a2) funcRaw, arglist, nargs, a0, a1, a2

// To invoke "invoke" methods use these

#define LCC_ARGS_FUNCALL_ELLIPSIS core::T_O *lcc_closure, core::T_O *dummyArgList, std::size_t lcc_nargs, core::T_O *lcc_fixed_arg0, core::T_O *lcc_fixed_arg1, core::T_O *lcc_fixed_arg2, ...
#define LCC_ARGS_CC_CALL_ELLIPSIS core::T_O *lcc_closure, core::T_O *dummyArgList, std::size_t lcc_nargs, core::T_O *lcc_fixed_arg0, core::T_O *lcc_fixed_arg1, core::T_O *lcc_fixed_arg2, ...
#define LCC_ARGS_ELLIPSIS core::T_O *lcc_closure, core::T_O *dummyArgList, std::size_t lcc_nargs, core::T_O *lcc_fixed_arg0, core::T_O *lcc_fixed_arg1, core::T_O *lcc_fixed_arg2, ...
#define LCC_ARGS_VA_LIST core::T_O *lcc_closure, core::T_O *lcc_arglist, std::size_t lcc_nargs, core::T_O *lcc_fixed_arg0, core::T_O *lcc_fixed_arg1, core::T_O *lcc_fixed_arg2
// When you pass args to another function use LCC_PASS_ARGS
#define LCC_PASS_ARGS lcc_closure, lcc_arglist, lcc_nargs, lcc_fixed_arg0, lcc_fixed_arg1, lcc_fixed_arg2
#define LCC_PASS_ARGS_ENV(_env) _env, lcc_arglist, lcc_nargs, lcc_fixed_arg0, lcc_fixed_arg1, lcc_fixed_arg2

// Compiled functions get the raw va_list
#define LCC_VA_LIST(_valist) (*_valist)._Args
#define LCC_VA_START_ARG lcc_fixed_arg2
#define LCC_LAST_FIXED_ARG lcc_fixed_arg2


#define LCC_CLOSED_ENVIRONMENT core::T_O *lcc_closedEnvironment

#define LCC_VIRTUAL virtual
#define LCC_RETURN gc::return_type

// Return raw values that can be used to construct a core::T_mv
#define LCC_RETURN_RAW gctools::return_type

/*! This is a void function */
#define LISP_CALLING_CONVENTION() invoke_va_list(LCC_ARGS_VA_LIST)

// To invoke functions of type InitFnPtr use these
#define LCC_PASS_ARGS0_VA_LIST_INITFNPTR() _Nil<core::T_O>().raw_(), NULL, 0, LCC_UNUSED_rest0()
#if 0
#define LCC_PASS_ARGS1_VA_LIST_INITFNPTR(a0) NULL, NULL, 1, a0, LCC_UNUSED_rest1()
#define LCC_PASS_ARGS2_VA_LIST_INITFNPTR(a0, a1) NULL, NULL, 2, a0, a1, LCC_UNUSED_rest2()
#define LCC_PASS_ARGS3_VA_LIST_INITFNPTR(a0, a1, a2) NULL, NULL, 3, a0, a1, a2
#endif


#define MULTIPLE_VALUES_ARRAY core::lisp_multipleValues()

/* ASSERT that the first argument is a VaList_sp */
#define ASSERT_FIRST_ARG_IS_VALIST() ASSERT(gctools::tagged_valistp(lcc_fixed_arg0))
#define LCC_ARG0_VALIST() gctools::smart_ptr<core::VaList_S>((gc::Tagged)lcc_fixed_arg0)
#define LCC_ARG0() gctools::smart_ptr<core::T_O>((gc::Tagged)lcc_fixed_arg0)
#define LCC_ARG1() gctools::smart_ptr<core::T_O>((gc::Tagged)lcc_fixed_arg1)
#define LCC_ARG2() gctools::smart_ptr<core::T_O>((gc::Tagged)lcc_fixed_arg2)
/*! LCC_ARGS_IN_REGISTERS is defined in src/core/config.h and is currently 4 (four)*/
#define LCC_FIXED_NUM LCC_ARGS_IN_REGISTERS
//#define MULTIPLE_VALUES_SETUP() core::T_sp* __multipleValuesPtr = core::lisp_multipleValues().start_address()

  
/* This is a switch statement that copies passed arguments in registers into the MultipleValues array */
#define LCC_SWITCH_TO_COPY_PASSED_ARGS_INTO_MULTIPLE_VALUES_ARRAY(_mv) \
  MultipleValues &_mv = lisp_callArgs();                               \
  _mv.setSize(lcc_nargs);                                              \
  switch (lcc_nargs) {                                                 \
  default:                                                             \
    for (int _zii = LCC_FIXED_ARGS; _zii < lcc_nargs; ++_zii) {        \
      _mv[_zii] = va_arg(lcc_arglist, LCC_TYPE);                       \
    }                                                                  \
    va_end(lcc_arglist);                                               \
  case 3:                                                              \
    _mv[2] = lcc_fixed_arg2;                                           \
  case 2:                                                              \
    _mv[1] = lcc_fixed_arg1;                                           \
  case 1:                                                              \
    _mv[0] = lcc_fixed_arg0;                                           \
  case 0:                                                              \
    break;                                                             \
  }

/*! This is X86_64 dependent code */
#if defined(X86) && defined(_ADDRESS_MODEL_64)

// This is VERY HACKISH
// it's based on the System V Application Binary Interface for X86_64
// I'm writing the register arguments into the reg_save_area and then
// resetting the gp_offset to point to the first register argument lcc_fixed_arg0
#define LCC_ABI_ARGS_IN_REGISTERS 6

#define ASSERT_LCC_VA_LIST_AT_START(_valist_s_) \
  ASSERT((_valist_s_)._Args->gp_offset == sizeof(uintptr_t) * (LCC_ABI_ARGS_IN_REGISTERS - LCC_ARGS_IN_REGISTERS));

// Registers are %rdi, %rsi, %rdx, %rcx, %r8, %r9
#define LCC_CLOSURE_REGISTER 0
#define LCC_REST_REGISTER 1
#define LCC_OVERFLOW_SAVE_REGISTER LCC_REST_REGISTER
#define LCC_NARGS_REGISTER 2
#define LCC_ARG0_REGISTER 3
#define LCC_ARG1_REGISTER 4
#define LCC_ARG2_REGISTER 5
#define LCC_TOTAL_REGISTERS 6
#define LCC_SPILL_NUMBER_ARGUMENTS_TO_VA_LIST(_valist_s_, _num_)                               \
  {                                                                                            \
    ((uintptr_t *)(_valist_s_)._Args->reg_save_area)[LCC_NARGS_REGISTER] = (uintptr_t)(_num_); \
  }
#define LCC_SPILL_CLOSURE_TO_VA_LIST(_valist_s_,_closure_)    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_CLOSURE_REGISTER] = (core::T_O*)_closure_;

#define LCC_SPILL_REGISTER_ARGUMENTS_TO_VA_LIST(_valist_s_) {                                                                          \
    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_CLOSURE_REGISTER] = (core::T_O*)lcc_closure;                                   \
    /* Tricky part!!! write the overflow_arg_area pointer into the reg_save_area */                                                    \
    /* so we can recover the overflow args even after the va_list has been traversed */                                                \
    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_OVERFLOW_SAVE_REGISTER] = (core::T_O*)((_valist_s_)._Args->overflow_arg_area); \
    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_NARGS_REGISTER] = (core::T_O*)lcc_nargs;                                       \
    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_ARG0_REGISTER] = (core::T_O*)lcc_fixed_arg0;                                   \
    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_ARG1_REGISTER] = (core::T_O*)lcc_fixed_arg1;                                   \
    ((core::T_O* *)(_valist_s_)._Args->reg_save_area)[LCC_ARG2_REGISTER] = (core::T_O*)lcc_fixed_arg2;                                   \
    (_valist_s_)._Args->gp_offset = sizeof(core::T_O*) * (LCC_ABI_ARGS_IN_REGISTERS - LCC_ARGS_IN_REGISTERS);                           \
  }

#define LCC_raw_VA_LIST_NUMBER_OF_ARGUMENTS(_args) (size_t)(((uintptr_t *)(_args[0].reg_save_area))[LCC_NARGS_REGISTER])
#define LCC_raw_VA_LIST_SET_NUMBER_OF_ARGUMENTS(_args, _n) (((uintptr_t *)(_args[0].reg_save_area))[LCC_NARGS_REGISTER]) = ((uintptr_t)_n)
#define LCC_raw_VA_LIST_DECREMENT_NUMBER_OF_ARGUMENTS(_args) (--((uintptr_t *)(_args[0].reg_save_area))[LCC_NARGS_REGISTER])

#ifdef DEBUG_ASSERTS
#define ASSERT_LCC_VA_LIST_CLOSURE_DEFINED() {\
    core::T_O* e = reinterpret_cast<core::T_O**>(reinterpret_cast<core::VaList_S*>(gctools::untag_valist(lcc_arglist))->_Args->reg_save_area)[LCC_CLOSURE_REGISTER]; \
    ASSERT(e && gctools::tagged_generalp(e)); \
  }
#else
#define ASSERT_LCC_VA_LIST_CLOSURE_DEFINED()
#endif

#define LCC_VA_LIST_CLOSURE(_args) core::Function_sp((gctools::Tagged)((core::T_O **)(*_args)._Args->reg_save_area)[LCC_CLOSURE_REGISTER])
#define LCC_VA_LIST_REGISTER_SAVE_AREA(_args) (core::T_O **)(((*_args)._Args)[0].reg_save_area)
#define LCC_VA_LIST_OVERFLOW_ARG_AREA(_args) (core::T_O **)(((*_args)._Args)[0].overflow_arg_area)
#define LCC_VA_LIST_NUMBER_OF_ARGUMENTS(_args) LCC_raw_VA_LIST_NUMBER_OF_ARGUMENTS((*_args)._Args)
#define LCC_VA_LIST_SET_NUMBER_OF_ARGUMENTS(_args, _n) LCC_raw_VA_LIST_SET_NUMBER_OF_ARGUMENTS((*_args)._Args, _n)
#define LCC_VA_LIST_DECREMENT_NUMBER_OF_ARGUMENTS(_args) LCC_raw_VA_LIST_DECREMENT_NUMBER_OF_ARGUMENTS((*_args)._Args)
#define LCC_VA_LIST_REGISTER_ARG0(_args) (((core::T_O **)(((*_args)._Args)[0].reg_save_area))[LCC_ARG0_REGISTER])
#define LCC_VA_LIST_REGISTER_ARG1(_args) (((core::T_O **)(((*_args)._Args)[0].reg_save_area))[LCC_ARG1_REGISTER])
#define LCC_VA_LIST_REGISTER_ARG2(_args) (((core::T_O **)(((*_args)._Args)[0].reg_save_area))[LCC_ARG2_REGISTER])
#define LCC_VA_LIST_INDEXED_ARG(_res, _args, _idx)                    \
  {                                                                   \
    int __x = (_idx) - ((48 - ((*_args)._Args[0].gp_offset)) / 8);     \
    if (__x < 0) {                                                    \
      _res = ((core::T_O **)(*_args)._Args[0].reg_save_area)[__x + 6]; \
    } else {                                                          \
      _res = ((core::T_O **)(*_args)._Args[0].overflow_arg_area)[__x]; \
    }                                                                 \
  }


//    _res = ((core::T_O **)(*_args)._Args[0].overflow_arg_area)[__x]; \

#define LCC_NEXT_ARG_RAW(arglist, arg_idx) va_arg((*arglist)._Args, core::T_O *)
#define LCC_NEXT_ARG(arglist, arg_idx) core::T_sp((gc::Tagged)LCC_NEXT_ARG_RAW(arglist, arg_idx))
#define LCC_SKIP_ARG(arglist)                           \
  {                                                     \
    va_arg((*arglist)._Args);                           \
    LCC_VA_LIST_DECREMENT_NUMBER_OF_ARGUMENTS(arglist); \
  }

#else  // #if defined(X86) && defined(_ADDRESS_MODEL_64)

#error "Add support for accessing LCC_INDEXED_ARG"
#endif // #if defined(X86) && defined(_ADDRESS_MODEL_64)


#define LCC_CALL_THUNK(_result, _closure)                               \
  core::VaList_S valist_s;                                            \
  LCC_SPILL_CLOSURE_TO_VA_LIST(valist_s,_closure.raw_());               \
  core::T_O *lcc_arglist = valist_s.asTaggedPtr();                      \
  _result = _closure->invoke_va_list(LCC_PASS_ARGS0_ARGLIST(_closure.raw_()));


#define LCC_CALL_WITH_ARGS_IN_FRAME(_result, _closure, _frame)          \
  core::VaList_S valist_s(_frame);                                      \
  LCC_SPILL_CLOSURE_TO_VA_LIST(valist_s,_closure.raw_());                \
  size_t lcc_nargs = _frame.getLength();                                \
  core::T_O *lcc_arglist = valist_s.asTaggedPtr();                      \
  switch (lcc_nargs) {                                                  \
  default:                                                              \
      _result = _closure->invoke_va_list(LCC_PASS_ARGS3_ARGLIST_GENERAL(_closure.raw_(),lcc_arglist, lcc_nargs, _frame[0], _frame[1], _frame[2])); \
    break;                                                              \
  case 2:                                                               \
      _result = _closure->invoke_va_list(LCC_PASS_ARGS2_ARGLIST(_closure.raw_(),_frame[0], _frame[1])); \
    break;                                                              \
  case 1:                                                               \
      _result = _closure->invoke_va_list(LCC_PASS_ARGS1_ARGLIST(_closure.raw_(),_frame[0])); \
    break;                                                              \
  case 0:                                                               \
      _result = _closure->invoke_va_list(LCC_PASS_ARGS0_ARGLIST(_closure.raw_())); \
    break;                                                              \
  };

#define LCC_VA_LIST_TO_VECTOR_OBJECTS(_valist, _vec)                                                                        \
  core::VectorObjects_sp _vec = core::VectorObjects_O::create(_Nil<core::T_O>(), LCC_VA_LIST_NUMBER_OF_ARGUMENTS(_valist)); \
  switch (_vec->vector_length()) {                                                                                          \
  default:                                                                                                                  \
    for (int _zii = LCC_FIXED_ARGS, _zend(_vec->vector_length()); _zii < _zend; ++_zii) {                                   \
      _vec->setf_elt(_zii, LCC_INDEXED_ARG(_valist, _zii));                                                                 \
    }                                                                                                                       \
  case 3:                                                                                                                   \
      _vec->setf_elt(2,LCC_INDEXED_ARG(_valist,2); \
  case 2:                                                              \
      _vec->setf_elt(1,LCC_INDEXED_ARG(_valist,1); \
  case 1:                                                              \
      _vec->setf_elt(0,LCC_INDEXED_ARG(_valist,0); \
  case 0:                                                              \
    break;                                                                                                                  \
  }

#define LCC_DECLARE_VA_LIST()                           \
  VaList_S lcc_arglist_struct(lcc_nargs);               \
  va_start(lcc_arglist_struct._Args, LCC_VA_START_ARG); \
  VaList_sp lcc_arglist(&lcc_arglist_struct);

/*! Initialize a VaList_S struct from a Frame object */
#define LCC_SETUP_VA_LIST_FROM_FRAME(_va_list_, _frame_)                                                                                 \
  {                                                                                                                                      \
    (_va_list_)[0].reg_save_area = &(_frame_).lowLevelElementRef(gc::frame::IdxRegisterSaveArea);                                        \
    (_va_list_)[0].overflow_arg_area = &(_frame_).lowLevelElementRef(gc::frame::IdxOverflowArgs);                                        \
    /* This is where the number of arguments remaining should be stored*/                                                                \
    ((uintptr_t *)((_va_list_)[0].reg_save_area))[LCC_NARGS_REGISTER] = (_frame_)._ArrayLength;                                          \
    (_va_list_)[0].gp_offset = (gc::frame::IdxRegisterArgumentsStart - gc::frame::IdxRegisterSaveArea) * sizeof(gc::frame::ElementType); \
    (_va_list_)[0].fp_offset = 304;                                                                                                      \
  }

/*! Initialize a VaList_S struct from another VaList_S struct */
#define LCC_SETUP_VA_LIST_FROM_VA_LIST(_dest_, _src_, _nargs_left_)                  \
  {                                                                                  \
    (_dest_)[0].reg_save_area = (_src_)[0].reg_save_area;                            \
    (_dest_)[0].overflow_arg_area = (_src_)[0].overflow_arg_area;                    \
    /* This is where the number of arguments remaining should be stored*/            \
    ((uintptr_t *)((_dest_)[0].reg_save_area))[LCC_NARGS_REGISTER] = (_nargs_left_); \
    (_dest_)[0].gp_offset = (_src_)[0].gp_offset;                                    \
    (_dest_)[0].fp_offset = 304;                                                     \
  }

// Create a VaList_sp from lcc_arglist
#define LCC_MAKE_VA_LIST_SP(valist_sp) VaList_sp valist_sp((gc::Tagged)lcc_arglist)
#endif // #ifdef LCC_MACROS

#ifdef LCC_PROTOTYPES
typedef LCC_RETURN_RAW (*fnLispCallingConvention)(LCC_ARGS_VA_LIST);
typedef LCC_RETURN_RAW (*CompiledClosure_fptr_type)(LCC_ARGS_VA_LIST);
typedef LCC_RETURN (*InitFnPtr)(LCC_ARGS_VA_LIST);
typedef LCC_RETURN (*GenericFunctionPtr)(core::Instance_sp gf, core::VaList_sp valist_sptr);



template <typename FuncType>
inline gctools::return_type apply_consume_valist_(FuncType func, VaList_sp args) {
  core::T_O *arg0;
  core::T_O *arg1;
  core::T_O *arg2;
  LCC_VA_LIST_INDEXED_ARG(arg0, args, 0);
  LCC_VA_LIST_INDEXED_ARG(arg1, args, 1);
  LCC_VA_LIST_INDEXED_ARG(arg2, args, 2);
  LCC_SPILL_CLOSURE_TO_VA_LIST(*args,func.raw_());
  gctools::return_type res = (*func).invoke_va_list(func.raw_(), // was NULL
                                               args.raw_(),
                                               LCC_VA_LIST_NUMBER_OF_ARGUMENTS(args),
                                               arg0,  // LCC_VA_LIST_REGISTER_ARG0(args),
                                               arg1,  // LCC_VA_LIST_REGISTER_ARG1(args),
                                               arg2); //LCC_VA_LIST_REGISTER_ARG2(args) );
  return res;
}
#endif // #ifdef LCC_PROTOTYPES
