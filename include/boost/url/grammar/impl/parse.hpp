//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/url
//

#ifndef BOOST_URL_GRAMMAR_IMPL_PARSE_HPP
#define BOOST_URL_GRAMMAR_IMPL_PARSE_HPP

#include <boost/url/grammar/error.hpp>

namespace boost {
namespace urls {
namespace grammar {

template<class R>
auto
parse(
    char const*& it,
    char const* end,
    R const& r) ->
        result<typename R::value_type>
{
    // If this goes off, it means the rule
    // passed in did not meet the requirements.
    // Please check the documentation.
    static_assert(
        is_rule<R>::value,
        "Rule requirements not met");

    return r.parse(it, end);
}

template<class R>
auto
parse(
    string_view s,
    R const& r) ->
        result<typename R::value_type>
{
    // If this goes off, it means the rule
    // passed in did not meet the requirements.
    // Please check the documentation.
    static_assert(
        is_rule<R>::value,
        "Rule requirements not met");

    auto it = s.data();
    auto const end = it + s.size();
    auto rv = r.parse(it, end);
    if( rv.has_value() &&
            it != end)
        return error::leftover;
    return rv;
}

} // grammar
} // urls
} // boost

#endif
