#ifndef FAS_JSONRPC_INVOKE_INVOKE_ASPECT_HPP
#define FAS_JSONRPC_INVOKE_INVOKE_ASPECT_HPP

#include <fas/jsonrpc/invoke/ad_invoke_notify.hpp>
#include <fas/jsonrpc/invoke/ad_invoke_request.hpp>
#include <fas/jsonrpc/invoke/ad_not_impl.hpp>
#include <fas/jsonrpc/invoke/ad_notify_not_found.hpp>
#include <fas/jsonrpc/invoke/ad_request_not_found.hpp>

#include <fas/jsonrpc/invoke/remote/ad_result_not_found.hpp>
#include <fas/jsonrpc/invoke/remote/ad_error_not_found.hpp>
#include <fas/jsonrpc/invoke/remote/ad_invoke_other_error_stub.hpp>
#include <fas/jsonrpc/invoke/remote/ad_invoke_invalid_id.hpp>

#include <fas/jsonrpc/invoke/tags.hpp>

#include <fas/aop/aspect.hpp>
#include <fas/aop/advice.hpp>
#include <fas/aop/stub.hpp>
#include <fas/aop/definition.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace jsonrpc{ 

struct invoke_list: type_list_n<
  advice< _invoke_notify_, ad_invoke_notify >,
  advice< _invoke_request_, ad_invoke_request >,
  advice< _not_impl_, ad_not_impl >,
  advice< _notify_not_found_, ad_notify_not_found >,
  advice< _request_not_found_, ad_request_not_found >,

  /// stubs
  advice< _invoke_invalid_id_, ad_invoke_invalid_id >,
  advice< _invoke_result_, ad_result_not_found >,
  advice< _invoke_error_, ad_error_not_found >,
  advice< _invoke_other_error_, ad_invoke_other_error_stub>
  
>::type {};

struct invoke_aspect: 
  ::fas::aspect<invoke_list> 
{
};
  
}}

#endif