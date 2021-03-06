//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_MP_PLACEHOLDERS_HPP
#define FAS_MP_PLACEHOLDERS_HPP

#include <fas/integral/int_.hpp>

namespace fas{

template<int i>
struct placeholder: int_<i>{};

struct _ : placeholder<-1> {};
struct _1: placeholder<1> {};
struct _2: placeholder<2> {};
struct _3: placeholder<3> {};
struct _4: placeholder<4> {};
struct _5: placeholder<5> {};

namespace placeholders 
{
  typedef ::fas::_  _;
  typedef ::fas::_1 _1;
  typedef ::fas::_2 _2;
  typedef ::fas::_3 _3;
  typedef ::fas::_4 _4;
  typedef ::fas::_5 _5;
}

}

#endif
