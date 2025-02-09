//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/url
//

#ifndef BOOST_URL_RFC_IPV4_ADDRESS_RULE_HPP
#define BOOST_URL_RFC_IPV4_ADDRESS_RULE_HPP

#include <boost/url/detail/config.hpp>
#include <boost/url/ipv4_address.hpp>
#include <boost/url/result.hpp>

namespace boost {
namespace urls {

/** Rule for an IP version 4 style address

    @par BNF
    @code
    IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet

    dec-octet   = DIGIT                 ; 0-9
                / %x31-39 DIGIT         ; 10-99
                / "1" 2DIGIT            ; 100-199
                / "2" %x30-34 DIGIT     ; 200-249
                / "25" %x30-35          ; 250-255
    @endcode

    @par Specification
    @li <a href="https://en.wikipedia.org/wiki/IPv4"
        >IPv4 (Wikipedia)</a>
    @li <a href="https://datatracker.ietf.org/doc/html/rfc3986#section-3.2.2"
        >3.2.2. Host (rfc3986)</a>
*/
struct ipv4_address_rule_t
{
    using value_type =
        ipv4_address;

    BOOST_URL_DECL
    auto
    parse(
        char const*& it,
        char const* end
            ) const noexcept ->
        result<ipv4_address>;
};

constexpr ipv4_address_rule_t ipv4_address_rule{};

} // urls
} // boost

#endif
