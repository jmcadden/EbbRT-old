//          Copyright Boston University SESA Group 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#include "Clock.h"

ebbrt::clock::HighResTimer::DoOnce ebbrt::clock::HighResTimer::once;

ebbrt::clock::Wall::time_point ebbrt::clock::Wall::Now() noexcept {
  return std::chrono::system_clock::now();
}
