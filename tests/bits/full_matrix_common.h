//----------------------------  full_matrix_common.h  ---------------------------
//    $Id$
//    Version: $Name$ 
//
//    Copyright (C) 2007, 2008 by the deal.II authors
//
//    This file is subject to QPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//----------------------------  full_matrix_common.h  ---------------------------


// common framework for the various full_matrix_*.cc tests

#include "../tests.h"
#include <base/logstream.h>
#include <lac/vector.h>
#include <lac/full_matrix.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>


// forward declaration of the function that must be provided in the
// .cc files
template <typename number>
void
check ();

// forward declaration of a variable with the name of the output file
extern std::string output_file_name;



template <typename number>
void make_matrix (FullMatrix<number> &m)
{
  m.reinit (5,5);
  for (unsigned int i=0; i<5; ++i)
    for (unsigned int j=0; j<5; ++j)
      m(i,j) = (i+1)*(j+2);
}


template <typename number>
void make_complex_matrix (FullMatrix<std::complex<number> > &m)
{
  m.reinit (5,5);
  for (unsigned int i=0; i<5; ++i)
    for (unsigned int j=0; j<5; ++j)
      m(i,j) = std::complex<number>((i+1)*(j+2), (i+3)*(j+4));
}


template <typename number>
void make_vector (Vector<number> &v)
{
  v.reinit (5);
  for (unsigned int i=0; i<5; ++i)
    v(i) = (i+1);
}



template <typename number>
void make_complex_vector (Vector<std::complex<number> > &v)
{
  v.reinit (5);
  for (unsigned int i=0; i<5; ++i)
    v(i) = std::complex<number>(i+1, i+3);
}



template <typename number>
void
print_matrix (const FullMatrix<number> &m)
{
  for (unsigned int i=0; i<m.m(); ++i)
    for (unsigned int j=0; j<m.n(); ++j)
      deallog << i << ' ' << j << ' ' << m(i,j)
	      << std::endl;
}



template <typename number>
void
print_vector (const Vector<number> &v)
{
  for (unsigned int i=0; i<v.size(); ++i)
    deallog << i << ' ' << v(i)
	    << std::endl;
}



int
main()
{
  try
    {
      std::ofstream logfile(output_file_name.c_str());
      deallog << std::setprecision (2);
      deallog.attach(logfile);
      deallog.depth_console(0);
      deallog.threshold_double(1.e-7);

      check<double> ();
      check<float> ();
      
      return 0;
    }
  catch (std::exception &exc)
    {
      deallog << std::endl << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
      deallog << "Exception on processing: " << std::endl
	      << exc.what() << std::endl
	      << "Aborting!" << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
      return 1;
    }
  catch (...) 
    {
      deallog << std::endl << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
      deallog << "Unknown exception!" << std::endl
	      << "Aborting!" << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
      return 1;
    };
}

