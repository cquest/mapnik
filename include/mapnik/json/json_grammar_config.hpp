/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2016 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

#ifndef MAPNIK_JSON_GRAMMAR_CONFIG_HPP
#define MAPNIK_JSON_GRAMMAR_CONFIG_HPP

#include <boost/spirit/home/x3.hpp>
#include <unordered_map>

namespace mapnik { namespace json {

struct keys_tag;

namespace grammar {

using keys_map = std::unordered_map<std::string, int>;

namespace x3 = boost::spirit::x3;
using space_type = x3::standard::space_type;
using iterator_type = std::string::const_iterator;
using context_type = x3::with_context<keys_tag,
                                      std::reference_wrapper<keys_map> const,
                                      x3::phrase_parse_context<space_type>::type>::type;
}}}

#endif // MAPNIK_JSON_GRAMMAR_CONFIG_HPP