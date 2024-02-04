include_directories(
    "${COTTON_INCLUDE_DIR}"
    "${COTTON_GTEST_DIR}/googletest/include"
    "${COTTON_GTEST_DIR}/googlemock/include"
    "${COTTON_TEST_DIR}/Include"
)

link_libraries(
    Cotton
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
)

project(TestMeta)
add_executable(TestMeta
    "Meta/TestTypeTraits.cpp"
    "Meta/TestTypeTransforms.cpp"
)
