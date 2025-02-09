//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/url
//

#ifndef BOOST_URL_RFC_IMPL_AUTHORITY_RULE_IPP
#define BOOST_URL_RFC_IMPL_AUTHORITY_RULE_IPP

#include <boost/url/rfc/authority_rule.hpp>
#include <boost/url/grammar/char_rule.hpp>
#include <boost/url/grammar/parse.hpp>
#include <boost/url/grammar/sequence_rule.hpp>
#include <boost/url/rfc/detail/host_rule.hpp>
#include <boost/url/rfc/detail/port_rule.hpp>
#include <boost/url/rfc/detail/userinfo_rule.hpp>

namespace boost {
namespace urls {

auto
authority_rule_t::
parse(
    char const*& it,
    char const* const end
        ) const noexcept ->
    result<value_type>
{
    detail::url_impl u(true);
    u.cs_ = it;

    // [ userinfo "@" ]
    {
        auto rv = grammar::parse(
            it, end,
            grammar::optional_rule(
                grammar::sequence_rule(
                    detail::userinfo_rule,
                    grammar::char_rule('@'))));
        if(! rv)
            return rv.error();
        if(rv->has_value())
        {
            u.apply_userinfo(
                std::get<0>(**rv).user,
                std::get<0>(**rv).has_password
                ? &std::get<0>(**rv).password
                : nullptr);
        }
    }

    // host
    {
        auto rv = grammar::parse(
            it, end, detail::host_rule);
        if(! rv)
            return rv.error();
        u.apply_host(
            rv->host_type, rv->match,
                rv->addr, rv->name);
    }

    // [ ":" port ]
    {
        auto rv = grammar::parse(
            it, end, detail::port_part_rule);
        if(! rv)
            return rv.error();
        if(rv->has_port)
            u.apply_port(
                rv->port,
                rv->port_number);
    }

    return u.construct_authority();
}

} // urls
} // boost

#endif
