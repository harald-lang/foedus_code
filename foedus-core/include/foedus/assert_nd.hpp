/*
 * Copyright (c) 2014, Hewlett-Packard Development Company, LP.
 * The license and distribution terms for this file are placed in LICENSE.txt.
 */
#ifndef FOEDUS_ASSERT_ND_HPP_
#define FOEDUS_ASSERT_ND_HPP_

/**
 * @var ASSERT_ND(x)
 * @ingroup IDIOMS
 * @brief A warning-free wrapper macro of assert() that has no performance effect in release
 * mode \e even \e when 'x' is not a simple variable.
 * @details
 * The standard assert() in release mode often results in compiler warnings for unused variables.
 * A common mistake is to wrap it like this:
 * @code{.cpp}
 * #define ASSERT_INCORRECT(x) do { (void)(x); } while(0)
 * @endcode
 * This can cause a performance issue when 'x' is a function call etc because the compiler might
 * not be able to confidently get rid of the code.
 * Instead, we use the idea of (void) sizeof(x) trick in the following URL.
 * @see http://cnicholson.net/2009/02/stupid-c-tricks-adventures-in-assert/
 */
/**
 * @var UNUSED_ND(var)
 * @ingroup IDIOMS
 * @brief Cross-compiler UNUSED macro for the same purpose as ASSERT_ND(x).
 */
#ifdef NDEBUG
#define ASSERT_ND(x) do { (void) sizeof(x); } while (0)
#define UNUSED_ND(var) ASSERT_ND(var)
#else  // NDEBUG
#include <cassert>
#define ASSERT_ND(x) assert(x)
#define UNUSED_ND(var)
#endif  // NDEBUG

#endif  // FOEDUS_ASSERT_ND_HPP_
