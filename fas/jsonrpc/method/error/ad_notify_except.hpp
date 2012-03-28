#ifndef FAS_JSONRPC_METHOD_AD_NOTIFY_EXCEPT_HPP
#define FAS_JSONRPC_METHOD_AD_NOTIFY_EXCEPT_HPP

#include <fas/jsonrpc/error/tags.hpp>

namespace fas{ namespace jsonrpc{

struct ad_notify_except
{
  template<typename T, typename M, typename V>
  void operator() (T& t, M&, V&, const std::exception&)
  {
    t.get_aspect().template get<_internal_error_>()( t );
  }

  template<typename T, typename M, typename V>
  void operator() (T& t, M&, V&)
  {
    t.get_aspect().template get<_internal_error_>()( t );
  }

};

}}

#endif