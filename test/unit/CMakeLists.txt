#
# Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
# Copyright (c) 2021 DMitry Arkhipov (grisumbras@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# Official repository: https://github.com/CPPAlliance/url
#

if(NOT TARGET tests)
    add_custom_target(tests)
    set_property(TARGET tests PROPERTY FOLDER _deps)
endif()

set(BOOST_URL_TESTS_FILES
    CMakeLists.txt
    Jamfile
    test_rule.hpp
    authority_view.cpp
    error.cpp
    error_code.cpp
    grammar.cpp
    host_type.cpp
    ipv4_address.cpp
    ipv6_address.cpp
    optional.cpp
    params.cpp
    params_encoded.cpp
    params_encoded_view.cpp
    params_view.cpp
    pct_encoded_view.cpp
    pct_encoding.cpp
    query_param.cpp
    result.cpp
    scheme.cpp
    segments.cpp
    segments_encoded.cpp
    segments_encoded_view.cpp
    segments_view.cpp
    snippets.cpp
    static_pool.cpp
    static_url.cpp
    string_view.cpp
    url.cpp
    url_view.cpp
    urls.cpp
    variant.cpp
    grammar/ascii.cpp
    grammar/char_rule.cpp
    grammar/charset.cpp
    grammar/dec_octet_rule.cpp
    grammar/error.cpp
    grammar/lut_chars.cpp
    grammar/not_empty_rule.cpp
    grammar/optional_rule.cpp
    grammar/parse.cpp
    grammar/range.cpp
    grammar/sequence_rule.cpp
    grammar/token_rule.cpp
    grammar/type_traits.cpp
    grammar/unsigned_dec_rule.cpp
    grammar/variant_rule.cpp
    rfc/absolute_uri_rule.cpp
    rfc/authority_rule.cpp
    rfc/charsets.cpp
    rfc/ipv4_address_rule.cpp
    rfc/ipv6_address_rule.cpp
    rfc/paths_rule.cpp
    rfc/pct_encoded_rule.cpp
    rfc/query_rule.cpp
    rfc/relative_ref_rule.cpp
    rfc/uri_rule.cpp
    rfc/uri_reference_rule.cpp
    )

set(TEST_MAIN ../../extra/test_main.cpp)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${BOOST_URL_TESTS_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/../../extra PREFIX "_extra" FILES ${TEST_MAIN})
add_executable(boost_url_tests ${BOOST_URL_TESTS_FILES} ${TEST_MAIN})
target_include_directories(boost_url_tests PRIVATE . ../../extra/include)
target_link_libraries(boost_url_tests PRIVATE Boost::url Boost::container Boost::filesystem)
add_test(NAME boost_url_tests COMMAND boost_url_tests)
add_dependencies(tests boost_url_tests)
