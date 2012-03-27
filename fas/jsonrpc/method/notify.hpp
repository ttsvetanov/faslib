#ifndef FAS_JSONRPC_METHOD_NOTIFY_HPP
#define FAS_JSONRPC_METHOD_NOTIFY_HPP

#include <fas/jsonrpc/method/tags.hpp>
#include <fas/jsonrpc/method/value_wrapper.hpp>

#include <fas/serialization/json/meta/null.hpp>
#include <fas/jsonrpc/method/ad_parse_notify.hpp>
#include <fas/jsonrpc/method/ad_notify_handler.hpp>

#include <fas/aop/advice.hpp>
#include <fas/aop/aspect.hpp>
#include <fas/aop/definition.hpp>

namespace fas{ namespace jsonrpc{ 

template< typename H, typename V = ::fas::empty_type, typename J = ::fas::json::null, template<typename> class W = value_holder >
struct notify: type_list_n<
      advice<_notify_, H >,
      advice< _parse_notify_, ad_parse_notify< W<V>, J > >,
      advice< _notify_handler_, ad_notify_handler >
    >::type
{};

  
}}

#endif
