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
#include "fossil/type/converter.h"
#include <string.h>
#include <stdlib.h>

#define MAX_CONVERTERS 128

static fossil_type_converter* registry[MAX_CONVERTERS];
static size_t registry_count = 0;

/* ------------------------------------------------------
 * Register a converter
 * ------------------------------------------------------ */
int fossil_type_converter_register(fossil_type_converter* converter) {
    if (!converter || registry_count >= MAX_CONVERTERS)
        return -1;

    registry[registry_count++] = converter;
    return 0;
}

/* ------------------------------------------------------
 * Find a converter by from_type and to_type
 * ------------------------------------------------------ */
static fossil_type_converter* find_converter(
    const char* from_type,
    const char* to_type
) {
    for (size_t i = 0; i < registry_count; i++) {
        if (strcmp(registry[i]->from_type, from_type) == 0 &&
            strcmp(registry[i]->to_type, to_type) == 0) {
            return registry[i];
        }
    }
    return NULL;
}

/* ------------------------------------------------------
 * Apply a converter
 * ------------------------------------------------------ */
int fossil_type_converter_apply(
    const char* from_type,
    const char* to_type,
    const void* input,
    void* output
) {
    fossil_type_converter* conv = find_converter(from_type, to_type);
    if (!conv || !conv->convert)
        return -1;

    return conv->convert(input, from_type, output, to_type, conv->user);
}
