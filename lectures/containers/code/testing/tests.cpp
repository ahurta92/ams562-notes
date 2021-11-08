//
// Created by adrian on 10/30/21.
//

#include "catch.hpp"
#include "problems.h"

// Returning Strings Problem
TEST_CASE("Test 1") {
    SECTION("Section 1") {
        CHECK(5.001 == Approx(5.0).epsilon(.01));
        REQUIRE(5.001 == Approx(5.0).epsilon(.01));
    }

    SECTION("Section 2") {
        REQUIRE(5.001 == Approx(5.0).epsilon(.01));
    }
}
