#ifndef FAS_JSONRPC_ERROR_AD_INVALID_ID_HPP
#define FAS_JSONRPC_ERROR_AD_INVALID_ID_HPP

#include <fas/jsonrpc/error/tags.hpp>
#include <fas/jsonrpc/error/error_code.hpp>

namespace fas{ namespace jsonrpc{ 

struct ad_invalid_id
{
  template<typename T>
  void operator() (T& t, int id)
  {
    t.get_aspect().template get<_send_error_>()( t, error_code::invalid_request, id );
  }

  template<typename T>
  void operator() (T& t)
  {
    t.get_aspect().template get<_send_error_>()( t, error_code::invalid_request );
  }
};

}}

#endif
