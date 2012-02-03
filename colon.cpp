#include "colon.h"

#include <cstdio>

template <typename L,typename S,typename H,typename T>
IGL_INLINE void igl::colon(
  const L low, 
  const S step, 
  const H hi, 
  Eigen::Matrix<T,Eigen::Dynamic,1> & I)
{
  if(low < hi)
  {
    if(step < 0)
    {
      I.resize(0);
      fprintf(stderr,"Error: colon() low(%g)<hi(%g) but step(%g)<0\n",
        (double)low,
        (double)hi,
        (double)step);
      return;
    }
  }
  if(low > hi)
  {
    if(step > 0)
    {
      I.resize(0);
      fprintf(stderr,"Error: colon() low(%g)>hi(%g) but step(%g)<0\n",
        (double)low,
        (double)hi,
        (double)step);
      return;
    }
  }
  // resize output
  int n = floor(double((hi-low)/step))+1;
  I.resize(n);
  int i = 0;
  T v = (T)low;
  while((low<hi && (H)v<=hi) || (low>hi && (H)v>=hi))
  {
    I(i) = v;
    v = v + (T)step;
    i++;
  }
  assert(i==n);
}

template <typename L,typename H,typename T>
IGL_INLINE void igl::colon(
  const L low, 
  const H hi, 
  Eigen::Matrix<T,Eigen::Dynamic,1> & I)
{
  return igl::colon(low,(T)1,hi,I);
}

template <typename T,typename L,typename H>
IGL_INLINE Eigen::Matrix<T,Eigen::Dynamic,1> igl::colon(
  const L low, 
  const H hi)
{
  Eigen::Matrix<T,Eigen::Dynamic,1> I;
  igl::colon(low,hi,I);
  return I;
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
// generated by autoexplicit.sh
template Eigen::Matrix<int, -1, 1, 0, -1, 1> igl::colon<int, int, int>(int, int);
// generated by autoexplicit.sh
template Eigen::Matrix<int, -1, 1, 0, -1, 1> igl::colon<int, int, long>(int, long);
#endif
