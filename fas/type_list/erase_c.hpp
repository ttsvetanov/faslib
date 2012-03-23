//
// Author: Vladimir Migashko <migashko@faslib.com>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_IMPLEMENTATION_TYPE_LIST_ERASE_C_HPP
#define FAS_IMPLEMENTATION_TYPE_LIST_ERASE_C_HPP

#include "detail/erase_c.hpp"

namespace fas{

template<int I, typename L>
struct erase_c
{
  typedef typename detail::erase_helper<I, L>::type type;
};


}

#endif
