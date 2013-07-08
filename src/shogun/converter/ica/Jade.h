/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2013 Kevin Hughes
 */

#ifndef JADE_H_
#define JADE_H_

#include <shogun/lib/config.h>
#ifdef HAVE_EIGEN3
#include <shogun/converter/Converter.h>
#include <shogun/features/Features.h>

namespace shogun
{

class CFeatures;

/** @brief class Jade
 * 
 * Implements the Jade algorithm for Independent
 * Component Analysis (ICA) and Blind Source
 * Separation (BSS).
 * 
 */
class CJade: public CConverter
{
	public:
		
		/** constructor */
		CJade();

		/** destructor */
		virtual ~CJade();

		/** apply to features
		 * @param features to embed
		 * @param embedding features
		 */
		virtual CFeatures* apply(CFeatures* features);

		/** getter for tau parameter
		 * @return tau vector
		 */
		SGVector<float64_t> get_tau() const;

		/** setter for tau parameter
		 * @param tau vector
		 */
		void set_tau(SGVector<float64_t> tau);

		/** getter for mixing_matrix
		 * @return mixing_matrix
		 */
		SGMatrix<float64_t> get_mixing_matrix() const;

		virtual const char* get_name() const { return "Jade"; };

	protected:

		/** init */
		void init();

	private:
		
		SGVector<float64_t> m_tau;
		SGMatrix<float64_t> m_mixing_matrix;
};	
}
#endif // HAVE_EIGEN3
#endif // JADE
