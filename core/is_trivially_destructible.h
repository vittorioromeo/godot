#pragma once

#if defined(__has_builtin)
#define HAS_BUILTIN(x) __has_builtin(x)
#else
#define HAS_BUILTIN(x) 0
#endif

#if HAS_BUILTIN(__is_trivially_destructible)
#define IS_TRIVIALLY_DESTRUCTIBLE(x) __is_trivially_destructible(x)
#elif HAS_BUILTIN(__has_trivial_destructor)
#define IS_TRIVIALLY_DESTRUCTIBLE(x) __has_trivial_destructor(x)
#else
#include <type_traits>
#define IS_TRIVIALLY_DESTRUCTIBLE(x) ::std::is_trivially_destructible_v<x>
#endif