#ifndef FAS_JSONRPC_JSON_NOTIFY_OBJECT_JSON_HPP
#define FAS_JSONRPC_JSON_NOTIFY_OBJECT_JSON_HPP

#include <fas/jsonrpc/names.hpp>
#include <fas/serialization/json/meta.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace jsonrpc{

namespace aj = ::fas::json;
  
template< typename N, typename J >
struct notify_object_json:
  aj::object<
    typename type_list_n<
      aj::member< n_jsonrpc, aj::tstring<version> >,
      aj::member< n_method,  aj::tstring<N>      >,
      aj::member< n_params,  J       >
    >::type
  >
{
};

}}

#endif
