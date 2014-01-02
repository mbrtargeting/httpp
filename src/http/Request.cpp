/*
 * Part of HTTPP.
 *
 * Distributed under the 3-clause BSD licence (See LICENCE.TXT file at the
 * project root).
 *
 * Copyright (c) 2013 Thomas Sanchez.  All rights reserved.
 *
 */

#include "httpp/http/Request.hpp"
#include <ostream>

namespace HTTPP
{
namespace HTTP
{
std::ostream& operator<<(std::ostream& os, const Request& request)
{
    switch (request.method)
    {
    case Request::Method::HEAD:
        os << "HEAD ";
        break;
    case Request::Method::GET:
        os << "GET ";
        break;
    case Request::Method::POST:
        os << "POST ";
        break;
    case Request::Method::PUT:
        os << "PUT ";
        break;
    case Request::Method::DELETE_:
        os << "DELETE ";
        break;
    case Request::Method::OPTIONS:
        os << "OPTIONS ";
        break;
    case Request::Method::TRACE:
        os << "TRACE ";
        break;
    case Request::Method::CONNECT:
        os << "CONNECT ";
        break;
    }

    std::string uri = request.uri;
    if (!request.query_params.empty())
    {
        uri += '?';
        for (auto const& q: request.query_params)
        {
            uri += q.first + "=" + q.second + "&";
        }
    }

    os << uri << " HTTP/" << request.major << "." << request.minor << "\n";
    for (auto const& h : request.headers)
    {
        os << h.first << ": " << h.second << "\n";
    }

    return os;
}

} // namespace HTTP
} // namespace HTTPP

