#pragma once
///@file

#include <gtest/gtest.h>

#include "nix/util/types.hh"
#include "nix/util/environment-variables.hh"
#include "nix/util/file-system.hh"

namespace nix {

/**
 * The path to the unit test data directory. See the contributing guide
 * in the manual for further details.
 */
static inline std::filesystem::path getUnitTestData()
{
    return getEnv("_NIX_TEST_UNIT_DATA").value();
}

/**
 * Whether we should update "golden masters" instead of running tests
 * against them. See the contributing guide in the manual for further
 * details.
 */
static inline bool testAccept()
{
    return getEnv("_NIX_TEST_ACCEPT") == "1";
}

/**
 * Mixin class for writing characterization tests
 */
class CharacterizationTest : public virtual ::testing::Test
{
protected:
    /**
     * While the "golden master" for this characterization test is
     * located. It should not be shared with any other test.
     */
    virtual std::filesystem::path goldenMaster(PathView testStem) const = 0;

public:
    /**
     * Golden test for reading
     *
     * @param test hook that takes the contents of the file and does the
     * actual work
     */
    void readTest(PathView testStem, auto && test)
    {
        auto file = goldenMaster(testStem);

        if (testAccept()) {
            GTEST_SKIP() << "Cannot read golden master " << file << "because another test is also updating it";
        } else {
            test(readFile(file));
        }
    }

    /**
     * Golden test for writing
     *
     * @param test hook that produces contents of the file and does the
     * actual work
     */
    void writeTest(PathView testStem, auto && test, auto && readFile2, auto && writeFile2)
    {
        auto file = goldenMaster(testStem);

        auto got = test();

        if (testAccept()) {
            std::filesystem::create_directories(file.parent_path());
            writeFile2(file, got);
            GTEST_SKIP() << "Updating golden master " << file;
        } else {
            decltype(got) expected = readFile2(file);
            ASSERT_EQ(got, expected);
        }
    }

    /**
     * Specialize to `std::string`
     */
    void writeTest(PathView testStem, auto && test)
    {
        writeTest(
            testStem,
            test,
            [](const std::filesystem::path & f) -> std::string { return readFile(f); },
            [](const std::filesystem::path & f, const std::string & c) { return writeFile(f, c); });
    }
};

} // namespace nix
