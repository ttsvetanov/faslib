// Author: Vladimir Migashko <migashko@faslib.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_MP_PH_MAX_HPP
#define FAS_MP_PH_MAX_HPP

#include <fas/mp/p.hpp>
#include <fas/mp/placeholders.hpp>
namespace fas{

template<typename F, int C = 0 >
struct ph_num { enum { value = 0, next = C}; };

template<int C>
struct ph_num<_, C> { enum { value = C + 1, next = C+1}; };

template<int C>
struct ph_num<_1, C> { enum { value = 1, next = C}; };

template<int C>
struct ph_num<_2, C> { enum { value = 2, next = C}; };

template<int C>
struct ph_num<_3, C> { enum { value = 3, next = C}; };

template<int C>
struct ph_num<_4, C> { enum { value = 4, next = C}; };

template<int C>
struct ph_num<_5, C> { enum { value = 5, next = C}; };

// перенести в integral
template<int L, int R>
struct max_c
{
  enum { value = L < R ? R : L};
};

namespace detail
{
  
  template<typename F, int _C>
  struct ph_max_impl;

  template<typename F>
  struct ph_max_helper
  {
    enum { value = max_c< ph_max_impl<F, 0>::value, ph_max_impl<F, 0>::count>::value };
  };
  
  template<typename F, int _C>
  struct ph_max_impl_1;

  template<typename F, int _C>
  struct ph_max_impl_2;

  template<typename F, int _C>
  struct ph_max_impl_3;

  template<typename F, int _C>
  struct ph_max_impl_4;

  template<typename F, int _C>
  struct ph_max_impl: ph_max_impl_4< F, _C>
  {
    // enum { value = max_c< ph_num<F, _C>::value, _C >::value, count = ph_num<F, _C>::next };
  };

  template< typename P1, int _C>
  struct ph_max_impl< p<P1>, _C > 
  {
    enum { value = 0, count = _C };
  };

  template<typename F, int _C>
  struct ph_max_impl_1
  {
    enum { value = max_c< ph_num<F, _C>::value, _C >::value, count = ph_num<F, _C>::next };
  };

  template<template<typename> class F, typename P1, int _C>
  struct ph_max_impl_1< F<P1>, _C > 
  {
    enum 
    { 
      //current = max_c< ph_num<P1, _C>::value, _C >::value,
      count = ph_max_impl< P1, _C>::count,
      value = max_c< ph_max_impl< P1, _C>::value, _C>::value
    };
  };

  template<typename F, int _C>
  struct ph_max_impl_2: ph_max_impl_1< F, _C> {};

  template<template<typename, typename> class F, typename P1, typename P2, int _C>
  struct ph_max_impl_2< F<P1, P2>, _C > 
  {
    enum 
    { 
      count = ph_max_impl< P2, ph_max_impl<P1, _C>::count>::count,
      p1 = ph_max_impl< P1, _C>::value,
      p2 = ph_max_impl< P2, _C>::value,
      value = max_c< p1, p2>::value
    };
  };

  template<typename F, int _C>
  struct ph_max_impl_3: ph_max_impl_2< F, _C> {};

  template<template<typename, typename, typename> class F, typename P1, typename P2, typename P3, int _C>
  struct ph_max_impl_3< F<P1, P2, P3>, _C > 
  {
    enum 
    { 
      count = ph_max_impl< P3, ph_max_impl<P2, ph_max_impl<P1, _C>::count >::count>::count,
      p1 = ph_max_impl< P1, _C>::value,
      p2 = ph_max_impl< P2, _C>::value,
      p3 = ph_max_impl< P3, _C>::value,
      value = max_c< p1, max_c<p2, p3>::value >::value
    };
  };

  template<typename F, int _C>
  struct ph_max_impl_4: ph_max_impl_3< F, _C> {};
  
  template<template<typename, typename, typename, typename> class F, 
          typename P1, typename P2, typename P3, typename P4, int _C>
  struct ph_max_impl_4< F<P1, P2, P3, P4>, _C > 
  {
    enum 
    { 
      count = ph_max_impl< P4, ph_max_impl<P3, ph_max_impl<P2, ph_max_impl<P1, _C>::count>::count >::count>::count,
      p1 = ph_max_impl< P1, _C>::value,
      p2 = ph_max_impl< P2, _C>::value,
      p3 = ph_max_impl< P3, _C>::value,
      p4 = ph_max_impl< P4, _C>::value,
      value = max_c< p1, max_c<p2, max_c<p3, p4>::value>::value >::value
    };
  };

 template<template<typename, typename, typename, typename, typename> class F, 
          typename P1, typename P2, typename P3, typename P4, typename P5,  int _C>
  struct ph_max_impl< F<P1, P2, P3, P4, P5>, _C > 
  {
    enum 
    { 
      count = ph_max_impl< P5, ph_max_impl<P4, ph_max_impl<P3, ph_max_impl<P2, ph_max_impl<P1, _C>::count >::count >::count >::count>::count,
      p1 = ph_max_impl< P1, _C>::value,
      p2 = ph_max_impl< P2, _C>::value,
      p3 = ph_max_impl< P3, _C>::value,
      p4 = ph_max_impl< P4, _C>::value,
      p5 = ph_max_impl< P5, _C>::value,
      value = max_c< p1, max_c<p2, max_c<p3, max_c<p4, p5>::value>::value>::value >::value
    };
  };

}


template<typename F>
struct ph_max
{
  enum { value = detail::ph_max_helper<F>::value };
};

}

#endif
