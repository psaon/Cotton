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

project(TestIterator)
add_executable(TestIterator
    "Iterator/TestIterConcepts.cpp"
)

project(TestMeta)
add_executable(TestMeta
    "Meta/TestConcepts.cpp"
    "Meta/TestExTypeOps.cpp"
    "Meta/TestIsConstEvaluated.cpp"
    "Meta/TestTypeOps.cpp"
    "Meta/TestTypeTraits.cpp"
    "Meta/TestTypeTransforms.cpp"
)
