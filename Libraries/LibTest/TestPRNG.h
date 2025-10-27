/*
 * Copyright (c) 2025, the Ladybird developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Assertions.h>
#include <AK/Types.h>

namespace Test::PRNG {

template<typename T>
inline T get_value()
{
    TODO();
}

inline void fill(Bytes bytes)
{
    (void)bytes;
    TODO();
}

inline u32 get_uniform_value(u32 const max_bounds)
{
    (void)max_bounds;
    TODO();
}

inline u64 get_uniform_value_64(u64 const max_bounds)
{
    (void)max_bounds;
    TODO();
}

template<typename Collection>
static void shuffle(Collection& collection)
{
    // Fisher-Yates shuffle
    for (size_t i = collection.size() - 1; i >= 1; --i) {
        size_t j = get_uniform_value(i + 1);
        AK::swap(collection[i], collection[j]);
    }
}

}
