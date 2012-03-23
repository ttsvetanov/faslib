//
// Author: Vladimir Migashko <migashko@faslib.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_STATIC_CHECK_VERIFYING_HPP
#define FAS_STATIC_CHECK_VERIFYING_HPP

#include "detail/verifying.hpp"

namespace fas{

template<typename T, typename CH>
struct verifying
{
  typedef typename detail::verifying_helper< T, CH >::type type;
};


}

#endif
