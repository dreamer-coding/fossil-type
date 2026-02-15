/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#ifndef FOSSIL_TYPE_COMBO_H
#define FOSSIL_TYPE_COMBO_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct fossil_type_combo {
    uint64_t bits;
} fossil_type_combo;

typedef fossil_type_combo combo;

/* Construction */
combo fossil_type_combo_make(uint64_t bits);

/* Operations */
combo fossil_type_combo_add(combo c, uint64_t mask);
combo fossil_type_combo_remove(combo c, uint64_t mask);
int   fossil_type_combo_has(combo c, uint64_t mask);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Combo {
    combo c;
public:
    Combo():c{0}{}
    explicit Combo(uint64_t b){ c=fossil_type_combo_make(b); }

    bool has(uint64_t m) const { return fossil_type_combo_has(c,m); }

    Combo operator|(uint64_t m) const {
        return Combo(fossil_type_combo_add(c,m).bits);
    }
};

}
#endif

#endif
