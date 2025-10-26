/*
 * Copyright (c) 2025, the Ladybird developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/HashMap.h>
#include <LibCrypto/SecureRandom.h>

namespace Crypto {

class SecureIdentifierPool {

public:
    SecureIdentifierPool() = default;

    explicit SecureIdentifierPool(int const minimum_value)
        : m_minimum_value(minimum_value)
    {
    }

    ~SecureIdentifierPool() = default;

    int acquire_identifier()
    {
        VERIFY(m_allocated_ids.size() < (INT32_MAX - 2));
        int id = 0;
        for (;;) {
            id = get_secure_random<int>();
            if (id < m_minimum_value)
                continue;
            if (m_allocated_ids.set(id) == HashSetResult::InsertedNewEntry)
                break;
        }
        return id;
    }

    void release_identifier(int const id)
    {
        m_allocated_ids.remove(id);
    }

private:
    HashTable<int> m_allocated_ids;
    int m_minimum_value { 1 };
};

}
