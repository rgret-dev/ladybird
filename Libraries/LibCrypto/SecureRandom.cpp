/*
 * Copyright (c) 2024, the Ladybird developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/UFixedBigInt.h>
#include <AK/UFixedBigIntDivision.h>
#include <LibCrypto/SecureRandom.h>

#include <openssl/rand.h>

namespace Crypto {

void fill_with_secure_random(Bytes bytes)
{
    auto const size = static_cast<int>(bytes.size());

    if (RAND_bytes(bytes.data(), size) != 1)
        VERIFY_NOT_REACHED();
}

u32 get_secure_random_uniform(u32 const max_bounds)
{
    u32 const max_usable = UINT32_MAX - ((static_cast<u64>(UINT32_MAX) + 1) % max_bounds);

    // TODO: Make this loop have a max number of iterations?
    u32 random_value;
    do {
        random_value = get_secure_random<u32>();
    } while (random_value > max_usable);

    return random_value % max_bounds;
}

}
